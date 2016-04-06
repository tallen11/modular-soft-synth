//
//  ModuleInput.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "ModuleInput.hpp"
#include <cassert>

ModuleInput::ModuleInput(const std::string &name)
{
    this->name = name;
    this->dataBuffer = nullptr;
}

ModuleInput::ModuleInput(const std::string &name, ModuleDataBuffer *inputDataBuffer)
{
    this->name = name;
    this->setDataBuffer(inputDataBuffer);
}

ModuleInput::~ModuleInput()
{
    
}

const std::string& ModuleInput::getName()
{
    return this->name;
}

void ModuleInput::setDataBuffer(ModuleDataBuffer *inputDataBuffer)
{
    this->dataBuffer = inputDataBuffer;
}

bool ModuleInput::canRead()
{
    return this->dataBuffer->hasData();
}

size_t ModuleInput::getBufferSize()
{
    return this->dataBuffer->getSize();
}

double ModuleInput::readData()
{
    assert(this->dataBuffer != nullptr);
    return this->dataBuffer->readData();
}