This Python script demonstrates how to encrypt and decrypt a message using the AES algorithm in CBC (Cipher Block Chaining) mode. Here's an explanation of the code:

```python
from Crypto.Cipher import AES

# Key has to be 16, 24, or 32 bytes long
key = "secret-key-12345"

# Create an AES cipher object in CBC mode with a specified IV (Initialization Vector)
encrypt_AES = AES.new(key.encode("utf8"), AES.MODE_CBC, 'This is an IV-12'.encode("utf8"))

# Fill with spaces the user until 32 characters
message = "This is the secret message      ".encode("utf8")

# Encrypt the message
ciphertext = encrypt_AES.encrypt(message)
print("Cipher text:", ciphertext)

# Create a new AES cipher object for decryption with the same key and IV
decrypt_AES = AES.new(key.encode("utf8"), AES.MODE_CBC, 'This is an IV-12'.encode("utf8"))

# Decrypt the ciphertext
message_decrypted = decrypt_AES.decrypt(ciphertext)

# Print the decrypted message after stripping trailing spaces
print("Decrypted text:", message_decrypted.strip().decode())
```

Explanation:

1. **Key and IV:**
   - The `key` is the secret key used for encryption and decryption. It must be 16, 24, or 32 bytes long for AES-128, AES-192, or AES-256, respectively.
   - An Initialization Vector (`IV`) is used in CBC mode to provide an additional layer of security. It should be a block size (16 bytes) long.

2. **Encryption:**
   - An AES cipher object (`encrypt_AES`) is created with the key, mode (CBC), and IV for encryption.
   - The message is padded and then encrypted using the `encrypt` method of the cipher object.

3. **Decryption:**
   - Another AES cipher object (`decrypt_AES`) is created with the same key, mode, and IV for decryption.
   - The ciphertext is decrypted using the `decrypt` method of the cipher object.

4. **Output:**
   - The encrypted ciphertext and the decrypted message are printed.

Note: In a real-world scenario, it's important to use a secure method for generating the key and IV. Also, ensure proper handling of padding and consider using authenticated encryption modes for additional security.
