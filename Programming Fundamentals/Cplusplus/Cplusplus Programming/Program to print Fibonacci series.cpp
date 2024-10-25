#include <iostream>
using namespace std;

int main()
{
    int n, i, a = 0, b = 1, c;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (i = 1; i <= n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
