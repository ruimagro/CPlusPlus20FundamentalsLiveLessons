//
// Created by Rui Magro on 2025-06-29.
#include <format>
#include <iostream>

void cubeByReference(int* nPtr);

int main() {
    int number{5};

    std::cout << std::format("Original value of number is {}\n", number);
    cubeByReference(&number); // pass number address to cubeByReference
    std::cout << std::format("New value of number is {}\n", number);
}

// calculate and return cube of an integer argument
void cubeByReference(int* nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube the lolcal vairable n and return result
}
