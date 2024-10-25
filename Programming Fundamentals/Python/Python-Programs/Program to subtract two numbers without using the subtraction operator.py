# This program subtracts two numbers without using the subtraction operator
num1 = 10
num2 = 5

# Subtract num2 from num1 using addition
result = num1 + (~num2 + 1)

print(f"The difference between {num1} and {num2} is {result}")
