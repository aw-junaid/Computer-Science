### TypeScript - `switch...case` Statement

The `switch...case` statement in TypeScript (and JavaScript) is an alternative to multiple `if...else` statements when you need to evaluate one expression against a series of possible values. It makes your code more readable and can simplify situations where there are many conditional branches.

### **Syntax of `switch...case` Statement**

```typescript
switch (expression) {
  case value1:
    // Block of code executed if expression === value1
    break;
  case value2:
    // Block of code executed if expression === value2
    break;
  case value3:
    // Block of code executed if expression === value3
    break;
  default:
    // Block of code executed if no cases match
}
```

- **expression**: This is the value you want to evaluate (it can be a number, string, or other types).
- **case valueN**: Compares the expression to `valueN`. If the expression matches, the code block for that `case` is executed.
- **break**: Terminates the switch statement and prevents the execution of subsequent cases.
- **default**: An optional block of code that executes if none of the `case` values match the expression.

### **Example 1: Basic `switch...case` Statement**

```typescript
let day: string = "Monday";

switch (day) {
  case "Monday":
    console.log("It's Monday.");
    break;
  case "Tuesday":
    console.log("It's Tuesday.");
    break;
  case "Wednesday":
    console.log("It's Wednesday.");
    break;
  default:
    console.log("It's another day.");
}
```

- Here:
  - The `switch` statement evaluates the variable `day`.
  - If `day` is `"Monday"`, it prints "It's Monday".
  - If none of the `case` values match, the `default` block is executed, printing "It's another day".

### **Example 2: `switch...case` with Numbers**

You can also use numeric values in the `switch...case` statement.

```typescript
let score: number = 85;

switch (score) {
  case 90:
    console.log("You got an A!");
    break;
  case 80:
    console.log("You got a B!");
    break;
  case 70:
    console.log("You got a C.");
    break;
  default:
    console.log("Grade not recognized.");
}
```

- Here:
  - The `switch` statement checks the value of `score` and matches it against the `case` values.
  - If no case matches, it prints `"Grade not recognized."`.

### **Example 3: `switch...case` with Strings**

You can use strings in the `switch...case` statement for string comparison.

```typescript
let fruit: string = "apple";

switch (fruit) {
  case "apple":
    console.log("It's an apple.");
    break;
  case "banana":
    console.log("It's a banana.");
    break;
  case "cherry":
    console.log("It's a cherry.");
    break;
  default:
    console.log("Unknown fruit.");
}
```

- Here:
  - The expression is the string `"apple"`, and the `switch` statement matches it to the corresponding case.
  - If `fruit` is `"apple"`, the message `"It's an apple."` is printed.

### **Example 4: `switch...case` without `break` (Fall-through)**

If you omit the `break` statement, the code will "fall through" to the next case, executing multiple blocks for matching cases.

```typescript
let score: number = 85;

switch (score) {
  case 90:
  case 80:
    console.log("You got a B or A.");
    break;
  case 70:
    console.log("You got a C.");
    break;
  default:
    console.log("Grade not recognized.");
}
```

- In this case:
  - Both the `case 90` and `case 80` will lead to the same block of code because there is no `break` after the first case.
  - The message `"You got a B or A."` will be printed if the score is 90 or 80.

### **Example 5: `switch...case` with Complex Expressions (Using `default`)**

The `default` case is useful when you want to handle situations where none of the `case` values match the expression.

```typescript
let month: number = 4;

switch (month) {
  case 1:
    console.log("January");
    break;
  case 2:
    console.log("February");
    break;
  case 3:
    console.log("March");
    break;
  case 4:
    console.log("April");
    break;
  default:
    console.log("Invalid month.");
}
```

- In this case:
  - If the month is 1, 2, 3, or 4, the corresponding month name will be printed.
  - If the month is any value other than 1-4, `"Invalid month."` is printed.

### **Example 6: `switch...case` with Multiple Conditions in One `case`**

You can group multiple `case` labels together if they should execute the same block of code.

```typescript
let fruit: string = "apple";

switch (fruit) {
  case "apple":
  case "banana":
    console.log("It's a fruit.");
    break;
  case "carrot":
    console.log("It's a vegetable.");
    break;
  default:
    console.log("Unknown food.");
}
```

- In this example:
  - Both `"apple"` and `"banana"` cases will print `"It's a fruit."` because there is no `break` statement between them.
  - `"carrot"` will print `"It's a vegetable."`, and if the value doesn't match any of these, the `default` case prints `"Unknown food."`.

### **Key Points to Remember**

1. **Expression Evaluation**: The expression in a `switch` statement is evaluated once, and its value is compared against each `case` value. The first matching `case` will execute its block of code.
  
2. **Fall-through Behavior**: If you omit the `break` statement in a `case`, the code will "fall through" and execute the next case, which can be useful for grouping cases.

3. **Default Case**: The `default` case is optional and executes if no `case` matches the expression. It’s a good practice to include it to handle unexpected values.

4. **Strict Equality**: The `switch...case` statement uses strict equality (`===`), meaning that both the value and type must match for a case to be executed.

5. **No Type Coercion**: Unlike `if...else`, `switch...case` does not perform type coercion. For instance, `1 === '1'` will evaluate to `false`, so a number `1` will not match a string `'1'`.

---

### **Summary**

The `switch...case` statement in TypeScript provides an efficient way to compare a variable to multiple possible values. It simplifies complex `if...else` chains and makes the code more readable, especially when there are many possible conditions. It’s ideal when you need to check a single expression against multiple possible outcomes, such as matching days of the week, grades, or types of items.
