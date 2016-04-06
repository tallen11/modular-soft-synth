//
//  ModuleInput.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleInput_hpp
#define ModuleInput_hpp

#include <string>
#include "ModuleDataBuffer.hpp"

class ModuleInput {
    
public:
    ModuleInput(const std::string &name);
    ModuleInput(const std::string &name, ModuleDataBuffer *inputDataBuffer);
    ~ModuleInput();
    const std::string& getName();
    void setDataBuffer(ModuleDataBuffer *inputDataBuffer);
    bool hasData();
    double readData();
    
private:
    std::string name;
    ModuleDataBuffer *dataBuffer;
};

#endif /* ModuleInput_hpp */
