num = int(input("Enter a number: "))
temp = num
reverse_num = 0

while temp > 0:
    digit = temp % 10
    reverse_num = reverse_num * 10 + digit
    temp //= 10

if num == reverse_num:
    print(num, "is a palindrome number")
else:
    print(num, "is not a palindrome number")
