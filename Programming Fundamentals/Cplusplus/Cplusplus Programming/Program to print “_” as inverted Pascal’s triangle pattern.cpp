#include <iostream>
using namespace std;

int main() {
    int rows, num=1;
    cout << "Enter the number of rows: ";
    cin >> rows;

    for(int i=rows; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }
        for(int j=1; j<=num; j++) {
            cout << "  ";
        }
        num++;
        cout << endl;
    }
    return 0;
}
