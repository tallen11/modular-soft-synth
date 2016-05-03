//
//  SpriteRenderer.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef SpriteRenderer_hpp
#define SpriteRenderer_hpp

#include "glfw3.h"
#include <OpenGL/gl3.h>
#include "Sprite.hpp"

#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512

class SpriteRenderer {
    
public:
    SpriteRenderer();
    ~SpriteRenderer();
    void renderSprite(const Sprite &sprite);
    
private:
    GLuint shaderHandle;
    GLuint vaoHandle;
//    GLuint positionHandle;
    GLuint modelHandle;
};

#endif /* SpriteRenderer_hpp */
