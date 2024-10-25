# function to remove duplicate elements
def removeDuplicates(arr):
    # create an empty list to store unique elements
    unique_arr = []

    # loop through each element in the array
    for element in arr:
        # check if the element is already present in the unique_arr list
        if element not in unique_arr:
            # if it is not present, add it to the list
            unique_arr.append(element)

    # return the unique_arr list
    return unique_arr

# example array
arr = [1, 2, 3, 4, 1, 2, 5, 6, 3, 4]

# call the function to remove duplicates
unique_arr = removeDuplicates(arr)

# print the result
print("Array with duplicates: ", arr)
print("Array without duplicates: ", unique_arr)
