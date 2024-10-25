#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 5;
    string arr[SIZE] = {"apple", "banana", "cherry", "date", "elderberry"};

    // Print original array
    cout << "Original array: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reverse each string in the array
    for (int i = 0; i < SIZE; i++) {
        int j = arr[i].length() - 1;
        for (int k = 0; k < j; k++, j--) {
            char temp = arr[i][k];
            arr[i][k] = arr[i][j];
            arr[i][j] = temp;
        }
    }

    // Print reversed array
    cout << "Reversed array: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
