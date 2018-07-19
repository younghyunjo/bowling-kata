//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_FRAME_H
#define BOWLING_KATA_FRAME_H

class Frame {
public:
    int roll(std::vector<int> pins) {
        score += pins[0];
        score += pins[1];
        return score;
    }

    int getScore() {
        return score;
    }

private:
    int score = 0;
};

#endif //BOWLING_KATA_FRAME_H
