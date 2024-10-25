#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char name[50];
    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello, " << name << "!" << endl;

    int len = strlen(name);
    cout << "Length of name: " << len << endl;

    char copy[50];
    strcpy(copy, name);
    cout << "Copy of name: " << copy << endl;

    char greeting[50] = "Hello, ";
    strcat(greeting, name);
    cout << greeting << "!" << endl;

    return 0;
}
