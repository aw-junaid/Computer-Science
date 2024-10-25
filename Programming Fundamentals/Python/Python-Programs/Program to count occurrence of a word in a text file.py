filename = input("Enter the filename: ")
word = input("Enter the word to count: ")

with open(filename, 'r') as f:
    count = 0
    for line in f:
        words = line.split()
        for w in words:
            if w == word:
                count += 1

print("The word '{}' occurs {} times in the file '{}'.".format(word, count, filename))
