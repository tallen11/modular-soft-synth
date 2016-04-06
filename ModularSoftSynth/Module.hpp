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

class Module {
    
public:
    Module() {
        this->outputs = new std::vector<Module*>();
    };
    
    virtual ~Module() { };
    virtual void update() = 0;
    
protected:
    std::vector<Module*> *outputs;
};

#endif /* Module_hpp */
