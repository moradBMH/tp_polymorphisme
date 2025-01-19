#include "character.h"

// Definition of the static variable
float Character::max_speed_ = 10.0f;

// Default constructor
Character::Character() : speed_(0) {}

// Destructor
Character::~Character() { std::cout << "Character destroyed\n"; }

// Increments the speed up to the maximum speed
void Character::Accelerate() {
    if (speed_ < max_speed_) {
        speed_ += 1.0f;
    }
    else {
        std::cout << WhatAmI() << " cannot accelerate further; maximum speed reached.\n" << std::endl;
    }
}

// Reduces the speed to 0
void Character::Break() {
    if (speed_ > 0) {
        speed_ -= 1.0f;
    }
}
