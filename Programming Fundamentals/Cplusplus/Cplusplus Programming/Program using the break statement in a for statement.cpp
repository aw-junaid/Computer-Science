#include <iostream>
using namespace std;

int main() {
    int target = 5;

    // Loop from 1 to 10
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";

        // If we have reached our target number, break out of the loop
        if (i == target) {
            cout << "(Target reached)" << endl;
            break;
        }
    }

    return 0;
}
