//
//  ModuleInput.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "ModuleDataBuffer.hpp"

ModuleDataBuffer::ModuleDataBuffer()
{
    this->buffer = new TSQueue<double>();
}

ModuleDataBuffer::~ModuleDataBuffer()
{
    delete this->buffer;
}

void ModuleDataBuffer::writeData(double data)
{
    this->buffer->push(data);
}

bool ModuleDataBuffer::hasData()
{
    return this->buffer->getSize() > 0;
}

size_t ModuleDataBuffer::getSize()
{
    return this->buffer->getSize();
}

double ModuleDataBuffer::readData()
{
    double data = this->buffer->pop();
    return data;
}