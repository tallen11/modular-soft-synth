//
//  WindowBase.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "WindowBase.hpp"

WindowBase::WindowBase(Module *module)
{
    this->module = module;
}

WindowBase::~WindowBase()
{
    
}

void WindowBase::addModuleComponent(ComponentBase *component)
{
    components.push_back(component);
}

void WindowBase::update()
{
    render();
}

void WindowBase::render()
{
    for (auto comp : components) {
        comp->update();
    }
}