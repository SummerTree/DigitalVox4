//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.


#include "cpp_mtl_buffer.h"
#include "cpp_mtl_internal_macros.h"

using namespace MTL;

Buffer::Buffer(cpp_mtl_internal::Buffer objCObj, Device &device) :
Resource(objCObj, device),
m_contentsPtr(nullptr) {
    MTLStorageMode mode = m_objCObj.storageMode;
    if (MTLStorageModeShared == mode
#if TARGET_OS_OSX
        || MTLStorageModeManaged == mode
#endif
        ) {
        m_contentsPtr = ((id <MTLBuffer>) m_objCObj).contents;
    }
}

Buffer::Buffer(const Buffer &rhs)
: Resource(rhs), m_contentsPtr(rhs.m_contentsPtr) {
    // Member initialization only
}

Buffer &Buffer::operator=(const Buffer &rhs) {
    Resource::operator=(rhs);
    m_contentsPtr = rhs.m_contentsPtr;
    
    return *this;
}

Buffer::~Buffer() {
    m_contentsPtr = nullptr;
}

UInteger Buffer::length() const {
    CPP_METAL_VALIDATE_WRAPPED_NIL();
    
    return ((id <MTLBuffer>) m_objCObj).length;
}

#if TARGET_OS_OSX

void Buffer::didModifyRange(CFRange range) {
    CPP_METAL_VALIDATE_WRAPPED_NIL();
    
    NSRange nsRange = NSMakeRange(range.location, range.length);
    
    [((id <MTLBuffer>) m_objCObj) didModifyRange:nsRange];
}

#endif

