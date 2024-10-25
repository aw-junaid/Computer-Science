#include <iostream>
using namespace std;

// Binary search function
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main() {
    int n, x;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        cout << "Element not found\n";
    } else {
        cout << "Element found at index " << result << "\n";
    }

    return 0;
}
