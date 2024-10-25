# This program converts a decimal number to binary

# Accept a decimal number from the user
decimal = int(input("Enter a decimal number: "))

# Convert decimal to binary using a loop
binary = ''
while decimal > 0:
    remainder = decimal % 2
    binary = str(remainder) + binary
    decimal = decimal // 2

# Print the binary number
print("The binary equivalent of", str(decimal), "is", binary)
