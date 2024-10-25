# function to check if a number is prime
def is_prime(n):
    # 1 is not a prime number
    if n == 1:
        return False
    # check for divisibility by numbers from 2 to n-1
    for i in range(2, n):
        if n % i == 0:
            return False
    # if no divisor is found, the number is prime
    return True

# take input from user
num = int(input("Enter a number: "))

# check if the number is prime or not
if is_prime(num):
    print(num, "is a prime number")
else:
    print(num, "is not a prime number")
