# Write a python program that takes 10 numbers from the user and 
# creates a dictionary with even and odd keys. 
# The value of the dictionary is stored in the two lists. 
# After storing the value, find out the minimum elements from the lists.


# create empty lists to store even and odd numbers
even_numbers = []
odd_numbers = []

# get 10 numbers from the user and add them to the appropriate list
for i in range(10):
    num = int(input("Enter a number: "))
    if num % 2 == 0:
        even_numbers.append(num)
    else:
        odd_numbers.append(num)

# create a dictionary with the even and odd keys
num_dict = {'even': even_numbers, 'odd': odd_numbers}

# find the minimum elements from the even and odd lists
min_even = min(even_numbers)
min_odd = min(odd_numbers)

# print the dictionary and minimum values
print("Dictionary:", num_dict)
print("Minimum even number:", min_even)
print("Minimum odd number:", min_odd)
