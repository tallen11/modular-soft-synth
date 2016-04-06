//
//  ModuleInput.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleInput_hpp
#define ModuleInput_hpp

#include "ModuleDataBuffer.hpp"

class ModuleInput {
    
public:
    ModuleInput();
    ModuleInput(ModuleDataBuffer *inputDataBuffer);
    ~ModuleInput();
    void setDataBuffer(ModuleDataBuffer *inputDataBuffer);
    bool hasData();
    double readData();
    
private:
    ModuleDataBuffer *dataBuffer;
};

#endif /* ModuleInput_hpp */
