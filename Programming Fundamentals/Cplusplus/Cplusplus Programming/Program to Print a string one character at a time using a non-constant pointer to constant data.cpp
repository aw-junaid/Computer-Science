#include <iostream>
using namespace std;

int main() {
    const char* str = "Hello, world!";
    const char* ptr = str;

    while (*ptr != '\0') {
        cout << *ptr;
        ptr++;
    }

    return 0;
}
