//
//  MDisplay.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MDisplay_hpp
#define MDisplay_hpp

#include "Module.hpp"
#include <GLUT/glut.h>
#include "glfw3.h"

class MDisplay : public Module {
    
public:
    MDisplay();
    ~MDisplay();
    void update();
    
private:
    void display(void);
    void reshape(int width, int height);
        
    ModuleInput *leftChannelInput;
    ModuleInput *rightChannelInput;
    GLFWwindow *window;
};

#endif /* MDisplay_hpp */
