To encrypt and decrypt using the AES (Advanced Encryption Standard) algorithm in Python, you can use the `Crypto.Cipher` module from the Pycryptodome library. Here's an example script that demonstrates how to encrypt and decrypt using AES:

```python
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def generate_aes_key():
    # Generate a random 16-byte key for AES (128 bits)
    return get_random_bytes(16)

def encrypt_aes(data, key):
    # Create an AES cipher object with the specified key and mode (AES.MODE_ECB for simplicity)
    cipher = AES.new(key, AES.MODE_ECB)
    
    # Pad the data to be a multiple of 16 bytes (AES block size)
    padded_data = pad(data.encode(), 16)
    
    # Encrypt the data
    ciphertext = cipher.encrypt(padded_data)
    
    return ciphertext

def decrypt_aes(ciphertext, key):
    # Create an AES cipher object with the specified key and mode (AES.MODE_ECB for simplicity)
    cipher = AES.new(key, AES.MODE_ECB)
    
    # Decrypt the data
    decrypted_data = cipher.decrypt(ciphertext)
    
    # Unpad the decrypted data
    unpadded_data = unpad(decrypted_data, 16)
    
    return unpadded_data.decode()

if __name__ == "__main__":
    # Sample data to be encrypted
    plaintext_data = "Hello, AES encryption and decryption!"

    # Generate an AES key
    aes_key = generate_aes_key()

    # Encrypt the data
    encrypted_data = encrypt_aes(plaintext_data, aes_key)
    print("Encrypted Data:", encrypted_data.hex())

    # Decrypt the data
    decrypted_data = decrypt_aes(encrypted_data, aes_key)
    print("Decrypted Data:", decrypted_data)
```

Explanation:

1. **`generate_aes_key` Function:**
   - Generates a random 16-byte key suitable for AES encryption.

2. **`encrypt_aes` Function:**
   - Takes plaintext data and an AES key as input.
   - Creates an AES cipher object in Electronic Codebook (ECB) mode.
   - Pads the input data to be a multiple of 16 bytes using PKCS7 padding.
   - Encrypts the padded data.

3. **`decrypt_aes` Function:**
   - Takes ciphertext data and an AES key as input.
   - Creates an AES cipher object in ECB mode.
   - Decrypts the data.
   - Unpads the decrypted data.

4. **Sample Usage:**
   - In the example, a sample plaintext data is encrypted and then decrypted using a randomly generated AES key.

5. **Note:**
   - The `with` statement is not used here for simplicity. In practical applications, it's recommended to use modes other than ECB (Electronic Codebook) for better security.

Remember to use AES with a strong key and consider using modes like CBC or GCM for better security in practical applications.
