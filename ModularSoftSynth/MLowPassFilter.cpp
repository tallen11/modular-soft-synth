//
//  MLowPassFilter.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MLowPassFilter.hpp"
#include <cmath>
#include <iostream>

MLowPassFilter::MLowPassFilter()
{
    hasInputs();
    hasOutput();
    dataInput = createInput("data");
    betaInput = createInput("beta");
}

MLowPassFilter::~MLowPassFilter()
{
    
}

void MLowPassFilter::update()
{
    if (isEnabled()) {        
        // y(i)= β∗x(i)+(1-β)∗y(i-1)
        
        size_t bufferSize = dataInput->getBufferSize();
        double data[bufferSize];
        for (int i = 0; i < bufferSize; ++i) {
            data[i] = dataInput->readData();
        }
        
        for (int i = 0; i < bufferSize; ++i) {
            float beta = 0.007;
            if (betaInput->canRead()) {
                beta = (1.0 * betaInput->readData() + 1.5) / 2.0;
            }
            
            float delayedSample = (i - 1) < 0 ? lastSample : data[i - 1];
            data[i] = beta * data[i] + (1.0 - beta) * delayedSample;
            output->writeData(data[i]);
        }
        
        lastSample = data[bufferSize - 1];
    } else {
        for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
            output->writeData(dataInput->readData());
        }
    }
}