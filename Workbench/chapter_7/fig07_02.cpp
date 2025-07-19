//
// Created by Rui Magro on 2025-06-29.
#include <format>
#include <iostream>

void cubeByReference(int* nPtr);        // prototype

int main() {
    int number{5};

    std::cout << std::format("Original value of number is {}\n", number);
    cubeByReference(&number);   // pass number address to cubeByReference
    std::cout << std::format("New vlaue of number is {}\n", number);
}

void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}
