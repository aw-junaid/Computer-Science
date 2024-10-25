#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int n, key;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Enter the key to be searched: ";
    cin>>key;
    int index = linearSearch(arr, n, key);
    if(index == -1) {
        cout<<"Element not found!";
    }
    else {
        cout<<"Element found at index "<<index;
    }
    return 0;
}
