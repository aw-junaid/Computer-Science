string = input("Enter a string: ")
vowels = "aeiouAEIOU"
new_string = ""

for letter in string:
    if letter not in vowels:
        new_string += letter

print("New string after removing vowels:", new_string)
