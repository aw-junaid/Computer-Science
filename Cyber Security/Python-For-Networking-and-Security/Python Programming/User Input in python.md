In Python, you can use the `input()` function to receive user input from the keyboard. The `input()` function displays a prompt (a message to the user) and waits for the user to enter text. Once the user presses the "Enter" key, the text entered by the user is returned as a string. Here's how you can use the `input()` function:

```python
# Getting user input and storing it in a variable
user_input = input("Enter your name: ")
print("Hello, " + user_input + "!")

# Getting an integer input and performing calculations
age = int(input("Enter your age: "))
years_to_100 = 100 - age
print("You will be 100 years old in approximately", years_to_100, "years.")
```

In the example above, the `input()` function is used to get user input and store it in the `user_input` variable. Then, the program prints a message using the user's input. Additionally, the second part of the example uses `int(input())` to get an integer input from the user, and the program calculates and prints the number of years until the user turns 100.

Keep in mind the following when using `input()`:

1. The text provided as an argument to `input()` serves as the prompt for the user.
2. The `input()` function always returns a string, so if you need to perform calculations with the input as a number (integer or float), you'll need to convert it using `int()` or `float()`.
3. User input includes leading and trailing whitespace (spaces, tabs, etc.), which you may need to handle appropriately using string methods like `strip()`.
4. The `input()` function waits for the user to press "Enter" before proceeding.

Be cautious when working with user input to handle potential errors or unexpected input. It's a good practice to validate and sanitize user input, especially when performing operations that could lead to errors or security vulnerabilities.
