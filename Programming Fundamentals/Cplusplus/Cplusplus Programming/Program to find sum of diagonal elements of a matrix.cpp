#include <iostream>
using namespace std;

int main() {
   int matrix[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
   int sum = 0;

   // Loop through the diagonal elements of the matrix and add them up
   for (int i = 0; i < 3; i++) {
      sum += matrix[i][i];
   }

   // Output the sum of the diagonal elements
   cout << "Sum of diagonal elements: " << sum << endl;

   return 0;
}
