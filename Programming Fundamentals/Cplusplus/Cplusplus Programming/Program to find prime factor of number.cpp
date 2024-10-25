#include <iostream>
#include <vector>
using namespace std;

// function to check if a number is prime or not
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// function to find prime factors of a number
vector<int> primeFactors(int num) {
    vector<int> factors;
    for (int i = 2; i <= num; i++) {
        if (isPrime(i)) {
            while (num % i == 0) {
                factors.push_back(i);
                num /= i;
            }
        }
    }
    return factors;
}

// main function to test the primeFactors function
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    vector<int> factors = primeFactors(num);
    cout << "Prime factors of " << num << " are: ";
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i] << " ";
    }
    cout << endl;
    return 0;
}
