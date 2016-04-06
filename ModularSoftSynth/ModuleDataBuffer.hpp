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
    ModuleDataBuffer(const std::string &name);
    ~ModuleDataBuffer();
    const std::string& getName();
    void writeData(double data);
    bool hasData();
    double readData();
    
private:
    std::string name;
    std::queue<double> *buffer;
};

#endif /* ModuleDataBuffer_hpp */
