#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    int len;

    cout << "Enter a string: ";
    cin >> str;

    len = strlen(str);

    cout << "Length of the string is: " << len << endl;

    return 0;
}
