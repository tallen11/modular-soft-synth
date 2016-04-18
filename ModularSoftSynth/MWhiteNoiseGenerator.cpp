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
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            double dx = (double)currentTime / SAMPLE_RATE;
            float data = envelopeCoeff(dx) * (rand() / float(RAND_MAX));
            writeToOutputs(data);
//            output->writeData(data);
            
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