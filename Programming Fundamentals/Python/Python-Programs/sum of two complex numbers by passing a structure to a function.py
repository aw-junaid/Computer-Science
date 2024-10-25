# Define a class to represent a complex number
class Complex:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

# Define a function that takes two complex numbers as input and returns their sum
def add(a, b):
    return Complex(a.real + b.real, a.imaginary + b.imaginary)

# Create two complex numbers
a = Complex(3.0, 2.0)
b = Complex(1.0, 7.0)

# Compute their sum by calling the add function
sum = add(a, b)

# Print the sum
print(f"The sum is {sum.real} + {sum.imaginary}i")
