//
//  Bar.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/27/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Bar_hpp
#define Bar_hpp

#include <OpenGL/gl3.h>
#include "glfw3.h"

class Bar {
    
public:
    Bar(double position, double width);
    ~Bar();
    void setHeight(double height);
    void setColor(float r, float g, float b, float a);
    void render(GLuint colorHandle);
    
    void multColor(float factor);
    
    double height;
    
private:
    double position;
    double width;
    float color[4];
    GLdouble vertices[12];
    GLuint vertexBufferHandle;
    GLuint colorHandle;
};

#endif /* Bar_hpp */
