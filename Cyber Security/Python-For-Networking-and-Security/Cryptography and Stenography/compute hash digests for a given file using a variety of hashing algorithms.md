This Python script prompts the user to enter a file name, reads the content of the file, and then calculates the hash digest using various available hashing algorithms provided by the `hashlib` module. Here's an explanation of the code:

1. **User Input:**
   ```python
   file_name = input("Enter file name:")
   ```
   The user is prompted to enter the name of the file.

2. **Read File Content:**
   ```python
   file = open(file_name, 'r')
   data = file.read().encode('utf-8')
   ```
   The specified file is opened in read mode (`'r'`), and its content is read. The content is then encoded as UTF-8 bytes.

3. **Hash Calculation:**
   ```python
   print("-- %s --" % file_name)
   print(hashlib.algorithms_available)

   for algorithm in hashlib.algorithms_available:
       hash = hashlib.new(algorithm)
       hash.update(data)
       try:
           hexdigest = hash.hexdigest()
       except TypeError:
           hexdigest = hash.hexdigest(128)
       
       print("%s: %s" % (algorithm, hexdigest))
   ```
   - The script prints the name of the file and the available hashing algorithms.
   - It iterates over the available hashing algorithms.
   - For each algorithm, a new hash object is created (`hashlib.new(algorithm)`).
   - The content of the file is then fed into the hash object using the `update()` method.
   - The hex digest of the hash is calculated using `hexdigest()`.
   - The result, including the algorithm name and hex digest, is printed to the console.

This script provides a way to compute hash digests for a given file using a variety of hashing algorithms. Keep in mind that different algorithms may produce different hash values. The `hashlib.algorithms_available` attribute provides a list of algorithms supported by the `hashlib` module on the current platform.
