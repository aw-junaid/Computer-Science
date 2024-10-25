To encrypt and decrypt information using the `cryptography` library in Python, you can use the Fernet symmetric encryption scheme provided by the library. Here's an example:

```python
from cryptography.fernet import Fernet

def generate_key():
    return Fernet.generate_key()

def encrypt_message(message, key):
    cipher_suite = Fernet(key)
    encrypted_message = cipher_suite.encrypt(message.encode())
    return encrypted_message

def decrypt_message(encrypted_message, key):
    cipher_suite = Fernet(key)
    decrypted_message = cipher_suite.decrypt(encrypted_message).decode()
    return decrypted_message

# Example Usage
if __name__ == "__main__":
    # Generate a key (you should securely store and manage this key)
    key = generate_key()
    print("Generated Key:", key)

    # Message to be encrypted
    original_message = "This is a secret message!"

    # Encrypt the message
    encrypted_message = encrypt_message(original_message, key)
    print("Encrypted Message:", encrypted_message)

    # Decrypt the message
    decrypted_message = decrypt_message(encrypted_message, key)
    print("Decrypted Message:", decrypted_message)
```

Explanation:

1. **`generate_key`:**
   - Generates a key for the Fernet symmetric encryption scheme.

2. **`encrypt_message`:**
   - Takes a message and a key, creates a Fernet cipher suite with the key, and encrypts the message.

3. **`decrypt_message`:**
   - Takes an encrypted message and a key, creates a Fernet cipher suite with the key, and decrypts the message.

4. **Example Usage:**
   - Generates a key.
   - Encrypts a message.
   - Decrypts the encrypted message.

Ensure that you securely manage and store the encryption key, as it is crucial for both encryption and decryption. Never hardcode the key or expose it insecurely. In a real-world scenario, you might want to consider using a key management system for better security.
