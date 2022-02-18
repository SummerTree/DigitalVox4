//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef multi_solver_app_hpp
#define multi_solver_app_hpp

#include "cloth_application.h"

namespace vox {
namespace cloth {
class MultiSolverApp : public ClothApplication {
public:
    void loadScene(uint32_t width, uint32_t height) override;
        
private:
    void _initializeCloth(EntityPtr entity, int index, physx::PxVec3 offset);
    
    nv::cloth::Fabric *_fabric[2];
    nv::cloth::Solver *_solver[2];
    ClothActor _clothActor[2];
};

}
}
#endif /* multi_solver_app_hpp */