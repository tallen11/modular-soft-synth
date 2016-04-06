//
//  MOscillator.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MOscillator_hpp
#define MOscillator_hpp

#include "Module.hpp"

class MOscillator : public Module {
    
public:
    MOscillator();
    MOscillator(double frequency);
    ~MOscillator();
    void update();
    
private:
    ModuleInput *frequencyInput;
    ModuleInput *amplitudeInput;
    int lastIndex;
};

#endif /* MOscillator_hpp */
