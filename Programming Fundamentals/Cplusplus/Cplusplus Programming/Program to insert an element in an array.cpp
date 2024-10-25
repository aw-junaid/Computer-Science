#include <iostream>
using namespace std;

int main() {
    int arr[50], size, pos, value;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the position to insert the element: ";
    cin >> pos;

    cout << "Enter the value to insert: ";
    cin >> value;

    // Shift the elements to the right of pos to create space for the new element
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the specified position
    arr[pos] = value;

    size++; // Increase the size of the array

    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
