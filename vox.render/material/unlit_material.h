//
//  unlit_material.hpp
//  vox.render
//
//  Created by 杨丰 on 2021/11/29.
//

#ifndef unlit_material_hpp
#define unlit_material_hpp

#include "base_material.h"
#include "ImathColor.h"

namespace vox {
/**
 * Unlit Material.
 */
class UnlitMaterial : public BaseMaterial {
public:
    /**
     * Base color.
     */
    Imath::Color4f baseColor();
    
    void setBaseColor(const Imath::Color4f &newValue);
    
    /**
     * Base texture.
     */
    std::shared_ptr<MTL::Texture> baseTexture();
    
    void setBaseTexture(std::shared_ptr<MTL::Texture> newValue);
    
    /**
     * Tiling and offset of main textures.
     */
    Imath::V4f tilingOffset();
    
    void setTilingOffset(const Imath::V4f &newValue);
    
    /**
     * Create a unlit material instance.
     */
    explicit UnlitMaterial();
    
private:
    ShaderProperty _baseColorProp;
    ShaderProperty _baseTextureProp;
    ShaderProperty _tilingOffsetProp;
};

}

#endif /* unlit_material_hpp */