// BowlingGame.cpp
#include "BowlingGame.h"

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() const {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10 && rollIndex < rolls.size(); ++frame) {
        if (rolls[rollIndex] == 10) {  // Strike
            if (rollIndex + 2 < rolls.size()) {
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            }
            rollIndex += 1;
        }
        else if (rollIndex + 1 < rolls.size() && rolls[rollIndex] + rolls[rollIndex + 1] == 10) {  // Spare
            if (rollIndex + 2 < rolls.size()) {
                totalScore += 10 + rolls[rollIndex + 2];
            }
            rollIndex += 2;
        }
        else if (rollIndex + 1 < rolls.size()) {  // Open frame
            totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
        else {
            break; // Not enough data to compute
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
