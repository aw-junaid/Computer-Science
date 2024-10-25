#include <iostream>
using namespace std;

int main() {
   int matrix[3][3] = {{0, 1, 0},
                       {0, 0, 0},
                       {0, 0, 2}};

   int num_zeros = 0;

   // Loop through all elements of the matrix and count the number of zeros
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (matrix[i][j] == 0) {
            num_zeros++;
         }
      }
   }

   // Calculate the ratio of zeros to non-zeros
   float ratio = (float) num_zeros / (3 * 3);

   // Output the result
   if (ratio > 0.5) {
      cout << "Matrix is a sparse matrix." << endl;
   } else {
      cout << "Matrix is a dense matrix." << endl;
   }

   return 0;
}
