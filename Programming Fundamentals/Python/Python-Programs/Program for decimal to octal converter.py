decimal_num = int(input("Enter a decimal number: "))
octal_num = 0
i = 1

while decimal_num != 0:
    remainder = decimal_num % 8
    octal_num += remainder * i
    i *= 10
    decimal_num //= 8

print("The octal representation is:", octal_num)
