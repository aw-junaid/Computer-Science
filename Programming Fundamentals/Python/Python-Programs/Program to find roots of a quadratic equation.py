import math

def find_roots(a, b, c):
    # calculate the discriminant
    disc = b * b - 4 * a * c

    # check if discriminant is negative, no real roots
    if disc < 0:
        return None

    # calculate the roots
    root1 = (-b + math.sqrt(disc)) / (2 * a)
    root2 = (-b - math.sqrt(disc)) / (2 * a)

    # return the roots
    return root1, root2

# example usage
a = 1
b = -5
c = 6

roots = find_roots(a, b, c)
if roots is None:
    print("No real roots")
else:
    print("Roots are:", roots)
