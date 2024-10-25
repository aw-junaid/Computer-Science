# Function to add two numbers using pointers
def add_numbers(num1_ptr, num2_ptr):
    return num1_ptr + num2_ptr

# Main function
if __name__ == '__main__':
    # Accept two numbers from user
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    # Create reference variables for numbers
    num1_ptr = num1
    num2_ptr = num2

    # Add two numbers using pointers and print the result
    sum_ptr = add_numbers(num1_ptr, num2_ptr)
    print("Sum of", num1_ptr, "and", num2_ptr, "is", sum_ptr)
