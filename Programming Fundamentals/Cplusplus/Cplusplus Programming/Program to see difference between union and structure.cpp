#include<iostream>
using namespace std;

struct ExampleStruct {
    int a;
    char b;
    float c;
};

union ExampleUnion {
    int a;
    char b;
    float c;
};

int main() {
    ExampleStruct s;
    ExampleUnion u;

    cout << "Size of Structure: " << sizeof(s) << endl;   // Output: 12
    cout << "Size of Union: " << sizeof(u) << endl;       // Output: 4

    s.a = 10;
    s.b = 'A';
    s.c = 1.5;

    u.a = 10;
    cout << "a: " << u.a << endl;    // Output: 10
    cout << "b: " << u.b << endl;    // Output: (Empty)
    cout << "c: " << u.c << endl;    // Output: 2.8026e-45

    u.b = 'A';
    cout << "a: " << u.a << endl;    // Output: 167772160 (Garbage Value)
    cout << "b: " << u.b << endl;    // Output: A
    cout << "c: " << u.c << endl;    // Output: 2.8026e-45

    return 0;
}
