//
//  ModuleDataBuffer.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleDataBuffer_hpp
#define ModuleDataBuffer_hpp

#include <queue>
#include <string>

class ModuleDataBuffer {
    
public:
    ModuleDataBuffer();
    ~ModuleDataBuffer();
    void writeData(double data);
    bool hasData();
    double readData();
    
private:
    std::queue<double> *buffer;
};

#endif /* ModuleDataBuffer_hpp */
