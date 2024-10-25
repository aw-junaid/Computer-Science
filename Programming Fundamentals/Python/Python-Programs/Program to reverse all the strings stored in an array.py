# Function to reverse a string
def reverse_string(string):
    return string[::-1]

# Example array
array = ["hello", "world", "python", "programming"]

# Loop through the array and reverse each string
for i in range(len(array)):
    array[i] = reverse_string(array[i])

# Print the reversed array
print("Reversed Array:")
print(array)
