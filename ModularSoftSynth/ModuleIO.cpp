//
//  ModuleInput.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "ModuleIO.hpp"

ModuleIO::ModuleIO(const std::string &name)
{
    this->name = name;
    this->buffer = new std::queue<double>();
}

ModuleIO::~ModuleIO()
{
    delete this->buffer;
}

const std::string& ModuleIO::getName()
{
    return this->name;
}

void ModuleIO::writeData(double data)
{
    this->buffer->push(data);
}

bool ModuleIO::hasData()
{
    return !this->buffer->empty();
}

double ModuleIO::readData()
{
    double data = this->buffer->back();
    this->buffer->pop();
    
    return data;
}