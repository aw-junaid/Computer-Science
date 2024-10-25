#include <iostream>
using namespace std;

// Function to convert meters to feet
double metersToFeet(double meters) {
    return meters * 3.28084;
}

// Function to convert feet to meters
double feetToMeters(double feet) {
    return feet / 3.28084;
}

// Function to convert kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.20462;
}

int main() {
    int choice;
    double value;

    cout << "Metric Conversion Assistant" << endl;
    cout << "--------------------------" << endl;

    do {
        cout << endl << "Select an option:" << endl;
        cout << "1. Meters to Feet" << endl;
        cout << "2. Feet to Meters" << endl;
        cout << "3. Kilograms to Pounds" << endl;
        cout << "4. Pounds to Kilograms" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter meters: ";
                cin >> value;
                cout << value << " meters is " << metersToFeet(value) << " feet." << endl;
                break;
            case 2:
                cout << "Enter feet: ";
                cin >> value;
                cout << value << " feet is " << feetToMeters(value) << " meters." << endl;
                break;
            case 3:
                cout << "Enter kilograms: ";
                cin >> value;
                cout << value << " kilograms is " << kilogramsToPounds(value) << " pounds." << endl;
                break;
            case 4:
                cout << "Enter pounds: ";
                cin >> value;
                cout << value << " pounds is " << poundsToKilograms(value) << " kilograms." << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
