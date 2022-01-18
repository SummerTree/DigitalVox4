//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef cpp_mtl_VertexDescriptor_hpp
#define cpp_mtl_VertexDescriptor_hpp

#include "cpp_mtl_types.h"
#include "cpp_mtl_implementation.h"
#include "cpp_mtl_constants.h"


namespace MTL {


typedef enum VertexFormat {
    VertexFormatInvalid = 0,
    
    VertexFormatUChar2 = 1,
    VertexFormatUChar3 = 2,
    VertexFormatUChar4 = 3,
    
    VertexFormatChar2 = 4,
    VertexFormatChar3 = 5,
    VertexFormatChar4 = 6,
    
    VertexFormatUChar2Normalized = 7,
    VertexFormatUChar3Normalized = 8,
    VertexFormatUChar4Normalized = 9,
    
    VertexFormatChar2Normalized = 10,
    VertexFormatChar3Normalized = 11,
    VertexFormatChar4Normalized = 12,
    
    VertexFormatUShort2 = 13,
    VertexFormatUShort3 = 14,
    VertexFormatUShort4 = 15,
    
    VertexFormatShort2 = 16,
    VertexFormatShort3 = 17,
    VertexFormatShort4 = 18,
    
    VertexFormatUShort2Normalized = 19,
    VertexFormatUShort3Normalized = 20,
    VertexFormatUShort4Normalized = 21,
    
    VertexFormatShort2Normalized = 22,
    VertexFormatShort3Normalized = 23,
    VertexFormatShort4Normalized = 24,
    
    VertexFormatHalf2 = 25,
    VertexFormatHalf3 = 26,
    VertexFormatHalf4 = 27,
    
    VertexFormatFloat = 28,
    VertexFormatFloat2 = 29,
    VertexFormatFloat3 = 30,
    VertexFormatFloat4 = 31,
    
    VertexFormatInt = 32,
    VertexFormatInt2 = 33,
    VertexFormatInt3 = 34,
    VertexFormatInt4 = 35,
    
    VertexFormatUInt = 36,
    VertexFormatUInt2 = 37,
    VertexFormatUInt3 = 38,
    VertexFormatUInt4 = 39,
    
    VertexFormatInt1010102Normalized = 40,
    VertexFormatUInt1010102Normalized = 41,
    
    VertexFormatUChar4Normalized_BGRA API_AVAILABLE(macos(10.13), ios(11.0)) = 42,
    
    VertexFormatUChar API_AVAILABLE(macos(10.13), ios(11.0)) = 45,
    VertexFormatChar API_AVAILABLE(macos(10.13), ios(11.0)) = 46,
    VertexFormatUCharNormalized API_AVAILABLE(macos(10.13), ios(11.0)) = 47,
    VertexFormatCharNormalized API_AVAILABLE(macos(10.13), ios(11.0)) = 48,
    
    VertexFormatUShort API_AVAILABLE(macos(10.13), ios(11.0)) = 49,
    VertexFormatShort API_AVAILABLE(macos(10.13), ios(11.0)) = 50,
    VertexFormatUShortNormalized API_AVAILABLE(macos(10.13), ios(11.0)) = 51,
    VertexFormatShortNormalized API_AVAILABLE(macos(10.13), ios(11.0)) = 52,
    
    VertexFormatHalf API_AVAILABLE(macos(10.13), ios(11.0)) = 53,
    
} VertexFormat API_AVAILABLE(macos(10.11), ios(8.0));

typedef enum VertexStepFunction {
    VertexStepFunctionConstant = 0,
    VertexStepFunctionPerVertex = 1,
    VertexStepFunctionPerInstance = 2,
    VertexStepFunctionPerPatch API_AVAILABLE(macos(10.12), ios(10.0)) = 3,
    VertexStepFunctionPerPatchControlPoint API_AVAILABLE(macos(10.12), ios(10.0)) = 4,
} VertexStepFunction;

#pragma mark -

class VertexBufferLayoutDescriptorArray;

class VertexBufferLayoutDescriptor {
public:
    
