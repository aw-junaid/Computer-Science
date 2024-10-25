# This program checks whether a given integer is positive or negative

# Accept the integer from the user
num = int(input("Enter an integer: "))

# Check if the integer is positive, negative, or zero
if num > 0:
    print("The integer is positive")
elif num < 0:
    print("The integer is negative")
else:
    print("The integer is zero")
