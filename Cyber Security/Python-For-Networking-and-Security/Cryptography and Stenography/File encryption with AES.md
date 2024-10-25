This Python script allows you to encrypt and decrypt files using the AES algorithm in CBC mode with a provided password. Here's an explanation of the code:

```python
from Crypto.Cipher import AES
from Crypto.Hash import SHA256
import os, random, struct
from Crypto import Random

def encrypt_file(key, filename):
    chunk_size = 64*1024

    output_filename = filename + '.encrypted'

    # Random Initialization Vector
    iv = Random.new().read(AES.block_size)

    # Create the encryption cipher
    encryptor = AES.new(key, AES.MODE_CBC, iv)

    # Determine the size of the file
    filesize = os.path.getsize(filename)

    # Open the output file and write the size of the file. 
    # We use the struct package for this purpose.
    with open(filename, 'rb') as inputfile:
        with open(output_filename, 'wb') as outputfile:
            outputfile.write(struct.pack('<Q', filesize))
            outputfile.write(iv)
            
            while True:
                chunk = inputfile.read(chunk_size)
                if len(chunk) == 0:
                    break
                elif len(chunk) % 16 != 0:
                    chunk += bytes(' ', 'utf-8') * (16 - len(chunk) % 16)

                outputfile.write(encryptor.encrypt(chunk))


def decrypt_file(key, filename):
    chunk_size = 64*1024

    output_filename = os.path.splitext(filename)[0]

    # Open the encrypted file and read the file size and the initialization vector. 
    # The IV is required for creating the cipher.
    with open(filename, 'rb') as infile:
        origsize = struct.unpack('<Q', infile.read(struct.calcsize('Q')))[0]
        iv = infile.read(16)
        
        # Create the cipher using the key and the IV.
        decryptor = AES.new(key, AES.MODE_CBC, iv)
        
        # We also write the decrypted data to a verification file, 
        # so we can check the results of the encryption 
        # and decryption by comparing with the original file.
        with open(output_filename, 'wb') as outfile:
            while True:
                chunk = infile.read(chunk_size)
                if len(chunk) == 0:
                    break
                outfile.write(decryptor.decrypt(chunk))

            outfile.truncate(origsize)


def getKey(password):
    hasher = SHA256.new(password)
    return hasher.digest()


def main():
    choice = input("Do you want to (E)ncrypt or (D)ecrypt?: ")
    
    if choice == 'E':
        filename = input('File to encrypt: ')
        password = input('Password: ')
        encrypt_file(getKey(password.encode("utf8")), filename)
        print('Done.')

    elif choice == 'D':
        filename = input('File to decrypt: ')
        password = input('Password: ')
        decrypt_file(getKey(password.encode("utf8")), filename)
        print('Done.')

    else:
        print('No option selected.')

if __name__ == "__main__":
    main()
```

Explanation:

1. **Encryption (`encrypt_file` function):**
   - The file is encrypted using the AES algorithm in CBC mode with a randomly generated Initialization Vector (IV).
   - The file size and IV are written to the output file.
   - The file is read in chunks, padded if necessary, and encrypted.

2. **Decryption (`decrypt_file` function):**
   - The encrypted file is read, and the file size and IV are extracted.
   - The file is decrypted using the key, IV, and the AES algorithm in CBC mode.
   - The decrypted data is written to an output file, which is truncated to the original file size.

3. **Key Derivation (`getKey` function):**
   - The user's password is hashed using the SHA-256 algorithm to derive a key.

4. **User Interface (`main` function):**
   - The user is prompted to choose between encryption and decryption.
   - The user provides the filename and password.
   - The appropriate function is called based on the user's choice.
