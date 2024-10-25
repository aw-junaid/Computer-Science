#include <iostream>
using namespace std;

int main() {
    int n, i, j, space;

    cout << "Enter the number of rows (odd number): ";
    cin >> n;

    // Upper half of the diamond
    for (i = 1; i <= n; i += 2) {
        for (space = 1; space <= (n - i) / 2; space++) {
            cout << " ";
        }
        for (j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half of the diamond
    for (i = n - 2; i >= 1; i -= 2) {
        for (space = 1; space <= (n - i) / 2; space++) {
            cout << " ";
        }
        for (j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
