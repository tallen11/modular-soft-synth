//
//  MValue.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/6/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MValue.hpp"

MValue::MValue(double value)
{
    this->value = value;
}

MValue::~MValue()
{
    
}

void MValue::update()
{
    if (this->output->getBufferSize() == 0) {
        this->output->writeData(this->value);
    }
}