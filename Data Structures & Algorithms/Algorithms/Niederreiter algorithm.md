# Niederreiter Cryptosystem: Leveraging Algebraic Geometry for Security

The Niederreiter cryptosystem is a public-key encryption scheme introduced by Harald Niederreiter in 1986. It is based on the algebraic geometry codes, which are a type of error-correcting codes with strong mathematical properties. Similar to other public-key cryptosystems, Niederreiter's approach offers a way to securely transmit information over potentially insecure channels.

## How the Niederreiter Algorithm Works

The Niederreiter cryptosystem is built upon algebraic geometry codes and relies on the error-correcting properties of these codes. Here's an overview of the algorithm's steps:

1. **Key Generation**:
   - Choose a binary matrix `G` of size `k x n` with full rank, where `n` is the code length and `k` is the number of information bits.
   - Compute the parity-check matrix `H` of the code by performing Gaussian elimination on `G`. This matrix defines the error-correcting properties of the code.

2. **Public Key Generation**:
   - Choose a random invertible `n x n` binary matrix `P`.
   - Compute the public key matrix `P*G`.

3. **Encryption**:
   - Convert the plaintext message into a binary vector of length `k`.
   - Add a random binary error vector of length `n - k` to the plaintext vector.
   - Compute the ciphertext vector by multiplying the error-added plaintext vector with the public key matrix.

4. **Decryption**:
   - Given the ciphertext vector, multiply it by the inverse of the matrix `P` to obtain the syndrome.
   - Decode the syndrome to correct errors using the error-correcting properties of the code.
   - Recover the original message by removing the error-added vector.

## Example Use Cases of the Niederreiter Algorithm

1. **Secure Communication**: The Niederreiter cryptosystem can be used to establish secure communication channels between parties, protecting the confidentiality of transmitted information.

2. **Digital Signatures**: Niederreiter can also be used to create digital signatures, allowing senders to prove the authenticity of their messages.

## Python Implementation of the Niederreiter Algorithm

```python
import numpy as np
from scipy.linalg import lu, inv

def generate_binary_matrix(rows, cols):
    return np.random.randint(0, 2, (rows, cols))

def generate_public_key(G):
    P = np.random.randint(0, 2, (G.shape[1], G.shape[1]))
    while np.linalg.det(P) == 0:
        P = np.random.randint(0, 2, (G.shape[1], G.shape[1]))
    return np.mod(np.dot(P, G), 2)

def encrypt(plaintext, public_key):
    return np.mod(np.dot(plaintext, public_key), 2)

def decrypt(ciphertext, H, P):
    syndrome = np.mod(np.dot(ciphertext, H.T), 2)
    corrected = np.mod(np.dot(syndrome, inv(P).T), 2)
    return np.mod(ciphertext - corrected, 2)

# Example usage
k = 128  # Number of information bits
n = 256  # Code length

G = generate_binary_matrix(k, n)
public_key = generate_public_key(G)

plaintext = np.random.randint(0, 2, k)
ciphertext = encrypt(plaintext, public_key)
decrypted = decrypt(ciphertext, G, np.linalg.inv(public_key))

print("Original Plaintext:", plaintext)
print("Ciphertext:", ciphertext)
print("Decrypted Plaintext:", decrypted)
```

## C++ Implementation of the Niederreiter Algorithm

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

MatrixXi generate_binary_matrix(int rows, int cols) {
    MatrixXi matrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix(i, j) = rand() % 2;
        }
    }
    return matrix;
}

MatrixXi generate_public_key(const MatrixXi& G) {
    MatrixXi P(G.cols(), G.cols());
    while (true) {
        P = generate_binary_matrix(G.cols(), G.cols());
        FullPivLU<MatrixXi> lu(P);
        if (lu.isInvertible()) {
            break;
        }
    }
    return (G * P).array() % 2;
}

VectorXi encrypt(const VectorXi& plaintext, const MatrixXi& public_key) {
    return (plaintext.transpose() * public_key).array() % 2;
}

VectorXi decrypt(const VectorXi& ciphertext, const MatrixXi& H, const MatrixXi& P) {
    VectorXi syndrome = (ciphertext.transpose() * H.transpose()).array() % 2;
    VectorXi corrected = (syndrome * P.transpose()).array() % 2;
    return (ciphertext - corrected).array() % 2;
}

int main() {
    int k = 128;  // Number of information bits
    int n = 256;  // Code length

    MatrixXi G = generate_binary_matrix(k, n);
    MatrixXi public_key = generate_public_key(G);

    VectorXi plaintext(k);
    for (int i = 0; i < k; ++i) {
        plaintext[i] = rand() % 2;
    }

    VectorXi ciphertext = encrypt(plaintext, public_key);
    VectorXi decrypted = decrypt(ciphertext, G.transpose(), public_key.inverse());

    cout << "Original Plaintext:\n" << plaintext.transpose() << endl;
    cout << "Ciphertext:\n" << ciphertext.transpose() << endl;
    cout << "Decrypted Plaintext:\n" << decrypted.transpose() << endl;

    return 0;
}
```

In both the Python and C++ implementations, the Niederreiter cryptosystem is demonstrated, including key generation, encryption, and decryption. The Niederreiter cryptosystem offers a post-quantum secure alternative to traditional encryption schemes, as its security is based on the hardness of decoding algebraic geometry codes. However, it's important to note that this algorithm is not as widely adopted as other encryption schemes, and its practical use may require careful implementation and analysis to ensure security.
