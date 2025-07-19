//
// Created by ruima on 2025-06-29.
//
#include <format>
#include <iostream>
#include <array>

int main() {

    constexpr size_t arraySize{5};

    std::array<int, arraySize> values{};

    for (int i{0}; i < values.size(); i++) {
        values.at(i) = 2 + 2 * i;
    }

    for (const int& value : values) {
        std::cout << std::format("{}  ", value);
    }

    std::cout << "\n";

}