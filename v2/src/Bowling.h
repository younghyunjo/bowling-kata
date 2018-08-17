//
// Created by younghyun on 18. 8. 7.
//

#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "ImmutableFrame.h"


class Bowling {
public:
    Bowling() {
        for (int i = 0; i < 10; i++)
            frames[i] = std::make_unique<ImmutableFrame>();
    }

    void play(std::vector<std::vector<int>> pins) {
        auto combinedPinfalls = pinfallsCombineForSingleFrame(pins);

//        for (int i=0; i<10; i++) {
//            std::for_each(std::begin(combinedPinfalls[i]), std::end(combinedPinfalls[i]), [](auto i) {
//                    std::cout << i;
//            });
//            std::cout << std::endl;
//        }

        for (int i=0; i<10; i++) {
            auto pin = combinedPinfalls[i];
            for (auto p : pin) {
                frames[i] = frames[i]->roll(p);
            }
        }
    }

    int score() {
        return std::accumulate(std::begin(frames), std::end(frames), 0, [](int& sum, std::unique_ptr<ImmutableFrame>& f) {
            return sum += f->score();
        });
    }

private:
    std::unique_ptr<ImmutableFrame> frames[10];

    std::vector<std::vector<int>> pinfallsCombineForSingleFrame(std::vector<std::vector<int>>& pins) {
        std::vector<std::vector<int>> ret;

        for (auto it = std::begin(pins); it < std::end(pins); it++) {
            int n = 3;
            if (it == std::end(pins) - 2)
                n = 2;
            else if (it == std::end(pins) -1)
                n = 1;

            std::vector<int> pinfallsForSingleFrame;
            std::for_each(it, it+n, [&pinfallsForSingleFrame](auto p) {
                pinfallsForSingleFrame.insert(pinfallsForSingleFrame.end(), p.begin(), p.end());
            });
            pinfallsForSingleFrame.resize(3);
            ret.push_back(pinfallsForSingleFrame);
        }
        return ret;
    }
};