    VertexBufferLayoutDescriptor();
    
    VertexBufferLayoutDescriptor(const VertexBufferLayoutDescriptor &rhs);
    
    CPP_METAL_VIRTUAL ~VertexBufferLayoutDescriptor();
    
    VertexBufferLayoutDescriptor &operator=(const VertexBufferLayoutDescriptor &rhs);
    
    UInteger stride() const;
    
    void stride(UInteger value);
    
    VertexStepFunction stepFunction() const;
    
    void stepFunction(VertexStepFunction function);
    
    UInteger stepRate() const;
    
    void stepRate(UInteger rate);
    
private:
    
    cpp_mtl_internal::VertexBufferLayoutDescriptor m_objCObj;
    
    cpp_mtl_internal::VertexBufferLayoutDescriptorArray m_objCContainer;
    
    UInteger m_arrayIndex;
    
    VertexBufferLayoutDescriptor(cpp_mtl_internal::VertexBufferLayoutDescriptorArray objCContainer, UInteger arrayIndex);
    
    void reinitialize(cpp_mtl_internal::VertexBufferLayoutDescriptorArray objCContainer);
    
    friend VertexBufferLayoutDescriptorArray;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    cpp_mtl_internal::VertexBufferLayoutDescriptor objCObj() const;
    
};

#pragma mark -

class VertexAttributeDescriptorArray;

class VertexAttributeDescriptor {
public:
    
    VertexAttributeDescriptor();
    
    VertexAttributeDescriptor(const VertexAttributeDescriptor &rhs);
    
    CPP_METAL_VIRTUAL ~VertexAttributeDescriptor();
    
    VertexAttributeDescriptor &operator=(const VertexAttributeDescriptor &rhs);
    
    VertexFormat format() const;
    
    void format(VertexFormat format);
    
    UInteger offset() const;
    
    void offset(UInteger value);
    
    UInteger bufferIndex() const;
    
    void bufferIndex(UInteger value);
    
private:
    
    cpp_mtl_internal::VertexAttributeDescriptor m_objCObj;
    
    cpp_mtl_internal::VertexAttributeDescriptorArray m_objCContainer;
    
    UInteger m_arrayIndex;
    
    VertexAttributeDescriptor(cpp_mtl_internal::VertexAttributeDescriptorArray objCContainer, UInteger arrayIndex);
    
    void reinitialize(cpp_mtl_internal::VertexAttributeDescriptorArray objCContainer);
    
    friend VertexAttributeDescriptorArray;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    cpp_mtl_internal::VertexAttributeDescriptor objCObj() const;
    
};

class VertexDescriptor;

#pragma mark -

class VertexBufferLayoutDescriptorArray {
public:
    
    VertexBufferLayoutDescriptorArray() = delete;
    
    VertexBufferLayoutDescriptorArray(const VertexBufferLayoutDescriptorArray &rhs) = delete;
    
    VertexBufferLayoutDescriptorArray &operator=(const VertexBufferLayoutDescriptorArray &rhs) = delete;
    
    CPP_METAL_VIRTUAL ~VertexBufferLayoutDescriptorArray();
    
    VertexBufferLayoutDescriptor operator[](UInteger i) const;
    
    VertexBufferLayoutDescriptor &operator[](UInteger i);
    
private:
    
    cpp_mtl_internal::VertexBufferLayoutDescriptorArray m_objCObj;
    
    VertexBufferLayoutDescriptor m_layouts[MaxVertexBufferLayouts];
    
    explicit VertexBufferLayoutDescriptorArray(cpp_mtl_internal::VertexBufferLayoutDescriptorArray objCObj);
    
    void reinitialize(cpp_mtl_internal::VertexBufferLayoutDescriptorArray objCObj);
    
    friend VertexDescriptor;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    cpp_mtl_internal::VertexBufferLayoutDescriptorArray objCObj() const;
    
};

#pragma mark -

class VertexAttributeDescriptorArray {
public:
    
    VertexAttributeDescriptorArray() = delete;
    
