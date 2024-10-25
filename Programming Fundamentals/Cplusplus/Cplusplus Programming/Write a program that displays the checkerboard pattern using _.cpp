#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the checkerboard: ";
    cin >> size;

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if ((i+j) % 2 == 0) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}
