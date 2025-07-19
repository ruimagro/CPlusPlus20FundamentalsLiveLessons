#include <array>
#include <format>
#include <iostream>

int main() {

    std::array items{10, 20, 30, 40};
    int total{0};

    for  (const int& item : items) {
        total += item;
    }

    std::cout << std::format("Tottal of the array elements: {}\n", total);

}