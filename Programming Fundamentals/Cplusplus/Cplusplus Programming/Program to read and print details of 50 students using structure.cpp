#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};

int main() {
    // declare an array of 50 students
    Student students[50];

    // read details of 50 students from user
    for (int i = 0; i < 50; i++) {
        cout << "\nEnter details of student " << i+1 << endl;
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cout << "Marks: ";
        cin >> students[i].marks;
        cin.ignore(); // to clear input buffer
    }

    // display details of all 50 students
    cout << "\nDetails of all 50 students:" << endl;
    for (int i = 0; i < 50; i++) {
        cout << "\nStudent " << i+1 << " Details" << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Marks: " << students[i].marks << endl;
    }

    return 0;
}
