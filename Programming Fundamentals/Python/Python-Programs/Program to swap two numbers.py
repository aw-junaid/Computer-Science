# This program swaps the values of two variables using a temporary variable
num1 = 10
num2 = 20

print(f"Before swapping: num1 = {num1}, num2 = {num2}")

# Swap the values of num1 and num2 using a temporary variable
temp = num1
num1 = num2
num2 = temp

print(f"After swapping: num1 = {num1}, num2 = {num2}")
