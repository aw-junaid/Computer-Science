#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename, line, newLine;
    int lineNumber;

    // Get the filename from user
    cout << "Enter filename: ";
    cin >> filename;

    // Open the file for reading
    ifstream inFile(filename);

    // Check if the file opened successfully
    if (!inFile) {
        cerr << "Error: Cannot open file '" << filename << "'" << endl;
        return 1;
    }

    // Read the number of the line to replace
    cout << "Enter line number to replace: ";
    cin >> lineNumber;

    // Read the new line to insert
    cout << "Enter new line: ";
    cin.ignore(); // Ignore any newline character left in input buffer
    getline(cin, newLine);

    // Open a temporary file for writing
    ofstream outFile("temp.txt");

    // Check if the file opened successfully
    if (!outFile) {
        cerr << "Error: Cannot open file 'temp.txt'" << endl;
        return 1;
    }

    // Loop through the input file
    int currentLine = 1;
    while (getline(inFile, line)) {
        // Write the new line if the current line matches the specified line number
        if (currentLine == lineNumber) {
            outFile << newLine << endl;
        } else {
            // Write the original line to the temporary file
            outFile << line << endl;
        }
        currentLine++;
    }

    // Close the input and output files
    inFile.close();
    outFile.close();

    // Delete the original file and rename the temporary file
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Line " << lineNumber << " has been replaced with '" << newLine << "' in file '" << filename << "'" << endl;

    return 0;
}
