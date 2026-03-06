#include <iostream>
#include <cmath>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice;
    double number;

    while (true) {
        std::cout << "\n=== Interactive Calculator ===\n";
        std::cout << "1. Square Root (√x)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 0) {
            std::cout << "Exiting calculator...\n";
            break;
        } else if (choice == 1) {
            std::cout << "Enter a number: ";
            if (!(std::cin >> number)) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                clearInputBuffer();
                continue;
            }

            if (number < 0) {
                std::cout << "Error: Cannot calculate the square root of a negative number.\n";
            } else {
                std::cout << "Result: √" << number << " = " << std::sqrt(number) << "\n";
            }
        } else {
            std::cout << "Invalid choice. Please choose 1 or 0.\n";
        }
    }

    return 0;
}