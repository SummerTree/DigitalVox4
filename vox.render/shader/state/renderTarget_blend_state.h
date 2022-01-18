//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef renderTarget_blend_state_hpp
#define renderTarget_blend_state_hpp

#include "core/cpp_mtl_render_pipeline.h"

namespace vox {
/**
 * The blend state of the render target.
 */
struct RenderTargetBlendState {
    /** Whether to enable blend. */
    bool enabled = false;
    /** color (RGB) blend operation. */
    MTL::BlendOperation colorBlendOperation = MTL::BlendOperationAdd;
    /** alpha (A) blend operation. */
    MTL::BlendOperation alphaBlendOperation = MTL::BlendOperationAdd;
    /** color blend factor (RGB) for source. */
    MTL::BlendFactor sourceColorBlendFactor = MTL::BlendFactorOne;
    /** alpha blend factor (A) for source. */
    MTL::BlendFactor sourceAlphaBlendFactor = MTL::BlendFactorOne;
    /** color blend factor (RGB) for destination. */
    MTL::BlendFactor destinationColorBlendFactor = MTL::BlendFactorZero;
    /** alpha blend factor (A) for destination. */
    MTL::BlendFactor destinationAlphaBlendFactor = MTL::BlendFactorZero;
    /** color mask. */
    MTL::ColorWriteMask colorWriteMask = MTL::ColorWriteMaskAll;
};

}

#endif /* renderTarget_blend_state_hpp */
