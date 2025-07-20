#include <format>
#include <iostream>
#include <array>

using namespace std;

int main() {
    const auto display {
        [](const auto& items) {
            for (const auto& item : items) {
                cout << format("{} ", item);
            }
        }
    };

    // initialize an array with a string literal
    // create a one-element array<const char*>
    const auto array1{array{"abc"}};
    cout << format("array1.size() = {}\narray1: ",
        array1.size());
    display(array1);

    // creating std::array of characters from a string liberal
    const auto array2{to_array("C++20")};
    cout << format("\n\narray2.size() = {}\narray2: ",
        array2.size());
    display(array2);

    cout << "\n";
}