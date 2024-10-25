#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3, num4, maxNum;

    cout << "Enter four numbers: ";
    cin >> num1 >> num2 >> num3 >> num4;

    maxNum = (num1 > num2) ? ((num1 > num3) ? ((num1 > num4) ? num1 : num4) : ((num3 > num4) ? num3 : num4)) : ((num2 > num3) ? ((num2 > num4) ? num2 : num4) : ((num3 > num4) ? num3 : num4));

    cout << "The greatest number among " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << " is: " << maxNum << endl;

    return 0;
}
