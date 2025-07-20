//#includes
#include <format>
#include <iostream>
#include <array>

using namespace std;

int main() {
    // generic lambda to display a collection of items
    const auto display {
        [](const auto& items) {
            for (const auto& item : items) {
                cout << format("{} ", item);
            }
        }
    };

    const int values1[]{10, 20, 30};

    // creating an array from a build-in aray
    const auto array1{std::to_array(values1)};

    cout << format("array1.size() = {}\n", array1.size()) << "aray1: ";
    display(array1);

    const auto array2{std::to_array({1, 2, 3, 4})};
    cout << format("\n\narray2.size() = {}\n", array2.size()) << "array2: ";
    display(array2);

    cout << '\n';
}
