#include <array>
#include <format>
#include <iostream>
#include <numeric>

int multiply(int x, int y) {
    return x * y;
}

int main() {
    constexpr std::array integers{1, 2, 3, 4, 5};

    std::cout << std::format("Product of integers: {}\n",
        std::accumulate(std::begin(integers), std::end(integers), 1, multiply));

    std::cout << std::format("Product of integers with a lambda: {}\n",
        std::accumulate(std::begin(integers), std::end(integers), 1,
            [](const auto& x, const auto& y) {return x * y;}));
}