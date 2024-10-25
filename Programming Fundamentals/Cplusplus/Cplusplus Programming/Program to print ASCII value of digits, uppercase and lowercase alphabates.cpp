#include <iostream>
using namespace std;

int main() {
    // Printing ASCII values of digits
    cout << "ASCII values of digits: " << endl;
    for (char c = '0'; c <= '9'; ++c) {
        cout << c << " = " << int(c) << endl;
    }

    // Printing ASCII values of uppercase alphabets
    cout << "ASCII values of uppercase alphabets: " << endl;
    for (char c = 'A'; c <= 'Z'; ++c) {
        cout << c << " = " << int(c) << endl;
    }

    // Printing ASCII values of lowercase alphabets
    cout << "ASCII values of lowercase alphabets: " << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        cout << c << " = " << int(c) << endl;
    }

    return 0;
}
