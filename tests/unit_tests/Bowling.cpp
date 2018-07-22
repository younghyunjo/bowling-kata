//
// Created by younghyun on 18. 7. 19.
//

#include <vector>

#include "gtest/gtest.h"
#include "Bowling.h"

TEST(BOWLING, play) {
    std::vector<std::vector<int>> input;
    for (int i=0; i<10; i++)
        input.push_back({1, 0});

    Bowling b;
    int score = b.play(input);
    EXPECT_EQ(10, score);
}

TEST(BOWLING, playWithSpare) {
    std::vector<std::vector<int>> input;
    input.push_back({1, 9});
    for (int i=1; i<10; i++)
        input.push_back({1, 0});



    Bowling b;
    int score = b.play(input);
    EXPECT_EQ(20, score);
}

