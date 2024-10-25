#include <iostream>
#include <climits> // for using INT_MAX
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // define the input array
    int n = 10; // size of the array
    int smallest = INT_MAX; // initialize smallest and second smallest
    int secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) { // if current element is smaller than smallest
            secondSmallest = smallest; // set second smallest as previous smallest
            smallest = arr[i]; // set smallest as current element
        } else if(arr[i] < secondSmallest && arr[i] != smallest) { // if current element is smaller than second smallest and not equal to smallest
            secondSmallest = arr[i]; // set second smallest as current element
        }
    }

    cout << "The second smallest element in the array is: " << secondSmallest << endl; // print second smallest element
    return 0;
}
