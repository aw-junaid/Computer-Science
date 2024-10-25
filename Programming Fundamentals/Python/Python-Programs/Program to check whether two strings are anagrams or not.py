# function to check if two strings are anagrams
def are_anagrams(s1, s2):
    # convert both strings to lowercase
    s1 = s1.lower()
    s2 = s2.lower()

    # check if the length of both strings are equal
    if len(s1) != len(s2):
        return False

    # convert the strings to lists of characters and sort them
    s1_list = list(s1)
    s1_list.sort()
    s2_list = list(s2)
    s2_list.sort()

    # compare the sorted lists of characters
    if s1_list == s2_list:
        return True
    else:
        return False

# take input from user
s1 = input("Enter first string: ")
s2 = input("Enter second string: ")

# call the function to check if the strings are anagrams
if are_anagrams(s1, s2):
    print("The strings are anagrams.")
else:
    print("The strings are not anagrams.")
