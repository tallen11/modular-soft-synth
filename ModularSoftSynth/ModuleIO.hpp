//
//  ModuleIO.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/5/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ModuleIO_hpp
#define ModuleIO_hpp

#include <queue>
#include <string>

class ModuleIO {
    
public:
    ModuleIO(const std::string &name);
    ~ModuleIO();
    const std::string& getName();
    void writeData(double data);
    bool hasData();
    double readData();
    
private:
    std::string name;
    std::queue<double> *buffer;
};

#endif /* ModuleIO_hpp */
