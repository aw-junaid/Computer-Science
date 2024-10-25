#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = { 3, 1, 4, 2, 5 }; // Declare and initialize array
    int temp;

    cout << "Original array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " "; // Print out original array
    }

    // Bubble sort
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Check if adjacent elements are in the wrong order
                // Swap the two elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " "; // Print out sorted array
    }

    return 0;
}
