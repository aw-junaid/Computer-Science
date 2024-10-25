#include <iostream>
using namespace std;

int digitalRoot(int num) {
    if (num == 0) {
        return 0;
    } else if (num % 9 == 0) {
        return 9;
    } else {
        return num % 9;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int root = digitalRoot(num);
    cout << "The digital root of " << num << " is " << root << endl;
    return 0;
}
