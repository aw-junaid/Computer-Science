#include <iostream>
using namespace std;

int main() {
   int matrix1[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
   int matrix2[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

   bool equal = true;

   // Loop through all elements of the matrices and check if they are equal
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (matrix1[i][j] != matrix2[i][j]) {
            equal = false;
            break;
         }
      }
      if (!equal) {
         break;
      }
   }

   // Output the result
   if (equal) {
      cout << "Matrices are equal." << endl;
   } else {
      cout << "Matrices are not equal." << endl;
   }

   return 0;
}
