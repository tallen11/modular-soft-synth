//
//  TestSynth.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "TestSynth.hpp"
#include "MOscillator.hpp"
#include "MAdder.hpp"
#include "MFinal.hpp"

#define C1 32.703
#define D1 36.708
#define E1 41.203
#define F1 43.654
#define G1 48.999
#define A1 55.000
#define B1 61.735

TestSynth::TestSynth()
{
    auto oscillator = new MOscillator(C1 * 7.0);
    auto oscillator2 = new MOscillator(C1 * 7.1);
    auto oscillator3 = new MOscillator(C1 * 7.0);
    auto adder = new MAdder();
    auto finalAdder = new MAdder();
    auto final = new MFinal();
    
    this->addModule(oscillator);
    this->addModule(oscillator2);
    this->addModule(oscillator3);
    this->addModule(adder);
    this->addModule(finalAdder);
    this->addModule(final);

    this->connectModules(oscillator, adder, "wave1");
    this->connectModules(oscillator2, adder, "wave2");
    this->connectModules(adder, finalAdder, "wave1");
    this->connectModules(oscillator3, finalAdder, "wave2");
    this->connectModules(finalAdder, final, "data");
}

TestSynth::~TestSynth()
{
    
}