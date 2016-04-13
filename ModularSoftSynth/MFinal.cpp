//
//  MFinal.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MFinal.hpp"
#include <iostream>
#include <cmath>

float lastHighest = 0.0;

int MFinal::callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    auto dataInput = static_cast<ModuleInput*>(userData);
//    double data[frameCount];
//    double maxAmpl = 0.0;
//    for (unsigned long i = 0; i < frameCount; ++i) {
//        data[i] = dataInput->readData();
//        if (fabs(data[i]) > maxAmpl) {
//            maxAmpl = fabs(data[i]);
//        }
//    }
    
    auto out = static_cast<float*>(output);
    for (unsigned long i = 0; i < frameCount; ++i) {
        out[i] = dataInput->readData(); // 1.0 * (float)(data[i] / (float)(maxAmpl + lastHighest) / 2.0);
//        std::cout << out[i] << std::endl;
    }
    
//    lastHighest = maxAmpl;
//    std::cout << "=" << std::endl;
    
    return 0;
}

MFinal::MFinal()
{
    this->hasInputs();
    this->dataInput = this->createInput("data");
    
    auto err = Pa_Initialize();
    if (err != paNoError) {
        std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }
    
    PaError streamError = Pa_OpenDefaultStream(&paStream, 0, 1, paFloat32, 44100, /* paFramesPerBufferUnspecified */ MAX_BUFFER_SIZE, MFinal::callback, this->dataInput);
    if (streamError != paNoError) {
        std::cout << "PortAudio stream error: " << Pa_GetErrorText(streamError) << std::endl;
    }
    
    PaError startError = Pa_StartStream(paStream);
    if (startError != paNoError) {
        std::cout << "PortAudio stream start error: " << Pa_GetErrorText(startError) << std::endl;
    }
}

MFinal::~MFinal()
{
    
}

void MFinal::update()
{
    
}