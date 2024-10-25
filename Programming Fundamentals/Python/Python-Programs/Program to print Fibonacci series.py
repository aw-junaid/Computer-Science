# take input from user for number of terms in Fibonacci series
n = int(input("Enter the number of terms: "))

# initialize variables
first_term = 0
second_term = 1

# check if number of terms is valid
if n <= 0:
    print("Please enter a positive integer.")
elif n == 1:
    print("Fibonacci series up to", n, "term:")
    print(first_term)
else:
    print("Fibonacci series up to", n, "terms:")
    print(first_term, ",", second_term, end=" ")
    for i in range(2, n):
        next_term = first_term + second_term
        print(",", next_term, end=" ")
        first_term = second_term
        second_term = next_term
