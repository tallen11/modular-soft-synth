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


int MFinal::callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    auto inputs = static_cast<DataInputs*>(userData);
    auto module = inputs->module;
    auto leftInput = inputs->leftInput;
    auto rightInput = inputs->rightInput;
    
    auto out = static_cast<float*>(output);
    for (unsigned long i = 0; i < frameCount; ++i) {
//        out[i] = dataInput->readData();
        if (leftInput->canRead()) {
            double leftData = leftInput->readData();
            *out++ = leftData;
            module->writeToOutputs(leftData);
            if (rightInput->canRead()) {
                *out++ = rightInput->readData();
            } else {
                *out++ = leftData;
            }
        } else {
            *out++ = 0.0f;
            *out++ = 0.0f;
        }
    }
    
    return 0;
}

MFinal::MFinal()
{
    this->hasInputs();
    this->hasOutput();
    this->leftDataInput = this->createInput("left");
    this->rightDataInput = this->createInput("right");
    this->inputs = new DataInputs;
    this->inputs->module = this;
    this->inputs->leftInput = leftDataInput;
    this->inputs->rightInput = rightDataInput;
    
    auto err = Pa_Initialize();
    if (err != paNoError) {
        std::cout << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }
    
    PaError streamError = Pa_OpenDefaultStream(&paStream, 0, 2, paFloat32, SAMPLE_RATE, /* paFramesPerBufferUnspecified */ MAX_BUFFER_SIZE, MFinal::callback, this->inputs);
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