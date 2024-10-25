#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 1; i <= 5; i++) {
        sum += i;
    }

    cout << "The sum of integers from 1 to 5 is " << sum << endl;

    return 0;
}
