# This program checks whether an input alphabet is a vowel or not
char = input("Enter an alphabet: ")

if char in ['a', 'e', 'i', 'o', 'u']:
    print(f"{char} is a vowel")
else:
    print(f"{char} is not a vowel")
