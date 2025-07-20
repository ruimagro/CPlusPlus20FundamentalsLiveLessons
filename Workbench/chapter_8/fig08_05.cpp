#include <format>
#include <iostream>
#include <string>

void printStatistics(const std::string& s) {
    std::cout << std::format(
        "capacity: {}\nmax size: {}\nsize: {}\nempty: {}",
        s.capacity(), s.max_size(), s.size(), s.empty()
        );
}

int main() {
    std::string string1;        // empty string

    std::cout << "Statistics before input:\n";
    printStatistics(string1);

    std::cout << "\n\nEnter a string: ";
    std::cin >> string1; // delimited by whitespace
    std::cout << std::format("The string entered was: {}\n", string1);
    std::cout << "Statistics after input:\n";
    printStatistics(string1);

    std::cout << "\n\nEnter a string: ";
    std::cin >> string1;
    std::cout << std::format("The string entered was: {}\n", string1);
    std::cout << "Statistics after input:\n";
    printStatistics(string1);

    // append 46 characters to string1
    string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    std::cout << std::format("\n\nstring1 is now: {}\n", string1);
    std::cout << "Statistics after concatenation:\n";
    printStatistics(string1);
}