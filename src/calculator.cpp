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

    double factorial(double x) {
        if (x < 0) {
            throw std::invalid_argument("Cannot calculate the factorial of a negative number.");
        }
        if (std::floor(x) != x) {
            throw std::invalid_argument("Factorial is only defined for integers.");
        }
        
        double result = 1.0;
        for (double i = 1.0; i <= x; ++i) {
            result *= i;
        }
        return result;
    }

    double natural_log(double x) {
        if (x <= 0) {
            throw std::invalid_argument("Cannot calculate the natural logarithm of zero or a negative number.");
        }
        return std::log(x);
    }

    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }
}
