/*
Open Asset Import Library (ASSIMP)
----------------------------------------------------------------------

Copyright (c) 2006-2010, ASSIMP Development Team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

/** @file  BlenderSceneGen.h
 *  @brief MACHINE GENERATED BY ./scripts/BlenderImporter/genblenddna.py
 */
#ifndef INCLUDED_AI_BLEND_SCENEGEN_H
#define INCLUDED_AI_BLEND_SCENEGEN_H

#include "BlenderDNA.h"
#include "BlenderScene.h"

namespace Assimp	{
	namespace Blender {


template <> void Structure :: Convert<Object> (
    Object& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Group> (
    Group& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MTex> (
    MTex& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<TFace> (
    TFace& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<SubsurfModifierData> (
    SubsurfModifierData& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MFace> (
    MFace& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Lamp> (
    Lamp& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MDeformWeight> (
    MDeformWeight& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<PackedFile> (
    PackedFile& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Base> (
    Base& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MTFace> (
    MTFace& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Material> (
    Material& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MTexPoly> (
    MTexPoly& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Mesh> (
    Mesh& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MDeformVert> (
    MDeformVert& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<World> (
    World& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MLoopCol> (
    MLoopCol& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MVert> (
    MVert& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MEdge> (
    MEdge& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MLoopUV> (
    MLoopUV& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<GroupObject> (
    GroupObject& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<ListBase> (
    ListBase& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MLoop> (
    MLoop& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<ModifierData> (
    ModifierData& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<ID> (
    ID& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MCol> (
    MCol& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MPoly> (
    MPoly& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Scene> (
    Scene& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Library> (
    Library& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Tex> (
    Tex& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Camera> (
    Camera& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<MirrorModifierData> (
    MirrorModifierData& dest,
    const FileDatabase& db
    ) const
;

template <> void Structure :: Convert<Image> (
    Image& dest,
    const FileDatabase& db
    ) const
;


	}
}

#endif
