def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    return a / b

def modulus(a, b):
    return a % b

def exponent(a, b):
    return a ** b

def default():
    return "Invalid operation"

# create a dictionary of operations
operations = {
    '+': add,
    '-': subtract,
    '*': multiply,
    '/': divide,
    '%': modulus,
    '**': exponent
}

# take user input for operands and operator
a = float(input("Enter first operand: "))
b = float(input("Enter second operand: "))
op = input("Enter operator (+, -, *, /, %, **): ")

# perform operation using the dictionary
result = operations.get(op, default)(a, b)

# print the result
print(f"{a} {op} {b} = {result}")
