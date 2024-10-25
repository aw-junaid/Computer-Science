# function to find transpose of matrix
def transpose_matrix(matrix):
    # get number of rows and columns in matrix
    rows = len(matrix)
    cols = len(matrix[0])

    # create a new matrix to hold the transpose
    transpose = [[0 for j in range(rows)] for i in range(cols)]

    # iterate through the matrix and assign values to transpose
    for i in range(rows):
        for j in range(cols):
            transpose[j][i] = matrix[i][j]

    # return the transpose matrix
    return transpose

# sample matrix
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

# print original matrix
print("Original Matrix:")
for row in matrix:
    print(row)

# get transpose of matrix
transpose = transpose_matrix(matrix)

# print transpose of matrix
print("\nTranspose of Matrix:")
for row in transpose:
    print(row)
