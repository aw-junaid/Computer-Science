def find_frequency(matrix):
    # Initialize count variables
    even_count = 0
    odd_count = 0

    # Iterate over each element in matrix
    for row in matrix:
        for num in row:
            # If number is even, increment even_count
            if num % 2 == 0:
                even_count += 1
            # If number is odd, increment odd_count
            else:
                odd_count += 1

    # Print results
    print("Frequency of even numbers:", even_count)
    print("Frequency of odd numbers:", odd_count)
