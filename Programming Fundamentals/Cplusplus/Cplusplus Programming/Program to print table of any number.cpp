#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter a number to print its multiplication table: ";
    cin >> num;

    cout << "Multiplication table of " << num << ":" << endl;

    for(int i=1; i<=10; i++) {
        cout << num << " x " << i << " = " << num*i << endl;
    }

    return 0;
}
