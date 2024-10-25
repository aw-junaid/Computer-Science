# initialize the matrix
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# get the dimensions of the matrix
rows = len(matrix)
cols = len(matrix[0])

# initialize row and column sums to zero
row_sums = [0] * rows
col_sums = [0] * cols

# calculate the sum of each row and column
for i in range(rows):
    for j in range(cols):
        row_sums[i] += matrix[i][j]
        col_sums[j] += matrix[i][j]

# print the row sums
print("Row sums:")
for i in range(rows):
    print(f"Row {i+1} sum: {row_sums[i]}")

# print the column sums
print("\nColumn sums:")
for j in range(cols):
    print(f"Column {j+1} sum: {col_sums[j]}")
