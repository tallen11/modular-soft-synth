//
//  Sprite.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "glfw3.h"
#include <string>
#include "Texture.hpp"

class Sprite {
    
public:
    Sprite(const std::string &filePath);
    Sprite(const Texture texture);
    ~Sprite();
    
    Texture texture;
    float x;
    float y;
    float rotation;
    float scale;
};

#endif /* Sprite_hpp */
