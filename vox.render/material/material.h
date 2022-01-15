//
//  material.hpp
//  vox.render
//
//  Created by 杨丰 on 2021/11/27.
//

#ifndef material_hpp
#define material_hpp

#include "../shader/shader.h"
#include "../shader/shader_data.h"
#include "../shader/state/render_state.h"
#include "enums/render_queue_type.h"

namespace vox {
/**
 * Material.
 */
class Material {
public:
    /** Name. */
    std::string name = "";
    /** Shader used by the material. */
    Shader *shader;
    /** Render queue type. */
    RenderQueueType renderQueueType = RenderQueueType::Opaque;
    /** Shader data. */
    ShaderData shaderData = ShaderData();
    /** Render state. */
    RenderState renderState = RenderState();
    
    /**
     * Create a material instance.
     * @param shader - Shader used by the material
     */
    Material(Shader *shader);
};
using MaterialPtr = std::shared_ptr<Material>;

}

#endif /* material_hpp */
