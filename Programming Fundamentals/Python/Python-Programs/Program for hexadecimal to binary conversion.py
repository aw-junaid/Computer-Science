hex_num = input("Enter a hexadecimal number: ")
bin_num = ""

# Define a dictionary to map hexadecimal digits to their binary equivalent
hex_to_bin = {"0": "0000", "1": "0001", "2": "0010", "3": "0011", "4": "0100",
              "5": "0101", "6": "0110", "7": "0111", "8": "1000", "9": "1001",
              "A": "1010", "B": "1011", "C": "1100", "D": "1101", "E": "1110", "F": "1111"}

# Convert each hexadecimal digit to its binary equivalent and concatenate them to get the final binary number
for digit in hex_num:
    bin_num += hex_to_bin[digit]

print("The binary equivalent of", hex_num, "is", bin_num)
