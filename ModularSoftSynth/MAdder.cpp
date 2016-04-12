//
//  MAdder.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/6/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MAdder.hpp"
#include <cmath>
#include <iostream>

MAdder::MAdder()
{
    hasInputs();
    hasOutput();
    wave1Input = createInput("wave1");
    wave2Input = createInput("wave2");
}

MAdder::~MAdder()
{
    
}

void MAdder::update()
{
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        double data1 = wave1Input->readData();
        double data2 = wave2Input->readData();
        output->writeData(data1 + data2);
    }
}