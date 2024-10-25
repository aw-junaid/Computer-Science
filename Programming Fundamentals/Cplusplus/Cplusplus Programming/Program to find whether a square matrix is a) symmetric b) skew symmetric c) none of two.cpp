#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int n, i, j, flag = 1;
    int mat[MAX][MAX];

    cout << "Enter the size of the square matrix: ";
    cin >> n;

    cout << "Enter the elements of the matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // Check if matrix is symmetric
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    if (flag == 1) {
        cout << "Matrix is symmetric\n";
    }

    // Check if matrix is skew-symmetric
    flag = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] != -mat[j][i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    if (flag == 1) {
        cout << "Matrix is skew-symmetric\n";
    }

    // Check if matrix is none of the two
    if (flag == 0) {
        cout << "Matrix is none of the two\n";
    }

    return 0;
}
