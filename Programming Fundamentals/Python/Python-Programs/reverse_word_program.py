# Write a python program that inputs a sentence as a string from the user, 
# reverse each word in that string and then asks 
# the user to remove a specific word from that string



#  using def function to split the sentence into the words that we can rervere them and after we can delete them out

def reverse_string(sentence):
    # Split the sentence into words
    words = sentence.split()

    # Reverse each word
    reversed_words = [word[::-1] for word in words]

    # Join the reversed words to form the new sentence
    reversed_sentence = ' '.join(reversed_words)

    return reversed_sentence

# Get the input sentence from the user
sentence = input("Enter a sentence: ")

# Reverse each word in the sentence
reversed_sentence = reverse_string(sentence)

# Print the reversed sentence
print("Reversed sentence: ", reversed_sentence)

# Ask the user to remove a specific word from the sentence
word_to_remove = input("Enter a word to remove: ")

# Remove the specified word from the sentence
new_sentence = ' '.join([word for word in reversed_sentence.split() if word != word_to_remove])

# Print the new sentence without the specified word
print("New sentence: ", new_sentence)
