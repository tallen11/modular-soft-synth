//
//  MLowPassFilter.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MLowPassFilter_hpp
#define MLowPassFilter_hpp

#include "Module.hpp"

class MLowPassFilter : public Module {
    
public:
    MLowPassFilter();
    ~MLowPassFilter();
    void update();
    
private:
    ModuleInput *dataInput;
    ModuleInput *betaInput;
    double lastSample = 0.0;
};

#endif /* MLowPassFilter_hpp */
