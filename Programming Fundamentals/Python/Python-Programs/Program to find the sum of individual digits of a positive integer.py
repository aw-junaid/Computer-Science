num = int(input("Enter a positive integer: "))
sum = 0

while num > 0:
    digit = num % 10
    sum += digit
    num //= 10

print("The sum of individual digits is:", sum)
