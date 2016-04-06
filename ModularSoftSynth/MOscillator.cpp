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
    this->hasInputs();
    this->hasOutput();
    this->frequencyInput = this->createInput("frequency"); // The desired frequency of the sine wave
    this->amplitudeInput = this->createInput("amplitude"); // The desired max amplitude of the sine wave
}

MOscillator::~MOscillator()
{
    
}

void MOscillator::update(double x)
{
    // Test data for now
    double data = sin(2 * M_PI * 440.0 * x);
    this->output->writeData(data);
}