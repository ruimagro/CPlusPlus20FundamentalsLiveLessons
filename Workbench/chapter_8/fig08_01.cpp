#include <format>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1{"cat"};
    string s2;
    string s3;

    s2 = s1;
    s3.assign(s1);
    cout << format("s1: {}\ns2: {}\ns3: {}\n\n", s1, s2, s3);

    s2.at(0) = 'r'; // modify s2
    s3.at(2) = 'r'; // modify s3

    cout << "\n\nAfter concatenations:\n";
    string s4{s1 + "apult"}; // concatenation
    s1.append("acomb");
    s3 += "pet";
    cout << format("s1: {}\ns3: {}\ns4: {}\n", s1, s3, s4);

    // append locations 4 through end of s1 to
    // create string "combo" (s5 was initially empty)
    string s5;
    s5.append(s1, 4, s1.size() - 4);
    cout << format("s5: {}\n", s5);
}
