#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Before swapping - Num1: " << num1 << ", Num2: " << num2 << endl;

    swap(num1, num2);

    cout << "After swapping - Num1: " << num1 << ", Num2: " << num2 << endl;

    return 0;
}
