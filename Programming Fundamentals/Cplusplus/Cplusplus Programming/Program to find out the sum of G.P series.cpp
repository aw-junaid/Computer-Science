#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, r, n, sum;

    cout << "Enter the first term (a): ";
    cin >> a;
    cout << "Enter the common ratio (r): ";
    cin >> r;
    cout << "Enter the number of terms (n): ";
    cin >> n;

    // calculating sum of the G.P series using formula
    sum = (a * (1 - pow(r, n))) / (1 - r);

    cout << "The sum of the G.P series is: " << sum << endl;

    return 0;
}
