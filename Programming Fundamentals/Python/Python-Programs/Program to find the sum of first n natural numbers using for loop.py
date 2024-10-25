n = int(input("Enter a positive integer n: "))
sum = 0

for i in range(1, n+1):
    sum += i

print("The sum of first", n, "natural numbers is:", sum)
