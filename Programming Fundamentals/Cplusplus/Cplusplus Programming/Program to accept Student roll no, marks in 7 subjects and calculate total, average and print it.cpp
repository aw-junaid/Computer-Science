#include <iostream>
using namespace std;

int main() {
    int rollNo;
    float marks[7], total = 0, average;

    cout << "Enter the student's roll number: ";
    cin >> rollNo;

    for(int i=0; i<7; i++) {
        cout << "Enter the marks in subject " << i+1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    average = total / 7;

    cout << "Roll No: " << rollNo << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Average Marks: " << average << endl;

    return 0;
}
