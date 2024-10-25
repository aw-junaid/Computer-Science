#include <iostream>
#include <string>

int countSubstr(std::string str, std::string sub) {
    int count = 0;
    size_t pos = str.find(sub, 0);
    while (pos != std::string::npos) {
        count++;
        pos = str.find(sub, pos + sub.length());
    }
    return count;
}

int main() {
    std::string str = "the quick brown fox jumps over the lazy dog";
    std::string sub = "the";
    int count = countSubstr(str, sub);
    std::cout << "Number of occurrences of \"" << sub << "\": " << count << std::endl;
    return 0;
}
