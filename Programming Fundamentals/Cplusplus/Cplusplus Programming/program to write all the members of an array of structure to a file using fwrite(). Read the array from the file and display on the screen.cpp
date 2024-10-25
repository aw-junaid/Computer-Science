#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    float height;
};

int main() {
    // create an array of structures
    Person people[3] = {{"John", 25, 1.75},
                        {"Mary", 30, 1.68},
                        {"Bob", 20, 1.80}};

    // write the array of structures to a file
    ofstream outfile("people.dat", ios::binary);
    if (!outfile) {
        cerr << "Error: Failed to open file for writing." << endl;
        return 1;
    }
    outfile.write((char*)&people, sizeof(people));
    outfile.close();

    // read the array of structures from the file
    Person readPeople[3];
    ifstream infile("people.dat", ios::binary);
    if (!infile) {
        cerr << "Error: Failed to open file for reading." << endl;
        return 1;
    }
    infile.read((char*)&readPeople, sizeof(readPeople));
    infile.close();

    // display the array of structures
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << readPeople[i].name << endl;
        cout << "Age: " << readPeople[i].age << endl;
        cout << "Height: " << readPeople[i].height << endl;
        cout << endl;
    }

    return 0;
}
