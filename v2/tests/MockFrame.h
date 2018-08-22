//
// Created by younghyun on 18. 8. 21.
//

#pragma once

#include "gmock/gmock.h"
#include "Frame.h"

class MockFrame : public Frame {
public:
    MOCK_METHOD1(roll, bool(int pinfalls));
    MOCK_METHOD0(score, int());
};

