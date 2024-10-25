#include <iostream>
#include <string>

using namespace std;

int main() {
    string hexNum;
    cout << "Enter a hexadecimal number: ";
    cin >> hexNum;

    string binNum = "";
    int len = hexNum.length();

    for(int i = 0; i < len; i++) {
        char hexDigit = hexNum[i];
        int decDigit;

        if(hexDigit >= '0' && hexDigit <= '9') {
            decDigit = hexDigit - '0';
        } else if(hexDigit >= 'A' && hexDigit <= 'F') {
            decDigit = hexDigit - 'A' + 10;
        } else if(hexDigit >= 'a' && hexDigit <= 'f') {
            decDigit = hexDigit - 'a' + 10;
        }

        for(int j = 3; j >= 0; j--) {
            if(decDigit >= (1 << j)) {
                binNum += '1';
                decDigit -= (1 << j);
            } else {
                binNum += '0';
            }
        }
    }

    cout << "The binary equivalent is " << binNum << endl;

    return 0;
}
