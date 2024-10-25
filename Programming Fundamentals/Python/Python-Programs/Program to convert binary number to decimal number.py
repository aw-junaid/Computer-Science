# This program converts a binary number to a decimal number

# Accept the binary number from the user
binary_num = input("Enter a binary number: ")

# Initialize the decimal number and the power of 2
decimal_num = 0
power = len(binary_num) - 1

# Convert the binary number to decimal
for digit in binary_num:
    if digit == '1':
        decimal_num += 2**power
    power -= 1

# Print the result
print("The decimal equivalent of", binary_num, "is", decimal_num)
