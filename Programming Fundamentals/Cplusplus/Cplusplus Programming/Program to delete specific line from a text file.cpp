#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("input.txt");  // input file
    ofstream outFile("output.txt");  // output file
    string line;
    int lineNumber, currentLine = 0;

    // Get the line number to delete
    cout << "Enter the line number to delete: ";
    cin >> lineNumber;

    // Check if the file is open
    if (inFile.is_open() && outFile.is_open()) {
        // Read the input file line by line
        while (getline(inFile, line)) {
            currentLine++;  // Increment the current line number
            // Write to the output file only if the line number is not equal to the line to be deleted
            if (currentLine != lineNumber) {
                outFile << line << endl;
            }
        }

        // Close the files
        inFile.close();
        outFile.close();

        // Remove the input file and rename the output file to input file name
        remove("input.txt");
        rename("output.txt", "input.txt");

        cout << "Line " << lineNumber << " has been deleted." << endl;
    }
    else {
        cout << "Error opening file(s)!" << endl;
    }

    return 0;
}
