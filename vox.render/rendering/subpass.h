//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef subpass_hpp
#define subpass_hpp

#include "Metal/Metal.hpp"
#include "scene.h"
#include "shader/shader_uniform.h"

namespace vox {
class RenderPass;

class Subpass {
public:
//    Subpass(View* view,
//            Scene* scene,
//            Camera* camera);
    
    Subpass(const Subpass &) = delete;
    
    Subpass(Subpass &&) = default;
    
    virtual ~Subpass() = default;
    
    Subpass &operator=(const Subpass &) = delete;
    
    Subpass &operator=(Subpass &&) = delete;
    
    /**
     * @brief Prepares the shaders and shader variants for a subpass
     */
    virtual void prepare() = 0;
    
    /**
     * @brief Draw virtual function
     * @param commandEncoder CommandEncoder to use to record draw commands
     */
    virtual void draw(MTL::RenderCommandEncoder& commandEncoder) = 0;
    
    virtual void setRenderPass(RenderPass* pass);
    
public:
    /**
     * Upload constant shader data in shader uniform block.
     * @param uniformBlock - shader Uniform block
     * @param shaderData - shader data
     */
    void uploadUniforms(MTL::RenderCommandEncoder& commandEncoder,
                        const std::vector<ShaderUniform> &uniformBlock,
                        const ShaderData &shaderData);
    
protected:
    RenderPass* _pass{nullptr};
    
//    View* _view{nullptr};
    Scene* _scene{nullptr};
    Camera* _camera{nullptr};
    
    static bool _compareFromNearToFar(const RenderElement &a, const RenderElement &b);
    static bool _compareFromFarToNear(const RenderElement &a, const RenderElement &b);
    
private:
    void process(const ShaderUniform &uniform, const std::any &a, MTL::RenderCommandEncoder& encoder);
};

}

#endif /* subpass_hpp */
