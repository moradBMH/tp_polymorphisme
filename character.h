#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
protected:
    float speed_; // Current speed
    static float max_speed_; // Maximum speed

public:
    // Default constructor
    Character();

    // Destructor
    virtual ~Character();

    // Methods
    virtual void Accelerate(); // Increases the speed. Virtual to allow override
    void Break();      // Reduces the speed

    // Accessor for speed
    auto speed() const { return speed_; }
    static float max_speed() { return max_speed_; }

    // The compiler detects a pure virtual function
    // => The virtual table is generated for Character
    // => The entry in the table for WhatAmI(), not implemented, points to nullptr
    // => The Character class is abstract
    // => It is impossible to instantiate an object of this class directly
    // => Implement WhatAmI() in every derived class, otherwise it remains abstract and non-instantiable
    virtual std::string WhatAmI() const = 0;
};

#endif // CHARACTER_H
