**ElGamal Encryption Algorithm: An Overview**

ElGamal is a public-key cryptosystem used for secure data encryption and decryption. It is based on the mathematical properties of discrete logarithms in finite fields. The algorithm provides a way for two parties to communicate securely over an insecure channel without the need for a shared secret key.

**Working of ElGamal Encryption Algorithm**

1. **Key Generation:**
   - Choose a large prime number, `p`, and a primitive root modulo `p`, `g`.
   - Select a secret random number, `a`, such that `1 < a < p-1`.
   - Compute the public key, `A`, as `A = g^a mod p`.

2. **Encryption:**
   - Obtain the recipient's public key, `A`.
   - Choose a random number, `k`, such that `1 < k < p-1`.
   - Compute the ciphertext pair `(C1, C2)` as `C1 = g^k mod p` and `C2 = (A^k * m) mod p`, where `m` is the plaintext message.

3. **Decryption:**
   - Use the recipient's private key, `a`, to compute the shared secret, `s`, as `s = C1^a mod p`.
   - Calculate the inverse of `s` modulo `p`, `s_inv`, using modular arithmetic.
   - Decrypt the ciphertext, `m`, as `m = (C2 * s_inv) mod p`.

**Example Use Cases for ElGamal Encryption Algorithm**

1. Secure Communication: ElGamal encryption can be used to securely transmit messages between two parties over an insecure channel, such as the internet.

2. Digital Signatures: ElGamal can also be used for generating digital signatures to ensure the authenticity and integrity of messages.

**Implementation of ElGamal Encryption Algorithm in Python:**

```python
import random

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp // 2
        base = (base * base) % mod
    return result

def generate_keys(bit_length):
    p = 0
    while True:
        p = random.getrandbits(bit_length)
        if pow(2, p-1, p) == 1 and pow(2, 2*p-1, p) == 1:
            break

    g = 0
    while True:
        g = random.randint(2, p-1)
        if pow(g, (p-1)//2, p) != 1 and pow(g, 2, p) != 1:
            break

    a = random.randint(2, p-2)
    A = mod_exp(g, a, p)

    public_key = (p, g, A)
    private_key = a
    return public_key, private_key

def encrypt(public_key, plaintext):
    p, g, A = public_key
    k = random.randint(2, p-2)
    C1 = mod_exp(g, k, p)
    s = mod_exp(A, k, p)
    C2 = (s * plaintext) % p
    return (C1, C2)

def decrypt(public_key, private_key, ciphertext):
    p, _, _ = public_key
    C1, C2 = ciphertext
    s = mod_exp(C1, private_key, p)
    s_inv = pow(s, -1, p)
    plaintext = (C2 * s_inv) % p
    return plaintext

# Example usage:
bit_length = 32
public_key, private_key = generate_keys(bit_length)
print("Public Key:", public_key)
print("Private Key:", private_key)

plaintext = 12345
ciphertext = encrypt(public_key, plaintext)
print("Ciphertext:", ciphertext)

decrypted_text = decrypt(public_key, private_key, ciphertext)
print("Decrypted Text:", decrypted_text)
```

**Implementation of ElGamal Encryption Algorithm in C++:**

```cpp
#include <iostream>
#include <vector>
#include <random>
using namespace std;

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

pair<unsigned long long, unsigned long long> generate_keys(int bit_length) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(2, (1ULL << bit_length) - 1);

    unsigned long long p = 0;
    while (true) {
        p = dist(gen);
        if (mod_exp(2, p - 1, p) == 1 && mod_exp(2, 2 * p - 1, p) == 1) {
            break;
        }
    }

    unsigned long long g = 0;
    while (true) {
        g = dist(gen);
        if (mod_exp(g, (p - 1) / 2, p) != 1 && mod_exp(g, 2, p) != 1) {
            break;
        }
    }

    unsigned long long a = dist(gen);
    unsigned long long A = mod_exp(g, a, p);

    return make_pair(p, A);
}

pair<unsigned long long, unsigned long long> encrypt(pair<unsigned long long, unsigned long long

> public_key, unsigned long long plaintext) {
    unsigned long long p = public_key.first;
    unsigned long long g = public_key.second;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(2, p - 2);

    unsigned long long k = dist(gen);
    unsigned long long C1 = mod_exp(g, k, p);
    unsigned long long s = mod_exp(C1, k, p);
    unsigned long long C2 = (s * plaintext) % p;

    return make_pair(C1, C2);
}

unsigned long long decrypt(pair<unsigned long long, unsigned long long> public_key, unsigned long long private_key, pair<unsigned long long, unsigned long long> ciphertext) {
    unsigned long long p = public_key.first;
    unsigned long long C1 = ciphertext.first;
    unsigned long long C2 = ciphertext.second;

    unsigned long long s = mod_exp(C1, private_key, p);
    unsigned long long s_inv = mod_exp(s, p - 2, p);
    unsigned long long plaintext = (C2 * s_inv) % p;

    return plaintext;
}

int main() {
    int bit_length = 32;
    pair<unsigned long long, unsigned long long> public_key, ciphertext;
    unsigned long long private_key, plaintext;

    tie(public_key, private_key) = generate_keys(bit_length);
    cout << "Public Key: (" << public_key.first << ", " << public_key.second << ")" << endl;
    cout << "Private Key: " << private_key << endl;

    plaintext = 12345;
    ciphertext = encrypt(public_key, plaintext);
    cout << "Ciphertext: (" << ciphertext.first << ", " << ciphertext.second << ")" << endl;

    unsigned long long decrypted_text = decrypt(public_key, private_key, ciphertext);
    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
```

**Conclusion**

The ElGamal encryption algorithm is a secure public-key cryptosystem that allows secure communication and digital signatures without the need for a shared secret key. Its implementation involves key generation, encryption, and decryption steps, making it a valuable tool for secure data transmission in various applications. The provided code examples in Python and C++ demonstrate the implementation of the ElGamal encryption algorithm, enabling secure communication between two parties and showcasing its use in data encryption and decryption processes.
