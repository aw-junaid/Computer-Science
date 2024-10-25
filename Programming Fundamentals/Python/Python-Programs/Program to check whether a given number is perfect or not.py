# program to check whether a given number is perfect or not

# accept input number from user
number = int(input("Enter a number: "))

# initialize sum to 0
sum = 0

# loop through all numbers from 1 to the input number
for i in range(1, number):
    # check if i is a factor of the input number
    if number % i == 0:
        # add i to the sum
        sum += i

# check if the sum of factors is equal to the input number
if sum == number:
    print(number, "is a perfect number.")
else:
    print(number, "is not a perfect number.")
