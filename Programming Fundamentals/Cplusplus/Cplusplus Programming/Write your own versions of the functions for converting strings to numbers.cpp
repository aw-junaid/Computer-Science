#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int stringToInt(string str) {
    int num = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    for (; i < str.size(); i++) {
        num += (str[i] - '0') * pow(10, str.size() - i - 1);
    }

    return sign * num;
}

int main() {
    string str = "-1234";
    int num = stringToInt(str);
    cout << "String: " << str << endl;
    cout << "Integer: " << num << endl;
    return 0;
}
