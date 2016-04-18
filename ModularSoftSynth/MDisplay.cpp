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
    if (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
//        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        
        
        if (leftChannelInput->canRead() && rightChannelInput->canRead()) {
            glColor3f(1.f, 0.f, 0.f);
            glPointSize(10.0);
            
            glBegin(GL_POINTS);
        
            double dataLeft = (WIDTH - 25.0) * leftChannelInput->readData();
            double dataRight = (HEIGHT - 25.0) * rightChannelInput->readData();
//            std::cout << data << std::endl;
            glVertex3d(dataLeft / WIDTH, dataRight / HEIGHT, 0.0);
            
            
            
            //        glVertex3f(-0.6f, -0.4f, 0.f);
            //        glColor3f(0.f, 1.f, 0.f);
            //        glVertex3f(0.6f, -0.4f, 0.f);
            //        glColor3f(0.f, 0.f, 1.f);
            //        glVertex3f(0.f, 0.6f, 0.f);
            
            glEnd();
        } else {
        }
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        /* set the current drawing color to red */
//        glColor3f(1, 0, 0);
//        
//        /* start drawing triangles, each triangle takes 3 vertices */
//        glBegin(GL_TRIANGLES);
//        
//        /* give the 3 triangle vertex coordinates 1 at a time */
//        glVertex2f(10, 10);
//        glVertex2f(250, 400);
//        glVertex2f(400, 10);
//        
//        /* tell OpenGL we're done drawing triangles */
//        glEnd();
//        
//        /* swap the back and front buffers so we can see what we just drew */
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//        std::cout << "fdsfds" <<std::endl;

    } else {
        
    }
    
}