//
// Created by younghyun on 18. 8. 8.
//

#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <iostream>
#include <vector>

#include "Throw.h"

class ImmutableFrame {
public:
    ImmutableFrame() : currentScore(0), numberOfThrow(Throw::none) {}
    ImmutableFrame(int score, Throw tthrow) : currentScore(score), numberOfThrow(tthrow) {

    }

    auto roll(int pinfalls) {
        std::vector<int> _pinfalls{pinfalls};
        return roll(_pinfalls);
    }

    auto roll(std::vector<int> pinfalls) -> std::unique_ptr<ImmutableFrame> {
        std::remove_if(std::begin(pinfalls), std::end(pinfalls), [](int n){
            return n< 0;
        });


        if ((currentScore < 10 && numberOfThrow == Throw::twice) || numberOfThrow == Throw::done) {
            return std::make_unique<ImmutableFrame>(currentScore, Throw::done);
        }

        int newScore = std::accumulate(std::begin(pinfalls), std::end(pinfalls), currentScore);
        Throw newThrow = numberOfThrow + pinfalls.size();
//        std::cout << "Throw:" << newThrow << std::endl;

        return std::make_unique<ImmutableFrame>(newScore, newThrow);
    }

    auto score() -> const int& {
        return currentScore;
    }

private:
    const int currentScore;
    const Throw numberOfThrow;
};
