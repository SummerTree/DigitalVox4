//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef gui_hpp
#define gui_hpp

#include "gui/imgui.h"
#include <Metal/Metal.hpp>

namespace vox {
class GUI {
public:
    GUI(MTL::Device* device);
    
    ~GUI();
    
    void newFrame(MTL::RenderPassDescriptor* renderPassDescriptor);
    
    void draw(ImDrawData* drawData,
              MTL::CommandBuffer* commandBuffer,
              MTL::RenderCommandEncoder* commandEncoder);
};

}

#endif /* gui_hpp */
