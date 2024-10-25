num = int(input("Enter a number: "))
original_num = num

# Finding the factorial of each digit
sum_of_factorials = 0
while num > 0:
    digit = num % 10
    factorial = 1
    for i in range(1, digit+1):
        factorial *= i
    sum_of_factorials += factorial
    num //= 10

# Checking if the number is strong or not
if original_num == sum_of_factorials:
    print(original_num, "is a strong number")
else:
    print(original_num, "is not a strong number")
