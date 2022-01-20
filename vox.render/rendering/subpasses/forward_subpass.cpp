//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "forward_subpass.h"
#include "rendering/render_pass.h"
#include "material/material.h"
#include "graphics/mesh.h"
#include "renderer.h"
#include "camera.h"
#include "core/cpp_mtl_assert.h"

// Include header shared between C code here, which executes Metal API commands, and .metal files
#include "shader_types.h"

namespace vox {
bool ForwardSubpass::_compareFromNearToFar(const RenderElement &a, const RenderElement &b) {
    return (a.material->renderQueueType < b.material->renderQueueType) ||
    (a.renderer->distanceForSort() < b.renderer->distanceForSort());
}

bool ForwardSubpass::_compareFromFarToNear(const RenderElement &a, const RenderElement &b) {
    return (a.material->renderQueueType < b.material->renderQueueType) ||
    (b.renderer->distanceForSort() < a.renderer->distanceForSort());
}

ForwardSubpass::ForwardSubpass(View* view,
                               Scene* scene,
                               Camera* camera):
Subpass(view, scene, camera) {
}

void ForwardSubpass::prepare() {
    _forwardPipelineDescriptor.label("Forward Pipeline");
    _forwardPipelineDescriptor.colorAttachments[RenderTargetLighting].pixelFormat(_view->colorPixelFormat());
    _forwardPipelineDescriptor.depthAttachmentPixelFormat(_view->depthStencilPixelFormat());
    _forwardPipelineDescriptor.stencilAttachmentPixelFormat(_view->depthStencilPixelFormat());
    
#pragma mark forward depth state setup
    {
#if LIGHT_STENCIL_CULLING
        MTL::StencilDescriptor stencilStateDesc;
        stencilStateDesc.stencilCompareFunction(MTL::CompareFunctionAlways);
        stencilStateDesc.stencilFailureOperation(MTL::StencilOperationKeep);
        stencilStateDesc.depthFailureOperation(MTL::StencilOperationKeep);
        stencilStateDesc.depthStencilPassOperation(MTL::StencilOperationReplace);
        stencilStateDesc.readMask(0x0);
        stencilStateDesc.writeMask(0xFF);
#else
        MTL::StencilDescriptor stencilStateDesc;
#endif
        MTL::DepthStencilDescriptor depthStencilDesc;
        depthStencilDesc.label("G-buffer Creation");
        depthStencilDesc.depthCompareFunction(MTL::CompareFunctionLess);
        depthStencilDesc.depthWriteEnabled(true);
        depthStencilDesc.frontFaceStencil = stencilStateDesc;
        depthStencilDesc.backFaceStencil = stencilStateDesc;
        
        _forwardDepthStencilState = _view->device().makeDepthStencilState(depthStencilDesc);
    }
}

void ForwardSubpass::draw(MTL::RenderCommandEncoder& commandEncoder) {
    commandEncoder.pushDebugGroup("Draw G-Buffer");
    commandEncoder.setCullMode(MTL::CullModeFront);
    commandEncoder.setDepthStencilState(_forwardDepthStencilState);
    commandEncoder.setStencilReferenceValue(128);
    
    _drawMeshes(commandEncoder);
    commandEncoder.popDebugGroup();
}

void ForwardSubpass::_drawMeshes(MTL::RenderCommandEncoder &renderEncoder) {
    auto compileMacros = ShaderMacroCollection();
    _scene->shaderData.mergeMacro(compileMacros, compileMacros);
    _camera->shaderData.mergeMacro(compileMacros, compileMacros);
    
    std::vector<RenderElement> opaqueQueue;
    std::vector<RenderElement> alphaTestQueue;
    std::vector<RenderElement> transparentQueue;
    _scene->_componentsManager.callRender(_camera, opaqueQueue, alphaTestQueue, transparentQueue);
    std::sort(opaqueQueue.begin(), opaqueQueue.end(), ForwardSubpass::_compareFromNearToFar);
    std::sort(alphaTestQueue.begin(), alphaTestQueue.end(), ForwardSubpass::_compareFromNearToFar);
    std::sort(transparentQueue.begin(), transparentQueue.end(), ForwardSubpass::_compareFromFarToNear);
    
    _drawElement(renderEncoder, opaqueQueue, compileMacros);
    _drawElement(renderEncoder, alphaTestQueue, compileMacros);
    _drawElement(renderEncoder, transparentQueue, compileMacros);
}

void ForwardSubpass::_drawElement(MTL::RenderCommandEncoder &renderEncoder,
                                  const std::vector<RenderElement> &items,
                                  const ShaderMacroCollection& compileMacros) {
    for (auto &element : items) {
        auto macros = compileMacros;
        auto renderer = element.renderer;
        renderer->shaderData.mergeMacro(macros, macros);
        
        auto material = element.material;
        material->shaderData.mergeMacro(macros, macros);
        ShaderProgram *program = _pass->resourceCache().requestShader(_pass->library(), material->shader->vertexSource(),
                                                                      material->shader->fragmentSource(), macros);
        if (!program->isValid()) {
            continue;
        }
        _forwardPipelineDescriptor.vertexFunction(program->vertexShader());
        _forwardPipelineDescriptor.fragmentFunction(program->fragmentShader());
        
        // manully
        auto& mesh = element.mesh;
        _forwardPipelineDescriptor.vertexDescriptor(&mesh->vertexDescriptor());
        
        auto m_forwardPipelineState = _pass->resourceCache().requestRenderPipelineState(_forwardPipelineDescriptor);
        uploadUniforms(renderEncoder, m_forwardPipelineState->materialUniformBlock, material->shaderData);
        uploadUniforms(renderEncoder, m_forwardPipelineState->rendererUniformBlock, renderer->shaderData);
        uploadUniforms(renderEncoder, m_forwardPipelineState->sceneUniformBlock, _scene->shaderData);
        uploadUniforms(renderEncoder, m_forwardPipelineState->cameraUniformBlock, _camera->shaderData);
        renderEncoder.setRenderPipelineState(*m_forwardPipelineState);
        
        for (auto &meshBuffer: mesh->vertexBuffers()) {
            renderEncoder.setVertexBuffer(meshBuffer.buffer(),
                                          meshBuffer.offset(),
                                          meshBuffer.argumentIndex());
        }
        auto& submesh = element.subMesh;
        renderEncoder.drawIndexedPrimitives(submesh->primitiveType(),
                                            submesh->indexCount(),
                                            submesh->indexType(),
                                            submesh->indexBuffer().buffer(),
                                            submesh->indexBuffer().offset());
    }
}

}
