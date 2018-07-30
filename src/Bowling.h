//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_BOWLING_H
#define BOWLING_KATA_BOWLING_H
#include <vector>

#include "Frame.h"

class Bowling {
public:
    Bowling() {
        for (int i=1; i<10 ;i++) {
            frames[i].setPrevFrame(&frames[i-1]);
        }
    };

    int play(std::vector<std::vector<int>> input) {
        for (int i=0; i<10; i++) {
            std::vector<int>pinFalls = input[i];
            for (auto p : pinFalls)
                frames[i].roll(p);
        }
    }

    int getScore() {
        int score = 0;
        for (auto f : frames) {
            score += f.getScore();
        }
        return score;
    }


private:
    Frame frames[10];
};

#endif //BOWLING_KATA_BOWLING_H
