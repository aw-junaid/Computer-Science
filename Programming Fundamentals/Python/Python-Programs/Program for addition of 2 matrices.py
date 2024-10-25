def add_matrices(mat1, mat2):
    """
    Function to add two matrices of same dimensions
    """
    rows = len(mat1)
    cols = len(mat1[0])
    result = [[0 for j in range(cols)] for i in range(rows)]

    for i in range(rows):
        for j in range(cols):
            result[i][j] = mat1[i][j] + mat2[i][j]

    return result

# Example usage
mat1 = [[1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]]

mat2 = [[9, 8, 7],
        [6, 5, 4],
        [3, 2, 1]]

print("Matrix 1: ")
for row in mat1:
    print(row)

print("Matrix 2: ")
for row in mat2:
    print(row)

result = add_matrices(mat1, mat2)
print("Addition Result: ")
for row in result:
    print(row)
