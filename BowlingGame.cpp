// BowlingGame.cpp
#include "BowlingGame.h"

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() const {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (rolls[rollIndex] == 10) {  // Strike
            totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex += 1;
        } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {  // Spare
            totalScore += 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        } else {
            totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }

    return totalScore;
}

// main.cpp
#include <iostream>
#include "BowlingGame.h"

int main() {
    BowlingGame game;

    std::vector<int> sampleRolls = {5, 4, 1, 5, 6, 4, 10, 4, 5, 10, 10, 10, 2, 6};

    for (int pins : sampleRolls) {
        game.roll(pins);
    }

    std::cout << "Total score: " << game.score() << std::endl;

    return 0;
}
