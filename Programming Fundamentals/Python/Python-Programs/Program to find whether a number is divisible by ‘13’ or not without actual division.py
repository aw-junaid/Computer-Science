num = int(input("Enter a number: "))

if num < 0:
    print("Invalid input. Please enter a positive integer.")
else:
    a = num // 1000
    b = (num // 100) % 10
    c = (num // 10) % 10
    d = num % 10

    if (100*a + 10*c + b - d) % 13 == 0:
        print(num, "is divisible by 13.")
    else:
        print(num, "is not divisible by 13.")
