//
//  Shaders.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/18/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Shaders_hpp
#define Shaders_hpp

#include <string>

class Shaders {
    
public:
    static std::string loadShaderCode(const std::string &filePath);
};

#endif /* Shaders_hpp */
