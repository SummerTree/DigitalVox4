//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pbr_material.h"

namespace vox {
float PBRMaterial::metallic() {
    return std::any_cast<float>(shaderData.getData(PBRMaterial::_metallicProp));
}

void PBRMaterial::setMetallic(float newValue) {
    shaderData.setData(PBRMaterial::_metallicProp, newValue);
}

float PBRMaterial::roughness() {
    return std::any_cast<float>(shaderData.getData(PBRMaterial::_roughnessProp));
}

void PBRMaterial::setRoughness(float newValue) {
    shaderData.setData(PBRMaterial::_roughnessProp, newValue);
}

std::shared_ptr<MTL::Texture> PBRMaterial::metallicRoughnessTexture() {
    return std::any_cast<std::shared_ptr<MTL::Texture>>(shaderData.getData(PBRMaterial::_metallicRoughnessTextureProp));
}

void PBRMaterial::setMetallicRoughnessTexture(std::shared_ptr<MTL::Texture> newValue) {
    shaderData.setData(PBRMaterial::_metallicRoughnessTextureProp, newValue);
    if (newValue) {
        shaderData.enableMacro(HAS_METALROUGHNESSMAP);
    } else {
        shaderData.disableMacro(HAS_METALROUGHNESSMAP);
    }
}

PBRMaterial::PBRMaterial() :
PBRBaseMaterial(),
_metallicProp(Shader::createProperty("u_metal", ShaderDataGroup::Material)),
_roughnessProp(Shader::createProperty("u_roughness", ShaderDataGroup::Material)),
_metallicRoughnessTextureProp(Shader::createProperty("u_metallicRoughnessTexture", ShaderDataGroup::Material)) {
    shaderData.enableMacro(IS_METALLIC_WORKFLOW);
    shaderData.setData(PBRMaterial::_metallicProp, 1.f);
    shaderData.setData(PBRMaterial::_roughnessProp, 1.f);
}

}
