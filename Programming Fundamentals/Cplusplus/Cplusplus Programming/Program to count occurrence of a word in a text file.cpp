#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename, word;
    int count = 0;
    cout << "Enter the file name: ";
    cin >> filename;
    cout << "Enter the word to be counted: ";
    cin >> word;

    ifstream file(filename);
    string temp;

    while (file >> temp) {
        if (temp == word) {
            count++;
        }
    }

    cout << "The word '" << word << "' appears " << count << " times in the file." << endl;
    return 0;
}
