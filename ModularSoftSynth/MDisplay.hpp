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
#include <cmath>
#include "glfw3.h"
#include "fftw3.h"
#include <OpenGL/gl3.h>

class MDisplay : public Module {
    
public:
    MDisplay();
    ~MDisplay();
    void update();
    
private:
    inline void render();
    inline void processDataOriginal();
    inline void processDataSlow();
    
    ModuleInput *leftChannelInput;
    ModuleInput *rightChannelInput;
    GLFWwindow *window;
    
    GLuint vaoHandle;
    GLuint vertexBufferHandle;
    GLuint shaderProgramHandle;
    GLint particleColorHandle;
    
    GLdouble freqs[MAX_BUFFER_SIZE * 2];
    GLfloat currentColor[4];
    
    fftw_complex *fftInputBuffer;
    fftw_complex *fftOutputBuffer;
    fftw_plan plan;
};

inline double hanningWindow(int x)
{
    return 0.5 * (1.0 - cos((2.0 * M_PI * x) / (MAX_BUFFER_SIZE - 1.0)));
}

#endif /* MDisplay_hpp */
