#include <format>
#include <iostream>
#include <string>

int main() {
    std::string s1{"one"};
    std::string s2{"two"};

    std::cout << std::format("Before swap:\ns1: {}; s2: {}\n\n", s1, s2);
    s1.swap(s2); // swap strings
    std::cout << std::format("After swap\ns1: {}; s2: {}\n\n", s1, s2);
}