import numpy as np

# define a matrix
A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

# calculate determinant of the matrix
det_A = np.linalg.det(A)

# print determinant
print("Determinant of the matrix A is:", det_A)
