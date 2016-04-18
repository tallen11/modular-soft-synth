//
//  MWavPlayer.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MWavPlayer_hpp
#define MWavPlayer_hpp

#include "Module.hpp"
#include <string>
#include "sndfile.hh"

class MWavPlayer : public Module {
    
public:
    MWavPlayer(const std::string &filePath, int loops);
    ~MWavPlayer();
    void update();
    
private:
    double *buffer;
    int currentSampleIndex = 0;
    int sampleCount = 0;
    int channelCount = 0;
    int loops;
};

#endif /* MWavPlayer_hpp */
