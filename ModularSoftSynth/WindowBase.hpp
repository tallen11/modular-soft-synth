//
//  WindowBase.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef WindowBase_hpp
#define WindowBase_hpp

#include <vector>
#include "Module.hpp"
#include "ComponentBase.hpp"

class WindowBase {
    
public:
    WindowBase(Module *module);
    ~WindowBase();
    void update();
    
protected:
    void addModuleComponent(ComponentBase *component);
    
private:
    void render();
    Module *module;
    std::vector<ComponentBase*> components;
};

#endif /* WindowBase_hpp */
