//
//  MPulser.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/19/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MPulser_hpp
#define MPulser_hpp

#include "Module.hpp"

class MPulser : public Module {
    
public:
    MPulser(int pulseLength, int quietLength);
    ~MPulser();
    void update();
    
private:
    ModuleInput *dataInput;
    int pulseLength;
    int quietLength;
    bool isLoud;
    int cycleLength;
};

#endif /* MPulser_hpp */
