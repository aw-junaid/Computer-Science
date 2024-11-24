### **2D Array (Two-Dimensional Array)**

A **2D array** is an array of arrays, essentially a matrix or a grid. It is a collection of elements arranged in rows and columns. Each element in a 2D array is accessed using two indices: one for the row and one for the column.

### **Representation of a 2D Array**

A 2D array is typically represented as a grid of rows and columns:

```
array[row][column]
```

Where:
- `row` specifies the row number (starting from 0).
- `column` specifies the column number (starting from 0).

---

### **Declaration of a 2D Array**

#### **In C/C++:**

To declare a 2D array, you specify the number of rows and columns as follows:

```cpp
data_type array[row_size][column_size];
```

Example:
```cpp
int matrix[3][3];  // A 2D array with 3 rows and 3 columns
```

You can also initialize the array while declaring it:

```cpp
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
```

---

#### **In Java:**

In Java, a 2D array is a reference to an array of arrays. Here's the syntax:

```java
data_type[][] array_name = new data_type[row_size][column_size];
```

Example:
```java
int[][] matrix = new int[3][3];  // A 2D array with 3 rows and 3 columns
```

You can initialize the 2D array with values at the time of declaration:

```java
int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
```

---

#### **In Python:**

In Python, 2D arrays are typically represented using **lists of lists** (since Python does not have built-in support for arrays in the traditional sense).

```python
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
```

---

### **Accessing Elements in a 2D Array**

To access an element in a 2D array, you use the **row index** and **column index**. For example:

- `array[row][column]`

#### **Example: Accessing Elements**

**C/C++ Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Accessing elements
    cout << "Element at [0][0]: " << matrix[0][0] << endl;  // 1
    cout << "Element at [1][2]: " << matrix[1][2] << endl;  // 6
    cout << "Element at [2][1]: " << matrix[2][1] << endl;  // 8
    
    return 0;
}
```

**Output:**
```
Element at [0][0]: 1
Element at [1][2]: 6
Element at [2][1]: 8
```

**Java Example:**

```java
public class Main {
    public static void main(String[] args) {
        int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        
        // Accessing elements
        System.out.println("Element at [0][0]: " + matrix[0][0]);  // 1
        System.out.println("Element at [1][2]: " + matrix[1][2]);  // 6
        System.out.println("Element at [2][1]: " + matrix[2][1]);  // 8
    }
}
```

**Output:**
```
Element at [0][0]: 1
Element at [1][2]: 6
Element at [2][1]: 8
```

**Python Example:**

```python
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# Accessing elements
print("Element at [0][0]:", matrix[0][0])  # 1
print("Element at [1][2]:", matrix[1][2])  # 6
print("Element at [2][1]:", matrix[2][1])  # 8
```

**Output:**
```
Element at [0][0]: 1
Element at [1][2]: 6
Element at [2][1]: 8
```

---

### **Iterating through a 2D Array**

To traverse a 2D array, you typically use **nested loops**: one loop for rows and one loop for columns.

#### **C/C++ Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Traversing a 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output:**
```
1 2 3 
4 5 6 
7 8 9 
```

#### **Java Example:**

```java
public class Main {
    public static void main(String[] args) {
        int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        
        // Traversing a 2D array
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
```

**Output:**
```
1 2 3 
4 5 6 
7 8 9 
```

#### **Python Example:**

```python
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# Traversing a 2D array
for row in matrix:
    for elem in row:
        print(elem, end=" ")
    print()
```

**Output:**
```
1 2 3 
4 5 6 
7 8 9 
```

---

### **Dynamic 2D Arrays**

In some cases, you may not know the size of the 2D array at compile time, and you may need to allocate it dynamically.

#### **C/C++ Dynamic 2D Array:**

In **C/C++**, you can allocate memory for a 2D array dynamically using **pointers**.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    
    // Dynamically allocate a 2D array (array of pointers)
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Assign values to the 2D array
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    // Display the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
```

---

### **Conclusion**

A **2D array** is a powerful data structure that allows you to store data in rows and columns. Accessing elements requires two indices: one for the row and one for the column. You can iterate over a 2D array using nested loops. It can be declared statically or dynamically, depending on the programming language and the specific use case.
