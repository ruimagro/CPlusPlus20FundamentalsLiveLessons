//
// Created by Rui Magro on 2025-06-29.
#include <format>
#include <iostream>
using namespace std;

void cubeByReference(int* nPtr);        // prototype

int main() {
    int number{5};

    cout << std::format("Original value of number is {}\n", number);
    cubeByReference(&number);   // pass number address to cubeByReference
    cout << std::format("New vlaue of number is {}\n", number);
}

void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}
