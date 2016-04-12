//
//  MFinal.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MFinal_hpp
#define MFinal_hpp

#include "Module.hpp"
#include "portaudio.h"

class MFinal : public Module {
    
public:
    MFinal();
    ~MFinal();
    void update();
    
private:
    static int callback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
    
    ModuleInput *dataInput;
    PaStream *paStream;
};

#endif /* MFinal_hpp */
