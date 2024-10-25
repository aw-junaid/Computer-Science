# function to find the largest and second largest numbers from a 2D array
def find_largest(arr):
    largest = arr[0][0]
    second_largest = arr[0][1]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] > largest:
                second_largest = largest
                largest = arr[i][j]
            elif arr[i][j] > second_largest and arr[i][j] != largest:
                second_largest = arr[i][j]
    return largest, second_largest

# test the function
arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(find_largest(arr)) # output: (9, 8)
