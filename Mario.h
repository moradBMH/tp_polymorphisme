#ifndef MARIO_H
#define MARIO_H

#include "character.h"
#include <string>

class Mario : public Character {
public:
    // Implementation of the pure virtual function WhatAmI()
    std::string WhatAmI() const override {
        return "Mario";
    }
};
// No need to define an explicit constructor/destructor for Mario, the default management is sufficient.
// But if dynamic resources are introduced into Mario,
// a destructor will need to be defined to prevent memory leaks.
#endif // MARIO_H
