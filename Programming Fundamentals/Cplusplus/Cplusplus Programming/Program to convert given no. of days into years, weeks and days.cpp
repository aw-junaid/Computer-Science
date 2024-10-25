#include <iostream>
using namespace std;

int main() {
    int days, years, weeks;

    cout << "Enter the number of days: ";
    cin >> days;

    years = days / 365;
    days = days % 365;

    weeks = days / 7;
    days = days % 7;

    cout << "Equivalent years: " << years << endl;
    cout << "Equivalent weeks: " << weeks << endl;
    cout << "Equivalent days: " << days << endl;

    return 0;
}
