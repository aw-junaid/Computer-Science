num = int(input("Enter a number: "))  # take input from user

reverse = 0  # initialize variable to store the reverse of number

while num > 0:  # loop through until all digits are reversed
    digit = num % 10  # get the last digit of the number
    reverse = reverse * 10 + digit  # append the digit to the reversed number
    num = num // 10  # remove the last digit from the number

print("The reverse of the number is:", reverse)  # print the reversed number
