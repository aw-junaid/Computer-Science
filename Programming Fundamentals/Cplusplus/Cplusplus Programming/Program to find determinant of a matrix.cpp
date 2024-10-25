#include <iostream>
using namespace std;

int main() {
    int A[2][2] = { // define the input matrix
        {1, 2},
        {3, 4}
    };
    int det = A[0][0] * A[1][1] - A[0][1] * A[1][0]; // compute the determinant of the matrix
    cout << "Determinant of the matrix:" << endl;
    cout << det << endl; // print the determinant value
    return 0;
}
