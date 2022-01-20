//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef cpp_mtl_CommandBuffer_hpp
#define cpp_mtl_CommandBuffer_hpp

#include "cpp_mtl_implementation.h"
#include "cpp_mtl_command_queue.h"
#include "cpp_mtl_types.h"
#include "cpp_mtl_device.h"


namespace MTL {
class Device;

class RenderPassDescriptor;

class RenderCommandEncoder;

class Drawable;

struct CommandBufferHandler {
    virtual void operator()(const MTL::CommandBuffer &) = 0;
    
    virtual ~CommandBufferHandler();
};

class CommandBuffer {
public:
    
    CommandBuffer() = delete;
    
    CommandBuffer(const CommandBuffer &rhs);
    
    CommandBuffer(CommandBuffer &&rhs);
    
    CommandBuffer &operator=(const CommandBuffer &rhs);
    
    CommandBuffer &operator=(CommandBuffer &&rhs);
    
    CPP_METAL_VIRTUAL ~CommandBuffer();
    
    bool operator==(const CommandBuffer &rhs);
    
    const char *label() const;
    
    void label(const char *string);
    
    void label(const CFStringRef string);
    
    const Device* device() const;
    
    RenderCommandEncoder renderCommandEncoderWithDescriptor(const RenderPassDescriptor &descriptor) const;
    
    void commit();
    
    void presentDrawable(Drawable &drawable);
    
    void waitUntilCompleted();
    
    void addCompletedHandler(CommandBufferHandler &completedHandler);
    
    void addScheduledHandler(CommandBufferHandler &scheduledHandler);
    
    void synchronizeResource(MTL::Texture& resource);
    
private:
    
    cpp_mtl_internal::CommandBuffer m_objCObj;
    
    Device *m_device;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    CommandBuffer(cpp_mtl_internal::CommandBuffer objCObj, Device &device);
    
};


#pragma mark - CommandBuffer inline method implementations

CPP_METAL_MOVE_CONSTRUCTOR_AND_OPERATOR_OVERLOAD_IMPLEMENTATION(CommandBuffer);

inline void CommandBuffer::label(const char *string) {
    CPP_METAL_PROCESS_LABEL(string, label);
}


} // namespace MTL

#endif // cpp_mtl_CommandBuffer_hpp
