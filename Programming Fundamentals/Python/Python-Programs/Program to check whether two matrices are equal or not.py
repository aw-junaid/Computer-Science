def are_matrices_equal(mat1, mat2):
    # Check if dimensions of the matrices are equal
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        return False

    # Check if each element of the matrices is equal
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            if mat1[i][j] != mat2[i][j]:
                return False

    return True

# Example usage
mat1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
mat2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
mat3 = [[1, 2, 3], [4, 5, 6], [10, 11, 12]]

print(are_matrices_equal(mat1, mat2))  # True
print(are_matrices_equal(mat1, mat3))  # False
