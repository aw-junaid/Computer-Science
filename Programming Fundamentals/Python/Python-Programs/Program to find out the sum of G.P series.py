a = float(input("Enter the first term: "))
r = float(input("Enter the common ratio: "))
n = int(input("Enter the number of terms: "))

if r == 1:
    # sum of infinite terms of a G.P with common ratio 1 is undefined
    print("Sum of infinite terms is undefined.")
else:
    # calculate the sum of first n terms
    S = a * (1 - r**n) / (1 - r)
    print("Sum of first", n, "terms is", S)
