//
//  TestSynth.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "TestSynth.hpp"
#include "MOscillator.hpp"
#include "MFinal.hpp"

TestSynth::TestSynth()
{
    auto oscillator = new MOscillator();
    auto final = new MFinal();
    
    this->addModule(oscillator);
    this->addModule(final);
    this->connectModules(oscillator, final, "data");
}

TestSynth::~TestSynth()
{
    
}