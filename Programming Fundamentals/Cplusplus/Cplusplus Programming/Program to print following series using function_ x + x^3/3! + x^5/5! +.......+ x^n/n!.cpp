#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double fact = 1.0;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double computeSeries(double x, int n) {
    double sum = x, term;
    for (int i = 1; i <= n; i += 2) {
        term = pow(x, i) / factorial(i);
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    int n;

    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter value of n: ";
    cin >> n;

    double result = computeSeries(x, n);
    cout << "Result: " << result << endl;

    return 0;
}
