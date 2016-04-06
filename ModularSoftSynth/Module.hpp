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

class Module {
    
public:
    Module() {
        this->inputs = std::vector<ModuleInput*>();
    };
    
    virtual ~Module() {
    
    };
    
    virtual void update() = 0;
    
    void createInput(const std::string &name) {
        auto input = new ModuleInput(name);
        this->inputs.push_back(input);
    };
    
protected:
    std::vector<ModuleInput*> inputs;
    ModuleOutput *output;
};

#endif /* Module_hpp */
