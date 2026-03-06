#include "calculator.h"
#include <cmath>
#include <stdexcept>

namespace calculator {
    double square_root(double x) {
        if (x < 0) {
            throw std::invalid_argument("Cannot calculate the square root of a negative number.");
        }
        return std::sqrt(x);
    }
}
