#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime> // Required for time()

using namespace std;

int main() {
    int roll; // The variable to store the result of the die roll

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Roll the die and print the result
    roll = rand() % 6 + 1; // Generate a random number between 1 and 6
    cout << "You rolled a " << roll << endl;

    return 0;
}
