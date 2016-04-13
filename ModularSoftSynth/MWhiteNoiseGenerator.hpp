//
//  MWhiteNoiseGenerator.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MWhiteNoiseGenerator_hpp
#define MWhiteNoiseGenerator_hpp

#include "Module.hpp"

class MWhiteNoiseGenerator : public Module {

public:
    MWhiteNoiseGenerator();
    ~MWhiteNoiseGenerator();
    void update();
};

#endif /* MWhiteNoiseGenerator_hpp */
