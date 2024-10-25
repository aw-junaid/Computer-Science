def is_identity_matrix(matrix):
    # Check if matrix is square
    rows = len(matrix)
    cols = len(matrix[0])
    if rows != cols:
        return False

    # Check diagonal elements
    for i in range(rows):
        for j in range(cols):
            if i == j and matrix[i][j] != 1:
                return False
            if i != j and matrix[i][j] != 0:
                return False
    return True

# Example Usage
matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
matrix2 = [[1, 0, 0], [0, 1, 1], [0, 0, 1]]

print(is_identity_matrix(matrix1)) # Output: True
print(is_identity_matrix(matrix2)) # Output: False
