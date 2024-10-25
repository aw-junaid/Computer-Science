#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt or decrypt a file using a key
void encrypt_decrypt_file(string file_name, string key, bool encrypt) {
    ifstream in_file(file_name, ios::binary);  // Open input file
    ofstream out_file(file_name + (encrypt ? ".enc" : ".dec"), ios::binary);  // Open output file

    // Calculate length of key and read input file
    int key_length = key.length();
    char c;
    int i = 0;

    // Loop through input file, XOR each character with the key, and write to output file
    while (in_file.get(c)) {
        char k = key[i % key_length];
        if (encrypt) {
            c = c ^ k;
        } else {
            c = c ^ k;
        }
        out_file.put(c);
        i++;
    }

    // Close files
    in_file.close();
    out_file.close();
}

int main() {
    string file_name, key;
    bool encrypt;

    // Get file name and key from user
    cout << "Enter file name: ";
    cin >> file_name;
    cout << "Enter key: ";
    cin >> key;

    // Ask user whether to encrypt or decrypt file
    char choice;
    do {
        cout << "Do you want to encrypt (e) or decrypt (d) the file? ";
        cin >> choice;
    } while (choice != 'e' && choice != 'd');

    encrypt = (choice == 'e');

    // Call function to encrypt or decrypt file
    encrypt_decrypt_file(file_name, key, encrypt);

    cout << "Done!\n";

    return 0;
}
