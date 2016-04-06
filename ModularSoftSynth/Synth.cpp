//
//  Synth.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "Synth.hpp"

Synth::Synth()
{
    this->modules = new std::vector<Module*>();
}

Synth::~Synth()
{
    delete this->modules;
}

void Synth::update()
{
    for (auto module : *this->modules) {
        module->update();
    }
}

void Synth::addModule(Module *module)
{
    
}

void Synth::removeModule(Module *module)
{
    
}

void Synth::connectModules(Module *outputModule, Module *inputModule)
{
    
}