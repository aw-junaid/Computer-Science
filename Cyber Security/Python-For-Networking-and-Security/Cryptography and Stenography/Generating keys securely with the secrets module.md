
```python
import uuid
import hashlib
 
def hash_password(password):
    # uuid is used to generate a random number
    salt = uuid.uuid4().hex
    return hashlib.sha256(salt.encode() + password.encode()).hexdigest() + ':' + salt
    
def check_password(hashed_password, user_password):
    password, salt = hashed_password.split(':')
    return password == hashlib.sha256(salt.encode() + user_password.encode()).hexdigest()
 
new_pass = input('Enter your password: ')
hashed_password = hash_password(new_pass)

print('The password hash: ' + hashed_password)
old_pass = input('Enter again the password for checking: ')
if check_password(hashed_password, old_pass):
    print("Password is correct")
else:
    print("Passwords doesn't match")
```
The provided code is a simple implementation of password hashing using a unique salt for each password. Here's an explanation of the code:

1. **`hash_password(password)` Function:**
   - This function takes a plain-text password as input.
   - It generates a random salt using `uuid.uuid4().hex`.
   - It then concatenates the salt and password, hashes the result using SHA-256, and returns the hashed password with the salt as a string in the format: `hashed_password:salt`.

2. **`check_password(hashed_password, user_password)` Function:**
   - This function takes a hashed password (in the format `hashed_password:salt`) and a user-provided plain-text password.
   - It extracts the stored salt from the hashed password.
   - It hashes the user-provided password with the extracted salt using SHA-256.
   - It checks if the computed hash matches the stored hash, returning `True` if they match and `False` otherwise.

3. **Usage:**
   - The script prompts the user to enter a new password (`new_pass`).
   - It then hashes the entered password using `hash_password` and prints the hashed password.
   - The user is prompted to enter the same password again (`old_pass`) for verification.
   - The script uses `check_password` to compare the hashed version of the second input with the originally hashed password.

This is a basic example of how password hashing with salt works. It's important to use such techniques to enhance password security, making it more difficult for attackers to use precomputed tables (rainbow tables) to crack passwords. Additionally, consider using more advanced password-hashing libraries like bcrypt for production systems.
