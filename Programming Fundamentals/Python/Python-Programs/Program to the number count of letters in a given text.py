text = input("Enter some text: ")
count = 0

for char in text:
    if char.isalpha():
        count += 1

print("The number of letters in the text is:", count)
