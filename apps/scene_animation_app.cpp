//
//  scene_animation_app.cpp
//  apps
//
//  Created by 杨丰 on 2022/1/22.
//

#include "scene_animation_app.h"
#include "mesh/primitive_mesh.h"
#include "mesh/mesh_renderer.h"
#include "loader/gltf_loader.h"
#include "controls/orbit_control.h"
#include "scene_animator.h"
#include "camera.h"

namespace vox {
void SceneAnimationApp::loadScene(uint32_t width, uint32_t height) {
    auto rootEntity = _scene->createRootEntity();
    
    auto cameraEntity = rootEntity->createChild();
    cameraEntity->transform->setPosition(2, 2, 2);
    _mainCamera = cameraEntity->addComponent<Camera>();
    _mainCamera->resize(width, height);
    auto control = cameraEntity->addComponent<control::OrbitControl>();
    control->target = Point3F(0, 1, 0);
    
    // init point light
    auto light = rootEntity->createChild("light");
    light->transform->setPosition(5.0f, 5.0f, -5.0f);
    light->addComponent<PointLight>();
    
    auto modelEntity = rootEntity->createChild();
    auto loader = loader::GLTFLoader(_device.get());
    loader.loadFromFile("../assets/Models/CesiumMan/CesiumMan.gltf", modelEntity);
    
    auto animator = modelEntity->getComponent<SceneAnimator>();
    animator->play("0");
}

}
