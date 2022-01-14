//
//  deferred.cpp
//  apps
//
//  Created by 杨丰 on 2022/1/14.
//

#include "deferred.h"
// Include header shared between C code here, which executes Metal API commands, and .metal files
#include "shader_types.h"
#include "rendering/lighting_subpass.h"
#include "engine.h"

namespace vox {
Deferred::~Deferred() {
    delete m_completedHandler;
    render_pipeline.reset();
}

bool Deferred::prepare(Engine &engine) {
    MetalApplication::prepare(engine);
    
    m_inFlightSemaphore = dispatch_semaphore_create(MaxFramesInFlight);

    // Create a render pass descriptor to create an encoder for rendering to the GBuffers.
    // The encoder stores rendered data of each attachment when encoding ends.
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetLighting].loadAction(MTL::LoadActionDontCare);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetLighting].storeAction(MTL::StoreActionDontCare);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetAlbedo].loadAction(MTL::LoadActionDontCare);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetAlbedo].storeAction(MTL::StoreActionStore);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetNormal].loadAction(MTL::LoadActionDontCare);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetNormal].storeAction(MTL::StoreActionStore);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetDepth].loadAction(MTL::LoadActionDontCare);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetDepth].storeAction(MTL::StoreActionStore);
    m_GBufferRenderPassDescriptor.depthAttachment.clearDepth(1.0);
    m_GBufferRenderPassDescriptor.depthAttachment.loadAction(MTL::LoadActionClear);
    m_GBufferRenderPassDescriptor.depthAttachment.storeAction(MTL::StoreActionStore);
    
    m_GBufferRenderPassDescriptor.stencilAttachment.clearStencil(0);
    m_GBufferRenderPassDescriptor.stencilAttachment.loadAction(MTL::LoadActionClear);
    m_GBufferRenderPassDescriptor.stencilAttachment.storeAction(MTL::StoreActionStore);
    
    // Create a render pass descriptor for thelighting and composition pass
    
    // Whatever rendered in the final pass needs to be stored so it can be displayed
    m_finalRenderPassDescriptor.colorAttachments[0].storeAction(MTL::StoreActionStore);
    m_finalRenderPassDescriptor.depthAttachment.loadAction(MTL::LoadActionLoad);
    m_finalRenderPassDescriptor.stencilAttachment.loadAction(MTL::LoadActionLoad);
    
    render_pipeline = std::make_unique<LightingSubpass>(render_context.get());
    
    auto extent = engine.get_window().get_extent();
    framebuffer_resize(extent.width*2, extent.height*2);
        
    return true;
}

void Deferred::update(float delta_time) {
    MetalApplication::update(delta_time);
    
    auto subpass = static_cast<LightingSubpass*>(render_pipeline.get());
    {
        // Wait to ensure only MaxFramesInFlight are getting processed by any stage in the Metal
        // pipeline (App, Metal, Drivers, GPU, etc)
        dispatch_semaphore_wait(m_inFlightSemaphore, DISPATCH_TIME_FOREVER);
        // Create a new command buffer for each render pass to the current drawable
        MTL::CommandBuffer commandBuffer = m_commandQueue.commandBuffer();
        commandBuffer.label("Shadow & GBuffer Commands");
        
        subpass->updateWorldState();
        subpass->drawShadow(commandBuffer);
        
        m_GBufferRenderPassDescriptor.depthAttachment.texture(*render_context->depthStencilTexture());
        m_GBufferRenderPassDescriptor.stencilAttachment.texture(*render_context->depthStencilTexture());
        
        MTL::RenderCommandEncoder renderEncoder =
        commandBuffer.renderCommandEncoderWithDescriptor(m_GBufferRenderPassDescriptor);
        renderEncoder.label("GBuffer Generation");
        
        subpass->drawGBuffer(renderEncoder);
        
        renderEncoder.endEncoding();
        
        // Commit commands so that Metal can begin working on non-drawable dependant work without
        // waiting for a drawable to become avaliable
        commandBuffer.commit();
    }
    
    {
        MTL::CommandBuffer commandBuffer = m_commandQueue.commandBuffer();
        if (!m_completedHandler) {
            // Create a completed handler functor for Metal to execute when the GPU has fully finished
            // processing the commands encoded for this frame.  This implenentation of the completed
            // hander signals the `m_inFlightSemaphore`, which indicates that the GPU is no longer
            // accesing the the dynamic buffer written this frame.  When the GPU no longer accesses the
            // buffer, the Subpass can safely overwrite the buffer's data to update data for a future
            // frame.
            struct CommandBufferCompletedHandler : public MTL::CommandBufferHandler {
                dispatch_semaphore_t semaphore;
                
                void operator()(const MTL::CommandBuffer &) {
                    dispatch_semaphore_signal(semaphore);
                }
            };
            
            CommandBufferCompletedHandler *completedHandler = new CommandBufferCompletedHandler();
            completedHandler->semaphore = m_inFlightSemaphore;
            
            m_completedHandler = completedHandler;
        }
        commandBuffer.addCompletedHandler(*m_completedHandler);
        commandBuffer.label("Lighting Commands");
        
        MTL::Texture *drawableTexture = subpass->currentDrawableTexture();
        
        // The final pass can only render if a drawable is available, otherwise it needs to skip
        // rendering this frame.
        if (drawableTexture) {
            // Render the lighting and composition pass
            
            m_finalRenderPassDescriptor.colorAttachments[0].texture(*drawableTexture);
            m_finalRenderPassDescriptor.depthAttachment.texture(*render_context->depthStencilTexture());
            m_finalRenderPassDescriptor.stencilAttachment.texture(*render_context->depthStencilTexture());
            
            MTL::RenderCommandEncoder renderEncoder =
            commandBuffer.renderCommandEncoderWithDescriptor(m_finalRenderPassDescriptor);
            renderEncoder.label("Lighting & Composition Pass");
            
            subpass->drawDirectionalLight(renderEncoder);
            
            subpass->drawPointLightMask(renderEncoder);
            
            subpass->drawPointLights(renderEncoder);
            
            subpass->drawSky(renderEncoder);
            
            subpass->drawFairies(renderEncoder);
            
            renderEncoder.endEncoding();
        }
        
        subpass->endFrame(commandBuffer);
    }
}

void Deferred::framebuffer_resize(uint32_t width, uint32_t height) {
    MetalApplication::framebuffer_resize(width, height);
    
    auto subpass = static_cast<LightingSubpass*>(render_pipeline.get());
    // The subpass base class allocates all GBuffers >except< lighting GBuffer (since with the
    // single-pass deferred subpass the lighting buffer is the same as the drawable)
    subpass->drawableSizeWillChange(MTL::SizeMake(width, height, 0), MTL::StorageModePrivate);
    
    // Re-set GBuffer textures in the GBuffer render pass descriptor after they have been
    // reallocated by a resize
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetAlbedo].texture(subpass->m_albedo_specular_GBuffer);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetNormal].texture(subpass->m_normal_shadow_GBuffer);
    m_GBufferRenderPassDescriptor.colorAttachments[RenderTargetDepth].texture(subpass->m_depth_GBuffer);
}

}
