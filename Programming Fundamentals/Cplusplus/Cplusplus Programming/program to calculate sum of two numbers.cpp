#include <iostream>  // Include input/output stream library

int main() {  // Main function
  int num1, num2, sum;  // Declare integer variables to store input numbers and sum
  std::cout << "Enter first number: ";  // Prompt user to enter first number
  std::cin >> num1;  // Read first input number from console and store in num1
  std::cout << "Enter second number: ";  // Prompt user to enter second number
  std::cin >> num2;  // Read second input number from console and store in num2
  sum = num1 + num2;  // Calculate sum of num1 and num2 and store in sum
  std::cout << "Sum of " << num1 << " and " << num2 << " is " << sum << std::endl;  // Print sum of input numbers to console
  return 0;  // End main function and return 0 to indicate successful execution
}
