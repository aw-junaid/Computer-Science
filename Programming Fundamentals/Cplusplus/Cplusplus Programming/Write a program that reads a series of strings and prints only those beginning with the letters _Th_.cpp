#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a series of strings (press Ctrl+Z to end):" << std::endl;
    std::string s;
    while (std::cin >> s) {
        if (s.size() >= 2 && s[0] == 'T' && s[1] == 'h') {
            std::cout << s << std::endl;
        }
    }
    return 0;
}
