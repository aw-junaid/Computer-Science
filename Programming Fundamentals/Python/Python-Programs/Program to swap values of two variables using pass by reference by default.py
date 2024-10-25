# program to swap values of two variables using pass by reference method

# take input from user
a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))

# print the original values
print("Before swapping: a =", a, "and b =", b)

# swap the values
a, b = b, a

# print the swapped values
print("After swapping: a =", a, "and b =", b)
