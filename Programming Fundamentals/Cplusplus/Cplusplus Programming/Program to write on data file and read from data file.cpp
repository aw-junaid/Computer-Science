#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open a file for writing
    ofstream outFile("data.txt");

    // Write some data to the file
    outFile << "Hello, world!\n";
    outFile << "This is some data.\n";
    outFile << "12345\n";

    // Close the file
    outFile.close();

    // Open the file for reading
    ifstream inFile("data.txt");

    // Read the data from the file
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the file
    inFile.close();

    return 0;
}
