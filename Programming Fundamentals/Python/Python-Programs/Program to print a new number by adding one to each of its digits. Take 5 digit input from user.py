# This program adds 1 to each digit of a 5-digit number

# Accept the 5-digit number from the user
num = input("Enter a 5-digit number: ")

# Check if the input is valid
if len(num) != 5 or not num.isdigit():
    print("Invalid input. Please enter a 5-digit number.")
else:
    # Convert the string to a list of integers
    digits = [int(d) for d in num]

    # Add 1 to each digit
    digits = [(d + 1) % 10 for d in digits]

    # Convert the list back to a string and print the result
    result = "".join(str(d) for d in digits)
    print("The new number is:", result)
