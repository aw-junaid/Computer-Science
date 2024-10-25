a = float(input("Enter first term of G.P.: "))
r = float(input("Enter common ratio of G.P.: "))

if abs(r) < 1:
    # calculate sum of infinite G.P. series
    sum = a / (1 - r)
    print("Sum of infinite G.P. series:", sum)
else:
    print("Common ratio should be less than 1 in absolute value for an infinite series.")
