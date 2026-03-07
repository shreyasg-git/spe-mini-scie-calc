#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace calculator {
    /**
     * Calculates the square root of a non-negative number.
     * Throws std::invalid_argument if the number is negative.
     */
    double square_root(double x);

    /**
     * Calculates the factorial of a non-negative integer.
     * Throws std::invalid_argument if the number is negative or not an integer.
     */
    double factorial(double x);
}

#endif // CALCULATOR_H
