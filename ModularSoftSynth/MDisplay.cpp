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

static const GLfloat vertexBufferData[] = {
    0.0f,  0.5f,  0.0f,
    0.5f, -0.5f,  0.0f,
    -0.5f, -0.5f,  0.0f
};

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
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glGenBuffers(1, &vertexBufferHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    std::string vsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/vertex.glsl");
    std::string fsc = Shaders::loadShaderCode("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/fragment.glsl");
    shaderProgramHandle = Shaders::createShaderProgram(vsc, fsc);
    
//    glClearColor(0, 0, 0, 1);
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
    
//    if (!leftChannelInput->canRead()) {
//        return;
//    }
    
    
    render();
    
    
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
    
    
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    
//    glColor3f(maxAmpl, 1.0 - maxAmpl, 1.0);
//    glPointSize(3.0);
//    
//    glBegin(GL_POINTS);
//    for (int i = 0; i < MAX_BUFFER_SIZE/2.0; ++i) {
//        double x = i / WIDTH * 2.0 - 0.95;
//        double y = ((freqs[i] * HEIGHT) / HEIGHT);
//        glVertex3d(x, y, 0.0);
//    }
//    glEnd();
//    
//    glfwSwapBuffers(window);
//    glfwPollEvents();
}

void MDisplay::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgramHandle);
    
    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
//    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
//    glVertexAttribPointer(0,
//                          3,
//                          GL_FLOAT,
//                          GL_FALSE,
//                          0,
//                          (void*)0);
//    
//    glDrawArrays(GL_TRIANGLES, 0, 3);
//    glDisableVertexAttribArray(0);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}