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
#include "glfw3.h"
#include "Texture.hpp"

class Shaders {
    
public:
    static std::string loadShaderCode(const std::string &filePath);
    static GLuint compileShaderCode(const std::string &code, GLenum type);
    static GLuint createShaderProgram(const std::string &vertexShaderCode, const std::string &fragmentShaderCode);

    static Texture loadTextureFromPNG(const std::string &filePath);
};

#endif /* Shaders_hpp */
