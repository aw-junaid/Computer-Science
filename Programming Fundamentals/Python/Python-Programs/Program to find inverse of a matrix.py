def inverse(matrix):
    """
    Calculates the inverse of a 3x3 matrix using Gauss-Jordan elimination.
    """
    # Augment the matrix with the identity matrix
    aug_matrix = matrix + [[1, 0, 0], [0, 1, 0], [0, 0, 1]]

    # Perform row operations to get the left side to be the identity matrix
    for i in range(3):
        pivot = aug_matrix[i][i]
        for j in range(3):
            if i != j:
                factor = aug_matrix[j][i] / pivot
                for k in range(6):
                    aug_matrix[j][k] -= factor * aug_matrix[i][k]

    # Divide the right side by the diagonal elements to get the inverse
    for i in range(3):
        diagonal_element = aug_matrix[i][i]
        for j in range(3, 6):
            aug_matrix[i][j] /= diagonal_element

    # Extract the inverse from the right side of the augmented matrix
    inverse_matrix = [[aug_matrix[i][j] for j in range(3, 6)] for i in range(3)]

    return inverse_matrix
