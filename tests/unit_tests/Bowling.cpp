//
// Created by younghyun on 18. 7. 19.
//

#include <vector>

#include "gtest/gtest.h"
#include "Bowling.h"

TEST(BOWLING, play) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<9 ;i++)
        pinFalls.push_back({10});
    pinFalls.push_back({10, 10, 10});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(300, score);
}

