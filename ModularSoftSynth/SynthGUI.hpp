//
//  SynthGUI.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef SynthGUI_hpp
#define SynthGUI_hpp

#include <cmath>
#include "glfw3.h"
#include <OpenGL/gl3.h>
#include "Sprite.hpp"
#include "SpriteRenderer.hpp"

class SynthGUI {
    
public:
    SynthGUI();
    ~SynthGUI();
    void update();
    
    
    Sprite *test;
    SpriteRenderer *renderer;
    
private:
    GLFWwindow *window;
    void render();
};

#endif /* SynthGUI_hpp */
