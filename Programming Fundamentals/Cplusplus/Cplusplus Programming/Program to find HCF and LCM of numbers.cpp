#include <iostream>
using namespace std;

// function to calculate HCF of two numbers using recursion
int hcf(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return hcf(b, a % b);
    }
}

// function to calculate LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / hcf(a, b);
}

int main() {
    int num1, num2, h, l;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // calculate HCF and LCM
    h = hcf(num1, num2);
    l = lcm(num1, num2);

    // print the results
    cout << "HCF of " << num1 << " and " << num2 << " is " << h << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is " << l << endl;

    return 0;
}
