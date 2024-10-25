# function to insert element in array
def insertElement(arr, n, x, pos):

    # increase size of array by 1
    arr.append(0)

    # shift elements from right to left
    for i in range(n, pos, -1):
        arr[i] = arr[i-1]

    # insert new element at given position
    arr[pos] = x

    # return new size of array
    return n+1

# example usage
arr = [1, 2, 3, 4, 5]
n = len(arr)
x = 6
pos = 2
n = insertElement(arr, n, x, pos)
print("New array:", arr)
