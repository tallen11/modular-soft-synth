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
        float data = rand() / float(RAND_MAX);
        output->writeData(0.8 * data);
    }
}