/* Copyright (c) 2018-2019, Arm Limited and Contributors
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

#include "scene_forward.h"
#include <memory>
#include <string>
#include <typeindex>
#include <vector>

namespace vox {
namespace sg {
/// @brief A generic class which can be used by nodes.
class Component {
public:
    Component() = default;
    
    Component(const std::string &name);
    
    Component(Component &&other) = default;
    
    virtual ~Component() = default;
    
    const std::string &get_name() const;
    
    virtual std::type_index get_type() = 0;
    
private:
    std::string name;
};
}        // namespace sg
}        // namespace vox