//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "skybox_material.h"

namespace vox {
bool SkyBoxMaterial::textureDecodeRGBM() {
    return _decodeParam.x;
}

void SkyBoxMaterial::setTextureDecodeRGBM(bool value) {
    _decodeParam.x = float(value);
}

float SkyBoxMaterial::RGBMDecodeFactor() {
    return _decodeParam.y;
}

void SkyBoxMaterial::setRGBMDecodeFactor(float value) {
    _decodeParam.y = value;
}

std::shared_ptr<MTL::Texture> SkyBoxMaterial::textureCubeMap() {
    return std::any_cast<std::shared_ptr<MTL::Texture>>(shaderData.getData(SkyBoxMaterial::_skyboxTextureProp));
}

void SkyBoxMaterial::setTextureCubeMap(std::shared_ptr<MTL::Texture> v) {
    shaderData.setData(SkyBoxMaterial::_skyboxTextureProp, v);
}

SkyBoxMaterial::SkyBoxMaterial() :
Material(Shader::find("skybox")),
_skyboxTextureProp(Shader::createProperty("u_skybox", ShaderDataGroup::Material)),
_mvpNoscaleProp(Shader::createProperty("u_mvpNoscale", ShaderDataGroup::Material)) {
    renderState.rasterState.cullMode = MTL::CullModeBack;
    renderState.depthState.compareFunction = MTL::CompareFunctionLessEqual;
}

}
