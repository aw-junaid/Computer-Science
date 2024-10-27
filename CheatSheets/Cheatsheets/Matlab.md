An extended MATLAB cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes basic syntax, data types, control structures, functions, plotting, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```matlab
disp('Hello, World!')
```

**Explanation**: This command uses `disp()` to display "Hello, World!" in the command window.

---

## **2. Data Types**

### 2.1 Scalars

```matlab
x = 5;  % Scalar assignment
```

**Explanation**: A scalar is a single numerical value.

### 2.2 Vectors

```matlab
row_vector = [1, 2, 3];      % Row vector
column_vector = [1; 2; 3];   % Column vector
```

**Explanation**: Vectors are one-dimensional arrays that can be either row or column vectors.

### 2.3 Matrices

```matlab
A = [1, 2; 3, 4];  % 2x2 matrix
```

**Explanation**: A matrix is a two-dimensional array of numbers.

### 2.4 Strings

```matlab
str = 'Hello, MATLAB!';  % String assignment
```

**Explanation**: Strings are arrays of characters. Use single quotes for character arrays.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```matlab
number = 10;

if number > 0
    disp('Positive')
elseif number < 0
    disp('Negative')
else
    disp('Zero')
end
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Switch Statement

```matlab
fruit = 'Apple';

switch fruit
    case 'Apple'
        disp('It''s an apple!')
    case 'Banana'
        disp('It''s a banana!')
    otherwise
        disp('Unknown fruit')
end
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases.

### 3.3 For Loop

```matlab
for i = 1:5
    disp(i)
end
```

**Explanation**: The `for` loop iterates over a specified range of values.

### 3.4 While Loop

```matlab
count = 5;

while count > 0
    disp(count)
    count = count - 1;
end
```

**Explanation**: The `while` loop continues to execute as long as its condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```matlab
function result = add(a, b)
    result = a + b;
end

% Calling the function
sum = add(5, 3);
disp(sum)  % Outputs: 8
```

**Explanation**: Functions are defined using the `function` keyword, and can return a value.

### 4.2 Default Parameters

```matlab
function result = multiply(x, y)
    if nargin < 2
        y = 1;  % Default value for y
    end
    result = x * y;
end
```

**Explanation**: Use `nargin` to check the number of input arguments and provide default values.

---

## **5. Data Structures**

### 5.1 Cell Arrays

```matlab
my_cell = {1, 'text', [1, 2, 3]};
```

**Explanation**: Cell arrays can hold different types of data in each cell.

### 5.2 Structures

```matlab
my_struct.name = 'Alice';
my_struct.age = 25;
```

**Explanation**: Structures are data types that group related data using named fields.

---

## **6. Plotting**

### 6.1 Basic Plotting

```matlab
x = 1:10;
y = x.^2;  % Square each element of x

plot(x, y)
title('Plot of x vs. y')
xlabel('x-axis')
ylabel('y-axis')
```

**Explanation**: The `plot()` function creates a basic line plot. Use `title()`, `xlabel()`, and `ylabel()` to add labels.

### 6.2 Scatter Plot

```matlab
scatter(x, y, 'filled')
```

**Explanation**: Use `scatter()` to create a scatter plot of x and y data points.

### 6.3 Histograms

```matlab
data = randn(1000, 1);  % Generate random data
histogram(data)
title('Histogram of Random Data')
```

**Explanation**: Use `histogram()` to create a histogram of the provided data.

---

## **7. File I/O**

### 7.1 Reading from Files

```matlab
data = readmatrix('data.csv');  % Read a CSV file
```

**Explanation**: Use `readmatrix()` to read data from a CSV or text file into a matrix.

### 7.2 Writing to Files

```matlab
writematrix(data, 'output.csv');  % Write data to a CSV file
```

**Explanation**: Use `writematrix()` to save matrix data to a CSV or text file.

---

## **8. Array Operations**

### 8.1 Element-wise Operations

```matlab
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];

C = A + B;  % Element-wise addition
D = A .* B; % Element-wise multiplication
```

**Explanation**: Use `+`, `-`, `.*`, and `./` for element-wise operations on matrices.

### 8.2 Matrix Operations

```matlab
E = A * B;  % Matrix multiplication
F = inv(A); % Inverse of matrix A
```

**Explanation**: Use `*` for matrix multiplication and `inv()` to compute the inverse of a matrix.

---

## **9. Control Flow Functions**

### 9.1 Applying Functions

```matlab
numbers = [1, 2, 3, 4, 5];

squared = arrayfun(@(x) x^2, numbers);
```

**Explanation**: Use `arrayfun()` to apply a function to each element of an array.

### 9.2 Using `cellfun`

```matlab
my_cell = {1, 2, 3};

squared_cells = cellfun(@(x) x^2, my_cell);
```

**Explanation**: Use `cellfun()` to apply a function to each cell in a cell array.

---

## **10. Regular Expressions**

### 10.1 Pattern Matching

```matlab
text = 'Hello, my name is Alice.';
match = regexp(text, 'Alice', 'match');
```

**Explanation**: Use `regexp()` to search for patterns in a string.

### 10.2 String Replacement

```matlab
new_text = strrep(text, 'Alice', 'Bob');
```

**Explanation**: Use `strrep()` to replace occurrences of a substring in a string.

---

## **11. Statistical Functions**

### 11.1 Basic Statistics

```matlab
mean_value = mean(numbers);
median_value = median(numbers);
std_value = std(numbers);
```

**Explanation**: Use `mean()`, `median()`, and `std()` to calculate basic statistical measures.

### 11.2 T-tests

```matlab
[h, p] = ttest(numbers);
```

**Explanation**: Use `ttest()` to perform a t-test on a vector of data.

---

## **12. Working with Dates**

### 12.1 Date Operations

```matlab
today = datetime('now');                % Get current date and time
formatted_date = datestr(today, 'dd-mmm-yyyy'); % Format date
```

**Explanation**: Use `datetime()` to get the current date and time, and `datestr()` to format it.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in MATLAB. Regular practice with these concepts will help you become proficient in MATLAB programming.
