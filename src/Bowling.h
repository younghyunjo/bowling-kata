//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_BOWLING_H
#define BOWLING_KATA_BOWLING_H

#include <vector>

#include "Frame.h"

class Bowling {
public:
    int play(std::vector<std::vector<int>> input) {
        int total_score = 0;
        for (int i=0; i<10 ;i++) {
            frame[i]._rool(input[i]);
        }

        for (int i=1; i<10; i++) {
            frame[i - 1]._getBonux(input[i]);
        }

        for (int i=0; i<10 ;i++) {
            total_score += frame[i]._getScore();
        }
        return total_score;
    }

private:
    Frame frame[10];
};


#endif //BOWLING_KATA_BOWLING_H
