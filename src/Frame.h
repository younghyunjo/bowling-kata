//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_FRAME_H
#define BOWLING_KATA_FRAME_H

class Frame {
public:
    Frame* prevFrame;


    enum State {
        REMAINED,
        SPARE,
    };

    int _rool(std::vector<int> pins) {
        score += pins[0];
        score += pins[1];

        if (pins[0] != 10 && score == 10) {
            remainedBonusPoint = 1;
            state = SPARE;
        }
        return score;
    }

    int _getScore() {
        return score;
    }

    int _getBonux(std::vector<int> pins) {
        int bonusPoint = 0;
        if (remainedBonusPoint > 0) {
            bonusPoint += pins[0];
            remainedBonusPoint--;
            score += bonusPoint;
        }

        return bonusPoint;
    }

    State getState() {
        return state;
    }

private:
    State state = REMAINED;
    int score = 0;
    int remainedBonusPoint = 0;
};

#endif //BOWLING_KATA_FRAME_H
