#include <iostream>
#include "character_test.h"

void TestDefaultConstructor() {
    Mario t;
    if (t.speed() == 0.0f) {
        std::cout << "TestDefaultConstructor PASSED\n";
    } else {
        std::cout << "TestDefaultConstructor FAILED\n";
    }
}

void TestAccelerate() {
    Mario t;
    t.Accelerate(); // Increases speed by 1
    if (t.speed() == 1.0f) {
        std::cout << "TestAccelerate PASSED\n";
    } else {
        std::cout << "TestAccelerate FAILED\n";
    }
}

void TestBreak() {
    Mario t;
    t.Accelerate(); // Increases speed by 1
    t.Break();      // Decreases speed by 1
    if (t.speed() == 0.0f) {
        std::cout << "TestBreak PASSED\n";
    } else {
        std::cout << "TestBreak FAILED\n";
    }
}

void TestMaxSpeed() {
    Mario t;
    for (int i = 0; i < 11; ++i) {
        t.Accelerate();
    }
    if (t.speed() == t.max_speed()) {
        std::cout << "TestMaxSpeed PASSED\n";
    } else {
        std::cout << "TestMaxSpeed FAILED\n";
    }
}

void TestBreakAtMaxSpeed() {
    Mario t;
    for (int i = 0; i < 11; ++i) {
        t.Accelerate();
    }
    t.Break();
    if (t.speed() == 9.0f) {
        std::cout << "TestBreakAtMaxSpeed PASSED\n";
    } else {
        std::cout << "TestBreakAtMaxSpeed FAILED\n";
    }
}
