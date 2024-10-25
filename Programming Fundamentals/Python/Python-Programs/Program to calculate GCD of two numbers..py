def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Example usage
a = 54
b = 24
print("GCD of", a, "and", b, "is", gcd(a, b))
