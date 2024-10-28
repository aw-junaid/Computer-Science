Let's dive into JavaScript basics covering control flow, conditions, and loops:

## Control Flow in JavaScript

Control flow refers to the order in which statements are executed in a program. JavaScript provides various control flow mechanisms:

1. **Conditional Statements:**

   - **`if` Statement:**
     Executes a block of code if a specified condition is true.

     ```javascript
     let num = 10;
     if (num > 0) {
       console.log("Number is positive");
     }
     ```

   - **`if-else` Statement:**
     Executes one block of code if a condition is true and another block if it's false.

     ```javascript
     let num = -5;
     if (num > 0) {
       console.log("Number is positive");
     } else {
       console.log("Number is not positive");
     }
     ```

   - **`else-if` Statement:**
     Allows checking multiple conditions sequentially.

     ```javascript
     let num = 0;
     if (num > 0) {
       console.log("Number is positive");
     } else if (num < 0) {
       console.log("Number is negative");
     } else {
       console.log("Number is zero");
     }
     ```

2. **Switch Statement:**

   Used to select one of many code blocks to be executed.

   ```javascript
   let day = "Monday";
   switch (day) {
     case "Monday":
       console.log("Today is Monday");
       break;
     case "Tuesday":
       console.log("Today is Tuesday");
       break;
     default:
       console.log("Invalid day");
   }
   ```

## Loops in JavaScript

Loops are used to execute a block of code repeatedly. JavaScript provides several types of loops:

1. **`for` Loop:**

   Executes a block of code a specified number of times.

   ```javascript
   for (let i = 0; i < 5; i++) {
     console.log(i);
   }
   ```

2. **`while` Loop:**

   Executes a block of code as long as a specified condition is true.

   ```javascript
   let i = 0;
   while (i < 5) {
     console.log(i);
     i++;
   }
   ```

3. **`do-while` Loop:**

   Similar to `while` loop but ensures the code block is executed at least once, even if the condition is false.

   ```javascript
   let i = 0;
   do {
     console.log(i);
     i++;
   } while (i < 5);
   ```

4. **`for...in` Loop:**

   Iterates over the properties of an object.

   ```javascript
   let person = { name: 'John', age: 30 };
   for (let key in person) {
     console.log(key + ": " + person[key]);
   }
   ```

5. **`for...of` Loop:**

   Iterates over iterable objects like arrays, strings, etc.

   ```javascript
   let fruits = ['apple', 'banana', 'cherry'];
   for (let fruit of fruits) {
     console.log(fruit);
   }
   ```

These control flow structures and loops are fundamental for building logic and executing code based on different conditions or iterating over collections of data.
