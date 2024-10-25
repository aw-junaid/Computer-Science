def sum_harmonic_series(n, series):
    """
    Function to calculate the sum of harmonic series

    Arguments:
    n -- Total number of terms in the series (int)
    series -- A list of individual terms in the series (list)

    Returns:
    The sum of harmonic series (float)
    """
    sum_series = 0
    for i in range(n):
        sum_series += 1 / series[i]
    return n / sum_series

# Example usage
n = 5
series = [2, 4, 6, 8, 10]
print("The sum of the harmonic series is:", sum_harmonic_series(n, series))
