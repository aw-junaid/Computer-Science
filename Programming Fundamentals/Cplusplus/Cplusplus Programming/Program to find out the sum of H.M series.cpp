#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    double a[n], sum = 0;
    cout << "Enter the terms of the series: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += 1 / a[i];
    }

    cout << "The sum of the series is " << n / sum << endl;

    return 0;
}
