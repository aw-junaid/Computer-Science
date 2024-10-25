This Python script demonstrates how to enhance security by using a key derivation function (PBKDF2) to derive a key from a password. Here's an explanation of the code:

```python
from Crypto.Cipher import AES
from Crypto.Protocol.KDF import PBKDF2
from Crypto import Random

# Key has to be 16, 24, or 32 bytes long
password = "secret-key-12345"

# Parameters for key derivation
iterations = 10000
key_size = 16
salt = Random.new().read(key_size)
iv = Random.new().read(AES.block_size)

# Derive a key from the password using PBKDF2
derived_key = PBKDF2(password, salt, key_size, iterations)

# Create an AES cipher object in CBC mode with the derived key and IV
encrypt_AES = AES.new(derived_key, AES.MODE_CBC, iv)

# Fill with spaces the user until 32 characters
message = "This is the secret message      ".encode("utf8")

# Encrypt the message
ciphertext = encrypt_AES.encrypt(message)
print("Cipher text:", ciphertext)

# Create a new AES cipher object for decryption with the derived key and IV
decrypt_AES = AES.new(derived_key, AES.MODE_CBC, iv)

# Decrypt the ciphertext
message_decrypted = decrypt_AES.decrypt(ciphertext)

# Print the decrypted message after stripping trailing spaces
print("Decrypted text:", message_decrypted.strip().decode())
```

Explanation:

1. **Key Derivation:**
   - Instead of using a static key, a key is derived from a password using the PBKDF2 key derivation function.
   - The key derivation parameters include the password, a random salt, key size, and the number of iterations.

2. **Encryption and Decryption:**
   - The derived key is used to create an AES cipher object for encryption and decryption.
   - The rest of the encryption and decryption process remains the same as in the previous example.

3. **Security Considerations:**
   - Using a key derivation function like PBKDF2 strengthens the security of the system by making it computationally expensive for an attacker to brute-force the password.
   - Random values (salt and IV) are crucial for adding entropy and preventing certain types of attacks.

4. **Note:**
   - In practice, consider using a secure password management library for handling passwords and key derivation functions.
