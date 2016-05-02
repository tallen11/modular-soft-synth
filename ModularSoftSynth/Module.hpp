//
//  Module.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Module_hpp
#define Module_hpp

#include <vector>
#include <string>
#include <iostream>
#include "ModuleInput.hpp"
#include "ModuleOutput.hpp"

#define MAX_BUFFER_SIZE 1024
#define SAMPLE_RATE 44100

// 44100

class Module {
    
public:
    Module() { };
    virtual ~Module() { };
    virtual void update() = 0;
    
    void hasInputs() { this->inputs = new std::vector<ModuleInput*>(); };
    void hasOutput() { this->outputs = new std::vector<ModuleOutput*>(); };
    
    ModuleInput* createInput(const std::string &name) {
        auto input = new ModuleInput(name);
        inputs->push_back(input);
        return input;
    };
    
    ModuleOutput* createOutput() {
        ModuleOutput *output = new ModuleOutput();
        this->outputs->push_back(output);
        return output;
    }
    
    ModuleInput* getInputNamed(const std::string &name) {
        for (auto input : *this->inputs) {
            if (input->getName() == name) {
                return input;
            }
        }
        
        return nullptr;
    };
    
    size_t getBufferSize()
    {
        auto out = static_cast<ModuleOutput*>(outputs->front());
        return out->getBufferSize();
    }
    
    void writeToOutputs(double data)
    {
        for (auto out : *this->outputs) {
            out->writeData(data);
        }
    }
    
    inline double envelopeCoeff(double dx)
    {
//        return 1.0;
        
        if (dx >= 130.0) {
            return 1.0;
        }
        
        return -(1.0 / (dx+1)) + 1.0;
    }
    
    bool isEnabled()
    {
        return this->enabled;
    }
    
    void setEnabled(bool onState)
    {
        this->enabled = onState;
    }
    
protected:
    std::vector<ModuleInput*> *inputs = nullptr;
    std::vector<ModuleOutput*> *outputs = nullptr;
    bool enabled = true;
    uint64_t currentTime = 0;
};

#endif /* Module_hpp */
