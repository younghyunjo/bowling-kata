//
// Created by younghyun on 18. 8. 7.
//

#pragma once

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

#include "Throw.h"


class Frame {
public:
    Frame() {}
    Frame(std::vector<int> pinfalls) {
        std::for_each(std::begin(pinfalls), std::end(pinfalls), [this](int p) {
            currentScore += p;
        });
    }

    auto roll(int pinfalls) -> bool {
        if (numberOfThrow++ != Throw::done)
            currentScore += pinfalls;

        // No Strike, No Spare
        if (numberOfThrow >= Throw::twice && currentScore < 10) {
            numberOfThrow = Throw::done;
        }

        if (numberOfThrow == Throw::done)
            return false;
        return true;
    }

    auto score() -> int {
        return currentScore;
    }

private:
    int currentScore = 0;
    Throw numberOfThrow = Throw::none;
};
