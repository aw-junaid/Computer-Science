#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("filename.txt"); // replace with the name of your file
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}