    VertexAttributeDescriptorArray(const VertexAttributeDescriptorArray &rhs) = delete;
    
    VertexAttributeDescriptorArray &operator=(const VertexAttributeDescriptorArray &rhs) = delete;
    
    CPP_METAL_VIRTUAL ~VertexAttributeDescriptorArray();
    
    VertexAttributeDescriptor operator[](UInteger i) const;
    
    VertexAttributeDescriptor &operator[](UInteger i);
    
private:
    
    cpp_mtl_internal::VertexAttributeDescriptorArray m_objCObj;
    
    VertexAttributeDescriptor m_attributes[MaxVertexAttributes];
    
    explicit VertexAttributeDescriptorArray(cpp_mtl_internal::VertexAttributeDescriptorArray objCObj);
    
    void reinitialize(cpp_mtl_internal::VertexAttributeDescriptorArray objCObj);
    
    friend VertexDescriptor;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    cpp_mtl_internal::VertexAttributeDescriptorArray objCObj() const;
    
};

#pragma mark -

class VertexDescriptor {
private:
    
    // cpp_mtl_ Internal Implementation Note:
    // The class must declare the 'm_objCObj' member before the 'layouts' and 'attributes' members.
    // The constructors of these members depend on the value of properties in 'm_objCObj'.  C++
    // executes member constructors in order of declaration (not in order of the initializer list in
    // the contstructor).  So the class must declare 'm_objCObj' first for it to initialize it
    // first and allow the 'layouts' and 'attributes' members to depend on its properties.
    cpp_mtl_internal::VertexDescriptor m_objCObj;
    
public:
    
    VertexDescriptor();
    
    VertexDescriptor(const VertexDescriptor &rhs);
    
    VertexDescriptor &operator=(const VertexDescriptor &rhs);
    
    CPP_METAL_VIRTUAL ~VertexDescriptor();
    
    void reset();
    
    VertexBufferLayoutDescriptorArray layouts;
    
    VertexAttributeDescriptorArray attributes;
    
public: // Public methods for cpp_mtl_ internal implementation
    
    cpp_mtl_internal::VertexDescriptor objCObj() const;
    
};


//================================================================
#pragma mark - VertexBufferLayoutDescriptor inline implementations

inline cpp_mtl_internal::VertexBufferLayoutDescriptor VertexBufferLayoutDescriptor::objCObj() const {
    return m_objCObj;
}


//=============================================================
#pragma mark - VertexAttributeDescriptor inline implementations

inline cpp_mtl_internal::VertexAttributeDescriptor VertexAttributeDescriptor::objCObj() const {
    return m_objCObj;
}


//=====================================================================
#pragma mark - VertexBufferLayoutDescriptorArray inline implementations

inline VertexBufferLayoutDescriptor VertexBufferLayoutDescriptorArray::operator[](UInteger i) const {
    return m_layouts[i];
}

inline VertexBufferLayoutDescriptor &VertexBufferLayoutDescriptorArray::operator[](UInteger i) {
    return m_layouts[i];
}

inline cpp_mtl_internal::VertexBufferLayoutDescriptorArray VertexBufferLayoutDescriptorArray::objCObj() const {
    return m_objCObj;
}


//==================================================================
#pragma mark - VertexAttributeDescriptorArray inline implementations

inline VertexAttributeDescriptor VertexAttributeDescriptorArray::operator[](UInteger i) const {
    return m_attributes[i];
}

inline VertexAttributeDescriptor &VertexAttributeDescriptorArray::operator[](UInteger i) {
    VertexAttributeDescriptor &attrib = m_attributes[i];
    return attrib;
}

inline cpp_mtl_internal::VertexAttributeDescriptorArray VertexAttributeDescriptorArray::objCObj() const {
    return m_objCObj;
}


//===================================================
#pragma mark - VertexDecriptor inline implementations

inline cpp_mtl_internal::VertexDescriptor VertexDescriptor::objCObj() const {
    return m_objCObj;
}


} // namespace MTL

#endif // cpp_mtl_VertexDescriptor_hpp
