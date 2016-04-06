//
//  MValue.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/6/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MValue_hpp
#define MValue_hpp

#include "Module.hpp"

class MValue : public Module {
    
public:
    MValue(double value);
    ~MValue();
    void update();
    
private:
    double value;
};

#endif /* MValue_hpp */
