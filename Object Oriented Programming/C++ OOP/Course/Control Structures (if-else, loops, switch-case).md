### **Control Structures in C++**

Control structures allow the flow of execution in a program to be directed based on conditions or repeated for loops.

---

### **1. Conditional Statements**

#### **A. if-else**
The `if-else` structure executes a block of code if a specified condition is true; otherwise, it executes another block.

**Syntax**:
```cpp
if (condition) {
    // Code to execute if the condition is true
} else {
    // Code to execute if the condition is false
}
```

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are eligible to vote." << endl;
    } else {
        cout << "You are not eligible to vote." << endl;
    }

    return 0;
}
```

---

#### **B. if-else-if Ladder**
Used when there are multiple conditions to evaluate.

**Syntax**:
```cpp
if (condition1) {
    // Code for condition1
} else if (condition2) {
    // Code for condition2
} else {
    // Code if none of the conditions are true
}
```

**Example**:
```cpp
if (marks >= 90) {
    cout << "Grade: A" << endl;
} else if (marks >= 75) {
    cout << "Grade: B" << endl;
} else if (marks >= 50) {
    cout << "Grade: C" << endl;
} else {
    cout << "Grade: F" << endl;
}
```

---

#### **C. switch-case**
The `switch` statement allows selecting one of many blocks of code to execute.

**Syntax**:
```cpp
switch (variable) {
    case value1:
        // Code for value1
        break;
    case value2:
        // Code for value2
        break;
    default:
        // Code if none of the cases match
}
```

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Enter a number (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You selected One." << endl;
            break;
        case 2:
            cout << "You selected Two." << endl;
            break;
        case 3:
            cout << "You selected Three." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
```

---

### **2. Looping Constructs**

#### **A. for Loop**
Used when the number of iterations is known.

**Syntax**:
```cpp
for (initialization; condition; update) {
    // Code to execute in each iteration
}
```

**Example**:
```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Iteration " << i << endl;
}
```

---

#### **B. while Loop**
Used when the number of iterations is not fixed, but depends on a condition.

**Syntax**:
```cpp
while (condition) {
    // Code to execute as long as the condition is true
}
```

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 1;

    while (count <= 5) {
        cout << "Count: " << count << endl;
        count++;
    }

    return 0;
}
```

---

#### **C. do-while Loop**
Executes the block at least once and then checks the condition.

**Syntax**:
```cpp
do {
    // Code to execute
} while (condition);
```

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int number;

    do {
        cout << "Enter a number (negative to quit): ";
        cin >> number;
    } while (number >= 0);

    cout << "You entered a negative number. Goodbye!" << endl;

    return 0;
}
```

---

### **3. Nested Control Structures**
You can nest `if-else`, loops, or even switch statements.

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        cout << "Outer loop iteration " << i << endl;

        for (int j = 1; j <= 2; j++) {
            cout << "  Inner loop iteration " << j << endl;
        }
    }

    return 0;
}
```

**Output**:
```
Outer loop iteration 1
  Inner loop iteration 1
  Inner loop iteration 2
Outer loop iteration 2
  Inner loop iteration 1
  Inner loop iteration 2
Outer loop iteration 3
  Inner loop iteration 1
  Inner loop iteration 2
```

---

### **4. Example Combining All Control Structures**
```cpp
#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a number (1-5): ";
    cin >> number;

    if (number > 0 && number <= 5) {
        for (int i = 1; i <= number; i++) {
            cout << "Iteration " << i << endl;
        }
    } else {
        switch (number) {
            case 0:
                cout << "You entered zero!" << endl;
                break;
            default:
                cout << "Number out of range!" << endl;
        }
    }

    return 0;
}
```

**Output**:
- If input is `3`:
  ```
  Iteration 1
  Iteration 2
  Iteration 3
  ```

- If input is `0`:
  ```
  You entered zero!
  ```

---

