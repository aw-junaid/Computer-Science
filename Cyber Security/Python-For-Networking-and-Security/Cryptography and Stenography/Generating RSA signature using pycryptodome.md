This Python code demonstrates the generation of an RSA key pair, encryption and decryption of data, and the signing and verification of a message using the RSA algorithm and various cryptographic modules from the `Crypto` library:

```python
from Crypto.PublicKey import RSA 
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Hash import SHA256
from Crypto.Signature import PKCS1_v1_5

# Function to generate an RSA key pair
def generate(bit_size):
    keys = RSA.generate(bit_size)
    return keys

# Function to encrypt data using RSA public key
def encrypt(pub_key, data):
    cipher = PKCS1_OAEP.new(pub_key)
    return cipher.encrypt(data)

# Function to decrypt data using RSA private key
def decrypt(priv_key, data):
    cipher = PKCS1_OAEP.new(priv_key)
    return cipher.decrypt(data)

# Generate an RSA key pair with a bit size of 2048
keys = generate(2048)

# Print and save the public key
print("Public key:")
print(keys.publickey().export_key('PEM').decode(), end='\n\n')
with open("public.key", 'wb') as file:
    file.write(keys.publickey().export_key())

# Print and save the private key
print("Private Key:")
print(keys.export_key('PEM').decode())
with open("private.key", 'wb') as file:
    file.write(keys.export_key('PEM'))

# Create a message to be signed
text_to_sign = "text_to_sign".encode("utf8")

# Hash the message using SHA256
hasher = SHA256.new(text_to_sign)

# Create a signer using the private key and sign the hashed message
signer = PKCS1_v1_5.new(keys)
signature = signer.sign(hasher)

# Create a verifier using the public key and verify the signature
verifier = PKCS1_v1_5.new(keys.publickey())
if verifier.verify(hasher, signature):
    print('The signature is valid!')
else:
    print('The message was signed with the wrong private key or modified')

# Encrypt the original message using the public key
encrypted_data = encrypt(keys.publickey(), text_to_sign)
print("Text encrypted:", encrypted_data)

# Decrypt the encrypted data using the private key
decrypted_data = decrypt(keys, encrypted_data)
print("Text Decrypted:", decrypted_data.decode())
```

Explanation:

1. **Key Generation (`generate`):**
   - Generates an RSA key pair with a specified bit size (2048 in this case).

2. **Encryption (`encrypt`):**
   - Uses the public key to encrypt data using the PKCS1_OAEP cipher.

3. **Decryption (`decrypt`):**
   - Uses the private key to decrypt data using the PKCS1_OAEP cipher.

4. **Signing (`sign`):**
   - Creates a digital signature for a message using the PKCS1_v1_5 signature scheme.

5. **Verification (`verify`):**
   - Verifies the signature of a message using the PKCS1_v1_5 signature scheme.

6. **Example Usage:**
   - Generates an RSA key pair.
   - Prints and saves the public and private keys.
   - Signs and verifies a message.
   - Encrypts and decrypts a message.

Note: Ensure that you handle and store private keys securely in a real-world scenario.
