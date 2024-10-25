octal = input("Enter an octal number: ")

decimal = 0
power = 0

# Iterate through the octal digits from right to left
for digit in octal[::-1]:
    decimal += int(digit) * (8 ** power)
    power += 1

print("The decimal equivalent of", octal, "is", decimal)
