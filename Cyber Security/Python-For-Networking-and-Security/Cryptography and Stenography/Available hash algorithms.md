The `hashlib` module in Python provides access to various hash functions. Here are some of the commonly used hash algorithms available in Python:

1. **MD5 (Message Digest Algorithm 5):**
   ```python
   import hashlib
   m = hashlib.md5()
   ```

2. **SHA-1 (Secure Hash Algorithm 1):**
   ```python
   import hashlib
   m = hashlib.sha1()
   ```

3. **SHA-224:**
   ```python
   import hashlib
   m = hashlib.sha224()
   ```

4. **SHA-256:**
   ```python
   import hashlib
   m = hashlib.sha256()
   ```

5. **SHA-384:**
   ```python
   import hashlib
   m = hashlib.sha384()
   ```

6. **SHA-512:**
   ```python
   import hashlib
   m = hashlib.sha512()
   ```

7. **BLAKE2b:**
   ```python
   import hashlib
   m = hashlib.blake2b()
   ```

8. **BLAKE2s:**
   ```python
   import hashlib
   m = hashlib.blake2s()
   ```

Each of the above hash functions provides a similar interface. You can use the `update()` method to feed data into the hash object, and then retrieve the hash digest using the `hexdigest()` method.

Example:
```python
import hashlib

# Create a new hash object using SHA-256
m = hashlib.sha256()

# Update the hash object with data
m.update(b"Hello, World!")

# Get the hexadecimal representation of the hash digest
hash_digest = m.hexdigest()

print("SHA-256 Hash:", hash_digest)
```

Note: MD5 and SHA-1 are considered weak and are not recommended for cryptographic purposes. For cryptographic applications, it's generally recommended to use SHA-256 or higher. Additionally, when storing passwords, it's recommended to use key derivation functions like PBKDF2 or bcrypt instead of simple hash functions.
