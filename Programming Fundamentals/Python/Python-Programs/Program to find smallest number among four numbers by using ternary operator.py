# Find smallest number among four numbers using ternary operator

a = 10
b = 20
c = 30
d = 40

# Using nested ternary operators to find the smallest number
min_num = a if a < b else b if b < c else c if c < d else d

print("The smallest number among", a, b, c, "and", d, "is", min_num)
