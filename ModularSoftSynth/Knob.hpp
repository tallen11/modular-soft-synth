//
//  Knob.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef Knob_hpp
#define Knob_hpp

#include "ComponentBase.hpp"

class Knob : public ComponentBase {
    
public:
    Knob(float low, float high, float start);
    ~Knob();
    float currentValue();
    
private:
    void render();
    float lowValue;
    float highValue;
    float startValue;
};

#endif /* Knob_hpp */
