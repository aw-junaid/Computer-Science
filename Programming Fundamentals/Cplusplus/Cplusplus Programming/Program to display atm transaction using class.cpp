#include <iostream>
using namespace std;

class ATM {
    private:
        int balance;

    public:
        ATM(int b) {
            balance = b;
        }

        void displayBalance() {
            cout << "Current Balance: " << balance << endl;
        }

        void withdraw(int amount) {
            if (amount > balance) {
                cout << "Insufficient balance." << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
                displayBalance();
            }
        }

        void deposit(int amount) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
            displayBalance();
        }
};

int main() {
    ATM account(5000);
    int choice, amount;

    do {
        cout << "1. Display Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                account.displayBalance();
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 4:
                cout << "Thank you for using our ATM!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while(choice != 4);

    return 0;
}
