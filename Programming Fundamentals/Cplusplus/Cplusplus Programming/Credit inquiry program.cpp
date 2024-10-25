#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if a given credit card number is valid
bool isValidCCNum(string ccNum) {
    int sum = 0;
    bool alternate = false;
    for (int i = ccNum.length() - 1; i >= 0; i--) {
        int digit = ccNum[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

// Function to print a credit report for a given user
void printCreditReport(string username) {
    // Open file for reading
    ifstream inputFile("credit.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Search for user in file
    string line;
    bool userFound = false;
    while (getline(inputFile, line)) {
        if (line == username) {
            userFound = true;
            break;
        }
    }

    // Print credit report for user if found
    if (userFound) {
        cout << "Credit report for " << username << ":" << endl;
        getline(inputFile, line); // skip username line
        cout << "Credit score: " << line << endl;
        getline(inputFile, line); // skip credit score line
        cout << "Credit history: " << endl;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "User not found." << endl;
    }

    inputFile.close();
}

int main() {
    string ccNum;
    cout << "Enter your credit card number: ";
    cin >> ccNum;
    if (isValidCCNum(ccNum)) {
        cout << "Credit card number is valid." << endl;
        string username;
        cout << "Enter your username: ";
        cin >> username;
        printCreditReport(username);
    } else {
        cout << "Invalid credit card number." << endl;
    }
    return 0;
}
