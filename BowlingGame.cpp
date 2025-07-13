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
