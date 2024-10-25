def check_matrix(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    # Check if the matrix is square or not
    if rows != cols:
        return "The given matrix is not a square matrix."

    # Check if the matrix is symmetric or skew-symmetric
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] != matrix[j][i]:
                break
        else:
            continue
        break
    else:
        return "The given matrix is symmetric."

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] != -matrix[j][i]:
                break
        else:
            continue
        break
    else:
        return "The given matrix is skew-symmetric."

    return "The given matrix is neither symmetric nor skew-symmetric."


# Test the function with some sample matrices
matrix1 = [[1, 2, 3], [2, 4, 5], [3, 5, 6]]
matrix2 = [[0, 1, -2], [-1, 0, 3], [2, -3, 0]]
matrix3 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

print(check_matrix(matrix1))
print(check_matrix(matrix2))
print(check_matrix(matrix3))
