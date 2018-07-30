//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_FRAME_H
#define BOWLING_KATA_FRAME_H

class Frame {
public:
    Frame(Frame* prevFrame = nullptr) : prevFrame(prevFrame) {}

    void roll(int pinfalls) {
        nrRolled++;
        score += pinfalls;
        if (prevFrame) {
            prevFrame = prevFrame->rollFromNextFrame(pinfalls);
        }
    }

    int getScore() const {
        return score;
    }

    int setPrevFrame(Frame* _prevFrame) {
        prevFrame = _prevFrame;
    }

private:
    Frame* prevFrame;
    int score = 0;
    int nrRolled = 0;

    Frame* rollFromNextFrame(int pinfalls) {
        if (prevFrame) {
            prevFrame = prevFrame->rollFromNextFrame(pinfalls);
        }

        if (score < 10)
            return nullptr;

        if (score >= 10 && nrRolled == 2) {
            score += pinfalls;
            return nullptr;
        }

        if (score == 10 && nrRolled == 1) {
            score += pinfalls;
            nrRolled++;
            return this;
        }

        return nullptr;
    }
};

#endif //BOWLING_KATA_FRAME_H
