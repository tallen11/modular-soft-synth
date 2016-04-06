//
//  Synth.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Synth_hpp
#define Synth_hpp

#include <vector>
#include "Module.hpp"

class Synth {
    
public:
    Synth();
    ~Synth();
    void update();
    void addModule(Module *module);
    void removeModule(Module *module);
    void connectModules(Module *outputModule, Module *inputModule);
    
private:
    std::vector<Module*> *modules;
};

#endif /* Synth_hpp */
