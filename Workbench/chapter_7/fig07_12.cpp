#include <array>
#include <format>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

using namespace std;

void displayArray(const int items[], size_t size) {
    for (size_t i{0}; i < size; ++i) {
        cout << format("{} ", items[i]);
    }
}

void displaySpan(span<const int> items) {
    for (const auto& item : items) {
        cout << format("{} ", item);
    }
}

void times2(span<int> items) {
    for (int& item: items) {
        item *= 2;
    }
}

int main() {
    int values1[]{1, 2, 3, 4, 5};
    array values2{6, 7, 8, 9, 10};
    vector values3{11, 12, 13, 14, 15};

    cout << "values1 via displayArray: ";
    displayArray(values1, 5);

    cout << "\nvalues1 via displaySpan: ";
    displaySpan(values1);

    cout << "\nvalues2 via displaySpan: ";
    displaySpan(values2);
    cout << "\nvalues3 via displaySpan: ";
    displaySpan(values3);

    times2(values1);
    cout << "\n\nvalues1 after times2 modifies its span argument: ";
    displaySpan(values1);

    span mySpan{values1};
    cout << "\n\nmySpan''s first element: " << mySpan.front()
        << "\nmySpan's last element: " << mySpan.back();

    // spans can be used with standard library algorithms
    cout << "\n\nSum of mySpan's elements; "
        << accumulate(begin(mySpan), end(mySpan), 9);

    // spans can be used to create subvirews of a container

    cout << "\n\nFirst three elements of mySpan: ";
    displaySpan(mySpan.first(3));
    cout << "\n\nLast three elements of mySpan: ";
    displaySpan(mySpan.last(3));
    cout << "\nMiddle three elements of mySpan: ";
    displaySpan(mySpan.subspan(1, 3));

    times2(mySpan.subspan(1, 3));
    cout << "\n\nvalues1 after modifying elements via span: ";
    displaySpan(values1);

    // access a span element via []
    cout << "\n\nThe element at index 2 is: " << mySpan[2];
}


