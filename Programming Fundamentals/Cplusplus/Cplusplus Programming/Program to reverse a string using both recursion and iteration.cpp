#include <iostream>
#include <cstring>
using namespace std;

// Function to reverse a string using iteration
void reverseStringIteration(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1]);
    }
    cout << "Reversed string (using iteration): " << str << endl;
}

// Function to reverse a string using recursion
void reverseStringRecursion(char str[], int start, int end) {
    if (start >= end) {
        cout << "Reversed string (using recursion): " << str << endl;
        return;
    }
    swap(str[start], str[end]);
    reverseStringRecursion(str, start + 1, end - 1);
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    reverseStringIteration(str);

    int len = strlen(str);
    reverseStringRecursion(str, 0, len - 1);

    return 0;
}
