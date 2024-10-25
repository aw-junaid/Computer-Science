#include <iostream>
using namespace std;

int main()
{
    int num, digit, sum = 0;
    cout << "Enter a positive integer: ";
    cin >> num;

    while (num > 0)
    {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }

    cout << "The sum of the digits is: " << sum << endl;
    return 0;
}
