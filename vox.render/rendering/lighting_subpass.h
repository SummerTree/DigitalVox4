/*
 See LICENSE folder for this sample’s licensing information.
 
 Abstract:
 Header for the subpass class which performs Metal setup and per frame rendering for a traditional
 deferred subpass used for macOS devices without Apple Silicon and the iOS & tvOS simulators.
 */

#ifndef AAPLLightingSubpass_h
#define AAPLLightingSubpass_h

#include "subpass.h"
#include "CPPMetal.hpp"

namespace vox {
class LightingSubpass : public Subpass {
public:
    explicit LightingSubpass(MTL::View *view);
    
    virtual ~LightingSubpass();
    
#pragma mark -
    MTL::RenderPipelineState m_lightPipelineState;
    
    void loadMetal();
    
    void drawDirectionalLight(MTL::RenderCommandEncoder &renderEncoder);
    
    void drawPointLights(MTL::RenderCommandEncoder &renderEncoder);
};

}

#endif // AAPLLightingSubpass_h
