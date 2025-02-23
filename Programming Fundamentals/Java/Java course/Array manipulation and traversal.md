Array manipulation and traversal are essential skills in Java programming. They involve accessing, modifying, and iterating over array elements to perform various operations. Let’s explore these concepts in detail.

---

### **1. Array Traversal**
Traversal refers to accessing each element of an array sequentially. There are several ways to traverse an array in Java:

#### **a. Using a `for` Loop**
```java
int[] numbers = {10, 20, 30, 40, 50};

for (int i = 0; i < numbers.length; i++) {
    System.out.println(numbers[i]);
}
```
**Output**:
```
10
20
30
40
50
```

#### **b. Using an Enhanced `for` Loop (for-each Loop)**
```java
for (int num : numbers) {
    System.out.println(num);
}
```
**Output**:
```
10
20
30
40
50
```

#### **c. Using a `while` Loop**
```java
int i = 0;
while (i < numbers.length) {
    System.out.println(numbers[i]);
    i++;
}
```
**Output**:
```
10
20
30
40
50
```

---

### **2. Array Manipulation**
Array manipulation involves modifying array elements or performing operations on them. Here are some common operations:

#### **a. Updating Array Elements**
```java
int[] numbers = {10, 20, 30, 40, 50};
numbers[2] = 35; // Update the third element

for (int num : numbers) {
    System.out.println(num);
}
```
**Output**:
```
10
20
35
40
50
```

#### **b. Finding the Sum of Array Elements**
```java
int sum = 0;
for (int num : numbers) {
    sum += num;
}
System.out.println("Sum: " + sum);
```
**Output**:
```
Sum: 155
```

#### **c. Finding the Maximum and Minimum Values**
```java
int max = numbers[0];
int min = numbers[0];

for (int num : numbers) {
    if (num > max) {
        max = num;
    }
    if (num < min) {
        min = num;
    }
}
System.out.println("Max: " + max);
System.out.println("Min: " + min);
```
**Output**:
```
Max: 50
Min: 10
```

#### **d. Reversing an Array**
```java
int[] reversed = new int[numbers.length];
for (int i = 0; i < numbers.length; i++) {
    reversed[i] = numbers[numbers.length - 1 - i];
}

for (int num : reversed) {
    System.out.println(num);
}
```
**Output**:
```
50
40
30
20
10
```

---

### **3. Multi-Dimensional Array Traversal and Manipulation**
For multi-dimensional arrays (e.g., 2D arrays), you can use nested loops to traverse and manipulate elements.

#### **a. Traversing a 2D Array**
```java
int[][] matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        System.out.print(matrix[i][j] + " ");
    }
    System.out.println();
}
```
**Output**:
```
1 2 3
4 5 6
7 8 9
```

#### **b. Updating a 2D Array**
```java
matrix[1][1] = 50; // Update the element at row 2, column 2

for (int[] row : matrix) {
    for (int num : row) {
        System.out.print(num + " ");
    }
    System.out.println();
}
```
**Output**:
```
1 2 3
4 50 6
7 8 9
```

#### **c. Sum of All Elements in a 2D Array**
```java
int sum = 0;
for (int[] row : matrix) {
    for (int num : row) {
        sum += num;
    }
}
System.out.println("Sum: " + sum);
```
**Output**:
```
Sum: 90
```

---

### **4. Common Array Manipulation Techniques**

#### **a. Copying an Array**
Use `System.arraycopy()` or `Arrays.copyOf()`:
```java
int[] source = {1, 2, 3, 4, 5};
int[] destination = new int[5];

// Using System.arraycopy()
System.arraycopy(source, 0, destination, 0, source.length);

// Using Arrays.copyOf()
int[] copy = Arrays.copyOf(source, source.length);
```

#### **b. Sorting an Array**
Use `Arrays.sort()`:
```java
int[] numbers = {5, 3, 1, 4, 2};
Arrays.sort(numbers); // Sorts the array in ascending order

for (int num : numbers) {
    System.out.println(num);
}
```
**Output**:
```
1
2
3
4
5
```

#### **c. Searching an Array**
Use `Arrays.binarySearch()` (only works on sorted arrays):
```java
int index = Arrays.binarySearch(numbers, 3);
System.out.println("Index of 3: " + index);
```
**Output**:
```
Index of 3: 2
```

---

### **5. Example Program**
Here’s a complete example that demonstrates array traversal and manipulation:

```java
public class Main {
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50};

        // Traverse and print array
        System.out.println("Original Array:");
        for (int num : numbers) {
            System.out.println(num);
        }

        // Update an element
        numbers[2] = 35;
        System.out.println("\nUpdated Array:");
        for (int num : numbers) {
            System.out.println(num);
        }

        // Find sum of elements
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.println("\nSum of Elements: " + sum);

        // Reverse the array
        int[] reversed = new int[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            reversed[i] = numbers[numbers.length - 1 - i];
        }
        System.out.println("\nReversed Array:");
        for (int num : reversed) {
            System.out.println(num);
        }
    }
}
```
**Output**:
```
Original Array:
10
20
30
40
50

Updated Array:
10
20
35
40
50

Sum of Elements: 155

Reversed Array:
50
40
35
20
10
```

---

### **Conclusion**
Array traversal and manipulation are fundamental skills in Java programming. By mastering these techniques, you can efficiently work with arrays to solve a wide range of problems. Whether you're updating elements, finding sums, or reversing arrays, these operations are essential for building robust and efficient programs.
