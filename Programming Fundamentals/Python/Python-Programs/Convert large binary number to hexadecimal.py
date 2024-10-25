binary_num = "101110110110010101010101"
hex_num = ""

# Pad the binary number with 0's to make its length a multiple of 4
while len(binary_num) % 4 != 0:
    binary_num = "0" + binary_num

# Loop through the binary number in groups of 4 bits and convert each group to hexadecimal
for i in range(0, len(binary_num), 4):
    # Extract the current group of 4 bits
    group = binary_num[i:i+4]

    # Convert the group to its corresponding hexadecimal digit
    if group == "0000":
        hex_num += "0"
    elif group == "0001":
        hex_num += "1"
    elif group == "0010":
        hex_num += "2"
    elif group == "0011":
        hex_num += "3"
    elif group == "0100":
        hex_num += "4"
    elif group == "0101":
        hex_num += "5"
    elif group == "0110":
        hex_num += "6"
    elif group == "0111":
        hex_num += "7"
    elif group == "1000":
        hex_num += "8"
    elif group == "1001":
        hex_num += "9"
    elif group == "1010":
        hex_num += "A"
    elif group == "1011":
        hex_num += "B"
    elif group == "1100":
        hex_num += "C"
    elif group == "1101":
        hex_num += "D"
    elif group == "1110":
        hex_num += "E"
    elif group == "1111":
        hex_num += "F"

print("Binary number:", binary_num)
print("Hexadecimal number:", hex_num)
