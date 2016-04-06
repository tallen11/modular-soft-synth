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
    this->buffer = new std::queue<double>();
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
    return !this->buffer->empty();
}

double ModuleDataBuffer::readData()
{
    double data = this->buffer->back();
    this->buffer->pop();
    
    return data;
}