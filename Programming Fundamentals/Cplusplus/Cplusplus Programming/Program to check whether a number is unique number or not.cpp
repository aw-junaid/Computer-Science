#include <iostream>
#include <unordered_set>

using namespace std;

bool isUniqueNumber(int num) {
    unordered_set<int> seen;
    while (num > 0) {
        int digit = num % 10;
        if (seen.count(digit)) {
            return false;
        }
        seen.insert(digit);
        num /= 10;
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isUniqueNumber(num)) {
        cout << num << " is a unique number." << endl;
    } else {
        cout << num << " is not a unique number." << endl;
    }
    return 0;
}
