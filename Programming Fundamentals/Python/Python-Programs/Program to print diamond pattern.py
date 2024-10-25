n = int(input("Enter the number of rows for the diamond pattern: "))

# Upper half of the diamond
for i in range(1, n+1, 2):
    print(" " * ((n-i)//2) + "*" * i)

# Lower half of the diamond
for i in range(n-2, 0, -2):
    print(" " * ((n-i)//2) + "*" * i)
