//
//  MDisplay.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MDisplay.hpp"
#include "Shaders.hpp"
#include <iostream>

#define WIDTH 512.0
#define HEIGHT 512.0


MDisplay::MDisplay()
{
    hasInputs();
    leftChannelInput = createInput("left");
    rightChannelInput = createInput("right");
    
//    std::string vsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/vertex.glsl");
//    std::string fsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/fragment.glsl");
//    GLuint pHandle = Shaders::createShaderProgram(vsc, fsc);
    
    fftInputBuffer = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    fftOutputBuffer = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    plan = fftw_plan_dft_1d(MAX_BUFFER_SIZE, fftInputBuffer, fftOutputBuffer, FFTW_FORWARD, FFTW_ESTIMATE);
    
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
    fftw_destroy_plan(plan);
    fftw_free(fftInputBuffer);
    fftw_free(fftOutputBuffer);
}

//static double lastTime = glfwGetTime();
//static int frames = 0;

void MDisplay::update()
{
//    frames++;
//    double time = glfwGetTime();
//    if (time - lastTime >= 1.0) {
//        std::cout << 1000.0 / frames << " ms/f, " << frames / 1.0 << " fps" << std::endl;
//        lastTime = time;
//        frames = 0;
//    }
    
    if (!leftChannelInput->canRead()) {
        return;
    }
    
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        if (leftChannelInput->canRead()) {
            double in = leftChannelInput->readData();
            fftInputBuffer[i][0] = in * hanningWindow(i);
            fftInputBuffer[i][1] = 0.0; // in * hanningWindow(i);
        } else {
            fftInputBuffer[i][0] = 0.0;
            fftInputBuffer[i][1] = 0.0;
        }
    }
    
    fftw_execute(plan);
    
    double magnitude = 0.0;
    for (int i = 0; i < MAX_BUFFER_SIZE/2; ++i) {
        double com[] = { fftOutputBuffer[i][0], fftOutputBuffer[i][1] };
        freqs[i] = com[0];
        magnitude += freqs[i] * freqs[i];
    }
    
    magnitude = sqrt(magnitude);
    double maxAmpl = 0.0;
    for (int i = 0; i < MAX_BUFFER_SIZE/2; ++i) {
        freqs[i] /= magnitude;
        if (fabs(freqs[i]) > maxAmpl) {
            maxAmpl = fabs(freqs[i]);
        }
    }
    
//    for (int k = 0; k < 1; ++k) {
//        for (int i = 1; i < MAX_BUFFER_SIZE/2 - 1; ++i) {
////            int prevIndex = (i - 1 < 0 ? MAX_BUFFER_SIZE / 2 : i - 1);
//            freqs[i] = (freqs[i-1] + freqs[i+1]) / 2.0;
//        }
//    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(maxAmpl, 1.0 - maxAmpl, 1.0);
    glPointSize(3.0);
    
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_BUFFER_SIZE/2.0; ++i) {
        double x = i / WIDTH * 2.0 - 0.95;
        double y = ((freqs[i] * HEIGHT) / HEIGHT);
        glVertex3d(x, y, 0.0);
    }
    glEnd();
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}