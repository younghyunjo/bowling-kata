//
// Created by younghyun on 18. 7. 19.
//


#include <vector>

#include "gtest/gtest.h"
#include "Frame.h"

TEST(Frame, roll) {
    std::vector<int> input = {1, 0};

    Frame f;
    f.roll(input);
    int score = f.getScore();
    EXPECT_EQ(1, score);
}