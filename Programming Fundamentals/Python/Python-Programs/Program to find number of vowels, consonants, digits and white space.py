string = input("Enter a string: ")

vowels = 0
consonants = 0
digits = 0
spaces = 0

for char in string:
    if char.isalpha():
        if char in 'AEIOUaeiou':
            vowels += 1
        else:
            consonants += 1
    elif char.isdigit():
        digits += 1
    elif char.isspace():
        spaces += 1

print("Number of vowels:", vowels)
print("Number of consonants:", consonants)
print("Number of digits:", digits)
print("Number of spaces:", spaces)
