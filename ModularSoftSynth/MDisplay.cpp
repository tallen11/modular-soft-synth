//
//  MDisplay.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MDisplay.hpp"
#include <iostream>

#define WIDTH 512.0
#define HEIGHT 512.0


MDisplay::MDisplay()
{
    hasInputs();
    leftChannelInput = createInput("left");
    rightChannelInput = createInput("right");
    
    if (!glfwInit()) {
        std::cout << "ERROR" << std::endl;
    }
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "Display", NULL, NULL);
    if (!window) {
        std::cout << "Error creating window!" << std::endl;
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    glClearColor(0, 0, 0, 1);
}

MDisplay::~MDisplay()
{

}

void MDisplay::update()
{
    fftw_complex *fftIn = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    fftw_complex *fftOut = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    fftw_plan p = fftw_plan_dft_1d(MAX_BUFFER_SIZE, fftIn, fftOut, FFTW_FORWARD, FFTW_ESTIMATE);
    
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        double in = leftChannelInput->readData();
        fftIn[i][0] = in * hanningWindow(i);
        fftIn[i][1] = 0.0;
    }
    
    fftw_execute(p);
    
    double magnitude = 0.0;
    for (int i = 0; i < MAX_BUFFER_SIZE/2; ++i) {
        double com[] = { fftOut[i][0], fftOut[i][1] };
        freqs[i] = com[0]; // * (0.5 * (1.0 - cos((2.0 * M_PI) / (i - 1.0))));
        magnitude += freqs[i] * freqs[i];
    }
    
    magnitude = sqrt(magnitude);
    for (int i = 0; i < MAX_BUFFER_SIZE/2; ++i) {
        freqs[i] /= magnitude;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    
    glBegin(GL_LINES);
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        double x = i / WIDTH * 2.0 - 1.0;
        double y = fabs((freqs[i] * HEIGHT) / HEIGHT);
        glVertex3d(x, y, 0.0);
    }
    glEnd();
    
    fftw_destroy_plan(p);
    fftw_free(fftIn);
    fftw_free(fftOut);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
//    if (leftChannelInput->canRead() && rightChannelInput->canRead() && !glfwWindowShouldClose(window)) {
//        
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        if (leftChannelInput->canRead() && rightChannelInput->canRead()) {
//            glColor3f(1.f, 0.f, 0.f);
//            glPointSize(10.0);
//            
//            glBegin(GL_POINTS);
//        
//            double dataLeft = (WIDTH - 25.0) * leftChannelInput->readData();
//            double dataRight = (HEIGHT - 25.0) * rightChannelInput->readData();
//            glVertex3d(dataLeft / WIDTH, dataRight / HEIGHT, 0.0);
//            
//            glEnd();
//            
//            glfwSwapBuffers(window);
//            glfwPollEvents();
//        }
//    }
}