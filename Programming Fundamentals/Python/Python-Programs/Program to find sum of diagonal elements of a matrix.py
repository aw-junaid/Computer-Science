# function to find sum of diagonal elements of a matrix
def sum_diagonal_elements(matrix):
    sum = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if i == j:
                sum += matrix[i][j]
    return sum

# example matrix
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

# call the function and print the result
print("Sum of diagonal elements:", sum_diagonal_elements(matrix))
