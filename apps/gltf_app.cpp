//
//  gltf_app.cpp
//  apps
//
//  Created by 杨丰 on 2022/1/22.
//

#include "gltf_app.h"
#include "mesh/primitive_mesh.h"
#include "mesh/mesh_renderer.h"
#include "loader/gltf_loader.h"
#include "controls/free_control.h"
#include "camera.h"

namespace vox {
void GLTFApp::loadScene(uint32_t width, uint32_t height) {
    auto rootEntity = _scene->createRootEntity();
    
    auto cameraEntity = rootEntity->createChild();
    cameraEntity->transform->setPosition(5, 5, 1);
    _mainCamera = cameraEntity->addComponent<Camera>();
    _mainCamera->resize(width, height);
    cameraEntity->addComponent<control::FreeControl>();
    
    // init point light
    auto light = rootEntity->createChild("light");
    light->transform->setPosition(5.0f, 5.0f, -5.0f);
    light->addComponent<PointLight>();
    
    auto modelEntity = rootEntity->createChild();
    auto loader = loader::GLTFLoader(_device.get());
    loader.loadFromFile("../assets/Models/sponza/sponza.gltf", modelEntity);
}

}