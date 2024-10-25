#include <iostream>
using namespace std;

const int MATRIX_SIZE = 3; // change this to adjust the size of the matrix

void printUpperTriangular(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    cout << "Upper Triangular Matrix: " << endl;
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            if(j >= i) {
                cout << matrix[i][j] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printUpperTriangular(matrix);

    return 0;
}
