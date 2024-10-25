import random

def roll_dice():
    return random.randint(1, 6), random.randint(1, 6)

def craps():
    dice_sum = sum(roll_dice())
    if dice_sum in (7, 11):
        print(f"You win! ({dice_sum})")
    elif dice_sum in (2, 3, 12):
        print(f"You lose! ({dice_sum})")
    else:
        point = dice_sum
        print(f"Point is {point}")
        while True:
            dice_sum = sum(roll_dice())
            print(f"Roll: {dice_sum}")
            if dice_sum == point:
                print("You win!")
                break
            elif dice_sum == 7:
                print("You lose!")
                break

craps()
