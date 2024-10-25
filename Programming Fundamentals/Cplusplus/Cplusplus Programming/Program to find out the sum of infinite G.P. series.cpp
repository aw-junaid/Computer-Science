#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, r;

    cout << "Enter the first term (a): ";
    cin >> a;

    cout << "Enter the common ratio (r): ";
    cin >> r;

    if (abs(r) < 1) {  // check if series is convergent
        double sum = a / (1 - r);
        cout << "The sum of the infinite G.P. series is: " << sum << endl;
    }
    else {
        cout << "The series is not convergent." << endl;
    }

    return 0;
}
