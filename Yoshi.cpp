#include "Yoshi.h"
#include <iostream>

// Constructor: dynamically allocate the crest_ pointer and ask the user
Yoshi::Yoshi() : crest_(nullptr) {
    int nb_crests;
    std::cout << "Number of crests for your Yoshi? ";
    std::cin >> nb_crests;

    // Dynamically allocate the crest_ pointer
    crest_ = new int(nb_crests);
}

// Destructor: free the dynamically allocated memory
Yoshi::~Yoshi() {
    delete crest_;
    std::cout << "Yoshi destroyed\n";
}

// Implementation of WhatAmI
std::string Yoshi::WhatAmI() const {
    std::string s = crest_ ? std::to_string(*crest_) : "unknown";
    return s + " crested Yoshi";
}

// Redefinition of Accelerate
void Yoshi::Accelerate() {
    if (speed() <= max_speed() - 2) {
        speed_ += 2.0f;  // Faster acceleration for Yoshi
    } else if (speed() == max_speed() - 1) {
        speed_ += 1.0f;
    } else {
        std::cout << WhatAmI() << " cannot accelerate further; maximum speed reached.\n" << std::endl;
    }
}

// Get the number of crests
int Yoshi::get_crest() const {
    return crest_ ? *crest_ : 0; // Returns 0 if crest_ is not defined
}
