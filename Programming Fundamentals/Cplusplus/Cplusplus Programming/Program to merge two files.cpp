#include <iostream>
#include <fstream>
using namespace std;

int main() {
   // open first file in read mode
   ifstream file1("file1.txt");

   // open second file in read mode
   ifstream file2("file2.txt");

   // open new file in write mode
   ofstream mergeFile("mergeFile.txt");

   // check if both files are open or not
   if (!file1.is_open() || !file2.is_open()) {
      cout << "Failed to open files!";
      return 0;
   }

   // read content of first file and write to merge file
   string line;
   while (getline(file1, line)) {
      mergeFile << line << "\n";
   }

   // read content of second file and write to merge file
   while (getline(file2, line)) {
      mergeFile << line << "\n";
   }

   // close all the files
   file1.close();
   file2.close();
   mergeFile.close();

   cout << "Merged file created successfully!";
   return 0;
}
