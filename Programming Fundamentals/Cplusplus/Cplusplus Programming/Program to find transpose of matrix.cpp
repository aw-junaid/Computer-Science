#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;

void transpose(int A[][COL], int B[][ROW]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            B[j][i] = A[i][j];
        }
    }
}

void printMatrix(int A[][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[ROW][COL] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[COL][ROW];
    transpose(A, B);
    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Transpose of matrix A:" << endl;
    printMatrix(B);
    return 0;
}
