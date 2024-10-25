#include <iostream>
using namespace std;

const int ROWS = 3; // Number of rows in the 2D array
const int COLS = 4; // Number of columns in the 2D array

int main() {
    int arr[ROWS][COLS] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {90, 100, 110, 120}}; // The 2D array to be checked
    int largest = arr[0][0]; // Initializing the largest variable to the first element in the array
    int secondLargest = arr[0][0]; // Initializing the second largest variable to the first element in the array

    // Looping through the entire 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > largest) {
                secondLargest = largest; // The current largest number becomes the second largest
                largest = arr[i][j]; // Updating the largest variable with the new largest number
            }
            else if (arr[i][j] > secondLargest && arr[i][j] != largest) {
                secondLargest = arr[i][j]; // Updating the second largest variable with the new second largest number
            }
        }
    }

    cout << "The largest number in the 2D array is: " << largest << endl;
    cout << "The second largest number in the 2D array is: " << secondLargest << endl;

    return 0;
}
