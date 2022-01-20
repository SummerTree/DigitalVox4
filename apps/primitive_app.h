//
//  primitive_app.hpp
//  apps
//
//  Created by 杨丰 on 2022/1/20.
//

#ifndef primitive_app_hpp
#define primitive_app_hpp

#include "forward_application.h"
#include "controls/orbit_control.h"

namespace vox {
class PrimitiveApp : public ForwardApplication {
public:
    void loadScene(uint32_t width, uint32_t height) override;
    
    void inputEvent(const InputEvent &inputEvent) override;

private:
    control::OrbitControl* _controller{nullptr};
};
}

#endif /* primitive_app_hpp */