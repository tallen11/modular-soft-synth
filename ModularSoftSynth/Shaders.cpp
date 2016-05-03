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
#include <fstream>
#include "picoPNG.h"

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

Texture Shaders::loadTextureFromPNG(const std::string &filePath)
{
    Texture texture;
    
    std::ifstream file(filePath, std::ios::binary);
    if (file.is_open()) {
        file.unsetf(std::ios::skipws);
        std::streampos fileSize;
        
        file.seekg(0, std::ios::end);
        fileSize = file.tellg();
        file.seekg(0, std::ios::beg);
        
        std::vector<unsigned char> vec;
        vec.reserve(fileSize);
        
        vec.insert(vec.begin(),
                   std::istream_iterator<unsigned char>(file),
                   std::istream_iterator<unsigned char>());
        
        file.close();
        
        std::vector<unsigned char> bytes;
        unsigned long width;
        unsigned long height;
        
        int err = decodePNG(bytes, width, height, &(vec[0]), vec.size());
        if (!err) {
            texture.textureWidth = (int)width;
            texture.textureHeight = (int)height;
            
            glGenTextures(1, &texture.textureHandle);
            glBindTexture(GL_TEXTURE_2D, texture.textureHandle);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLint)width, (GLint)height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(bytes[0]));
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        }
    }
    
    return texture;
}