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

class Bowling {
public:
    void play(std::vector<std::vector<int>> pins) {

        auto combinedPinfalls = pinfallsCombineForSingleFrame(pins);


        //TODO

    }

    int score() {
        //TODO
        return 10;
    }

private:
    std::vector<std::vector<std::vector<int>>> pinfallsCombineForSingleFrame(std::vector<std::vector<int>>& pins) {
        std::vector<std::vector<std::vector<int>>> ret;

        for (auto it = std::begin(pins); it < std::end(pins); it++) {
            int n = 3;
            if (it == std::end(pins) - 2)
                n = 2;
            else if (it == std::end(pins) -1)
                n = 1;

            ret.push_back(std::vector<std::vector<int>>{it, it+n});
        }

        /*
        std::for_each(std::begin(ret), std::end(ret), [](auto b) {
            std::cout << "size:" << b.size() << std::endl;
            std::for_each(std::begin(b), std::end(b), [](auto c) {
                std::for_each(std::begin(c), std::end(c), [](auto d) {
                    std::cout << d << std::endl;
                });
                std::cout << std::endl;
            });
            std::cout << std::endl;
        });
        */

        return ret;

    }
};

