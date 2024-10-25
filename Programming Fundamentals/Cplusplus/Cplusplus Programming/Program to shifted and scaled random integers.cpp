#include <iostream>
#include <random>

using namespace std;

int main() {
    // Define the range of the random integer (0 to 99)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    // Generate and print a random integer
    int num = dis(gen);
    cout << "Random integer: " << num << endl;

    // Prompt the user for the shift and scale values
    int shift, scale;
    cout << "Enter the shift value: ";
    cin >> shift;
    cout << "Enter the scale value: ";
    cin >> scale;

    // Shift and scale the random integer
    int shifted_num = num + shift;
    int scaled_num = shifted_num * scale;

    // Print the shifted and scaled integer
    cout << "Shifted and scaled integer: " << scaled_num << endl;

    return 0;
}
