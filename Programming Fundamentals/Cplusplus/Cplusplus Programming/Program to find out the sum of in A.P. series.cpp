#include <iostream>

using namespace std;

int main()
{
    int first_term, common_diff, num_terms, sum;

    cout << "Enter the first term of the AP: ";
    cin >> first_term;

    cout << "Enter the common difference of the AP: ";
    cin >> common_diff;

    cout << "Enter the number of terms in the AP: ";
    cin >> num_terms;

    // Using the formula for the sum of an AP series: S = n/2[2a + (n-1)d]
    sum = num_terms/2 * (2 * first_term + (num_terms - 1) * common_diff);

    cout << "The sum of the AP series is: " << sum << endl;

    return 0;
}
