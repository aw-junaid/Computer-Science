#include <iostream>
using namespace std;

int binaryToDecimal(int n) {
    int ans = 0, base = 1;
    while(n > 0) {
        int rem = n % 10;
        ans += rem * base;
        base *= 2;
        n /= 10;
    }
    return ans;
}

int decimalToBinary(int n) {
    int ans = 0, base = 1;
    while(n > 0) {
        int rem = n % 2;
        ans += rem * base;
        base *= 10;
        n /= 2;
    }
    return ans;
}

int multiplyBinary(int n1, int n2) {
    int ans = 0, base = 1;
    while(n2 > 0) {
        int bit = n2 % 10;
        if(bit == 1) {
            ans += n1 * base;
        }
        base *= 10;
        n2 /= 10;
    }
    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter two binary numbers: ";
    cin >> n1 >> n2;
    int decimal1 = binaryToDecimal(n1);
    int decimal2 = binaryToDecimal(n2);
    int product = decimal1 * decimal2;
    int binaryProduct = decimalToBinary(product);
    cout << "Product of " << n1 << " and " << n2 << " is: " << binaryProduct << endl;
    return 0;
}
