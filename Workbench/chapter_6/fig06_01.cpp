

#include <format>
#include <iostream>
#include <array>

int main() {
    std::array<int, 5> values;

    for (size_t i{0}; i < values.size(); ++i) {
        values[i] = 0;
    }

    std::cout << std::format("{:>7}{:>10}\n", "Element", "Value");

    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << std::format("{:>7}{:>10}\n", i, values[i]);
    }

    std::cout << std::format("\n{:>7}{:>10}\n", "Element", "Value");

    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << std::format("{:>7}{:>10}\n", i, values.at(i));
    }

    values.at(10);
}
