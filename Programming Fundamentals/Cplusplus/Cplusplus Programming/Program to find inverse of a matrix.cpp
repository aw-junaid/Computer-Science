#include <iostream>
using namespace std;

const int N = 3; // size of matrix

void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(row != p && col != q) {
                temp[i][j++] = A[row][col];
                if(j == n-1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(float A[N][N], int n) {
    float det = 0;
    if(n == 1) {
        return A[0][0];
    }
    float temp[N][N];
    int sign = 1;
    for(int i = 0; i < n; i++) {
        getCofactor(A, temp, 0, i, n);
        det += sign * A[0][i] * determinant(temp, n-1);
        sign = -sign;
    }
    return det;
}

void adjugate(float A[N][N], float adj[N][N]) {
    int sign = 1;
    float temp[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            getCofactor(A, temp, i, j, N);
            sign = ((i+j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, N-1);
        }
    }
}

bool inverse(float A[N][N], float inverse[N][N]) {
    float det = determinant(A, N);
    if(det == 0) {
        cout << "Matrix is not invertible" << endl;
        return false;
    }
    float adj[N][N];
    adjugate(A, adj);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            inverse[i][j] = adj[i][j] / det;
        }
    }
    return true;
}

void printMatrix(float A[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    float A[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    float inverseA[N][N];
    if(inverse(A, inverseA)) {
        cout << "Inverse of matrix A:" << endl;
        printMatrix(inverseA);
    }
    return 0;
}
