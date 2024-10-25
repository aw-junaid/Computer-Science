# This program prints a numeric pyramid
num_rows = 5  # Set the number of rows

for i in range(1, num_rows + 1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print()
