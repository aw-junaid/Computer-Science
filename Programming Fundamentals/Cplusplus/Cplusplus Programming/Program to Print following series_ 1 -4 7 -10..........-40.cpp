#include <iostream>
using namespace std;

int main()
{
    int n = 10; // number of terms in the series
    int sign = 1; // starting sign of the series
    int term = 1; // starting term of the series

    for (int i = 1; i <= n; i++)
    {
        cout << term << " "; // output the current term
        sign *= -1; // change the sign for the next term
        term += 3 * sign; // calculate the next term
    }

    return 0;
}
