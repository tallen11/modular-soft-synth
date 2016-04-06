//
//  main.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "TestSynth.hpp"

int main(int argc, const char * argv[]) {
    
    auto synth = TestSynth();
    while (true) {
        synth.update();
    }
    
    return 0;
}
