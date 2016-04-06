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

#define MAX_BUFFER_SIZE 1000

class ModuleOutput {
    
public:
    ModuleOutput();
    ModuleOutput(ModuleDataBuffer *outputDataBuffer);
    ~ModuleOutput();
    void setDataBuffer(ModuleDataBuffer *outputDataBuffer);
    bool canWrite();
    size_t getBufferSize();
    void writeData(double data);
    
private:
    ModuleDataBuffer *dataBuffer;
};

#endif /* ModuleOutput_hpp */
