#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    int i, j, flag = 0;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    for(i = 0; str1[i] != '\0'; i++);
    for(j = 0; str2[j] != '\0'; j++);

    if(i != j) {
        cout << "The two strings are not equal" << endl;
        return 0;
    }

    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        cout << "The two strings are equal" << endl;
    } else {
        cout << "The two strings are not equal" << endl;
    }

    return 0;
}
