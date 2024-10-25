#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string line;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, line);

    std::stack<char> s;
    for (char c : line) {
        s.push(c);
    }

    std::cout << "The line in reverse order is: ";
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
