#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10; // Size of the array
    int arr[SIZE] = {3, 6, 8, 2, 9, 1, 4, 5, 7, 0}; // Array of integers
    int counts[10] = {}; // Array to hold the counts of each value

    // Count the occurrences of each value in the array
    for (int i = 0; i < SIZE; i++) {
        counts[arr[i]]++;
    }

    // Display the histogram
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (int j = 0; j < counts[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
