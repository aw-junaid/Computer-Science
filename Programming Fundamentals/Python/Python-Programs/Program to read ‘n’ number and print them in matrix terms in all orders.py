import math

# function to read 'n' numbers and create a matrix
def create_matrix():
    n = int(input("Enter the number of elements: "))
    rows = int(math.sqrt(n))
    matrix = []
    for i in range(rows):
        row = []
        for j in range(rows):
            if len(matrix) < n:
                num = int(input("Enter the number: "))
                row.append(num)
        matrix.append(row)
    return matrix

# function to print matrix in all orders
def print_matrix(matrix):
    print("\nMatrix in row major order:")
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=" ")
        print()

    print("\nMatrix in column major order:")
    for i in range(len(matrix[0])):
        for j in range(len(matrix)):
            print(matrix[j][i], end=" ")
        print()

    print("\nMatrix in diagonal major order:")
    for i in range(len(matrix)):
        for j in range(i+1):
            print(matrix[i-j][j], end=" ")
        print()

    for i in range(1, len(matrix)):
        for j in range(len(matrix)-i):
            print(matrix[len(matrix)-j-1][i+j], end=" ")
        print()

# main function
if __name__ == "__main__":
    matrix = create_matrix()
    print_matrix(matrix)
