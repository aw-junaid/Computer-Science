#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binaryToHex(string binary) {
    // Pad the binary number with zeros if necessary
    while (binary.length() % 4 != 0) {
        binary = "0" + binary;
    }

    string hex = "";
    for (int i = 0; i < binary.length(); i += 4) {
        string group = binary.substr(i, 4);
        if (group == "0000") hex += "0";
        else if (group == "0001") hex += "1";
        else if (group == "0010") hex += "2";
        else if (group == "0011") hex += "3";
        else if (group == "0100") hex += "4";
        else if (group == "0101") hex += "5";
        else if (group == "0110") hex += "6";
        else if (group == "0111") hex += "7";
        else if (group == "1000") hex += "8";
        else if (group == "1001") hex += "9";
        else if (group == "1010") hex += "A";
        else if (group == "1011") hex += "B";
        else if (group == "1100") hex += "C";
        else if (group == "1101") hex += "D";
        else if (group == "1110") hex += "E";
        else if (group == "1111") hex += "F";
    }

    return hex;
}

int main() {
    string binary = "1010101010101010101010101010101010101010101010101010101010101010";
    string hex = binaryToHex(binary);
    cout << hex << endl; // Output: "AAAAAAAA"
    return 0;
}
