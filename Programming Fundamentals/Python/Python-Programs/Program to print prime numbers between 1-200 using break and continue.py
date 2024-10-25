# function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# print prime numbers between 1 and 200
for i in range(1, 201):
    if i == 1:
        continue
    elif i > 200:
        break
    elif is_prime(i):
        print(i, end=" ")
