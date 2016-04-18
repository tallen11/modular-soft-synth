//
//  Shaders.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/18/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "Shaders.hpp"
#include <fstream>
#include <iostream>

std::string Shaders::loadShaderCode(const std::string &filePath)
{
    std::string code = "";
    
    std::ifstream file(filePath, std::ios::in);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            code += line + "\n";
        }
        
        file.close();
        
        std::cout << code << std::endl;
    } else {
        std::cout << "Could not open shader file: " << filePath << std::endl;
    }
    
    return code;
}