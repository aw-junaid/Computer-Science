def second_smallest(arr):
    # Set the first and second smallest elements initially to maximum value
    smallest = second_smallest = float('inf')

    for num in arr:
        # If current number is smaller than smallest, update both smallest and second smallest
        if num < smallest:
            second_smallest = smallest
            smallest = num
        # If current number is between smallest and second smallest, update second smallest
        elif num < second_smallest and num != smallest:
            second_smallest = num

    # Return second smallest element
    return second_smallest
