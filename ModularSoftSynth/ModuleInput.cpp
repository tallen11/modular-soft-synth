//
//  ModuleInput.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "ModuleInput.hpp"

ModuleInput::ModuleInput()
{
    this->dataBuffer = nullptr;
}

ModuleInput::ModuleInput(ModuleDataBuffer *inputDataBuffer)
{
    this->setDataBuffer(inputDataBuffer);
}

ModuleInput::~ModuleInput()
{
    
}

void ModuleInput::setDataBuffer(ModuleDataBuffer *inputDataBuffer)
{
    this->dataBuffer = inputDataBuffer;
}

bool ModuleInput::hasData()
{
    return this->dataBuffer->hasData();
}

double ModuleInput::readData()
{
    return this->dataBuffer->readData();
}