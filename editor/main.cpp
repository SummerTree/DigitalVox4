//
//  main.cpp
//  editor
//
//  Created by 杨丰 on 2022/1/21.
//

#include "unix_engine.h"
#include "engine.h"
#include "editor.h"

int main(int argc, char * argv[]) {
    vox::UnixEngine engine{vox::UnixType::Mac, argc, argv};
        
    auto code = engine.initialize();
    if (code == vox::ExitCode::Success) {
        engine.setApp(std::make_unique<vox::Editor>());
        code = engine.mainLoop();
    }
    
    engine.terminate(code);
    
    return EXIT_SUCCESS;
}