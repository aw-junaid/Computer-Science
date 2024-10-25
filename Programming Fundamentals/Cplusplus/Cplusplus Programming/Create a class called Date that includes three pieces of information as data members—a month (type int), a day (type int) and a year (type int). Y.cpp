#include <iostream>

class Date {
public:
    // Default constructor initializes date to 01/01/2000
    Date() : month(1), day(1), year(2000) {}

    // Constructor to set the date to a specific month, day, and year
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    // Accessor functions to get the month, day, and year
    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    int getYear() const {
        return year;
    }

    // Mutator functions to set the month, day, and year
    void setMonth(int m) {
        month = m;
    }

    void setDay(int d) {
        day = d;
    }

    void setYear(int y) {
        year = y;
    }

    // Function to display the date in the format mm/dd/yyyy
    void displayDate() const {
        std::cout << month << '/' << day << '/' << year << std::endl;
    }

private:
    int month;
    int day;
    int year;
};
