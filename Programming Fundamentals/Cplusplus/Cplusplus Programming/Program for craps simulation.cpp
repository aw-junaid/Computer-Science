#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // initialize the random number generator

    int balance = 1000; // initial balance
    int bet;

    while (balance > 0) {
        cout << "Balance: $" << balance << endl;
        cout << "Enter bet (0 to quit): ";
        cin >> bet;
        if (bet == 0) break;

        int roll1 = rand() % 6 + 1; // roll the dice
        int roll2 = rand() % 6 + 1;
        int sum = roll1 + roll2;

        cout << "Roll: " << roll1 << " + " << roll2 << " = " << sum << endl;

        if (sum == 7 || sum == 11) {
            cout << "You win!" << endl;
            balance += bet;
        } else if (sum == 2 || sum == 3 || sum == 12) {
            cout << "You lose!" << endl;
            balance -= bet;
        } else {
            int point = sum;
            cout << "Point is " << point << endl;
            while (true) {
                roll1 = rand() % 6 + 1; // roll the dice again
                roll2 = rand() % 6 + 1;
                sum = roll1 + roll2;
                cout << "Roll: " << roll1 << " + " << roll2 << " = " << sum << endl;
                if (sum == point) {
                    cout << "You win!" << endl;
                    balance += bet;
                    break;
                } else if (sum == 7) {
                    cout << "You lose!" << endl;
                    balance -= bet;
                    break;
                }
            }
        }
    }

    cout << "Game over." << endl;
    return 0;
}

