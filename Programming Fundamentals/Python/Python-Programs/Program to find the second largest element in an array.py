def find_second_largest(arr):
    n = len(arr)
    if n < 2:
        return None
    largest = second_largest = float('-inf')
    for num in arr:
        if num > largest:
            second_largest = largest
            largest = num
        elif num > second_largest and num != largest:
            second_largest = num
    if second_largest == float('-inf'):
        return None
    return second_largest

# Example usage:
arr = [12, 35, 1, 10, 34, 1]
print("Second largest element:", find_second_largest(arr))
