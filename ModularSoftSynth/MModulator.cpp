//
//  MModulator.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/12/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MModulator.hpp"
#include <cmath>
#include <iostream>

MModulator::MModulator(double modFreq, double carFreq, double modIndex)
{
    hasInputs();
    hasOutput();
//    carrierInput = createInput("carrier");
//    signalInput = createInput("signal");
    
    alphaInput = createInput("alpha");
    betaInput = createInput("beta");
    modFrequency = modFreq;
    carrierFrequency = carFreq;
    modulationIndex = modIndex;
}

MModulator::~MModulator()
{
    
}

void MModulator::update()
{
    while (output->getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            double dx = ((double)currentTime / SAMPLE_RATE);
            double alpha = 1.0;
            if (alphaInput->canRead()) {
                alpha = alphaInput->readData();
            }
            
            double beta = 1.0;
            if (betaInput->canRead()) {
                beta = betaInput->readData();
            }
            
            double data = envelopeCoeff(dx) * sin(alpha * 2.0 * M_PI * carrierFrequency * dx + modulationIndex * sin(beta * 2.0 * M_PI * modFrequency * dx));
            output->writeData(data);
            
            currentTime++;
            if (currentTime == INT64_MAX) {
                currentTime = 0;
            }
        } else {
            output->writeData(0.0);
        }
    }
}