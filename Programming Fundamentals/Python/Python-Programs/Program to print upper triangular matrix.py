def upper_triangular_matrix(matrix):
    n = len(matrix)
    upper_matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            if j >= i:
                row.append(matrix[i][j])
            else:
                row.append(0)
        upper_matrix.append(row)
    return upper_matrix

# Example usage
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
result = upper_triangular_matrix(matrix)
print(result)
