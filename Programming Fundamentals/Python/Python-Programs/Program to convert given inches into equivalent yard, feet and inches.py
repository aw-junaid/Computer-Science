inches = int(input("Enter the length in inches: "))

yards = inches // 36  # 1 yard = 36 inches
inches = inches % 36

feet = inches // 12  # 1 foot = 12 inches
inches = inches % 12

print(f"{yards} yards, {feet} feet, {inches} inches")
