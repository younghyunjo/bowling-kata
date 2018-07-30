//
// Created by younghyun on 18. 7. 19.
//


#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Frame.h"

TEST(Frame,setPrevFrame) {
    Frame firstFrame;
    Frame secondFrame;

    firstFrame.setPrevFrame(&secondFrame);
}

TEST(Frame, RollOneBall) {
    int pinfalls = 9;

    Frame frame;
    frame.roll(pinfalls);

    EXPECT_EQ(pinfalls, frame.getScore());
}

TEST(Frame, RollTwoBall) {
    int firstPinFalls = 9;
    int secondPinFalls = 1;

    Frame frame;
    frame.roll(firstPinFalls);
    frame.roll(secondPinFalls);

    EXPECT_EQ(firstPinFalls + secondPinFalls, frame.getScore());
}

TEST(Frame, RollThreeBalls) {
    int firstPinFalls = 10;
    int secondPinFalls = 10;
    int thridPinFalls = 10;

    Frame frame;
    frame.roll(firstPinFalls);
    frame.roll(secondPinFalls);
    frame.roll(thridPinFalls);

    EXPECT_EQ(firstPinFalls + secondPinFalls + thridPinFalls, frame.getScore());
}

TEST(Frame, PassPrevFrameWithNullptr) {
    Frame firstFrame(nullptr);
}

TEST(Frame, PassPrevFrame) {
    Frame firstFrame{};
    Frame secondFrame(&firstFrame);
}

TEST(Frame, prevFrameSpareAddAdditionalPoint) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};

    firstFrame.roll(9);
    firstFrame.roll(1);

    secondFrame.roll(1);

    EXPECT_EQ(11, firstFrame.getScore());
}

TEST(Frame, prevFrameRemainedNextFrameRoll) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};

    firstFrame.roll(9);
    firstFrame.roll(0);

    secondFrame.roll(1);

    EXPECT_EQ(9, firstFrame.getScore());
}

TEST(Frame, prevFrameSparedNextFrameRollTwice) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};

    firstFrame.roll(9);
    firstFrame.roll(1);

    secondFrame.roll(1);
    secondFrame.roll(1);

    EXPECT_EQ(11, firstFrame.getScore());
}

TEST(Frame, prevFrameStrikeNextFrameRoll) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};

    firstFrame.roll(10);

    secondFrame.roll(1);

    EXPECT_EQ(11, firstFrame.getScore());
}

TEST(Frame, prevFrameStrikeNextFrameRollTwice) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};

    firstFrame.roll(10);

    secondFrame.roll(1);
    secondFrame.roll(1);

    EXPECT_EQ(12, firstFrame.getScore());
}

TEST(Frame, prevFrameStrikeNextFrameSpareAndStrike) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};
    Frame thirdFrame{&secondFrame};

    firstFrame.roll(10);

    secondFrame.roll(9);
    secondFrame.roll(1);

    thirdFrame.roll(10);


    EXPECT_EQ(20, firstFrame.getScore());
    EXPECT_EQ(20, secondFrame.getScore());
}

TEST(Frame, prevFrameStrikeNextTwoFrameStrike) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};
    Frame thirdFrame{&secondFrame};

    firstFrame.roll(10);

    secondFrame.roll(10);
    thirdFrame.roll(10);

    EXPECT_EQ(30, firstFrame.getScore());
    EXPECT_EQ(20, secondFrame.getScore());
    EXPECT_EQ(10, thirdFrame.getScore());
}

TEST(Frame, prevFrameStrikeNextThreeFrameStrike) {
    Frame firstFrame{};
    Frame secondFrame{&firstFrame};
    Frame thirdFrame{&secondFrame};
    Frame fourthFrame{&thirdFrame};

    firstFrame.roll(10);
    secondFrame.roll(10);
    thirdFrame.roll(10);
    fourthFrame.roll(10);

    EXPECT_EQ(30, firstFrame.getScore());
    EXPECT_EQ(30, secondFrame.getScore());
    EXPECT_EQ(20, thirdFrame.getScore());
    EXPECT_EQ(10, fourthFrame.getScore());
}

TEST(Frame, prevStrikeNextLastThreeRoll) {
    Frame nineFrame{};
    Frame tenFrame{&nineFrame};

    nineFrame.roll(10);
    tenFrame.roll(10);
    tenFrame.roll(10);
    tenFrame.roll(10);

    EXPECT_EQ(30, nineFrame.getScore());
    EXPECT_EQ(30, tenFrame.getScore());
}
