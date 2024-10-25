# Function to calculate factorial
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

# Take user input
num = int(input("Enter a number: "))

# Call the function and print the result
print("Factorial of", num, "is", factorial(num))
