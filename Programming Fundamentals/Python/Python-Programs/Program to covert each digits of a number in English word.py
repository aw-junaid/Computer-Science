def digit_to_word(num):
    # Define lists for each digit word
    ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    teens = ["", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

    # Convert number to string
    num_str = str(num)

    # Define variables for digit words
    thousands_word = ""
    hundreds_word = ""
    tens_word = ""
    ones_word = ""

    # Handle thousands place
    if len(num_str) == 4:
        thousands_word = ones[int(num_str[0])] + " thousand "
        num_str = num_str[1:]

    # Handle hundreds place
    if len(num_str) == 3:
        hundreds_word = ones[int(num_str[0])] + " hundred "
        num_str = num_str[1:]

    # Handle tens place
    if len(num_str) == 2:
        if num_str[0] == "1":
            tens_word = teens[int(num_str[1])] + " "
        else:
            tens_word = tens[int(num_str[0])] + " "
            num_str = num_str[1:]

    # Handle ones place
    if len(num_str) == 1:
        ones_word = ones[int(num_str[0])]

    # Concatenate digit words and return
    return thousands_word + hundreds_word + tens_word + ones_word
