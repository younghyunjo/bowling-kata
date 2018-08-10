//
// Created by younghyun on 18. 8. 7.
//

#pragma once

#include <ostream>

enum class Throw {
    none,
    once,
    twice,
    done
};

//pre ++Throw
inline Throw& operator++(Throw& t) {
    if (t != Throw::done) {
        t = static_cast<Throw>(static_cast<int>(t) + 1);
    }

    return t;
}

//post Throw++
inline Throw operator++(Throw& t, int) {
    Throw result = t;
    ++t;
    return result;
}

// Throw + INT
inline Throw operator+(const Throw& t, int i) {
    if (i >= static_cast<int>(Throw::done)) {
        return Throw::done;
    }

    Throw result = t;
    while (i--)
        ++result;

    return result;
}

inline std::ostream& operator<<(std::ostream& os, const Throw& t) {
    switch (t) {
        case Throw::none:
            os << "none\n";
            break;
        case Throw::once:
            os << "once\n";
            break;
        case Throw::twice:
            os << "twice\n";
            break;
        case Throw::done:
            os << "done\n";
            break;
    }
    return os;
}