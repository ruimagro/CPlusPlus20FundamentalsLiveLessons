#include <iostream>
#include <format>

using namespace std;

int main(int argc, char* argv[]) {

    cout << format("Number of arguments: {}\n\n", argc);

    for (int i{0}; i < argc; i++) {
        cout << format("{}\n", argv[i]);
    }
}