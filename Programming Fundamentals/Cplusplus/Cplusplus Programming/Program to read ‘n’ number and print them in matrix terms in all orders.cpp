#include <iostream>

using namespace std;

int main() {
    int n, rows, cols;
    cout << "Enter the number of elements: ";
    cin >> n;

    // calculate the number of rows and columns in the matrix
    rows = cols = sqrt(n);
    if (rows * cols < n) {
        cols++;
    }

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // print the elements in row-major order
    cout << "Row-major order:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (index < n) {
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    // print the elements in column-major order
    cout << "Column-major order:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            int index = i * cols + j;
            if (index < n) {
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
