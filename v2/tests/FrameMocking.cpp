//
// Created by younghyun on 18. 8. 21.
//

//
// Created by younghyun on 18. 8. 7.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Bowling.h"
#include "MockFrame.h"

using ::testing::AtLeast;

class FrameMockTest : public :: testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    MockFrame frame;
};

TEST_F(FrameMockTest, RollOnce) {

    EXPECT_CALL(frame, score())
            .Times(AtLeast(1));

    //given
    int pinfalls = 1;

    //when
    frame.roll(pinfalls);

    //then
    int score = frame.score();
}
