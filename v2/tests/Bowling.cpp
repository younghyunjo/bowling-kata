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
        /*
        std::for_each(std::begin(singlePins), std::end(singlePins), [] (std::vector<int> pins){
            std::for_each(std::begin(pins), std::end(pins), [](int p) {
                std::cout << p << std::endl;
            });
            std::cout << std::endl;
        });
        */
    }

    void TearDown() override {
    }

    const std::vector<std::vector<int>> singlePins{10, std::vector<int>{1, 0}};
    std::unique_ptr<Bowling> bowling;
};

TEST_F(BowlingTest, Bowling) {
    bowling->play(singlePins);
    int score = bowling->score();

    EXPECT_EQ(10, score);
}