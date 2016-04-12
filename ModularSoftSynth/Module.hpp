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

#define MAX_BUFFER_SIZE (100)
#define SAMPLE_RATE (44100);

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
    
protected:
    std::vector<ModuleInput*> *inputs = nullptr;
    ModuleOutput *output = nullptr;
};

#endif /* Module_hpp */
