//
//  MOscillator.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MOscillator.hpp"

MOscillator::MOscillator()
{
    this->createInput("frequency"); // The desired frequency of the sine wave
    this->createInput("amplitude"); // The desired max amplitude of the sine wave
}

MOscillator::~MOscillator()
{
    
}

void MOscillator::update()
{
    
}