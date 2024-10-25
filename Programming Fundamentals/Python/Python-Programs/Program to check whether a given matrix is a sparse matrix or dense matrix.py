# function to check if a matrix is sparse or dense
def check_sparse_or_dense(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    count_zeroes = 0
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                count_zeroes += 1

    # if more than half of the elements are zero, matrix is sparse
    if count_zeroes > rows * cols // 2:
        return "Sparse Matrix"
    # else matrix is dense
    else:
        return "Dense Matrix"
