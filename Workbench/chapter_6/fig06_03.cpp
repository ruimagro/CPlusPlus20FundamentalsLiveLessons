#include <format>
#include <iostream>
#include <array>

int main() {

    std::array items {1, 2, 3, 4, 5};

    std::cout << "items before modification: ";
    for (const int& item : items) {
        std::cout << std::format("{} ", item);
    }

    for (int& item : items) {
        item *= 2;
    }

    std::cout << "\n\nitems after modification: ";
    for (const int& item : items) {
        std::cout << std::format("{} ", item);
    }

    std::cout << "\n\ncalculating running total: ";
    for (int runningTotal{0}; const int& item : items) {
        runningTotal += item;
        std::cout << std::format("item: {}; running total: {}\n", item, runningTotal);
    }

}