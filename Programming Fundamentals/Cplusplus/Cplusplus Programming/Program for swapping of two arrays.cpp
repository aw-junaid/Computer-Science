#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5; // change this to adjust the size of the arrays

void swapArrays(int arr1[], int arr2[], int size) {
   for (int i = 0; i < size; i++) {
      int temp = arr1[i];
      arr1[i] = arr2[i];
      arr2[i] = temp;
   }
}

int main() {
   int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
   int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};

   // Before swapping
   cout << "Array 1: ";
   for (int i = 0; i < ARRAY_SIZE; i++) {
      cout << array1[i] << " ";
   }
   cout << endl;
   cout << "Array 2: ";
   for (int i = 0; i < ARRAY_SIZE; i++) {
      cout << array2[i] << " ";
   }
   cout << endl;

   // Swap the arrays
   swapArrays(array1, array2, ARRAY_SIZE);

   // After swapping
   cout << "Array 1: ";
   for (int i = 0; i < ARRAY_SIZE; i++) {
      cout << array1[i] << " ";
   }
   cout << endl;
   cout << "Array 2: ";
   for (int i = 0; i < ARRAY_SIZE; i++) {
      cout << array2[i] << " ";
   }
   cout << endl;

   return 0;
}
