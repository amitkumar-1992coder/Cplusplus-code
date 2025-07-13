// BowlingGame.h
#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H  // or use #pragma once

#include <vector>

class BowlingGame {
public:
    void roll(int pins);
    int score() const;

private:
    std::vector<int> rolls;
};

#endif // BOWLINGGAME_H
