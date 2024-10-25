#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, substr;
    cout << "Enter the main string: ";
    getline(cin, str);
    cout << "Enter the substring: ";
    getline(cin, substr);

    int n = str.length();
    int m = substr.length();

    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(str[i + j] != substr[j])
                break;
        }
        if(j == m) {
            cout << "Substring found at index " << i << endl;
            return 0;
        }
    }
    cout << "Substring not found!" << endl;
    return 0;
}
