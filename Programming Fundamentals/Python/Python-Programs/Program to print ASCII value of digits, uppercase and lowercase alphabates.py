# ASCII value of digits, uppercase and lowercase alphabets

# Digits
for i in range(10):
    print(f"ASCII value of {i} is {ord(str(i))}")

# Uppercase alphabets
for i in range(65, 91):
    print(f"ASCII value of {chr(i)} is {i}")

# Lowercase alphabets
for i in range(97, 123):
    print(f"ASCII value of {chr(i)} is {i}")
