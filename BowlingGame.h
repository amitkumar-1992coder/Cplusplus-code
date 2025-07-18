// BowlingGame.h
#pragma once  // BowlingGame.h

#include <vector>

class BowlingGame {
public:
    void roll(int pins);
    int score() const;

private:
    std::vector<int> rolls;
};



