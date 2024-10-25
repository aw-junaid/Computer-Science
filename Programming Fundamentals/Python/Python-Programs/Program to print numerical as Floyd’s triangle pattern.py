n = int(input("Enter the number of rows: "))

num = 1

for i in range(1, n+1):
    for j in range(1, i+1):
        print(num, end=" ")
        num += 1
    print()
