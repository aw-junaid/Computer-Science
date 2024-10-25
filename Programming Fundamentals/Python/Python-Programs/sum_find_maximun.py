# Write a python program that takes three lists from the user,
# it calculates the sum of each list individually and
# prints the maximum list sum.


# here you can can use input funtion to take the list ftom the user
# user have to write numeber with space 12 124 435 then it will
# add all the numbers 


list1 = list(map(int, input("Enter list 1: ").split()))
list2 = list(map(int, input("Enter list 2: ").split()))
list3 = list(map(int, input("Enter list 3: ").split()))

# use sum funtion to find the addition of all list enter by user

sum1 = sum(list1)
sum2 = sum(list2)
sum3 = sum(list3)
# Use max function to find the sum of all given list 
max_sum = max(sum1, sum2, sum3)

print("The maximum list sum is:", max_sum)
