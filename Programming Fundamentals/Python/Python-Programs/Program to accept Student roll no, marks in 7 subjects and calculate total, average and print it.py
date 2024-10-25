# This program accepts a student's roll number and marks in 7 subjects, and calculates the total and average marks

# Accept the roll number and marks from the user
roll_number = input("Enter the student's roll number: ")
marks = []

for i in range(7):
    subject_marks = int(input(f"Enter the marks for subject {i+1}: "))
    marks.append(subject_marks)

# Calculate the total marks and average marks
total_marks = sum(marks)
average_marks = total_marks / len(marks)

# Print the results
print(f"Roll Number: {roll_number}")
print(f"Total Marks: {total_marks}")
print(f"Average Marks: {average_marks}")
