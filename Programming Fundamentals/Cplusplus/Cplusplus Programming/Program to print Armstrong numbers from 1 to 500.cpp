#include <iostream>
using namespace std;

int main() {
   int num, sum, rem, i;
   cout << "Armstrong numbers between 1 to 500:" << endl;
   for (i = 1; i <= 500; i++) {
      sum = 0;
      num = i;
      while (num > 0) {
         rem = num % 10;
         sum += (rem * rem * rem);
         num = num / 10;
      }
      if (sum == i) {
         cout << i << " ";
      }
   }
   return 0;
}

