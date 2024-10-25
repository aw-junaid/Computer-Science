#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    // Evaluate the expression
    double result = 0.0;
    try {
        result = stod(expression);
    } catch (const invalid_argument& e) {
        cerr << "Invalid input: " << expression << endl;
        return 1;
    }

    // Print the result
    cout << "Result: " << result << endl;
    return 0;
}
