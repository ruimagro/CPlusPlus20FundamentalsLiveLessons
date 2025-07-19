//
//
#include <iostream>
using namespace std;

int main() {

    constexpr int a{7};
    const int* aPtr{&a};

    std::cout << "The address of a is " << &a
        << "\nThe value of aPtr is " << aPtr;

    std::cout << "\n\nThe address of aPtr is " << &aPtr << "\n\n";

    std::cout << "\n\nThe value of a is " << a
        << "\nThe value of *aPtr is " << *aPtr << '\n';

}
