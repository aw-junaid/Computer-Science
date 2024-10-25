n = int(input("Enter the number of rows: "))

num = 1
for i in range(n, 0, -1):
    for j in range(1, i+1):
        print("*", end=" ")
    for k in range(n-i):
        print(num, end=" ")
        num += 1
    print()
