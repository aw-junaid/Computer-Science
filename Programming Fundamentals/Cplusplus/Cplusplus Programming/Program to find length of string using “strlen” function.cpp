#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    int length = strlen(str);

    cout << "The length of the string is: " << length << endl;

    return 0;
}
