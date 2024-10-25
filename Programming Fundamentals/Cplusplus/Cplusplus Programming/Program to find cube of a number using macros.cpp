#include <iostream>
#define CUBE(x) (x * x * x)

using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Cube of " << num << " is: " << CUBE(num) << endl;
    return 0;
}
