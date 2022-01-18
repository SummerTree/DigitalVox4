//
//  stencil_state.hpp
//  vox.render
//
//  Created by 杨丰 on 2021/11/27.
//

#ifndef stencil_state_hpp
#define stencil_state_hpp

#include "core/cpp_mtl_depth_stencil.h"
#include "core/cpp_mtl_render_command_encoder.h"

namespace vox {
/**
 * Stencil state.
 */
struct StencilState {
    /** Whether to enable stencil test. */
    bool enabled = false;
    /** Write the reference value of the stencil buffer. */
    uint32_t referenceValue = 0;
    /** Specifying a bit-wise mask that is used to AND the reference value and the stored stencil value when the test is done. */
    uint32_t mask = 0xff;
    /** Specifying a bit mask to enable or disable writing of individual bits in the stencil planes. */
    uint32_t writeMask = 0xff;
    /** The comparison function of the reference value of the front face of the geometry and the current buffer storage value. */
    MTL::CompareFunction compareFunctionFront = MTL::CompareFunctionAlways;
    /** The comparison function of the reference value of the back of the geometry and the current buffer storage value. */
    MTL::CompareFunction compareFunctionBack = MTL::CompareFunctionAlways;
    /** specifying the function to use for front face when both the stencil test and the depth test pass. */
    MTL::StencilOperation passOperationFront = MTL::StencilOperationKeep;
    /** specifying the function to use for back face when both the stencil test and the depth test pass. */
    MTL::StencilOperation passOperationBack = MTL::StencilOperationKeep;
    /** specifying the function to use for front face when the stencil test fails. */
    MTL::StencilOperation failOperationFront = MTL::StencilOperationKeep;
    /** specifying the function to use for back face when the stencil test fails. */
    MTL::StencilOperation failOperationBack = MTL::StencilOperationKeep;
    /** specifying the function to use for front face when the stencil test passes, but the depth test fails. */
    MTL::StencilOperation zFailOperationFront = MTL::StencilOperationKeep;
    /** specifying the function to use for back face when the stencil test passes, but the depth test fails. */
    MTL::StencilOperation zFailOperationBack = MTL::StencilOperationKeep;
    
    void apply(MTL::RenderPipelineDescriptor &pipelineDescriptor,
               MTL::DepthStencilDescriptor &depthStencilDescriptor,
               MTL::RenderCommandEncoder &encoder) {
        platformApply(pipelineDescriptor, depthStencilDescriptor, encoder);
    }
    
    void platformApply(MTL::RenderPipelineDescriptor &pipelineDescriptor,
                       MTL::DepthStencilDescriptor &depthStencilDescriptor,
                       MTL::RenderCommandEncoder &encoder);
};

}
#endif /* stencil_state_hpp */
