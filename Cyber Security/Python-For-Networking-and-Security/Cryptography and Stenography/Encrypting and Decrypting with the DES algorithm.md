To encrypt and decrypt using the DES (Data Encryption Standard) algorithm in Python, you can use the `Crypto.Cipher` module from the Pycryptodome library. DES is a symmetric-key algorithm, meaning the same key is used for both encryption and decryption. Below is an example script that demonstrates how to encrypt and decrypt using DES:

```python
from Crypto.Cipher import DES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def generate_des_key():
    # Generate a random 8-byte key for DES
    return get_random_bytes(8)

def encrypt_des(data, key):
    # Create a DES cipher object with the specified key and mode
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Pad the data to be a multiple of 8 bytes (DES block size)
    padded_data = pad(data.encode(), 8)
    
    # Encrypt the data
    ciphertext = cipher.encrypt(padded_data)
    
    return ciphertext

def decrypt_des(ciphertext, key):
    # Create a DES cipher object with the specified key and mode
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Decrypt the data
    decrypted_data = cipher.decrypt(ciphertext)
    
    # Unpad the decrypted data
    unpadded_data = unpad(decrypted_data, 8)
    
    return unpadded_data.decode()

if __name__ == "__main__":
    # Sample data to be encrypted
    plaintext_data = "Hello, DES encryption and decryption!"

    # Generate a DES key
    des_key = generate_des_key()

    # Encrypt the data
    encrypted_data = encrypt_des(plaintext_data, des_key)
    print("Encrypted Data:", encrypted_data.hex())

    # Decrypt the data
    decrypted_data = decrypt_des(encrypted_data, des_key)
    print("Decrypted Data:", decrypted_data)
```

Explanation:

1. **`generate_des_key` Function:**
   - Generates a random 8-byte key suitable for DES encryption.

2. **`encrypt_des` Function:**
   - Takes plaintext data and a DES key as input.
   - Creates a DES cipher object in Electronic Codebook (ECB) mode.
   - Pads the input data to be a multiple of 8 bytes using PKCS7 padding.
   - Encrypts the padded data.

3. **`decrypt_des` Function:**
   - Takes ciphertext data and a DES key as input.
   - Creates a DES cipher object in ECB mode.
   - Decrypts the data.
   - Unpads the decrypted data.

4. **Sample Usage:**
   - In the example, a sample plaintext data is encrypted and then decrypted using a randomly generated DES key.

5. **Note:**
   - ECB mode is used for simplicity in this example. In practice, more secure modes like CBC should be considered for better security.

Remember that DES is considered insecure for most applications due to its short key length. For stronger security, consider using a more modern algorithm like AES.
