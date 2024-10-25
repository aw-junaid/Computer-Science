#include <iostream>
using namespace std;

int main() {
   int matrix[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
   int row_sum[3] = {0}; // Initialize all elements to zero
   int col_sum[3] = {0}; // Initialize all elements to zero

   // Calculate the sum of each row
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         row_sum[i] += matrix[i][j];
      }
   }

   // Calculate the sum of each column
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         col_sum[j] += matrix[i][j];
      }
   }

   // Output the row sums
   cout << "Row sums: ";
   for (int i = 0; i < 3; i++) {
      cout << row_sum[i] << " ";
   }
   cout << endl;

   // Output the column sums
   cout << "Column sums: ";
   for (int i = 0; i < 3; i++) {
      cout << col_sum[i] << " ";
   }
   cout << endl;

   return 0;
}
