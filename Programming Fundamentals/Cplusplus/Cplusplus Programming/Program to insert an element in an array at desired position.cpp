#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // define the input array
    int n = 10; // size of the array
    int position = 3; // position to insert the element
    int element = 25; // element to be inserted

    // shift the elements to the right from the end of the array until the desired position
    for(int i = n - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // insert the element at the desired position
    arr[position] = element;

    // increment the size of the array
    n++;

    // print the new array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
