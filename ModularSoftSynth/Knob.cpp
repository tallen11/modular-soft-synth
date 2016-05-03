//
//  Knob.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "Knob.hpp"

Knob::Knob(float low, float high, float start)
{
    this->lowValue = low;
    this->highValue = high;
    this->startValue = start;
}

Knob::~Knob()
{
    
}

float Knob::currentValue()
{
    return 0.0f;
}

void Knob::render()
{
    
}