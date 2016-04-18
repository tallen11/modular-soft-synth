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
}

MOscillator::MOscillator(double frequency)
{
    this->hasOutput();
    this->frequency = frequency;
    this->phaseOffset = 0.0;
}

MOscillator::MOscillator(double frequency, double phaseOffset)
{
    this->hasOutput();
    this->frequency = frequency;
    this->phaseOffset = phaseOffset;
}

MOscillator::~MOscillator()
{
    
}

void MOscillator::update()
{
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            double dx = ((double)currentTime / SAMPLE_RATE);
            double data = envelopeCoeff(dx) * sin(2.0 * M_PI * frequency * dx + phaseOffset);
            writeToOutputs(data);
//            output->writeData(data);
            
//            std::cout << data << std::endl;
            
            currentTime++;
            if (currentTime == INT64_MAX) {
                currentTime = 0;
            }
        } else {
            writeToOutputs(0.0);
//            output->writeData(0.0);
        }
    }
}
