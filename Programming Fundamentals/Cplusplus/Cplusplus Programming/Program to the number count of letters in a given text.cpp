#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string text;
    int count = 0;

    cout << "Enter a text: ";
    getline(cin, text);

    for(int i = 0; i < text.length(); i++) {
        if(isalpha(text[i])) { // check if the character is an alphabet
            count++;
        }
    }

    cout << "The number of letters in the text is: " << count << endl;

    return 0;
}
