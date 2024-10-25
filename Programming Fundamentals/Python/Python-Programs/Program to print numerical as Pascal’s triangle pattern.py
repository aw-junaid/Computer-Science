def print_pascals_triangle(n):
    # initialize the first row of the triangle
    row = [1]
    # loop through each row up to n
    for i in range(n):
        # print each value in the current row
        for j in range(len(row)):
            print(row[j], end=" ")
        print()
        # calculate the next row
        new_row = [1]
        for j in range(1, len(row)):
            new_row.append(row[j-1] + row[j])
        new_row.append(1)
        row = new_row

# test the function with n = 5
print_pascals_triangle(5)
