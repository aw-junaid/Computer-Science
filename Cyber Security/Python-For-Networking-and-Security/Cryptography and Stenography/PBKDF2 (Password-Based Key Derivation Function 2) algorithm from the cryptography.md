The provided code demonstrates encryption using the PBKDF2 (Password-Based Key Derivation Function 2) algorithm from the `cryptography` library. PBKDF2 is commonly used for securely deriving cryptographic keys from passwords.

Here's an explanation of the code:

```python
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

# Function to derive a key from a password using PBKDF2
def derive_key_from_password(password, salt):
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        length=32,  # Length of the derived key (in bytes)
        salt=salt,
        iterations=100000,  # Number of iterations (adjustable for security)
        backend=default_backend()
    )
    key = kdf.derive(password.encode("utf-8"))
    return key

# Encryption function using AES-GCM
def encrypt_with_pbkdf2(password, plaintext):
    salt = os.urandom(16)  # Generate a random salt
    key = derive_key_from_password(password, salt)

    cipher = Cipher(algorithms.AES(key), modes.GCM())
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(plaintext.encode("utf-8")) + encryptor.finalize()

    # Include the salt and the authentication tag with the ciphertext
    encrypted_data = salt + encryptor.tag + ciphertext
    return encrypted_data

# Decryption function using AES-GCM
def decrypt_with_pbkdf2(password, encrypted_data):
    salt = encrypted_data[:16]
    tag = encrypted_data[16:32]
    ciphertext = encrypted_data[32:]

    key = derive_key_from_password(password, salt)

    cipher = Cipher(algorithms.AES(key), modes.GCM(tag))
    decryptor = cipher.decryptor()
    plaintext = decryptor.update(ciphertext) + decryptor.finalize()
    return plaintext.decode("utf-8")

# Example usage
password = "secure_password"
plaintext_message = "This is a secret message"

encrypted_data = encrypt_with_pbkdf2(password, plaintext_message)
decrypted_message = decrypt_with_pbkdf2(password, encrypted_data)

print("Original Message:", plaintext_message)
print("Encrypted Data:", encrypted_data)
print("Decrypted Message:", decrypted_message)
```

Explanation:

1. **`derive_key_from_password` Function:**
   - Derives a key from the password using PBKDF2 with SHA256 as the hash function.
   - Adjustments can be made to the iteration count for security.

2. **`encrypt_with_pbkdf2` Function:**
   - Generates a random salt.
   - Derives a key using PBKDF2.
   - Uses the derived key to initialize an AES-GCM encryptor.
   - Encrypts the plaintext message and includes the salt and authentication tag with the ciphertext.

3. **`decrypt_with_pbkdf2` Function:**
   - Extracts the salt, tag, and ciphertext from the encrypted data.
   - Derives the key using PBKDF2.
   - Initializes an AES-GCM decryptor with the key and tag.
   - Decrypts the ciphertext to obtain the original plaintext message.

4. **Example Usage:**
   - Demonstrates how to use the encryption and decryption functions with a sample password and plaintext message.

Note: This code provides a basic example and should be used with caution in real-world applications. Ensure proper handling of keys, salts, and ciphertexts for security. Adjustments may be needed based on specific security requirements and best practices.
