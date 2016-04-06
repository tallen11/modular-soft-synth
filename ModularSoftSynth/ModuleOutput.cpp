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

bool ModuleOutput::canWrite()
{
    return this->dataBuffer->getSize() < MAX_BUFFER_SIZE;
}

size_t ModuleOutput::getBufferSize()
{
    return this->dataBuffer->getSize();
}

void ModuleOutput::writeData(double data)
{
    assert(this->dataBuffer != nullptr);
    this->dataBuffer->writeData(data);
}