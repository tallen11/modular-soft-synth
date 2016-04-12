//
//  MAdder.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/6/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MAdder_hpp
#define MAdder_hpp

#include "Module.hpp"

class MAdder : public Module {
    
public:
    MAdder();
    ~MAdder();
    void update();
    
private:
    ModuleInput *wave1Input;
    ModuleInput *wave2Input;
};

#endif /* MAdder_hpp */
