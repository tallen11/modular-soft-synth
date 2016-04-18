//
//  MWhiteNoiseGenerator.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MWhiteNoiseGenerator.hpp"
#include <stdlib.h>

MWhiteNoiseGenerator::MWhiteNoiseGenerator()
{
    hasOutput();
    srand((unsigned int)time(0));
}

MWhiteNoiseGenerator::~MWhiteNoiseGenerator()
{
    
}

void MWhiteNoiseGenerator::update()
{
    while (output->getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            double dx = (double)currentTime / SAMPLE_RATE;
            float data = envelopeCoeff(dx) * (rand() / float(RAND_MAX));
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