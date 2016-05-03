//
//  SpriteRenderer.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "SpriteRenderer.hpp"
#include "Shaders.hpp"
#include <string>
#include "glm.hpp"
#include "transform.hpp"
#include "type_vec.hpp"
#include "type_ptr.hpp"

#include <iostream>

SpriteRenderer::SpriteRenderer()
{
    GLuint vboHandle;
//    GLfloat vertices[] = {
//        0.0f, 1.0f, 0.0f, 1.0f,
//        1.0f, 0.0f, 1.0f, 0.0f,
//        0.0f, 0.0f, 0.0f, 0.0f,
//        
//        0.0f, 1.0f, 0.0f, 1.0f,
//        1.0f, 1.0f, 1.0f, 1.0f,
//        1.0f, 0.0f, 1.0f, 0.0f
//    };

    GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        
        0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };
    
    glGenVertexArrays(1, &vaoHandle);
    glGenBuffers(1, &vboHandle);
    
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(vaoHandle);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    std::string vertexShaderCode = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/SpriteVertex.glsl");
    std::string fragmentShaderCode = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/SpriteFragment.glsl");
    shaderHandle = Shaders::createShaderProgram(vertexShaderCode, fragmentShaderCode);
    
//    positionHandle = glGetUniformLocation(shaderHandle, "position");
    modelHandle = glGetUniformLocation(shaderHandle, "model");
}

SpriteRenderer::~SpriteRenderer()
{
    
}

void SpriteRenderer::renderSprite(const Sprite &sprite)
{
    glUseProgram(shaderHandle);
    
    glm::mat4 projection = glm::ortho(0.0f, (float)WINDOW_WIDTH, 0.0f, (float)WINDOW_HEIGHT, -1.0f, 1.0f);
    GLuint projectionHandle = glGetUniformLocation(shaderHandle, "projection");
    glUniformMatrix4fv(projectionHandle, 1, GL_FALSE, glm::value_ptr(projection));
    
    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(sprite.x, sprite.y, 0.0f));
    model = glm::translate(model, glm::vec3(0.5f * sprite.texture.textureWidth, 0.5f * sprite.texture.textureHeight, 0.0f));
    model = glm::rotate(model, sprite.rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * sprite.texture.textureWidth, -0.5f * sprite.texture.textureHeight, 0.0f));
    model = glm::scale(model, glm::vec3(sprite.texture.textureWidth, sprite.texture.textureHeight, 1.0f));
    glUniformMatrix4fv(modelHandle, 1, GL_FALSE, glm::value_ptr(model));
    
//    std::cout << "matrix" << std::endl;
//    for (int x = 0; x < 4; ++x) {
//        for (int y = 0; y < 4; ++y) {
//            glm::mat4 kek = projection * model;
//            std::cout << kek[y][x] << ", ";
//        }
//        
//        std::cout << std::endl;
//    }
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite.texture.textureHandle);
    
    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glBindVertexArray(0);
}