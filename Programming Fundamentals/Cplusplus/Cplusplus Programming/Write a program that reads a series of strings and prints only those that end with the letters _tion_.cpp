#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    // read strings from user
    cout << "Enter strings (type 'quit' to stop):" << endl;
    getline(cin, str);

    // check each string for "tion" at the end
    while (str != "quit") {
        int length = str.length();
        if (length >= 4 && str[length-1] == 'n' && str[length-2] == 'o' && str[length-3] == 'i' && str[length-4] == 't') {
            cout << str << endl;
        }
        getline(cin, str);
    }

    return 0;
}
