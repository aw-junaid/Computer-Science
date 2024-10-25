def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

# Example usage
num = 5
fact = factorial(num)
print("The factorial of", num, "is", fact)
