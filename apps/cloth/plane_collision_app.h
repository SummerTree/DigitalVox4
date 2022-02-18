//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef plane_collision_app_hpp
#define plane_collision_app_hpp

#include "cloth_application.h"

namespace vox {
namespace cloth {
class PlaneCollisionApp : public ClothApplication {
public:
    void loadScene(uint32_t width, uint32_t height) override;
        
private:
    void _initializeCloth(EntityPtr entity, physx::PxVec3 offset);
    
    nv::cloth::Fabric *_fabric{nullptr};
    nv::cloth::Solver *_solver{nullptr};
    ClothActor _clothActor;
};

}
}
#endif /* plane_collision_app_hpp */