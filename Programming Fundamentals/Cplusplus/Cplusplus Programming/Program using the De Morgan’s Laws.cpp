#include <iostream>
using namespace std;

int main() {
   int A = 1, B = 0;

   // Original expressions
   if (!(A && B)) {
      cout << "!(A && B) is true." << endl;
   }

   if (!(A || B)) {
      cout << "!(A || B) is true." << endl;
   }

   // Equivalent negated expressions
   if ((!A || !B)) {
      cout << "(!A || !B) is true." << endl;
   }

   if ((!A && !B)) {
      cout << "(!A && !B) is true." << endl;
   }

   return 0;
}
