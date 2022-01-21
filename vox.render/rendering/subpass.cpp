//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "subpass.h"
#include "material/material.h"
#include "renderer.h"
#include <glog/logging.h>

namespace vox {
bool Subpass::_compareFromNearToFar(const RenderElement &a, const RenderElement &b) {
    return (a.material->renderQueueType < b.material->renderQueueType) ||
    (a.renderer->distanceForSort() < b.renderer->distanceForSort());
}

bool Subpass::_compareFromFarToNear(const RenderElement &a, const RenderElement &b) {
    return (a.material->renderQueueType < b.material->renderQueueType) ||
    (b.renderer->distanceForSort() < a.renderer->distanceForSort());
}

Subpass::Subpass(View* view,
                 Scene* scene,
                 Camera* camera):
_view(view),
_scene(scene),
_camera(camera) {
}

void Subpass::setRenderPass(RenderPass* pass) {
    _pass = pass;
    prepare();
}

void Subpass::uploadUniforms(MTL::RenderCommandEncoder& commandEncoder,
                             const std::vector<ShaderUniform> &uniformBlock,
                             const ShaderData &shaderData) {
    const auto &properties = shaderData.properties();
    
    for (size_t i = 0; i < uniformBlock.size(); i++) {
        const auto &uniform = uniformBlock[i];
        auto iter = properties.find(uniform.propertyId);
        if (iter != properties.end()) {
            process(uniform, iter->second, commandEncoder);
        }
    }
}

void Subpass::process(const ShaderUniform &uniform, const std::any &a,
                      MTL::RenderCommandEncoder& encoder) {
    const auto &any_uploader = uniform.type == MTL::FunctionTypeVertex ?
    _scene->vertexUploader() : _scene->fragmentUploader();
    
    if (const auto it = any_uploader.find(std::type_index(a.type())); it != any_uploader.cend()) {
        it->second(a, uniform.location, encoder);
    } else {
        LOG(INFO) << "Unregistered type " << std::quoted(a.type().name());
    }
}

}
