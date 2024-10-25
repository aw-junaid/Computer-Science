def insert_element(arr, num, pos):
    """
    Function to insert an element in an array at a desired position.
    """
    n = len(arr)
    if pos < 0 or pos > n:
        print("Invalid position.")
        return arr
    arr.append(None)
    for i in range(n, pos, -1):
        arr[i] = arr[i-1]
    arr[pos] = num
    return arr
