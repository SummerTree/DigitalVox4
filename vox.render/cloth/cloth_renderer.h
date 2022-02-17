//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef cloth_renderer_hpp
#define cloth_renderer_hpp

#include "renderer.h"
#include "core/cpp_mtl.h"
#include <NvClothExt/ClothMeshDesc.h>

namespace vox {
namespace cloth {
class ClothRenderer: public Renderer {
public:
    struct Vertex {
        physx::PxVec3 position;
        physx::PxVec3 normal;
    };
    
    ClothRenderer(Entity* entity);
    
    void _render(std::vector<RenderElement> &opaqueQueue,
                 std::vector<RenderElement> &alphaTestQueue,
                 std::vector<RenderElement> &transparentQueue) override;
    
    void setClothMeshDesc(const nv::cloth::ClothMeshDesc& desc);
    
    void update(const physx::PxVec3* positions, uint32_t numVertices);
    
private:
    void _initialize(const void* vertices, uint32_t numVertices, uint32_t vertexSize,
                     const uint16_t* faces, uint32_t numFaces);
    
    std::vector<Vertex> _vertices;
    std::vector<uint16_t> _indices;
    std::vector<uint32_t> _submeshOffsets;
    
    uint32_t _numFaces;
    uint32_t _numVertices;
    uint32_t _vertexSize;
    
    MTL::Buffer _vertexBuffers;
    MTL::Buffer _indexBuffers;
    MTL::VertexDescriptor _vertexDescriptor;
    
    MeshPtr _mesh{nullptr};
};

};
}

#endif /* cloth_renderer_hpp */
