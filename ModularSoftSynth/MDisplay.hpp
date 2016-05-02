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
#include <vector>
#include <cmath>
#include "glfw3.h"
#include "fftw3.h"
#include <OpenGL/gl3.h>
#include "Bar.hpp"

class MDisplay : public Module {
    
public:
    MDisplay();
    ~MDisplay();
    void update();
    
private:
    inline void render();
    inline void renderBars();
//    inline void processDataOriginal();
    inline void processDataSlow();
    inline void processDataBars();
    
    ModuleInput *leftChannelInput;
    ModuleInput *rightChannelInput;
    GLFWwindow *window;
    
    GLuint vaoHandle;
    GLuint vertexBufferHandle;
    GLuint shaderProgramHandle;
    GLint particleColorHandle;
    GLint barHeightHandle;
    GLint timeHandle;
    GLint rotationMatrixHandle;
    
    GLdouble freqs[MAX_BUFFER_SIZE * 2];
    GLfloat currentColor[4];
    
//    fftw_complex *fftInputBuffer;
//    fftw_complex *fftOutputBuffer;
    double *fftInputBuffer;
    double *fftOutputBuffer;
    fftw_plan plan;
    
    std::vector<Bar*> bars;
};

inline double hanningWindow(int x)
{
    return 0.5 * (1.0 - cos((2.0 * M_PI * x) / (MAX_BUFFER_SIZE - 1.0)));
}

#define MAX_RESPONSE 0.9
#define MIN_RESPONSE 0.65

inline double responseCurve(int x, int count)
{
    return MAX_RESPONSE * pow(pow(MIN_RESPONSE / MAX_RESPONSE, 1.0 / count), (double)x);
}

#define MIN_BUFF 1.0
#define MAX_BUFF 1.5

inline double heightBuffCurve(int x, int count)
{
    return MIN_BUFF * pow(pow(MAX_BUFF / MIN_BUFF, 1.0 / count), (double)x);
}

enum ColorOffset {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

inline double gaussianColorCurve(int x, int count, ColorOffset offset)
{
    int os = 0;
    if (offset != RED)
        os = count / (2 / offset);
    
    return pow(M_E, -pow(x - os, 2.0) / (2.0 * pow(8.0, 2.0)));
}

#endif /* MDisplay_hpp */
