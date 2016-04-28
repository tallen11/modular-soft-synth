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
    
    fftInputBuffer = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    fftOutputBuffer = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * MAX_BUFFER_SIZE);
    plan = fftw_plan_dft_1d(MAX_BUFFER_SIZE, fftInputBuffer, fftOutputBuffer, FFTW_FORWARD, FFTW_ESTIMATE);
    
    if (!glfwInit()) {
        std::cout << "ERROR" << std::endl;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "Display", NULL, NULL);
    if (!window) {
        std::cout << "Error creating window!" << std::endl;
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    
    const GLubyte *rendererVersion =  glGetString(GL_RENDERER);
    const GLubyte *glVersion = glGetString(GL_VERSION);
    const GLubyte *slVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::cout << "Renderer: " << rendererVersion << ", GL: " << glVersion << ", Shading Language: " << slVersion << std::endl;
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glGenBuffers(1, &vertexBufferHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(freqs), freqs, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, NULL);
    
    std::string vsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/vertex.glsl");
    std::string fsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/fragment.glsl");
    shaderProgramHandle = Shaders::createShaderProgram(vsc, fsc);
    
    particleColorHandle = glGetUniformLocation(shaderProgramHandle, "particleColor");
}

MDisplay::~MDisplay()
{
    glDeleteBuffers(1, &vertexBufferHandle);
//    glDeleteVertexArrays(1, &VertexArrayID);
//    glDeleteProgram(programID);
    glfwTerminate();
    
    fftw_destroy_plan(plan);
    fftw_free(fftInputBuffer);
    fftw_free(fftOutputBuffer);
}

void MDisplay::update()
{
//    processDataOriginal();
    processDataSlow();
    render();
}

inline void MDisplay::processDataOriginal()
{
    if (leftChannelInput->canRead()) {
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            if (leftChannelInput->canRead()) {
                double in = leftChannelInput->readData();
                fftInputBuffer[i][0] = in * hanningWindow(i);
                fftInputBuffer[i][1] = in * hanningWindow(i);
            } else {
                fftInputBuffer[i][0] = 0.0;
                fftInputBuffer[i][1] = 0.0;
            }
        }
        
        fftw_execute(plan);
        
        double magnitude = 0.0;
        int freqsIndex = 0;
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            double com[] = { fftOutputBuffer[i][0], fftOutputBuffer[i][1] };
            freqs[freqsIndex] = (GLdouble)com[0];
            freqs[freqsIndex+1] = (GLdouble)(i / WIDTH);
            magnitude += freqs[freqsIndex] * freqs[freqsIndex];
            freqsIndex += 2;
        }
        
        freqsIndex = 0;
        magnitude = sqrt(magnitude);
        double maxAmpl = 0.0;
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            freqs[freqsIndex] /= (GLdouble)magnitude;
            if (fabs(freqs[freqsIndex]) > maxAmpl) {
                maxAmpl = fabs(freqs[freqsIndex]);
            }
            
            freqsIndex += 2;
        }
        
        currentColor[0] = static_cast<GLfloat>(1.0 - maxAmpl);
        currentColor[1] = static_cast<GLfloat>(1.0 - maxAmpl);
        currentColor[2] = static_cast<GLfloat>(maxAmpl);
        currentColor[3] = 1.0f;
    } else {
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            freqs[i] *= 0.95;
        }
    }
}

inline void MDisplay::processDataSlow()
{
    if (leftChannelInput->canRead()) {
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            if (leftChannelInput->canRead()) {
                double in = leftChannelInput->readData();
                fftInputBuffer[i][0] = in * hanningWindow(i);
                fftInputBuffer[i][1] = in * hanningWindow(i);
            } else {
                fftInputBuffer[i][0] = 0.0;
                fftInputBuffer[i][1] = 0.0;
            }
        }
        
        fftw_execute(plan);
        
        double buffer[MAX_BUFFER_SIZE];
        
        double magnitude = 0.0;
        int freqsIndex = 0;
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            double com[] = { fftOutputBuffer[i][0], fftOutputBuffer[i][1] };
            buffer[i] = com[0];
            freqs[freqsIndex+1] = (GLdouble)(i / WIDTH);
            magnitude += buffer[i] * buffer[i];
            freqsIndex += 2;
        }
        
        freqsIndex = 0;
        magnitude = sqrt(magnitude);
        double maxAmpl = 0.0;
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            buffer[i] /= magnitude;
            if (fabs(buffer[i]) > maxAmpl) {
                maxAmpl = fabs(buffer[i]);
            }
            
            freqsIndex += 2;
        }
        
        currentColor[0] = static_cast<GLfloat>(1.0 - maxAmpl);
        currentColor[1] = static_cast<GLfloat>(1.0 - maxAmpl);
        currentColor[2] = static_cast<GLfloat>(maxAmpl);
        currentColor[3] = 1.0f;
        
        freqsIndex = 0;
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            if (fabs(freqs[freqsIndex]) < fabs(buffer[i])) {
                freqs[freqsIndex] = (GLdouble)(buffer[i]);
            } else {
                freqs[freqsIndex] *= 0.75;
            }
            
            freqsIndex += 2;
        }
    } else {
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            freqs[i] *= 0.9;
        }
    }
}

//static double lastTime = glfwGetTime();
//static int frames = 0;

inline void MDisplay::render()
{
//    frames++;
//    double time = glfwGetTime();
//    if (time - lastTime >= 1.0) {
//        std::cout << 1000.0 / frames << " ms/f, " << frames / 1.0 << " fps" << std::endl;
//        lastTime = time;
//        frames = 0;
//    }
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(freqs), freqs, GL_STATIC_DRAW);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgramHandle);
    
    glUniform4f(particleColorHandle, currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, NULL);
    glDrawArrays(GL_POINTS, 0, MAX_BUFFER_SIZE);
    glDisableVertexAttribArray(0);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}