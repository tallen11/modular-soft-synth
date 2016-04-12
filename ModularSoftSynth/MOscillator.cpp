//
//  MOscillator.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MOscillator.hpp"
#include <cmath>
#include <iostream>

MOscillator::MOscillator()
{
    this->hasOutput();
    this->frequency = 440.0;
    this->lastIndex = 0;
}

MOscillator::MOscillator(double frequency)
{
    this->hasOutput();
    this->frequency = frequency;
    this->lastIndex = 0;
}

MOscillator::~MOscillator()
{
    
}

void MOscillator::update()
{
    // Test data for now
    while (this->output->getBufferSize() < MAX_BUFFER_SIZE) {
        double dx = (double)lastIndex / SAMPLE_RATE;
        double data = sin(2 * M_PI * this->frequency * dx);
        this->output->writeData(data);
        lastIndex++;
    }    
}