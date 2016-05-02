//
//  MPulser.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/19/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MPulser.hpp"

MPulser::MPulser(int pulseLength, int quietLength)
{
    hasInputs();
    hasOutput();
    dataInput = createInput("data");
    
    this->pulseLength = pulseLength;
    this->quietLength = quietLength;
    this->isLoud = true;
    this->cycleLength = 0;
}

MPulser::~MPulser()
{
    
}

void MPulser::update()
{
    if (isEnabled()) {
        while (dataInput->canRead()) {
            if (isLoud) {
                writeToOutputs(dataInput->readData());
                cycleLength++;
                if (cycleLength > pulseLength) {
                    isLoud = false;
                    cycleLength = 0;
                }
            } else {
                writeToOutputs(0.0);
                cycleLength++;
                if (cycleLength > quietLength) {
                    isLoud = true;
                    cycleLength = 0;
                }
            }
        }
    }
}
