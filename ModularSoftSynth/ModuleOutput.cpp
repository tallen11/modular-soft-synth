//
//  ModuleOutput.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "ModuleOutput.hpp"
#include <cassert>

ModuleOutput::ModuleOutput()
{
    this->dataBuffer = nullptr;
}

ModuleOutput::ModuleOutput(ModuleDataBuffer *outputDataBuffer)
{
    this->setDataBuffer(outputDataBuffer);
}

ModuleOutput::~ModuleOutput()
{
    
}

void ModuleOutput::setDataBuffer(ModuleDataBuffer *outputDataBuffer)
{
    this->dataBuffer = outputDataBuffer;
}

void ModuleOutput::writeData(double data)
{
    assert(this->dataBuffer != nullptr);
    this->dataBuffer->writeData(data);
}