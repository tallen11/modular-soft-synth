//
//  ModuleOutput.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleOutput_hpp
#define ModuleOutput_hpp

#include "ModuleDataBuffer.hpp"

class ModuleOutput {
    
public:
    ModuleOutput();
    ModuleOutput(ModuleDataBuffer *outputDataBuffer);
    ~ModuleOutput();
    void setDataBuffer(ModuleDataBuffer *outputDataBuffer);
    void writeData(double data);
    
private:
    ModuleDataBuffer *dataBuffer;
};

#endif /* ModuleOutput_hpp */
