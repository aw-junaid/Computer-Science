#include <iostream>
using namespace std;

int main() {
    int a, b, c, m, n;

    // First triplet
    m = 2;
    n = 1;
    a = m*m - n*n;
    b = 2*m*n;
    c = m*m + n*n;
    cout << "First triplet: " << a << ", " << b << ", " << c << endl;

    // Second triplet
    m = 3;
    n = 2;
    a = m*m - n*n;
    b = 2*m*n;
    c = m*m + n*n;
    cout << "Second triplet: " << a << ", " << b << ", " << c << endl;

    // Third triplet
    m = 4;
    n = 1;
    a = m*m - n*n;
    b = 2*m*n;
    c = m*m + n*n;
    cout << "Third triplet: " << a << ", " << b << ", " << c << endl;

    return 0;
}
