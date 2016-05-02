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
#include <vector>

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
    } else {
        std::cout << "Could not open shader file: " << filePath << std::endl;
    }
    
    return code;
}

GLuint Shaders::compileShaderCode(const std::string &code, GLenum type)
{
    GLuint shaderHandle = glCreateShader(type);
    
    char const *shaderCodeRaw = code.c_str();
    glShaderSource(shaderHandle, 1, &shaderCodeRaw, NULL);
    glCompileShader(shaderHandle);
    
    GLint result = GL_FALSE;
    int infoLength;
    
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLength);
    if (infoLength > 0) {
        std::vector<char> shaderErrorMessage(infoLength + 1);
        glGetShaderInfoLog(shaderHandle, infoLength, NULL, &shaderErrorMessage[0]);
        std::cout << "Error compiling shader: " << &shaderErrorMessage[0] << std::endl;
    } else {
        std::cout << "Shader compilation successful" << std::endl;
    }
    
    return shaderHandle;
}

GLuint Shaders::createShaderProgram(const std::string &vertexShaderCode, const std::string &fragmentShaderCode)
{
    GLuint vertexHandle = compileShaderCode(vertexShaderCode, GL_VERTEX_SHADER);
    GLuint fragmentHandle = compileShaderCode(fragmentShaderCode, GL_FRAGMENT_SHADER);
    
    GLuint programHandle = glCreateProgram();
    glAttachShader(programHandle, vertexHandle);
    glAttachShader(programHandle, fragmentHandle);
    glLinkProgram(programHandle);
    
    GLint result = GL_FALSE;
    int infoLength;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &result);
    glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &infoLength);
    if (infoLength > 0) {
        std::vector<char> programErrorMessage(infoLength + 1);
        glGetProgramInfoLog(programHandle, infoLength, NULL, &programErrorMessage[0]);
        std::cout << "Error linking program: " << &programErrorMessage[0] << std::endl;
    } else {
        std::cout << "Shader program linking successful" << std::endl;
    }
    
    glDetachShader(programHandle, vertexHandle);
    glDetachShader(programHandle, fragmentHandle);
    
    glDeleteShader(vertexHandle);
    glDeleteShader(fragmentHandle);
    
    return programHandle;
}