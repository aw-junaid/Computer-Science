#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double principle, rate, time, compound_interest;

    // Input principle amount
    cout << "Enter principle amount: ";
    cin >> principle;

    // Input rate of interest
    cout << "Enter rate of interest: ";
    cin >> rate;

    // Input time period
    cout << "Enter time period (in years): ";
    cin >> time;

    // Calculate compound interest
    compound_interest = principle * pow((1 + rate / 100), time) - principle;

    // Display the result
    cout << "Compound interest = " << compound_interest << endl;

    return 0;
}
