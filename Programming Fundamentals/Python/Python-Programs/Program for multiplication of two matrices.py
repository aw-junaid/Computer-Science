# function to multiply two matrices
def multiply_matrices(mat1, mat2):
    rows1, cols1 = len(mat1), len(mat1[0])
    rows2, cols2 = len(mat2), len(mat2[0])

    # check if multiplication is possible
    if cols1 != rows2:
        return None

    # create result matrix
    result = [[0 for _ in range(cols2)] for _ in range(rows1)]

    # perform multiplication
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += mat1[i][k] * mat2[k][j]

    return result


# sample input matrices
matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix2 = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]

# print input matrices
print("Input matrix 1:")
for row in matrix1:
    print(row)

print("Input matrix 2:")
for row in matrix2:
    print(row)

# perform matrix multiplication
result_matrix = multiply_matrices(matrix1, matrix2)

# print result matrix
if result_matrix is None:
    print("Cannot multiply the matrices.")
else:
    print("Result matrix:")
    for row in result_matrix:
        print(row)
