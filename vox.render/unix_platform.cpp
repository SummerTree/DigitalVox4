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

#include "unix_platform.h"

#include "glfw_window.h"

namespace vox {
namespace {
inline const std::string get_temp_path_from_environment() {
    std::string temp_path = "/tmp/";
    
    if (const char *env_ptr = std::getenv("TMPDIR")) {
        temp_path = std::string(env_ptr) + "/";
    }
    
    return temp_path;
}
}        // namespace

namespace fs {
void create_directory(const std::string &path) {
    if (!is_directory(path)) {
        mkdir(path.c_str(), 0777);
    }
}
}        // namespace fs

UnixPlatform::UnixPlatform(const UnixType &type, int argc, char **argv) :
type{type} {
    Platform::set_arguments({argv + 1, argv + argc});
    Platform::set_temp_directory(get_temp_path_from_environment());
}

void UnixPlatform::create_window(const Window::Properties &properties) {
    window = std::make_unique<GlfwWindow>(this, properties);
}
}        // namespace vox