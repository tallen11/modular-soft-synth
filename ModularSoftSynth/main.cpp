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

const static int SAMPLES_PER_SEC = 44100;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    auto synth = TestSynth();
    
    auto lastTime = std::chrono::high_resolution_clock::now();
    uint64_t x = 0;
    while (true) {
        auto time = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(time-lastTime).count();
        if (diff >= 22675.7) {
//            std::cout << "DIFF: " << x << std::endl;
            synth.update((double)x / SAMPLES_PER_SEC);
            
            x++;
            if (x == INT64_MAX) {
                x = 0;
            }
            
            lastTime = time;
        }
    }
    
    return 0;
}
