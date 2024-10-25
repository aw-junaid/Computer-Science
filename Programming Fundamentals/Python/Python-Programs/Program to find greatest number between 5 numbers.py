# This program finds the greatest number among 5 numbers

# Accept 5 numbers from the user
num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))
num3 = float(input("Enter the third number: "))
num4 = float(input("Enter the fourth number: "))
num5 = float(input("Enter the fifth number: "))

# Find the greatest number using if statements
if num1 >= num2 and num1 >= num3 and num1 >= num4 and num1 >= num5:
    greatest = num1
elif num2 >= num1 and num2 >= num3 and num2 >= num4 and num2 >= num5:
    greatest = num2
elif num3 >= num1 and num3 >= num2 and num3 >= num4 and num3 >= num5:
    greatest = num3
elif num4 >= num1 and num4 >= num2 and num4 >= num3 and num4 >= num5:
    greatest = num4
else:
    greatest = num5

# Print the result
print("The greatest number among", num1, ",", num2, ",", num3, ",", num4, "and", num5, "is", greatest)
