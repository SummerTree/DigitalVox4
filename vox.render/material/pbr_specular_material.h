//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef pbr_specular_material_hpp
#define pbr_specular_material_hpp

#include "pbr_base_material.h"

namespace vox {
/**
 * PBR (Specular-Glossiness Workflow) Material.
 */
class PBRSpecularMaterial : public PBRBaseMaterial {
public:
    /**
     * Specular color.
     */
    Color specularColor();
    
    void setSpecularColor(const Color &newValue);
    
    /**
     * Glossiness.
     */
    float glossiness();
    
    void setGlossiness(float newValue);
    
    /**
     * Specular glossiness texture.
     * @remarks RGB is specular, A is glossiness
     */
    std::shared_ptr<MTL::Texture> specularGlossinessTexture();
    
    void setSpecularGlossinessTexture(std::shared_ptr<MTL::Texture> newValue);
    
    /**
     * Create a pbr specular-glossiness workflow material instance.
     */
    explicit PBRSpecularMaterial();
    
private:
    ShaderProperty _glossinessProp;
    ShaderProperty _specularColorProp;
    ShaderProperty _specularGlossinessTextureProp;
};

}

#endif /* pbr_specular_material_hpp */
