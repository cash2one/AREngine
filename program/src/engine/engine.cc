#include "engine.h"
#include "dx11/renderer_dx11.h"
#include "es2/renderer_es2.h"
#include "mesh/mesh.h"
#include "camera/camera.h"
#include "util/file_util.h"

#include <assimp/Importer.hpp>
#include <BaseImporter.h>

Log* g_log = 0;
Engine* g_engine = 0;
Renderer* g_renderer = 0;
FreeCamera* g_camera = 0;
FileUtil* g_file_util = 0;

Engine::Engine(){
	Assimp::Importer* pImp = new Assimp::Importer();
}

Engine::~Engine(){
	Free();
}

bool Engine::Init(const Renderer::Window& param){
	Plateform::Init();

	g_log = new Log();
	if (!g_log->Init()){
		return false;
	}

	g_file_util = new FileUtil();
	if (!g_file_util->Init()){
		return false;
	}
	
	if (Plateform::graphic_api() == Plateform::D3D_11){
		g_renderer = new RendererDx11();
	}
	else if (Plateform::graphic_api() == Plateform::GLES_2){
		g_renderer = new RendererEs2();
	}
	
	if (!g_renderer->Init(param)){
		return false;
	}

	g_camera = new FreeCamera();
	g_camera->SetPos(Vector(0.0f, 0.0f, -5.0f));

	return true;
}

void Engine::Update(){
	g_camera->Update();
	g_renderer->Update();
}

void Engine::Render(){
	Vector clear_color(0, 0, 0);
	g_renderer->PreRender(clear_color);

	std::vector<Mesh*>::const_iterator iter = Mesh::s_mesh_list.begin();
	for (; iter != Mesh::s_mesh_list.end(); iter++){
		(*iter)->Render();
	}

	g_renderer->PostRender();
}



void Engine::Free(){

	std::vector<Mesh*>::iterator iter = Mesh::s_mesh_list.begin();
	for(; iter != Mesh::s_mesh_list.end(); iter++){
		(*iter)->Free();
	}

	SAFE_FREE(g_camera);
	SAFE_FREE(g_renderer);
}