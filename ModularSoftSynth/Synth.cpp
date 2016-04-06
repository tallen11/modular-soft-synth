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
    this->modules = std::vector<Module*>();
}

Synth::~Synth()
{
    // delete this->modules;
}

void Synth::update()
{
    for (auto module : this->modules) {
        module->update();
    }
}

void Synth::addModule(Module *module)
{
    this->modules.push_back(module);
}

void Synth::removeModule(Module *module)
{
    int index = 0;
    for (auto synthModule : this->modules) {
        if (synthModule == module) {
            this->modules.erase(this->modules.begin() + index);
            break;
        }
        
        index++;
    }
}

void Synth::connectModules(Module *outputModule, Module *inputModule, const std::string &inputName)
{
    auto output = outputModule->getOutput();
    auto input = inputModule->getInputNamed(inputName);
    auto dataBuffer = new ModuleDataBuffer(); // TODO: Delete this somewhere...
    output->setDataBuffer(dataBuffer);
    input->setDataBuffer(dataBuffer);
}