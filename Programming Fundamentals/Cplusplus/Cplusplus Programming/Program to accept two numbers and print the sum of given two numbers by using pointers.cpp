#include <iostream>
using namespace std;

int main() {
   int num1, num2, *ptr1, *ptr2, sum;

   cout << "Enter first number: ";
   cin >> num1;

   cout << "Enter second number: ";
   cin >> num2;

   ptr1 = &num1;
   ptr2 = &num2;

   sum = *ptr1 + *ptr2;

   cout << "Sum of " << *ptr1 << " and " << *ptr2 << " is " << sum << endl;

   return 0;
}
