#include <iostream>
using namespace std;

int main() {
   string name;
   cout << "Enter a name: ";
   getline(cin, name);  // read the full name including spaces

   // print the first character of the name and each character after a space
   for (int i = 0; i < name.length(); i++) {
      if (i == 0 || name[i - 1] == ' ') {
         cout << name[i];
      }
   }

   return 0;
}
