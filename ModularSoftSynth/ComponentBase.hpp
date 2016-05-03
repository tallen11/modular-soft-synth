//
//  ComponentBase.hpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 5/2/16.
//  Copyright © 2016 tate. All rights reserved.
//

#ifndef ComponentBase_hpp
#define ComponentBase_hpp

class ComponentBase {
    
public:
    ComponentBase();
    ~ComponentBase();
    virtual void update();
    
protected:
    virtual void render() = 0;
};

#endif /* ComponentBase_hpp */
