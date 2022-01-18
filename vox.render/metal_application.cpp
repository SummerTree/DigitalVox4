//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "metal_application.h"
#include "engine.h"
#include "core/cpp_mtl_assert.h"
#include <glog/logging.h>

namespace vox {
MetalApplication::~MetalApplication() {
    _renderContext.reset();
    _device.reset();
}

bool MetalApplication::prepare(Engine &engine) {
    if (!Application::prepare(engine)) {
        return false;
    }
    
    LOG(INFO) << "Initializing Metal Application";
    
    _device = std::unique_ptr<MTL::Device>(MTL::CreateSystemDefaultDevice());
    printf("Selected Device: %s\n", _device->name());

    _commandQueue = _device->makeCommandQueue();

    _renderContext = engine.createRenderContext(*_device);
    _scene = std::make_unique<Scene>();
    return true;
}

void MetalApplication::update(float delta_time) {
    _scene->update(delta_time);
    _renderContext->draw();
}

bool MetalApplication::resize(const uint32_t width, const uint32_t height) {
    Application::resize(width, height);
    
    return true;
}

void MetalApplication::framebufferResize(uint32_t width, uint32_t height) {
    Application::framebufferResize(width, height);

    _renderContext->resize(MTL::sizeMake(width, height, 0));
}

void MetalApplication::inputEvent(const InputEvent &inputEvent) {}

void MetalApplication::finish() {}


MTL::Library MetalApplication::makeShaderLibrary() {
    CFErrorRef error = nullptr;
    CFURLRef libraryURL = nullptr;

    libraryURL = CFBundleCopyResourceURL( CFBundleGetMainBundle() , CFSTR("vox.shader"), CFSTR("metallib"), nullptr);
    MTL::Library shaderLibrary = _device->makeLibrary(libraryURL, &error);
    
    MTLAssert(!error, error, "Could not load Metal shader library");
    
    CFRelease(libraryURL);
    return shaderLibrary;
}


}
