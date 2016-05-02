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
    MWavPlayer(const std::string &filePath);
    ~MWavPlayer();
    void update();
    
private:
    double *buffer;
    int sampleRate = 0;
    int currentSampleIndex = 0;
    sf_count_t sampleCount = 0;
    int channelCount = 0;
};

#endif /* MWavPlayer_hpp */
