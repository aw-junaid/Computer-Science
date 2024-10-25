#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;

    cout << "Enter a positive integer n: ";
    cin >> n;

    // Loop through numbers 1 to n and add them up
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    cout << "The sum of the series 1 + 2 + 3 + ... + " << n << " is " << sum << endl;

    return 0;
}
