def digital_root(n):
    # If n is a single digit, return it
    if n < 10:
        return n

    # If n has multiple digits, find the sum of its digits
    sum_of_digits = 0
    while n > 0:
        sum_of_digits += n % 10
        n = n // 10

    # Recursively call the function with the sum of digits
    return digital_root(sum_of_digits)

# Test the function with some sample inputs
print(digital_root(12345)) # Output: 6
print(digital_root(987654321)) # Output: 9
print(digital_root(888)) # Output: 6
