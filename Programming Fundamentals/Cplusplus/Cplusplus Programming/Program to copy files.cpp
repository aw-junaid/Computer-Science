#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream in_file;
   ofstream out_file;
   char ch;
   string filename1, filename2;
   cout << "Enter input file name: ";
   cin >> filename1;
   cout << "Enter output file name: ";
   cin >> filename2;
   in_file.open(filename1);
   out_file.open(filename2);
   if (!in_file) {
      cout << "Unable to open input file!";
      return 1;
   }
   if (!out_file) {
      cout << "Unable to open output file!";
      return 1;
   }
   while (in_file.get(ch)) {
      out_file.put(ch);
   }
   cout << "File copied successfully!";
   in_file.close();
   out_file.close();
   return 0;
}
