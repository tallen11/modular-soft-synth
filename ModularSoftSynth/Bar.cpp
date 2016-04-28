//
//  Bar.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/27/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "Bar.hpp"

Bar::Bar(double position, double width)
{
    this->position = position;
    this->width = width;
    this->color[0] = 0.25f;
    this->color[1] = 0.25f;
    this->color[2] = 0.25f;
    
    this->vertices[0] = position;
    this->vertices[1] = 0.0;
    
    this->vertices[2] = position + width;
    this->vertices[3] = height;
    
    this->vertices[4] = position + width;
    this->vertices[5] = 0.0;
    
    this->vertices[6] = position;
    this->vertices[7] = height;
    
    this->vertices[8] = position + width;
    this->vertices[9] = height;
    
    this->vertices[10] = position;
    this->vertices[11] = 0.0;
    
    glGenBuffers(1, &vertexBufferHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
//    glGenVertexArrays(1, &vaoHandle);
//    glBindVertexArray(vaoHandle);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
//    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, NULL);
}

Bar::~Bar()
{
    
}

void Bar::setHeight(double height)
{
    this->height = height;
    
    this->vertices[2] = position + width;
    this->vertices[3] = height;
    
    this->vertices[6] = position;
    this->vertices[7] = height;
    
    this->vertices[8] = position + width;
    this->vertices[9] = height;
}

void Bar::setColor(float r, float g, float b, float a)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
    color[3] = a;
}

void Bar::multColor(float factor)
{
    color[0] *= factor;
    color[1] *= factor;
    color[2] *= factor;
}

void Bar::render(GLuint colorHandle)
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glUniform4f(colorHandle, color[0], color[1], color[2], color[3]);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, NULL);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glDisableVertexAttribArray(0);
}