//
// Created by younghyun on 18. 8. 7.
//

#include <iostream>
#include <functional>

#include "gtest/gtest.h"
#include "Frame.h"

TEST(FrameConstructor, constructWithPinfalls) {
    //given
    std::vector<int> pinfalls = {1, 0};

    //when
    Frame frame(pinfalls);

    //then
    EXPECT_EQ(1, frame.score());
}

class FrameTest : public :: testing::Test {
protected:
    void SetUp() override {
        frame = std::make_unique<Frame>();
    }

    void TearDown() override {
        frame.release();
    }

    std::unique_ptr<Frame> frame;
};

TEST_F(FrameTest, RollOnce) {
    //given
    int pinfalls = 1;

    //when
    frame->roll(pinfalls);

    //then
    int score = frame->score();
    EXPECT_EQ(pinfalls, score);
}

TEST_F(FrameTest, RollTwice) {
    //given
    int firstPinfalls = 1;
    int secondPinfalls = 2;

    //when
    frame->roll(firstPinfalls);
    frame->roll(secondPinfalls);

    //then
    int score = frame->score();
    EXPECT_EQ(firstPinfalls + secondPinfalls, score);
}


TEST_F(FrameTest, RollThreeTimes) {
    //given
    int firstPinfalls = 1;
    int secondPinfalls = 2;
    int thirdPinfalls = 3;

    //when
    frame->roll(firstPinfalls);
    frame->roll(secondPinfalls);
    frame->roll(thirdPinfalls);

    //then
    int score = frame->score();
    EXPECT_EQ(firstPinfalls + secondPinfalls, score);
}

TEST_F(FrameTest, RollThreeTimesWithTenFalls) {
    //given
    int firstPinfalls = 10;
    int secondPinfalls = 10;
    int thirdPinfalls = 10;

    //when
    frame->roll(firstPinfalls);
    frame->roll(secondPinfalls);
    frame->roll(thirdPinfalls);

    //then
    int score = frame->score();
    EXPECT_EQ(firstPinfalls + secondPinfalls + thirdPinfalls, score);
}

TEST_F(FrameTest, RollThreeTimesWithSpared) {
    //given
    int firstPinfalls = 1;
    int secondPinfalls = 9;
    int thirdPinfalls = 9;

    //when
    frame->roll(firstPinfalls);
    frame->roll(secondPinfalls);
    frame->roll(thirdPinfalls);

    //then
    int score = frame->score();
    EXPECT_EQ(firstPinfalls + secondPinfalls + thirdPinfalls, score);
}


class FrameTestStrike : public :: testing::Test {
protected:
    void SetUp() override {
        frame = std::make_unique<Frame>();
        frame->roll(10);
    }

    void TearDown() override {
        frame.release();
    }

    std::unique_ptr<Frame> frame;
};

TEST_F(FrameTestStrike, isScoreTen) {
    //when
    int score = frame->score();

    //then
    EXPECT_EQ(score, 10);
}

TEST_F(FrameTestStrike, bonusOnce) {
    //given
    int pinfallsFromNextFrame = 1;

    //when
    frame->roll(pinfallsFromNextFrame);

    //then
    EXPECT_EQ(10 + pinfallsFromNextFrame, frame->score());
}

TEST_F(FrameTestStrike, bonusTwice) {
    //given
    int firstPinfallsFromNextFrame = 1;
    int secondPinfallsFromNextFrame = 1;


    //when
    frame->roll(firstPinfallsFromNextFrame);
    frame->roll(secondPinfallsFromNextFrame);

    //then
    EXPECT_EQ(10 + firstPinfallsFromNextFrame + secondPinfallsFromNextFrame,
            frame->score());
}

TEST_F(FrameTestStrike, bonusThreeTimes) {
    //given
    int firstPinfallsFromNextFrame = 1;
    int secondPinfallsFromNextFrame = 1;
    int thridPinfallsFromNextFrame = 1;


    //when
    frame->roll(firstPinfallsFromNextFrame);
    frame->roll(secondPinfallsFromNextFrame);
    frame->roll(thridPinfallsFromNextFrame);

    //then
    EXPECT_EQ(10 + firstPinfallsFromNextFrame + secondPinfallsFromNextFrame,
              frame->score());
}

TEST_F(FrameTestStrike, bonusOnceRemainRoll) {
    //given
    int pinfallsFromNextFrame = 1;

    //when
    bool remainRoll = frame->roll(pinfallsFromNextFrame);

    //then
    EXPECT_EQ(true, remainRoll);
}

TEST_F(FrameTestStrike, bonusTwiceNoRemainRoll) {
    //given
    int firstPinfallsFromNextFrame = 1;
    int secondPinfallsFromNextFrame = 1;


    //when
    frame->roll(firstPinfallsFromNextFrame);
    bool remainRoll = frame->roll(secondPinfallsFromNextFrame);

    //then
    EXPECT_EQ(false, remainRoll);
}

class FrameTestSpare : public :: testing::Test {
protected:
    void SetUp() override {
        frame = std::make_unique<Frame>();
        frame->roll(1);
        frame->roll(9);
    }

    void TearDown() override {
        frame.release();
    }

    std::unique_ptr<Frame> frame;
};

TEST_F(FrameTestSpare, bonusOnce) {
    //given
    int pinfallsFromNextFrame = 1;

    //when
    frame->roll(pinfallsFromNextFrame);

    //then
    EXPECT_EQ(10 + pinfallsFromNextFrame, frame->score());
}

TEST_F(FrameTestSpare, bonusTwice) {
    //given
    int firstPinfallsFromNextFrame = 1;
    int secondPinfallsFromNextFrame = 2;

    //when
    frame->roll(firstPinfallsFromNextFrame);
    frame->roll(secondPinfallsFromNextFrame);

    //then
    EXPECT_EQ(10 + firstPinfallsFromNextFrame, frame->score());
}