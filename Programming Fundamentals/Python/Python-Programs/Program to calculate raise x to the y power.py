# This program calculates x to the power of y

# Accept the values of x and y from the user
x = float(input("Enter the value of x: "))
y = int(input("Enter the value of y: "))

# Calculate the result using the ** operator
result = x ** y

# Print the result
print("{0} to the power of {1} is {2}".format(x, y, result))
