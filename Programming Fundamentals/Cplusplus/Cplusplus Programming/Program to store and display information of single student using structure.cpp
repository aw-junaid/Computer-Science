#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};

int main() {
    // declare a Student variable
    Student s;

    // read information from user
    cout << "Enter name of student: ";
    getline(cin, s.name);
    cout << "Enter roll number of student: ";
    cin >> s.rollNo;
    cout << "Enter marks of student: ";
    cin >> s.marks;

    // display information of student
    cout << "\nStudent Information" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNo << endl;
    cout << "Marks: " << s.marks << endl;

    return 0;
}
