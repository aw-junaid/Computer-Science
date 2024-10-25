#include <iostream>
using namespace std;

// function to accept an integer array and its size and display the array
void displayArray(int arr[], int size) {
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function to accept an integer array and its size and return the sum of its elements
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// function to accept an integer element and display it
void displayElement(int element) {
    cout << "The element is: " << element << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = arr[2];

    displayArray(arr, size);
    cout << "The sum of array elements is: " << sumArray(arr, size) << endl;
    displayElement(element);

    return 0;
}
