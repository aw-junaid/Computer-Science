n = int(input("Enter a positive integer: "))
sum_odd = 0
sum_even = 0

for i in range(1, n+1):
    if i % 2 == 0:
        sum_even += i
    else:
        sum_odd += i

print("Sum of even numbers up to", n, "is", sum_even)
print("Sum of odd numbers up to", n, "is", sum_odd)
