//
//  TestSynth.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "TestSynth.hpp"
#include "MValue.hpp"
#include "MOscillator.hpp"
#include "MWhiteNoiseGenerator.hpp"
#include "MAdder.hpp"
#include "MLowPassFilter.hpp"
#include "MTriadGenerator.hpp"
#include "MModulator.hpp"
#include "MFinal.hpp"
#include "MDisplay.hpp"
#include "MWavPlayer.hpp"
#include <cmath>

#define C1 32.703
#define D1 36.708
#define E1 41.203
#define F1 43.654
#define G1 48.999
#define A1 55.000
#define B1 61.735

TestSynth::TestSynth()
{
//    /* Basic Sine Waves */
//    auto oscillator = new MOscillator(220.0);
//    auto final = new MFinal();
//    
//    addModule(oscillator);
//    addModule(final);
//    
//    connectModules(oscillator, final, "left");

    /* Wav Files w/ Display */
    auto player = new MWavPlayer("/Users/tateallen/Desktop/loop1.wav", 2);
    auto lpfOscillator = new MOscillator(0.25);
    auto lpf = new MLowPassFilter();
    auto final = new MFinal();
    auto display = new MDisplay();
    
    lpfOscillator->setEnabled(false);
    lpf->setEnabled(false);
    
    addModule(player);
    addModule(lpfOscillator);
    addModule(lpf);
    addModule(final);
    addModule(display);
    
    connectModules(lpfOscillator, lpf, "beta");
    connectModules(player, lpf, "data");
    connectModules(lpf, final, "left");
    connectModules(lpf, display, "left");
    
//    /* FM Sound */
//    double carrier = 440.0;
//    auto fm = new MModulator(carrier * 1.5, carrier, 1.0);
//    auto alphaValue = new MValue(0.5);
//    auto betaValue = new MValue(0.5);
//    auto final = new MFinal();
//    
//    addModule(alphaValue);
//    addModule(betaValue);
//    addModule(fm);
//    addModule(final);
//    
//    connectModules(alphaValue, fm, "alpha");
//    connectModules(betaValue, fm, "beta");
//    connectModules(fm, final, "left");
    
//    /* Frequency Modulated Beats */
//    auto fm = new MModulator(2.0, 440.0, 25.0);
//    auto fm2 = new MModulator(2.0, 460.0, 25.0);
//    auto adder = new MAdder();
//    auto final = new MFinal();
//    
//    addModule(fm);
//    addModule(fm2);
//    addModule(adder);
//    addModule(final);
//    
//    connectModules(fm, adder, "wave1");
//    connectModules(fm2, adder, "wave2");
//    connectModules(adder, final, "left");
    
//    /* FM Sound with Modified Coefficients */
//    auto osc = new MOscillator(0.5);
//    auto osc2 = new MOscillator(1.0);
//    auto fm = new MModulator(2.0, 440.0, 25.0);
//    auto final = new MFinal();
//    
//    addModule(osc);
//    addModule(osc2);
//    addModule(fm);
//    addModule(final);
//    
//    connectModules(osc, fm, "alpha");
//    connectModules(osc2, fm, "beta");
//    connectModules(fm, final, "left");
    
//    /* FM with Value Coefficient */
//    auto value = new MValue(1.0);
//    auto fm = new MModulator(2.0, 440.0, 25.0);
//    auto final = new MFinal();
//    
//    addModule(value);
//    addModule(fm);
//    addModule(final);
//    
//    connectModules(value, fm, "beta");
//    connectModules(fm, final, "left");
    
//    /* Triads Testing */
//    auto triads = new MTriadGenerator(C1 * 7.0, E1 * 7.0, G1 * 7.0);
//    auto final = new MFinal();
//    
//    addModule(triads);
//    addModule(final);
//    
//    connectModules(triads, final, "left");
    
//    /* Low Pass Filtered White Noise */
//    auto noise = new MWhiteNoiseGenerator();
//    auto lpFilter = new MLowPassFilter();
//    auto final = new MFinal();
//    
//    lpFilter->setEnabled(true);
//    
//    addModule(noise);
//    addModule(lpFilter);
//    addModule(final);
//    
//    connectModules(noise, lpFilter, "data");
//    connectModules(lpFilter, final, "left");
    
//    /* Additive Synthesis */
//    auto noise = new MWhiteNoiseGenerator();
//    auto oscillator = new MOscillator(C1 * 7.0);
//    auto oscillator2 = new MOscillator(E1 * 7.0);
//    auto oscillator3 = new MOscillator(G1 * 7.0);
//    auto adder = new MAdder();
//    auto finalAdder = new MAdder();
//    auto betaOscillator = new MOscillator(1.0);
//    auto lpFilter = new MLowPassFilter();
//    auto final = new MFinal();
//    
//    noise->setEnabled(true);
//    oscillator->setEnabled(true);
//    oscillator2->setEnabled(true);
//    oscillator3->setEnabled(true);
//    adder->setEnabled(true);
//    finalAdder->setEnabled(true);
//    betaOscillator->setEnabled(true);
//    lpFilter->setEnabled(true);
//    final->setEnabled(true);
//    
//    this->addModule(oscillator);
//    this->addModule(oscillator2);
//    this->addModule(oscillator3);
//    this->addModule(adder);
//    this->addModule(finalAdder);
//    this->addModule(betaOscillator);
//    this->addModule(lpFilter);
//    this->addModule(final);
//
//    this->connectModules(oscillator, adder, "wave1");
//    this->connectModules(oscillator2, adder, "wave2");
//    this->connectModules(adder, finalAdder, "wave1");
//    this->connectModules(oscillator3, finalAdder, "wave2");
//    this->connectModules(finalAdder, lpFilter, "data");
//    this->connectModules(betaOscillator, lpFilter, "beta");
//    this->connectModules(lpFilter, final, "left");
}

TestSynth::~TestSynth()
{
    
}