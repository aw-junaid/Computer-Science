#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int totalMatchsticks = 21;
    int userChoice, computerChoice;

    cout << "Welcome to the matchstick game!\n";
    cout << "There are 21 matchsticks on the table.\n";
    cout << "You can pick 1, 2, 3, or 4 matchsticks at a time.\n";
    cout << "The player who picks up the last matchstick wins.\n\n";

    while (totalMatchsticks > 1) {
        cout << "Total matchsticks left on the table: " << totalMatchsticks << endl;

        // User's turn
        cout << "Your turn: ";
        cin >> userChoice;
        while (userChoice < 1 || userChoice > 4 || userChoice > totalMatchsticks) {
            cout << "Invalid choice! Choose between 1 and 4 matchsticks and make sure you don't pick more than the remaining matchsticks.\n";
            cout << "Your turn: ";
            cin >> userChoice;
        }
        totalMatchsticks -= userChoice;
        if (totalMatchsticks == 1) {
            cout << "You win!\n";
            break;
        }
        cout << "You picked " << userChoice << " matchsticks.\n";
        cout << "Total matchsticks left on the table: " << totalMatchsticks << endl << endl;

        // Computer's turn
        srand(time(NULL));
        computerChoice = rand() % 4 + 1;
        while (computerChoice > totalMatchsticks) {
            computerChoice = rand() % 4 + 1;
        }
        totalMatchsticks -= computerChoice;
        if (totalMatchsticks == 1) {
            cout << "The computer wins!\n";
            break;
        }
        cout << "The computer picked " << computerChoice << " matchsticks.\n";
        cout << "Total matchsticks left on the table: " << totalMatchsticks << endl << endl;
    }

    cout << "Thanks for playing!\n";

    return 0;
}
