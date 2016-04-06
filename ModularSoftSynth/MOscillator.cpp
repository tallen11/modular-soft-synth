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

const static int SAMPLES_PER_SEC = 44100;

MOscillator::MOscillator()
{
    this->hasOutput();
    this->lastIndex = 0;
}

MOscillator::~MOscillator()
{
    
}

void MOscillator::update()
{
    // Test data for now
    while (this->output->canWrite()) {
        double dx = (double)lastIndex / SAMPLES_PER_SEC;
        double data = sin(2 * M_PI * 880.0 * dx);
        this->output->writeData(data);
        lastIndex++;
    }    
}