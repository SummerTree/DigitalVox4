/* Copyright (c) 2019-2021, Arm Limited and Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>

#include "input_events.h"
#include "timer.h"

namespace vox {
class Window;

class Engine;

class Application {
public:
    Application();
    
    virtual ~Application() = default;
    
    /**
     * @brief Prepares the application for execution
     * @param engine The engine the application is being run on
     */
    virtual bool prepare(Engine &engine);
    
    /**
     * @brief Updates the application
     * @param delta_time The time since the last update
     */
    virtual void update(float delta_time);
    
    /**
     * @brief Handles cleaning up the application
     */
    virtual void finish();
    
    /**
     * @brief Handles resizing of the window
     * @param width New width of the window
     * @param height New height of the window
     */
    virtual bool resize(const uint32_t width, const uint32_t height);
    
    /**
     * @brief Handles resizing of the window
     * @param width New pixel width of the window
     * @param height New pixel height of the window
     */
    virtual void framebuffer_resize(uint32_t width, uint32_t height);
    
    /**
     * @brief Handles input events of the window
     * @param inputEvent The input event object
     */
    virtual void inputEvent(const InputEvent &inputEvent);
    
    const std::string &get_name() const;
    
    void set_name(const std::string &name);
    
protected:
    float fps{0.0f};
    
    float frame_time{0.0f};        // In ms
    
    uint32_t frame_count{0};
    
    uint32_t last_frame_count{0};
    
    Engine *engine;
    
private:
    std::string name{};
};

}        // namespace vox
