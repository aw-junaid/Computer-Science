Arrays in Java are used to store multiple values of the same type in a single variable. They can be categorized into two types:

1. **Single-dimensional arrays**: Arrays with a single row of elements.
2. **Multi-dimensional arrays**: Arrays with multiple rows and columns (e.g., 2D arrays, 3D arrays).

Let’s explore both types in detail.

---

### **1. Single-Dimensional Arrays**
A single-dimensional array is a linear collection of elements stored in a single row.

#### **Declaration**:
```java
dataType[] arrayName; // Preferred
// or
dataType arrayName[];
```

#### **Initialization**:
```java
arrayName = new dataType[size];
```

#### **Declaration and Initialization in One Line**:
```java
dataType[] arrayName = new dataType[size];
```

#### **Example**:
```java
int[] numbers = new int[5]; // Array of size 5
numbers[0] = 10; // Assign value to the first element
numbers[1] = 20; // Assign value to the second element
```

#### **Shortcut Syntax**:
You can declare, initialize, and assign values in one line:
```java
int[] numbers = {10, 20, 30, 40, 50};
```

#### **Accessing Elements**:
Use the index (starting from 0) to access elements:
```java
System.out.println(numbers[0]); // 10
System.out.println(numbers[2]); // 30
```

#### **Iterating Over an Array**:
Use a `for` loop or enhanced `for` loop:
```java
for (int i = 0; i < numbers.length; i++) {
    System.out.println(numbers[i]);
}

// Enhanced for loop
for (int num : numbers) {
    System.out.println(num);
}
```

---

### **2. Multi-Dimensional Arrays**
A multi-dimensional array is an array of arrays. The most common type is a **2D array** (matrix), but Java supports arrays with more dimensions (e.g., 3D, 4D).

#### **Declaration**:
```java
dataType[][] arrayName; // Preferred
// or
dataType arrayName[][];
```

#### **Initialization**:
```java
arrayName = new dataType[rows][columns];
```

#### **Declaration and Initialization in One Line**:
```java
dataType[][] arrayName = new dataType[rows][columns];
```

#### **Example**:
```java
int[][] matrix = new int[3][3]; // 3x3 matrix
matrix[0][0] = 1; // Assign value to the first element
matrix[0][1] = 2; // Assign value to the second element
```

#### **Shortcut Syntax**:
You can declare, initialize, and assign values in one line:
```java
int[][] matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

#### **Accessing Elements**:
Use row and column indices (starting from 0):
```java
System.out.println(matrix[0][0]); // 1
System.out.println(matrix[1][2]); // 6
```

#### **Iterating Over a 2D Array**:
Use nested `for` loops:
```java
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        System.out.print(matrix[i][j] + " ");
    }
    System.out.println();
}
```

---

### **3. Jagged Arrays**
A jagged array is a multi-dimensional array where each row can have a different number of columns.

#### **Example**:
```java
int[][] jaggedArray = new int[3][];
jaggedArray[0] = new int[2]; // First row has 2 columns
jaggedArray[1] = new int[3]; // Second row has 3 columns
jaggedArray[2] = new int[4]; // Third row has 4 columns

// Assign values
jaggedArray[0][0] = 1;
jaggedArray[0][1] = 2;
jaggedArray[1][0] = 3;
jaggedArray[1][1] = 4;
jaggedArray[1][2] = 5;
jaggedArray[2][0] = 6;
jaggedArray[2][1] = 7;
jaggedArray[2][2] = 8;
jaggedArray[2][3] = 9;
```

#### **Iterating Over a Jagged Array**:
```java
for (int i = 0; i < jaggedArray.length; i++) {
    for (int j = 0; j < jaggedArray[i].length; j++) {
        System.out.print(jaggedArray[i][j] + " ");
    }
    System.out.println();
}
```

---

### **4. Common Operations on Arrays**
#### **a. Finding the Length of an Array**:
Use the `length` property:
```java
int[] numbers = {10, 20, 30, 40, 50};
System.out.println(numbers.length); // 5

int[][] matrix = {
    {1, 2, 3},
    {4, 5, 6}
};
System.out.println(matrix.length); // 2 (number of rows)
System.out.println(matrix[0].length); // 3 (number of columns in the first row)
```

#### **b. Copying an Array**:
Use `System.arraycopy()` or `Arrays.copyOf()`:
```java
int[] source = {1, 2, 3, 4, 5};
int[] destination = new int[5];

// Using System.arraycopy()
System.arraycopy(source, 0, destination, 0, source.length);

// Using Arrays.copyOf()
int[] copy = Arrays.copyOf(source, source.length);
```

#### **c. Sorting an Array**:
Use `Arrays.sort()`:
```java
int[] numbers = {5, 3, 1, 4, 2};
Arrays.sort(numbers); // Sorts the array in ascending order
```

---

### **5. Example Programs**

#### **Single-Dimensional Array Example**:
```java
public class Main {
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50};

        // Print all elements
        for (int num : numbers) {
            System.out.println(num);
        }
    }
}
```

#### **2D Array Example**:
```java
public class Main {
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // Print all elements
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
```

---

### **Conclusion**
Arrays are a fundamental data structure in Java, allowing you to store and manipulate collections of data efficiently. Whether you're working with single-dimensional arrays, multi-dimensional arrays, or jagged arrays, understanding their syntax and usage is essential for solving a wide range of programming problems.
