#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> filenames = {"file1.txt", "file2.txt", "file3.txt"}; // input filenames
    string output_filename = "output.txt"; // output filename

    ofstream outfile(output_filename, ios::out | ios::binary); // create output file

    for (const string& filename : filenames) {
        ifstream infile(filename, ios::in | ios::binary); // open input file
        if (infile) {
            // read input file and write to output file
            infile.seekg(0, ios::end); // seek to end of file
            size_t size = infile.tellg(); // get size of file
            infile.seekg(0, ios::beg); // seek back to beginning of file
            char* buffer = new char[size]; // allocate buffer
            infile.read(buffer, size); // read file into buffer
            outfile.write(buffer, size); // write buffer to output file
            delete[] buffer; // free buffer memory
            infile.close(); // close input file
        }
        else {
            cerr << "Error: could not open input file '" << filename << "'\n";
        }
    }

    outfile.close(); // close output file
    cout << "Concatenation complete.\n";

    return 0;
}
