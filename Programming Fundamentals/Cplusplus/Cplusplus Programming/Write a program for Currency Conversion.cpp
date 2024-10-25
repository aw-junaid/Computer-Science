#include <iostream>
using namespace std;

int main()
{
    double amount, result;
    char choice;

    cout << "Enter the amount in US Dollars: ";
    cin >> amount;

    cout << "Choose currency to convert to (E for Euro, P for Pound, Y for Yen): ";
    cin >> choice;

    switch (choice)
    {
        case 'E':
        case 'e':
            result = amount * 0.82; // 1 USD = 0.82 Euro
            cout << "Equivalent amount in Euro: " << result << endl;
            break;
        case 'P':
        case 'p':
            result = amount * 0.72; // 1 USD = 0.72 Pound
            cout << "Equivalent amount in Pound: " << result << endl;
            break;
        case 'Y':
        case 'y':
            result = amount * 109.44; // 1 USD = 109.44 Yen
            cout << "Equivalent amount in Yen: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
