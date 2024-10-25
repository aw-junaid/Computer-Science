#include <iostream>
using namespace std;

int main() {
   int i;
   for(i=1; i<=10; i++) {
      if(i==5) {
         continue; // skip rest of the loop body and continue with next iteration
      }
      cout << i << " "; // print the current value of i
   }
   return 0;
}
