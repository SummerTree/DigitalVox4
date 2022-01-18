//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "blend_state.h"

namespace vox {
void BlendState::platformApply(MTL::RenderPipelineDescriptor &pipelineDescriptor,
                               MTL::DepthStencilDescriptor &depthStencilDescriptor,
                               MTL::RenderCommandEncoder &encoder) {
    const auto enabled = targetBlendState.enabled;
    const auto colorBlendOperation = targetBlendState.colorBlendOperation;
    const auto alphaBlendOperation = targetBlendState.alphaBlendOperation;
    const auto sourceColorBlendFactor = targetBlendState.sourceColorBlendFactor;
    const auto destinationColorBlendFactor = targetBlendState.destinationColorBlendFactor;
    const auto sourceAlphaBlendFactor = targetBlendState.sourceAlphaBlendFactor;
    const auto destinationAlphaBlendFactor = targetBlendState.destinationAlphaBlendFactor;
    const auto colorWriteMask = targetBlendState.colorWriteMask;
    
    if (enabled) {
        pipelineDescriptor.colorAttachments[0].blendingEnabled(true);
    } else {
        pipelineDescriptor.colorAttachments[0].blendingEnabled(false);
    }
    
    if (enabled) {
        // apply blend factor.
        pipelineDescriptor.colorAttachments[0].sourceRGBBlendFactor(sourceColorBlendFactor);
        pipelineDescriptor.colorAttachments[0].destinationRGBBlendFactor(destinationColorBlendFactor);
        pipelineDescriptor.colorAttachments[0].sourceAlphaBlendFactor(sourceAlphaBlendFactor);
        pipelineDescriptor.colorAttachments[0].destinationAlphaBlendFactor(destinationAlphaBlendFactor);
        
        // apply blend operation.
        pipelineDescriptor.colorAttachments[0].rgbBlendOperation(colorBlendOperation);
        pipelineDescriptor.colorAttachments[0].alphaBlendOperation(alphaBlendOperation);
        
        // apply blend color.
        encoder.setBlendColor(blendColor.r, blendColor.g, blendColor.b, blendColor.a);
    }
    
    // apply color mask.
    pipelineDescriptor.colorAttachments[0].writeMask(colorWriteMask);
    
    // apply alpha to coverage.
    if (alphaToCoverage) {
        pipelineDescriptor.alphaToCoverageEnabled(true);
    } else {
        pipelineDescriptor.alphaToCoverageEnabled(false);
    }
}
}
