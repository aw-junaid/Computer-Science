#include <iostream>
using namespace std;

const int ROWS_1 = 2; // number of rows in first matrix
const int COLS_1 = 3; // number of columns in first matrix
const int ROWS_2 = 3; // number of rows in second matrix
const int COLS_2 = 2; // number of columns in second matrix

void matrixMultiplication(int matrix1[][COLS_1], int matrix2[][COLS_2], int result[][COLS_2]) {
    // Initialize result matrix with 0s
    for(int i = 0; i < ROWS_1; i++) {
        for(int j = 0; j < COLS_2; j++) {
            result[i][j] = 0;
        }
    }
    // Perform matrix multiplication
    for(int i = 0; i < ROWS_1; i++) {
        for(int j = 0; j < COLS_2; j++) {
            for(int k = 0; k < ROWS_2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][COLS_2]) {
    for(int i = 0; i < ROWS_1; i++) {
        for(int j = 0; j < COLS_2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix1[ROWS_1][COLS_1] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int matrix2[ROWS_2][COLS_2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    int result[ROWS_1][COLS_2];

    matrixMultiplication(matrix1, matrix2, result);

    cout << "Result of matrix multiplication:" << endl;
    printMatrix(result);

    return 0;
}
