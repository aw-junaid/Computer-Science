#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Record {
    int id;
    char name[20];
    double balance;
};

int main() {
    // Open the file for writing in binary mode
    fstream file("records.dat", ios::out | ios::binary);

    // Check if the file is open
    if (!file) {
        cerr << "Error opening file\n";
        exit(1);
    }

    // Get the number of records to write
    int num_records;
    cout << "Enter the number of records to write: ";
    cin >> num_records;

    // Write the records to the file
    for (int i = 0; i < num_records; i++) {
        Record record;

        // Get the record data from the user
        cout << "Enter record #" << i+1 << " data:\n";
        cout << "ID: ";
        cin >> record.id;
        cin.ignore(); // Ignore the newline character
        cout << "Name: ";
        cin.getline(record.name, 20);
        cout << "Balance: ";
        cin >> record.balance;

        // Calculate the position to write the record to
        int position = (record.id - 1) * sizeof(Record);

        // Move the file pointer to the correct position
        file.seekp(position);

        // Write the record to the file
        file.write(reinterpret_cast<char*>(&record), sizeof(Record));
    }

    // Close the file
    file.close();

    cout << "Records written to file\n";

    return 0;
}
