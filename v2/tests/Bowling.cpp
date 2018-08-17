//
// Created by younghyun on 18. 8. 7.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "gtest/gtest.h"

#include "Bowling.h"


class BowlingTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    const std::vector<std::vector<int>> singlePins{10, std::vector<int>{1, 0}};
    Bowling bowling;
};

TEST_F(BowlingTest, Bowling) {
    bowling.play(singlePins);
    int score = bowling.score();

    EXPECT_EQ(10, score);
}

TEST_F(BowlingTest, Perfect) {
    std::vector<std::vector<int>> perfectPins{9, std::vector<int>{10}};
    perfectPins.push_back(std::vector<int>{10, 10, 10});

    bowling.play(perfectPins);
    int score = bowling.score();

    EXPECT_EQ(300, score);
}

TEST_F(BowlingTest, Spares) {
    std::vector<std::vector<int>> perfectPins{9, std::vector<int>{9, 1}};
    perfectPins.push_back(std::vector<int>{9, 0});

    bowling.play(perfectPins);
    int score = bowling.score();

    EXPECT_EQ(180, score);
}

TEST_F(BowlingTest, Zero) {
    std::vector<std::vector<int>> perfectPins{10, std::vector<int>{0, 0}};

    bowling.play(perfectPins);
    int score = bowling.score();

    EXPECT_EQ(0, score);
}

