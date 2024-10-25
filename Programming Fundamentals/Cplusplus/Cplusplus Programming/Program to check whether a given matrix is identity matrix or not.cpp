#include <iostream>
using namespace std;

int main() {
   int matrix[3][3] = {{1, 0, 0},
                       {0, 1, 0},
                       {0, 0, 1}};

   bool is_identity = true;

   // Loop through all elements of the matrix and check if they are equal to 1 on the diagonal and 0 elsewhere
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (i == j && matrix[i][j] != 1) {
            is_identity = false;
            break;
         }
         if (i != j && matrix[i][j] != 0) {
            is_identity = false;
            break;
         }
      }
      if (!is_identity) {
         break;
      }
   }

   // Output the result
   if (is_identity) {
      cout << "Matrix is an identity matrix." << endl;
   } else {
      cout << "Matrix is not an identity matrix." << endl;
   }

   return 0;
}
