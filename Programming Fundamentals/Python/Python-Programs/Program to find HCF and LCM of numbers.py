# function to find HCF or GCD
def find_hcf(a, b):
    if b == 0:
        return a
    else:
        return find_hcf(b, a % b)

# function to find LCM
def find_lcm(a, b):
    lcm = (a*b) // find_hcf(a, b)
    return lcm

# take input from user
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))

# find HCF and LCM
hcf = find_hcf(num1, num2)
lcm = find_lcm(num1, num2)

# print the results
print("The HCF of", num1, "and", num2, "is", hcf)
print("The LCM of", num1, "and", num2, "is", lcm)
