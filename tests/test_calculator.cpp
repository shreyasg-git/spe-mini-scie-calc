#include <gtest/gtest.h>
#include "calculator.h"
#include <stdexcept>

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
