#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int DECK_SIZE = 52;
const int HAND_SIZE = 5;

void shuffle(int * const deck, const int size);
void deal(int * const deck, const int size, int * const hand, const int handSize);
void printCards(int * const cards, const int size);

int main()
{
    srand(time(NULL)); // seed the random number generator with current time

    int deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }

    int hand[HAND_SIZE];

    shuffle(deck, DECK_SIZE);
    deal(deck, DECK_SIZE, hand, HAND_SIZE);

    cout << "Your hand is: ";
    printCards(hand, HAND_SIZE);

    return 0;
}

void shuffle(int * const deck, const int size)
{
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int * const deck, const int size, int * const hand, const int handSize)
{
    for (int i = 0; i < handSize; i++) {
        hand[i] = deck[i];
    }
}

void printCards(int * const cards, const int size)
{
    for (int i = 0; i < size; i++) {
        int suit = cards[i] / 13;
        int rank = cards[i] % 13;
        switch (rank) {
            case 0: cout << "Ace"; break;
            case 10: cout << "Jack"; break;
            case 11: cout << "Queen"; break;
            case 12: cout << "King"; break;
            default: cout << rank + 1; break;
        }
        cout << " of ";
        switch (suit) {
            case 0: cout << "Hearts"; break;
            case 1: cout << "Diamonds"; break;
            case 2: cout << "Clubs"; break;
            case 3: cout << "Spades"; break;
        }
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}
