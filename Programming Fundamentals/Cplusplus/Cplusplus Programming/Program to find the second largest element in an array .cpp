#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // define the input array
    int n = 10; // size of the array
    int largest = arr[0]; // initialize largest and second largest
    int secondLargest = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) { // if current element is greater than largest
            secondLargest = largest; // set second largest as previous largest
            largest = arr[i]; // set largest as current element
        } else if(arr[i] > secondLargest && arr[i] != largest) { // if current element is greater than second largest and not equal to largest
            secondLargest = arr[i]; // set second largest as current element
        }
    }

    cout << "The second largest element in the array is: " << secondLargest << endl; // print second largest element
    return 0;
}
