#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "Mario.h"
#include "Yoshi.h"
#include "character_test.h"

// Displays the current state of a participant
void DisplayParticipantState(const Character* participant) {
    std::cout << participant->WhatAmI()
              << " - Speed: " << participant->speed()
              << " / Max Speed: " << Character::max_speed()
              << std::endl;
}

// Displays the state of all participants
void DisplayRaceState(const std::vector<Character*>& participants) {
    for (const auto& participant : participants) {
        DisplayParticipantState(participant);
    }
}

// First round with direct iterators
void FirstRound(std::vector<Character*>& participants) {
    std::cout << "\n=== First Round (initial acceleration) ===\n";

    // Using direct iterators to accelerate
    for (auto it = participants.begin(); it != participants.end(); ++it) {
        (*it)->Accelerate(); // Each participant accelerates once
        std::cout << (*it)->WhatAmI() << " accelerates.\n";
    }

    // Confirming that Yoshi accelerates faster
    std::cout << "\nAfter the first acceleration round:\n";
    DisplayRaceState(participants);

    // Comparing speeds using an indirect iterator
    auto fasterParticipant = participants.begin(); // Initialize iterator at the beginning
    for (auto it = participants.begin(); it != participants.end(); ++it) {
        if ((*it)->speed() > (*fasterParticipant)->speed()) {
            fasterParticipant = it;  // Update iterator to the fastest participant
        }
    }

    // Display the fastest participant
    std::cout << (*fasterParticipant)->WhatAmI() << " has better acceleration.\n";
}

// Second round of sprint with range-based loop
void SecondRound(const std::vector<Character*>& participants) {
    std::cout << "\n=== Second Round (Final Sprint) ===\n";

    bool raceOver = false;
    Character* winner = nullptr;

    // Display the state before the final sprint
    std::cout << "\nBefore the final sprint:\n";
    DisplayRaceState(participants);

    // Accelerate the participants until one reaches max speed
    while (!raceOver) {
        for (auto& participant : participants) {
            if (participant->speed() < Character::max_speed()) {
                participant->Accelerate();
                std::cout << participant->WhatAmI() << " accelerates.\n";
            }
            else {
                winner = participant;
                raceOver = true;
            }
        }
    }

    // Announce that the winner has reached maximum speed
    if (winner != nullptr) {
        winner->Accelerate();
    }

    // Display the state after the final sprint
    std::cout << "\nAfter the final sprint:\n";
    DisplayRaceState(participants);
}

int main() {
    // Creating the participants
    Mario mario;
    Yoshi yoshi;

    TestDefaultConstructor();
    TestAccelerate();
    TestBreak();
    TestMaxSpeed();
    TestBreakAtMaxSpeed();

    // Container for participants
    std::vector<Character*> raceParticipants = {&mario, &yoshi}; // Stack allocation, automatic memory management

    for (const auto& participant : raceParticipants) {
        std::cout << participant->WhatAmI() << " is ready for the race.\n";
    }

    // First round with initial acceleration
    FirstRound(raceParticipants);

    // Braking before the final sprint
    std::cout << "\nBefore the final sprint, participants brake.\n";
    for (auto& participant : raceParticipants) {
        participant->Break();
        std::cout << participant->WhatAmI() << " brakes.\n";
    }

    // Second round of sprint
    SecondRound(raceParticipants);

    return EXIT_SUCCESS;
}
