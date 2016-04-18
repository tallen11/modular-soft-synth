//
//  MTriadGenerator.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MTriadGenerator.hpp"
#include <cmath>

MTriadGenerator::MTriadGenerator(double freq1, double freq2, double freq3)
{
    this->hasOutput();
    this->lastIndex = 0;
    this->freq1 = freq1;
    this->freq2 = freq2;
    this->freq3 = freq3;
}

MTriadGenerator::~MTriadGenerator()
{
    
}

void MTriadGenerator::update()
{
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        if (isEnabled()) {
            double dx = ((double)lastIndex / SAMPLE_RATE);
            double data = sin(2.0 * M_PI * this->freq1 * dx);
            data += sin(2.0 * M_PI * this->freq2 * dx);
            data += sin(2.0 * M_PI * this->freq3 * dx);
            writeToOutputs(data);
//            this->output->writeData(data);
            lastIndex++;
        } else {
            writeToOutputs(0.0);
//            this->output->writeData(0.0);
        }
    }
}