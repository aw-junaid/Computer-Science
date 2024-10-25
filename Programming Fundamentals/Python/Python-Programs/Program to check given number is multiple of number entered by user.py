# Taking input from user
num = int(input("Enter a number: "))
divisor = int(input("Enter divisor: "))

# Checking if number is multiple of divisor
if num % divisor == 0:
    print(num, "is a multiple of", divisor)
else:
    print(num, "is not a multiple of", divisor)
