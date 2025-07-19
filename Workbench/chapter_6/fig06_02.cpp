#include <format>
#include <iostream>
#include <array>

int main() {
    std::array<int, 5> values{32, 27, 64, 18, 95};

    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << std::format("{}  ", values.at(i));
    }

    std::cout << "\n\n";

    std::array values2{1.1, 2.2, 3.3, 4.4};

    for (size_t i{0}; i < values2.size(); ++i) {
        std::cout << std::format("{}  ", values2.at(i));
    }

    std::cout << "\n\n";
}