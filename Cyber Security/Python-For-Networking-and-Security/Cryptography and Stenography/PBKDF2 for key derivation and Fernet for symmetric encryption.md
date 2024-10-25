The provided code demonstrates the use of PBKDF2 for key derivation and Fernet for symmetric encryption. Here's an explanation of the code:

```python
from cryptography.fernet import Fernet
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
import base64
import os

# Password to be used for key derivation
password = "password".encode("utf8")

# Generate a random salt
salt = os.urandom(16)

# Initialize PBKDF2HMAC with SHA256 as the hash function
pbkdf = PBKDF2HMAC(algorithm=hashes.SHA256(), length=32, salt=salt, iterations=100000, backend=default_backend())

# Derive a key from the password using PBKDF2
key = pbkdf.derive(password)

# Verify the password using the derived key
pbkdf.verify(password, key)

# Encode the key in URL-safe base64 format
key = base64.urlsafe_b64encode(key)

# Initialize Fernet cipher with the derived key
fernet = Fernet(key)

# Encrypt a message using Fernet
token = fernet.encrypt("Secret message".encode("utf8"))

# Print the encrypted token and decrypt it to obtain the original message
print("Token:", token)
print("Message:", fernet.decrypt(token).decode())
```

Explanation:

1. **Password and Salt:**
   - The password is converted to bytes (`password = "password".encode("utf8")`).
   - A random 16-byte salt is generated using `os.urandom(16)`.

2. **PBKDF2 Key Derivation:**
   - `PBKDF2HMAC` is initialized with SHA256 as the hash function, the specified key length (32 bytes), the generated salt, and the iteration count.
   - The key is derived using the `derive` method.

3. **Password Verification:**
   - The `verify` method is used to verify the password against the derived key.

4. **Key Encoding:**
   - The derived key is URL-safe base64 encoded using `base64.urlsafe_b64encode`.

5. **Fernet Encryption:**
   - A Fernet cipher is initialized with the encoded key.
   - A message ("Secret message") is encrypted using `encrypt` and stored in the `token` variable.

6. **Print Results:**
   - The encrypted token and the decrypted message are printed.

Note: This example demonstrates key derivation, password verification, and encryption using Fernet. Ensure proper key management practices and securely handle passwords in real-world applications. Adjust security parameters (such as iteration count) based on specific requirements and best practices.
