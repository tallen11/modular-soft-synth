//
//  SynthGUI.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "SynthGUI.hpp"
#include <iostream>

SynthGUI::SynthGUI()
{
    if (!glfwInit()) {
        std::cout << "ERROR: Could not initialize glwf." << std::endl;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Modular Software Synth", NULL, NULL);
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
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    test = new Sprite("/Users/tateallen/Documents/DigitalAudio/ModularSoftSynth/ModularSoftSynth/Knob.png");
    test->x = 30.0f;
    test->y = 30.0f;
    renderer = new SpriteRenderer();
}

SynthGUI::~SynthGUI()
{
    
}

void SynthGUI::update()
{
    render();
}

void SynthGUI::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    renderer->renderSprite(*test);
    test->rotation += 0.1f;
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}