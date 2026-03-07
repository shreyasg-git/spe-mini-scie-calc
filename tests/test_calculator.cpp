#include <gtest/gtest.h>
#include "calculator.h"
#include <stdexcept>
#include <cmath>

// Test positive numbers
TEST(CalculatorSquareRootTest, PositiveNumbers) {
    EXPECT_DOUBLE_EQ(calculator::square_root(4.0), 2.0);
    EXPECT_DOUBLE_EQ(calculator::square_root(9.0), 3.0);
    EXPECT_DOUBLE_EQ(calculator::square_root(16.0), 4.0);
    EXPECT_DOUBLE_EQ(calculator::square_root(2.0), 1.4142135623730951);
    EXPECT_DOUBLE_EQ(calculator::square_root(0.0), 0.0);
}

// Test negative number (should throw std::invalid_argument)
TEST(CalculatorSquareRootTest, NegativeNumbers) {
    EXPECT_THROW(calculator::square_root(-1.0), std::invalid_argument);
    EXPECT_THROW(calculator::square_root(-4.0), std::invalid_argument);
}

// Test Factorial with positive integers and zero
TEST(CalculatorFactorialTest, PositiveIntegersAndZero) {
    EXPECT_DOUBLE_EQ(calculator::factorial(0.0), 1.0);
    EXPECT_DOUBLE_EQ(calculator::factorial(1.0), 1.0);
    EXPECT_DOUBLE_EQ(calculator::factorial(5.0), 120.0);
    EXPECT_DOUBLE_EQ(calculator::factorial(10.0), 3628800.0);
}

// Test Factorial exceptions (negative numbers and non-integers)
TEST(CalculatorFactorialTest, InvalidInputs) {
    EXPECT_THROW(calculator::factorial(-1.0), std::invalid_argument);
    EXPECT_THROW(calculator::factorial(-5.0), std::invalid_argument);
    EXPECT_THROW(calculator::factorial(2.5), std::invalid_argument);
    EXPECT_THROW(calculator::factorial(3.14159), std::invalid_argument);
}

// Test Natural Logarithm with positive numbers
TEST(CalculatorNaturalLogTest, PositiveNumbers) {
    EXPECT_NEAR(calculator::natural_log(1.0), 0.0, 1e-9);
    EXPECT_NEAR(calculator::natural_log(std::exp(1.0)), 1.0, 1e-9);
    EXPECT_NEAR(calculator::natural_log(10.0), 2.302585092994046, 1e-9);
}

// Test Natural Logarithm exceptions (zero and negative numbers)
TEST(CalculatorNaturalLogTest, ZeroAndNegativeNumbers) {
    EXPECT_THROW(calculator::natural_log(0.0), std::invalid_argument);
    EXPECT_THROW(calculator::natural_log(-1.0), std::invalid_argument);
    EXPECT_THROW(calculator::natural_log(-100.0), std::invalid_argument);
}

// Test Power function with positive base and exponent
TEST(CalculatorPowerTest, PositiveBaseAndExponent) {
    EXPECT_DOUBLE_EQ(calculator::power(2.0, 3.0), 8.0);
    EXPECT_DOUBLE_EQ(calculator::power(5.0, 2.0), 25.0);
    EXPECT_DOUBLE_EQ(calculator::power(10.0, 4.0), 10000.0);
}

// Test Power function with fractional exponents and negative bases
TEST(CalculatorPowerTest, MixedInputs) {
    EXPECT_DOUBLE_EQ(calculator::power(4.0, 0.5), 2.0); // Square root basically
    EXPECT_DOUBLE_EQ(calculator::power(-2.0, 3.0), -8.0);
    EXPECT_DOUBLE_EQ(calculator::power(2.0, -2.0), 0.25);
}

// Test Power function with zero exponent (should always be 1)
TEST(CalculatorPowerTest, ZeroExponent) {
    EXPECT_DOUBLE_EQ(calculator::power(5.0, 0.0), 1.0);
    EXPECT_DOUBLE_EQ(calculator::power(-5.0, 0.0), 1.0);
    EXPECT_DOUBLE_EQ(calculator::power(0.0, 0.0), 1.0); // Often 1 in std::pow
}
