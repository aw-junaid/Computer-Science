# taking two strings as input
str1 = input("Enter first string: ")
str2 = input("Enter second string: ")

# printing original strings
print("Original strings:")
print("String 1:", str1)
print("String 2:", str2)

# swapping using a temporary variable
temp = str1
str1 = str2
str2 = temp

# printing swapped strings
print("Swapped strings:")
print("String 1:", str1)
print("String 2:", str2)
