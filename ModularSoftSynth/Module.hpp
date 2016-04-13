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
#include "ModuleInput.hpp"
#include "ModuleOutput.hpp"

#define MAX_BUFFER_SIZE 1000
#define SAMPLE_RATE 44100

class Module {
    
public:
    Module() { };
    virtual ~Module() { };
    virtual void update() = 0;
    
    void hasInputs() { this->inputs = new std::vector<ModuleInput*>(); };
    void hasOutput() { this->output = new ModuleOutput(); };
    
    ModuleInput* createInput(const std::string &name) {
        auto input = new ModuleInput(name);
        this->inputs->push_back(input);
        return input;
    };
    
    ModuleOutput* getOutput() {
        return this->output;
    }
    
    ModuleInput* getInputNamed(const std::string &name) {
        for (auto input : *this->inputs) {
            if (input->getName() == name) {
                return input;
            }
        }
        
        return nullptr;
    };
    
    inline double envelopeCoeff(double dx)
    {
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
    ModuleOutput *output = nullptr;
    bool enabled = true;
    uint64_t currentTime = 0;
};

#endif /* Module_hpp */
