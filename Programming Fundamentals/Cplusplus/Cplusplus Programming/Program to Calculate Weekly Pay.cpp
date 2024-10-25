#include <iostream>
using namespace std;

int main() {
    double hourly_rate, hours_worked, weekly_pay;

    // Get input from user
    cout << "Enter hourly rate: $";
    cin >> hourly_rate;
    cout << "Enter hours worked: ";
    cin >> hours_worked;

    // Calculate weekly pay
    if (hours_worked <= 40) {
        weekly_pay = hourly_rate * hours_worked;
    } else {
        weekly_pay = hourly_rate * 40 + (hourly_rate * 1.5 * (hours_worked - 40));
    }

    // Display weekly pay
    cout << "Weekly pay: $" << weekly_pay << endl;

    return 0;
}
