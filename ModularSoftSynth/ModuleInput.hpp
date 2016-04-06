//
//  ModuleInput.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleInput_hpp
#define ModuleInput_hpp

#include <queue>

class ModuleInput {
    
public:
    ModuleInput();
    ~ModuleInput();
    void writeData(double data);
    
private:
    std::queue<double> buffer;
};

#endif /* ModuleInput_hpp */
