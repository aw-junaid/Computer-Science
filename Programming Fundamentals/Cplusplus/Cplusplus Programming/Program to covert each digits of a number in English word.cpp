#include <iostream>
using namespace std;

// function to convert a digit to its English word equivalent
string convertDigit(int digit) {
    switch(digit) {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "Invalid digit";
    }
}

// function to convert the number to its English word equivalent
string convertNumber(int number) {
    if (number == 0) {
        return convertDigit(0);
    }
    string word = "";
    while (number != 0) {
        int digit = number % 10;
        word = convertDigit(digit) + " " + word;
        number /= 10;
    }
    return word;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    string word = convertNumber(number);
    cout << "The number in words is: " << word << endl;
    return 0;
}
