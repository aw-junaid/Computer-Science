#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "hello";
    char str2[] = "world";

    int result = strcmp(str1, str2);

    if(result == 0) {
        cout << "The two strings are equal" << endl;
    } else if(result < 0) {
        cout << "The first string is less than the second string" << endl;
    } else {
        cout << "The first string is greater than the second string" << endl;
    }

    return 0;
}
