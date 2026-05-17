#include "calculator.hpp"
#include <iostream>

int main() {
    Calculator calc;
    double a = 12.0, b = 3.0;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << calc.add(a, b) << std::endl;
    std::cout << "a - b = " << calc.subtract(a, b) << std::endl;
    std::cout << "a * b = " << calc.multiply(a, b) << std::endl;
    try {
        std::cout << "a / b = " << calc.divide(a, b) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
