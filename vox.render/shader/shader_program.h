//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#ifndef shader_program_hpp
#define shader_program_hpp

#include "shader_macro_collection.h"
#include "core/cpp_mtl_library.h"
#include "core/cpp_mtl_function_constant_values.h"

namespace vox {
/**
 * Shader program, corresponding to the GPU shader program.
 */
class ShaderProgram {
public:
    MTL::Function vertexShader();
    
    MTL::Function fragmentShader();
    
    /**
     * Whether this shader program is valid.
     */
    bool isValid();
    
    ShaderProgram(MTL::Library* library,
                  const std::string &vertexSource, const std::string &fragmentSource,
                  const ShaderMacroCollection &macroInfo);
    
    
private:
    MTL::FunctionConstantValues makeFunctionConstants(const ShaderMacroCollection &macroInfo);
    
    /**
     * init and link program with shader.
     */
    void _createProgram(const std::string &vertexSource, const std::string &fragmentSource,
                        const ShaderMacroCollection &macroInfo);
    
    static int _counter;
    int ID;
    bool _isValid;
    MTL::Library* _library;
    MTL::Function _vertexShader;
    MTL::Function _fragmentShader;
};

}

#endif /* shader_program_hpp */
