#include <iostream>

unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    int numBits = sizeof(n) * 8;
    for (int i = 0; i < numBits; ++i) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {
    unsigned int n = 0b110010101;
    std::cout << "Original value: " << n << std::endl;
    std::cout << "Reversed bits: " << reverseBits(n) << std::endl;
    return 0;
}
