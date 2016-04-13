//
//  MTriadGenerator.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/11/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef MTriadGenerator_hpp
#define MTriadGenerator_hpp

#include "Module.hpp"

class MTriadGenerator : public Module {
    
public:
    MTriadGenerator(double freq1, double freq2, double freq3);
    ~MTriadGenerator();
    void update();
    
private:
    uint64_t lastIndex;
    double freq1;
    double freq2;
    double freq3;
};

#endif /* MTriadGenerator_hpp */
