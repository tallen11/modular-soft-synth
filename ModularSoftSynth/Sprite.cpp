//
//  Sprite.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "Sprite.hpp"
#include "Shaders.hpp"

Sprite::Sprite(const std::string &filePath)
{
    this->texture = Shaders::loadTextureFromPNG(filePath);
    rotation = 0.0f;
    x = 0.0f;
    y = 0.0f;
    scale = 1.0f;
}

Sprite::Sprite(const Texture texture)
{
    this->texture = texture;
    rotation = 0.0f;
    x = 0.0f;
    y = 0.0f;
    scale = 1.0f;
}

Sprite::~Sprite()
{
    
}