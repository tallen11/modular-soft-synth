//
//  MDispayInsane.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/24/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MDispayInsane_hpp
#define MDispayInsane_hpp

#include "Module.hpp"
#include <cmath>
#include "glfw3.h"
#include "fftw3.h"
#include <OpenGL/gl3.h>

class MDisplayInsane {
    
public:
    MDisplayInsane();
    ~MDisplayInsane();
    void update();
    
private:
    inline void render();
    inline void processData();
    
    ModuleInput *dataInput;
    GLFWwindow *window;
    
    GLuint vaoHandle;
    GLuint vertexBufferHandle;
    GLuint shaderProgramHandle;
    
    fftw_complex *fftInputBuffer;
    fftw_complex *fftOutputBuffer;
    fftw_plan plan;
};

#endif /* MDispayInsane_hpp */
