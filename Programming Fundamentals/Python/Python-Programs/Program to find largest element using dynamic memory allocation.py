import sys

n = int(input("Enter number of elements in the array: "))

# allocate memory for the array dynamically
arr = []
for i in range(n):
    arr.append(int(input("Enter element " + str(i+1) + ": ")))

# initialize max variable to the first element of the array
max = arr[0]

# iterate over the array to find the largest element
for i in range(1, n):
    if arr[i] > max:
        max = arr[i]

# print the largest element
print("Largest element in the array is:", max)

# free the dynamically allocated memory
del arr
