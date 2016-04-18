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
    hasOutput();
    this->value = value;
}

MValue::~MValue()
{
    
}

void MValue::update()
{
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            writeToOutputs(value);
//            this->output->writeData(this->value);
        } else {
            writeToOutputs(0.0);
//            this->output->writeData(0.0);
        }
    }
}