#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt"); // open input file
    string line; // to store each line of the file

    // check if file is opened successfully
    if (!inputFile.is_open()) {
        cout << "Failed to open file." << endl;
        return 1; // exit program with error code
    }

    // read and print each line of the file
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // close input file
    inputFile.close();

    return 0; // exit program successfully
}
