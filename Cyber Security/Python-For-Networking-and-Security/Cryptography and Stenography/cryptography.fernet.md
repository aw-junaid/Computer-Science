This Python code demonstrates a simple implementation of encrypting and decrypting a message using the Fernet symmetric encryption algorithm from the `cryptography.fernet` module. The code is organized into functions for key generation, key loading, message encryption, and message decryption. Let's go through each part:

1. **Key Generation:**
   ```python
   def generate_key():
       key = Fernet.generate_key()
       with open("secret.key", "wb") as key_file:
           key_file.write(key)
   ```
   - `generate_key()`: Generates a new Fernet key and saves it to a file named "secret.key" in binary mode.

2. **Key Loading:**
   ```python
   def load_key():
       return open("secret.key", "rb").read()
   ```
   - `load_key()`: Reads the Fernet key from the "secret.key" file in binary mode and returns it.

3. **Encryption:**
   ```python
   def encrypt_message(message):
       key = load_key()
       encoded_message = message.encode()
       fernet = Fernet(key)
       encrypted_message = fernet.encrypt(encoded_message)
       return encrypted_message
   ```
   - `encrypt_message(message)`: Encrypts the input message using the loaded Fernet key.

4. **Decryption:**
   ```python
   def decrypt_message(encrypted_message):
       key = load_key()
       fernet = Fernet(key)
       decrypted_message = fernet.decrypt(encrypted_message)
       return decrypted_message.decode()
   ```
   - `decrypt_message(encrypted_message)`: Decrypts the input encrypted message using the loaded Fernet key.

5. **Main Execution:**
   ```python
   if __name__ == "__main__":
       generate_key()
       message_encrypted = encrypt_message("encrypt this message")
       print('Message encrypted:', message_encrypted)
       print('Message decrypted:', decrypt_message(message_encrypted))
   ```
   - The `generate_key()` function is called to create a new key and save it to "secret.key".
   - A sample message is encrypted using `encrypt_message()` and then decrypted using `decrypt_message()`. The original and decrypted messages are printed for verification.

This code illustrates a basic usage pattern for secure message encryption and decryption using the Fernet algorithm. The key management functions ensure that the same key is used for both encryption and decryption.
