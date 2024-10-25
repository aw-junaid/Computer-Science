#include <iostream>
using namespace std;

int main() {
    int num, factor;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter a factor: ";
    cin >> factor;
    if (num % factor == 0) {
        cout << num << " is a multiple of " << factor << endl;
    }
    else {
        cout << num << " is not a multiple of " << factor << endl;
    }
    return 0;
}
