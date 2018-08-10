//
// Created by younghyun on 18. 8. 7.
//

#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "Frame.h"

class Pinfall {
public:
    Pinfall(std::vector<int> pinfalls) : m_pinfalls(pinfalls) {}

private:
    const std::vector<int> m_pinfalls;
};

//class Pinfalls {
//public:
//    Pinfalls (std::vector<std::vector<int>> pinfalls) {
//
//    }
//
//private:
//    const Pinfall m_pinfalls[10];
//};


class Bowling {
public:
    void play(std::vector<std::vector<int>> pins) {
        Frame frames[10];
        std::transform(std::begin(pins), std::end(pins), std::begin(frames), [](std::vector<int> p){
            return Frame(p);
        });
    }

    int score() {
        return 10;
    }

private:
};

