#include <iostream>
using namespace std;

int main() {
    int num1 = 10, num2 = 5, result;

    // Subtract num2 from num1 using bitwise NOT and AND operators
    result = num1 + (~num2 + 1);

    // Display the result to the console
    cout << "The result of subtracting " << num2 << " from " << num1 << " is " << result << endl;

    return 0;
}
