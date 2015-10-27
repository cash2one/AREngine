#include "assimp_util.h"
#include "file_system.h"
#include "../mesh/mesh.h"

#include <assimp/cimport.h>
#include <assimp/LogStream.hpp>
#include <assimp/DefaultLogger.hpp>
#include <assimp/Importer.hpp>
#include <assimp/importerdesc.h>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

using namespace Assimp;

unsigned int ppsteps = aiProcess_CalcTangentSpace | // calculate tangents and bitangents if possible
aiProcess_JoinIdenticalVertices | // join identical vertices/ optimize indexing
aiProcess_ValidateDataStructure | // perform a full validation of the loader's output
aiProcess_ImproveCacheLocality | // improve the cache locality of the output vertices
aiProcess_RemoveRedundantMaterials | // remove redundant materials
aiProcess_FindDegenerates | // remove degenerated polygons from the import
aiProcess_FindInvalidData | // detect invalid model data, such as invalid normal vectors
aiProcess_GenUVCoords | // convert spherical, cylindrical, box and planar mapping to proper UVs
aiProcess_TransformUVCoords | // preprocess UV transformations (scaling, translation ...)
aiProcess_FindInstances | // search for instanced meshes and remove them by references to one master
aiProcess_LimitBoneWeights | // limit bone weights to 4 per vertex
aiProcess_OptimizeMeshes | // join small meshes, if possible;
aiProcess_SplitByBoneCount | // split meshes with too many bones. Necessary for our (limited) hardware skinning shader
0;


bool AssimpUtil::LoadFile(const char* file_name, std::vector<Mesh*>& meshes){
	if (file_name == NULL){
		return false;
	}

	if (!FileSystem::FileExists(file_name)){

		std::string log = file_name + std::string(" is not exsit!");
		g_log->Write(log);
		return false;
	}

	aiPropertyStore* props = aiCreatePropertyStore();
	aiSetImportPropertyInteger(props, AI_CONFIG_IMPORT_TER_MAKE_UVS, 1);
	aiSetImportPropertyFloat(props, AI_CONFIG_PP_GSN_MAX_SMOOTHING_ANGLE, 80.0f);

	aiScene* root = (aiScene*)aiImportFileExWithProperties(file_name,
		ppsteps |
		aiProcess_GenSmoothNormals |
		aiProcess_SplitLargeMeshes |
		aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded |
		aiProcess_SortByPType |
		0,
		NULL,
		props);

	if (root == NULL){
		g_log->Write("failed to load file");
	}

	for (int i = 0; i < root->mNumMeshes; i++){
		Mesh* mesh = CreateMesh(root->mMeshes[i]);
		if (mesh != NULL)
		{
			Mesh::s_mesh_list.push_back(mesh);
		}
	}

	aiReleasePropertyStore(props);

	return true;
}

Mesh* AssimpUtil::CreateMesh(aiMesh* src_mesh){

	if (src_mesh == NULL){
		return NULL;
	}

	// vertex data
	int vertex_num = src_mesh->mNumVertices;
	Geometry::VertexFull* vertex_list = new Geometry::VertexFull[vertex_num];
	if (vertex_list == NULL){
		return NULL;
	}
	for (int i = 0; i < src_mesh->mNumVertices; i++){
		// position
		vertex_list[i].position = RTMath::Vector(src_mesh->mVertices[i].x, 
			src_mesh->mVertices[i].y, 
			src_mesh->mVertices[i].z);
		// normal
		if (src_mesh->mNormals != NULL){
			vertex_list[i].normal = RTMath::Vector(src_mesh->mNormals[i].x,
				src_mesh->mNormals[i].y,
				src_mesh->mNormals[i].z);
		}
		// color
		if (src_mesh->HasVertexColors(0) != NULL){
			vertex_list[i].color = RTMath::Color(src_mesh->mColors[i][0].r,
				src_mesh->mColors[i][0].g,
				src_mesh->mColors[i][0].b,
				src_mesh->mColors[i][0].a);
		}
		// tangent
		if (src_mesh->mTangents != NULL){
			vertex_list[i].tangent = RTMath::Vector(src_mesh->mTangents[i].x,
				src_mesh->mTangents[i].y,
				src_mesh->mTangents[i].z);
		}
		// bitangent
		if (src_mesh->mBitangents != NULL){
			vertex_list[i].bitangent = RTMath::Vector(src_mesh->mBitangents[i].x,
				src_mesh->mBitangents[i].y,
				src_mesh->mBitangents[i].z);
		}
		// tex coordinate
		if (src_mesh->HasTextureCoords(0)){
			vertex_list[i].texture1 = Geometry::TexCoord(src_mesh->mTextureCoords[0][i].x,
				src_mesh->mTextureCoords[0][i].y);
		}
		if (src_mesh->HasTextureCoords(1)){
			vertex_list[i].texture2 = Geometry::TexCoord(src_mesh->mTextureCoords[1][i].x,
				src_mesh->mTextureCoords[1][i].y);
		}
		// bone indices and weights
		if (src_mesh->HasBones()){
			
		}
	}

	// index data
	int nidx;
	switch (src_mesh->mPrimitiveTypes)
	{
	case aiPrimitiveType_POINT:
		nidx = 1; break;
	case aiPrimitiveType_LINE:
		nidx = 2; break;
	case aiPrimitiveType_TRIANGLE:
		nidx = 3; break;
	default:
		SAFE_DELETE(vertex_list);
		return NULL;
		break;
	}
	int index_num = src_mesh->mNumFaces * nidx;
	unsigned int* index_list = new unsigned int[index_num];
	if (index_list == NULL)
	{
		SAFE_DELETE(vertex_list);
		return NULL;
	}
	unsigned int* address = index_list;
	for (int i = 0; i < src_mesh->mNumFaces; i++){
		for (int j = 0; j < nidx; j++){
			*address++ = src_mesh->mFaces[i].mIndices[j];
		}
	}

	// mesh
	Mesh* dst_mesh = new Mesh();
	if (!dst_mesh->geometry()->Init<Geometry::VertexFull>(vertex_list,
		vertex_num, 
		index_list, 
		index_num)){
		SAFE_DELETE(vertex_list);
		SAFE_DELETE(index_list);
		SAFE_DELETE(dst_mesh);
		return NULL;
	}
	if (!dst_mesh->material()->Init("../../bin/res/color.vs", "../../bin/res/color.ps")){
		SAFE_DELETE(vertex_list);
		SAFE_DELETE(index_list);
		SAFE_DELETE(dst_mesh);
		return NULL;
	}
	if (!dst_mesh->material()->SetTexture("../../bin/res/stone01.tga")){
		SAFE_DELETE(vertex_list);
		SAFE_DELETE(index_list);
		SAFE_DELETE(dst_mesh);
		return NULL;
	}

	return dst_mesh;
}