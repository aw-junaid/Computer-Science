#include <iostream>
using namespace std;

int main() {
    int n, sum_odd = 0, sum_even = 0;
    cout << "Enter a positive integer n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
    }
    cout << "The sum of even numbers up to " << n << " is " << sum_even << endl;
    cout << "The sum of odd numbers up to " << n << " is " << sum_odd << endl;
    return 0;
}
