//
// Created by younghyun on 18. 7. 19.
//

#ifndef BOWLING_KATA_FRAME_H
#define BOWLING_KATA_FRAME_H

class Frame {
public:
    Frame(Frame* prevFrame = nullptr) : prevFrame(prevFrame) {}

    auto roll(int pinfalls) {
        nrRolled++;
        score += pinfalls;
        if (prevFrame) {
            prevFrame = prevFrame->rollFromNextFrame(pinfalls);
        }
    }

    auto getScore() const ->int {
        return score;
    }

    int setPrevFrame(Frame* _prevFrame) {
        prevFrame = _prevFrame;
    }

private:
    Frame* prevFrame;
    int score = 0;
    int nrRolled = 0;

    auto rollFromNextFrame(int pinfalls) -> Frame* {
        if (prevFrame) {
            prevFrame = prevFrame->rollFromNextFrame(pinfalls);
        }

        if (score < 10)
            return nullptr;

        if (isSpare()) {
            score += pinfalls;
            return nullptr;
        }

        if (isStrike()) {
            score += pinfalls;
            nrRolled++;
            return this;
        }

        return nullptr;
    }

    auto isSpare() -> bool {
        return score >= 10 && nrRolled == 2;
    }
    auto isStrike() -> bool {
        return score == 10 && nrRolled == 1;
    }
};

#endif //BOWLING_KATA_FRAME_H
