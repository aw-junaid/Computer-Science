#include <iostream>
using namespace std;

int main()
{
    int seconds, minutes, hours, total_seconds;

    cout << "Enter time in seconds: ";
    cin >> total_seconds;

    hours = total_seconds / 3600;
    minutes = (total_seconds % 3600) / 60;
    seconds = (total_seconds % 3600) % 60;

    cout << "Time is " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;

    return 0;
}
