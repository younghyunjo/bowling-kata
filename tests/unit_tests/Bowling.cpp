//
// Created by younghyun on 18. 7. 19.
//

#include <vector>

#include "gtest/gtest.h"
#include "Bowling.h"

TEST(BOWLING, perfect) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<9 ;i++)
        pinFalls.push_back({10});
    pinFalls.push_back({10, 10, 10});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(300, score);
}

TEST(BOWLING, zero) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<10 ;i++)
        pinFalls.push_back({0});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(0, score);
}

TEST(BOWLING, allThree) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<10 ;i++)
        pinFalls.push_back({3,3});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(60, score);
}

TEST(BOWLING, allSparesWith4) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<9 ;i++)
        pinFalls.push_back({4,6});

    pinFalls.push_back({4,6,4});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(140, score);
}

TEST(BOWLING, nineStrikesLastIsGutter) {
    Bowling game;

    std::vector<std::vector<int>> pinFalls;
    for (int i=0; i<9 ;i++)
        pinFalls.push_back({10});

    pinFalls.push_back({0, 0});

    game.play(pinFalls);
    int score = game.getScore();

    EXPECT_EQ(240, score);
}
