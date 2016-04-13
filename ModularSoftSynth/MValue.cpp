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
    while (this->output->getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            this->output->writeData(this->value);
        } else {
            this->output->writeData(0.0);
        }
    }
}