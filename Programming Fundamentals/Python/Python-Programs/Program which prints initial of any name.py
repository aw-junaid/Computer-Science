name = input("Enter a name: ")

# Split the name into words using whitespace as delimiter
words = name.split()

# Extract the first character of each word and capitalize it
initials = [word[0].upper() for word in words]

# Join the initials to form a string
initials_str = "".join(initials)

print("Initials of the name:", initials_str)
