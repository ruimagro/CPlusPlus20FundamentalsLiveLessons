
#include <format>
#include <iostream>

using namespace std;

size_t getSize(double* ptr);;

int main() {
    double numbers[20];

    cout << format("Number of bytes in numbers in {}\n",
        sizeof(numbers)
    );

    cout << format("Number of bytes returned by getSize is {}\n",
        getSize(numbers));
}

size_t getSize(double* ptr) {
    return sizeof(ptr);
}
