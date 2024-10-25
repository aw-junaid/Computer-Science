#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // set the seed for random number generation

    int numFlips;
    cout << "Enter the number of times you want to flip the coin: ";
    cin >> numFlips;

    int headsCount = 0;
    int tailsCount = 0;

    for (int i = 0; i < numFlips; i++)
    {
        int coin = rand() % 2; // generate a random number either 0 or 1

        if (coin == 0)
            headsCount++;
        else
            tailsCount++;
    }

    cout << "Heads count: " << headsCount << endl;
    cout << "Tails count: " << tailsCount << endl;

    return 0;
}
