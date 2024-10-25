class SwapNumbers:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2

    def swap(self):
        temp = self.num1
        self.num1 = self.num2
        self.num2 = temp

    def display(self):
        print("After swapping: num1 =", self.num1, ", num2 =", self.num2)

# Taking input from the user
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

# Creating an object of SwapNumbers class
swap_obj = SwapNumbers(num1, num2)

# Displaying the original numbers
print("Before swapping: num1 =", num1, ", num2 =", num2)

# Calling the swap method to swap the numbers
swap_obj.swap()

# Displaying the swapped numbers
swap_obj.display()
