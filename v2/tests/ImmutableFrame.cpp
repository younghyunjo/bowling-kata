//
// Created by younghyun on 18. 8. 8.
//


#include <iostream>
#include <functional>

#include "gtest/gtest.h"
#include "ImmutableFrame.h"

TEST(ImFrame, constructor) {
    ImmutableFrame imFrame;
    EXPECT_EQ(0, imFrame.score());
}

TEST(ImmutableFrame, constructWithScoreAndThrow) {
    ImmutableFrame imFrame(10, Throw::once);
    EXPECT_EQ(10, imFrame.score());
}

class ImmutableFrameTest : public ::testing :: Test {
protected:
    void SetUp() override {
        frame = std::make_unique<ImmutableFrame>();
    }

    void TearDown() override {
        frame.release();
    }

    std::unique_ptr<ImmutableFrame> frame;
};

TEST_F(ImmutableFrameTest, rollWithInt) {
    auto f = frame->roll(1);
    EXPECT_EQ(1, f->score());
}

TEST_F(ImmutableFrameTest, rollOnce) {
    std::vector<int> pinfalls = {1, 0};

    auto f = frame->roll(std::vector<int>{1, 0});

    EXPECT_EQ(1, f->score());
}

TEST_F(ImmutableFrameTest, rollTwice) {
    auto f = frame->roll(std::vector<int>{1, 1});

    EXPECT_EQ(2, f->score());
}

TEST_F(ImmutableFrameTest, rollThreetimes) {
    auto f = frame->roll(std::vector<int>{1, 1});
    auto f2 = f->roll(std::vector<int>{1});


    EXPECT_EQ(2, f2->score());
}

class ImmutableFrameStrike : public :: testing :: Test {
protected:
    void SetUp() override {
        frame = std::make_unique<ImmutableFrame>(10, Throw::once);
    }

    void TearDown() override {
        frame.release();
    }

    std::unique_ptr<ImmutableFrame> frame;
};

TEST_F(ImmutableFrameStrike, bonusOnce) {
    //when
    auto f = frame->roll(std::vector<int>{1});

    //then
    EXPECT_EQ(11, f->score());
}

TEST_F(ImmutableFrameStrike, bonusTwice) {
    //when
    auto f = frame->roll(1)->roll(1);

    //then
    EXPECT_EQ(12, f->score());
}

TEST_F(ImmutableFrameStrike, bonusThird) {
    //when
    auto f = frame->roll(1)->roll(1)->roll(1);

    //then
    EXPECT_EQ(12, f->score());
}

TEST_F(ImmutableFrameStrike, bonusIsZeroOnce) {
    //when
    auto f = frame->roll(0);

    //then
    EXPECT_EQ(10, f->score());
}

TEST_F(ImmutableFrameStrike, bonusIsZeroTwice) {
    //when
    auto f = frame->roll(0)->roll(0);

    //then
    EXPECT_EQ(10, f->score());
}

TEST_F(ImmutableFrameStrike, bonusIsZeroTwiceAndOneOnce) {
    //when
    auto f = frame->roll(0)->roll(0)->roll(1);

    //then
    EXPECT_EQ(10, f->score());
}


class ImmutableFrameSpare : public :: testing :: Test {
protected:
    void SetUp() override {
        frame = std::make_unique<ImmutableFrame>(10, Throw::twice);
    }

    void TearDown() override {
        frame.release();

    }

    std::unique_ptr<ImmutableFrame> frame;
};

TEST_F(ImmutableFrameSpare, bonusOnce) {
    auto f = frame->roll(10);

    EXPECT_EQ(20, f->score());
}

TEST_F(ImmutableFrameSpare, bonusTwice) {
    auto f = frame->roll(10)->roll(10);

    EXPECT_EQ(20, f->score());
}
