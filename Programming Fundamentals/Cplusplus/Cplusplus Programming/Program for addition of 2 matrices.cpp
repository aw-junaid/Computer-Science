#include <iostream>
using namespace std;

int main() {
    int rows, cols, i, j;

    cout << "Enter the number of rows and columns of matrix: ";
    cin >> rows >> cols;

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    cout << "Enter the elements of first matrix:\n";

    // input matrix1
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter the elements of second matrix:\n";

    // input matrix2
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }

    // add the two matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "The sum of the two matrices is:\n";

    // print the result matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
