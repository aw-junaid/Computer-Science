**SHA (Secure Hash Algorithm)**

The Secure Hash Algorithm (SHA) is a family of cryptographic hash functions that generate fixed-size hash values from input data of arbitrary size. These hash values are commonly used in various security applications, such as digital signatures, certificate generation, and data integrity verification. The most commonly used SHA algorithms are SHA-1, SHA-256, SHA-384, and SHA-512.

**Working of SHA Algorithm**

1. **Padding:** The input data is padded to ensure that its length is a multiple of the block size (e.g., 512 bits for SHA-512). The padding includes a '1' bit followed by '0' bits and the length of the original message in bits.

2. **Initial Hash Values:** SHA algorithms use a set of fixed initial hash values (constants) called the initialization vector (IV). The IV varies based on the specific SHA variant being used.

3. **Message Digest Computation:** The padded input data is divided into blocks of the block size. For each block, a compression function is applied along with the current hash value to produce a new hash value. The compression function involves bitwise operations and modular addition.

4. **Final Hash Value:** After processing all the blocks, the final hash value, also known as the message digest, is obtained. The message digest is typically a fixed-length string (e.g., 256 bits for SHA-256) that represents the input data.

**Example: Using SHA-256 in Python**

Python provides a standard library module `hashlib` that supports various hash functions, including SHA-256.

```python
import hashlib

def sha256_hash(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

if __name__ == "__main__":
    data = "Hello, SHA-256!"
    hash_value = sha256_hash(data)
    print("SHA-256 Hash:", hash_value)
```

**Example: Using SHA-256 in C++**

In C++, you can use third-party libraries like OpenSSL to compute SHA-256 hashes.

```cpp
#include <iostream>
#include <openssl/sha.h>
#include <cstring>

std::string sha256_hash(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.length());
    SHA256_Final(hash, &sha256);

    char hex_hash[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hex_hash[i * 2], "%02x", hash[i]);
    }

    return std::string(hex_hash);
}

int main() {
    std::string data = "Hello, SHA-256!";
    std::string hash_value = sha256_hash(data);
    std::cout << "SHA-256 Hash: " << hash_value << std::endl;

    return 0;
}
```

In this article, we explored the Secure Hash Algorithm (SHA), which is a family of cryptographic hash functions used for generating fixed-size hash values from input data. We provided examples of using SHA-256 in Python and C++. SHA algorithms are widely used for various security applications, especially in digital signatures and data integrity verification. They are designed to be irreversible and collision-resistant, meaning it is computationally infeasible to retrieve the original input data from the hash value or find two different inputs that produce the same hash value.
