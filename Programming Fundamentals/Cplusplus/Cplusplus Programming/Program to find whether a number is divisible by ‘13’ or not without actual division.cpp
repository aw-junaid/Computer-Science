#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int factor[] = {1, 10, 9, 12, 3, 4}; // the factors to use for each digit
    int sum = 0;
    int i = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * factor[i % 6]; // use the appropriate factor for this digit
        n /= 10;
        i++;
    }

    if (sum % 13 == 0) {
        cout << "The number is divisible by 13.\n";
    } else {
        cout << "The number is not divisible by 13.\n";
    }

    return 0;
}
