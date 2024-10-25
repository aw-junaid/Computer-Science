import math

def series(x, n):
    sum = 0
    for i in range(n):
        term = ((x**((2*i)+1)) / math.factorial((2*i)+1))
        sum += term
    return sum

x = int(input("Enter the value of x: "))
n = int(input("Enter the number of terms: "))

result = series(x, n)
print("The sum of the series is:", result)
