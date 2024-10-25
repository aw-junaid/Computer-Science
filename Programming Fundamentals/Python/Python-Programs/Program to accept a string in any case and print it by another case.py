# program to accept a string in any case and print it in a specified case

# accept input string from user
string = input("Enter a string: ")

# convert string to upper case
upper_case_string = string.upper()

# convert string to lower case
lower_case_string = string.lower()

# convert string to title case
title_case_string = string.title()

# print results
print("Original String:", string)
print("Upper Case String:", upper_case_string)
print("Lower Case String:", lower_case_string)
print("Title Case String:", title_case_string)
