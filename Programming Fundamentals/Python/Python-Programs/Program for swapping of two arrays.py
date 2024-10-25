# function to swap two arrays
def swapArrays(arr1, arr2):
    # swapping
    arr1[:], arr2[:] = arr2[:], arr1[:]
    # printing swapped arrays
    print("Array 1 after swapping: ", arr1)
    print("Array 2 after swapping: ", arr2)

# example usage
array1 = [1, 2, 3, 4, 5]
array2 = [6, 7, 8, 9, 10]

print("Array 1 before swapping: ", array1)
print("Array 2 before swapping: ", array2)

# calling function to swap two arrays
swapArrays(array1, array2)
