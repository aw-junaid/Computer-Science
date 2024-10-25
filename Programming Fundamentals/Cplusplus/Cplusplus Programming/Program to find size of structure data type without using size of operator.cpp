#include <iostream>
using namespace std;

struct MyStruct {
    int x;
    char c;
    float f;
};

int main() {
    MyStruct* ptr1 = nullptr;
    MyStruct* ptr2 = nullptr;

    ptr1 = new MyStruct;
    ptr2 = ptr1 + 1;

    cout << "Size of MyStruct = " << (char*)ptr2 - (char*)ptr1 << " bytes" << endl;

    delete ptr1;
    ptr1 = nullptr;
    ptr2 = nullptr;

    return 0;
}
