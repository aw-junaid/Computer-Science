#include <iostream>
#include <string>

using namespace std;

class GradeBook {
public:
    void displayMessage() {
        cout << "Welcome to the Grade Book program!" << endl;
    }
};

int main() {
    GradeBook myGradeBook;
    myGradeBook.displayMessage();

    return 0;
}
