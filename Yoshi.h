#ifndef YOSHI_H
#define YOSHI_H

#include "character.h"
#include <string>

class Yoshi : public Character {
public:
    // Constructor
    Yoshi();

    // Destructor
    ~Yoshi() override;

    // Implementation of the pure virtual function WhatAmI()
    std::string WhatAmI() const override;

    // Redefine Accelerate so that Yoshi accelerates faster
    void Accelerate() override;

    // Methods related to crests
    int get_crest() const;

private:
    int* crest_;
};

#endif // YOSHI_H
