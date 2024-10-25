def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

# Testing the function
arr = [1, 2, 3, 4, 5, 6, 7]
x = 5
result = linear_search(arr, x)
if result == -1:
    print("Element not found in the array")
else:
    print("Element found at index", result)
