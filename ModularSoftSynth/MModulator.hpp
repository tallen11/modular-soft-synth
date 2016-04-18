//
//  MModulator.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/12/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MModulator_hpp
#define MModulator_hpp

#include "Module.hpp"

class MModulator : public Module {
    
public:
    MModulator(double modFreq, double carFreq, double modIndex);
    ~MModulator();
    void update();
    
private:
//    ModuleInput *carrierInput;
//    ModuleInput *signalInput;
    ModuleInput *alphaInput;
    ModuleInput *betaInput;
    double modulationIndex;
    double modFrequency;
    double carrierFrequency;
};

#endif /* MModulator_hpp */
