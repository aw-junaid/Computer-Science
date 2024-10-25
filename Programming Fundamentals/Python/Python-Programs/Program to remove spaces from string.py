s = input("Enter a string with spaces: ")
new_s = ""
for i in s:
    if i != " ":
        new_s += i
print("String without spaces:", new_s)
