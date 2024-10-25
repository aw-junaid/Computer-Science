#include <iostream>
using namespace std;

int main() {
   int matrix[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
   int odd_freq = 0;
   int even_freq = 0;

   // Count the frequency of odd and even numbers
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (matrix[i][j] % 2 == 0) {
            even_freq++;
         } else {
            odd_freq++;
         }
      }
   }

   // Output the results
   cout << "Frequency of even numbers: " << even_freq << endl;
   cout << "Frequency of odd numbers: " << odd_freq << endl;

   return 0;
}
