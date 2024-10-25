#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 2, 3, 4, 4, 5, 5, 6, 6}; // define the input array
    int n = 10; // size of the array

    // loop over the array elements
    for(int i = 0; i < n; i++) {
        // loop over the remaining elements after i
        for(int j = i + 1; j < n; j++) {
            // check if there is a duplicate element
            if(arr[i] == arr[j]) {
                // shift the elements to the left
                for(int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                // decrement the size of the array
                n--;
                // decrement j to avoid skipping elements
                j--;
            }
        }
    }

    // print the new array without duplicates
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
