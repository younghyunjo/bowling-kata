//
// Created by younghyun on 18. 7. 19.
//


#include <vector>

#include "gtest/gtest.h"
#include "Frame.h"

TEST(Frame, roll) {
    std::vector<int> input = {1, 0};

    Frame f;
    f._rool(input);
    int score = f._getScore();
    EXPECT_EQ(1, score);

    Frame::State s = f.getState();
    EXPECT_EQ(Frame::State::REMAINED, s);
}

TEST(Frame, spareState) {
    std::vector<int> input= {9, 1};

    Frame f;
    f._rool(input);

    int score = f._getScore();
    EXPECT_EQ(10, score);

    Frame::State s = f.getState();
    EXPECT_EQ(Frame::State::SPARE, s);
}

TEST(Frame, spareBonusPoint) {
    std::vector<int> input = {9, 1};

    Frame f;
    f._rool(input);

    std::vector<int> nextFrameRoll = {1, 0};
    f._getBonux(nextFrameRoll);

    int score = f._getScore();
    EXPECT_EQ(11, score);
}

TEST(Frame, spareBonusPointTwice) {
    std::vector<int> input = {9, 1};

    Frame f;
    f._rool(input);

    std::vector<int> nextFrameRoll = {1, 0};
    f._getBonux(nextFrameRoll);
    f._getBonux(nextFrameRoll);

    int score = f._getScore();
    EXPECT_EQ(11, score);
}
