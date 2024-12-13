### TypeScript - Nested `if` Statements

In TypeScript, **nested `if` statements** refer to placing one `if` statement inside another. This is useful when you need to evaluate multiple conditions that depend on each other. 

### **Syntax of Nested `if` Statements**

A nested `if` statement occurs when one `if` statement is placed inside the block of another `if` statement.

```typescript
if (condition1) {
  // Block of code executed if condition1 is true
  if (condition2) {
    // Block of code executed if condition2 is true
  }
}
```

- **condition1** is the first condition checked.
- **condition2** is the second condition checked, but only if **condition1** is true.

### **Example 1: Basic Nested `if` Statement**

```typescript
let age: number = 20;
let hasID: boolean = true;

if (age >= 18) {
  if (hasID) {
    console.log("You are allowed entry.");
  } else {
    console.log("You need an ID to enter.");
  }
} else {
  console.log("You are too young to enter.");
}
```

- In this example:
  - First, it checks if the `age` is greater than or equal to 18.
  - If the person is an adult, it checks if they have an ID.
  - If they have an ID, it allows entry; if not, it asks for an ID.
  - If the person is under 18, it denies entry.

### **Example 2: Multiple Nested `if` Statements**

You can nest `if` statements more than one level deep to check multiple conditions.

```typescript
let score: number = 85;
let passed: boolean = true;

if (score >= 60) {
  if (passed) {
    console.log("You passed the exam with a score of " + score);
  } else {
    console.log("You failed the exam, but you can retake it.");
  }
} else {
  console.log("You need to score at least 60 to pass.");
}
```

- In this example:
  - First, the program checks if the score is 60 or more.
  - If the score is enough, it checks if the student passed or failed.
  - If the student did not pass, a message is displayed for a retake.
  - If the score is below 60, it prints a message indicating the requirement to pass.

### **Example 3: Using Nested `if` with Logical Operators**

You can use logical operators (`&&`, `||`) inside nested `if` statements to combine conditions.

```typescript
let age: number = 25;
let hasTicket: boolean = true;
let isVIP: boolean = false;

if (age >= 18) {
  if (hasTicket && !isVIP) {
    console.log("You can enter the event.");
  } else if (isVIP) {
    console.log("Welcome, VIP! You have special access.");
  } else {
    console.log("You need a ticket to enter.");
  }
} else {
  console.log("You are too young to enter.");
}
```

- Here:
  - The first `if` checks if the person is at least 18 years old.
  - If they are, the second `if` checks if they have a ticket but are not VIP.
  - If they are VIP, a special message is shown.
  - If they have no ticket, an error message is shown.
  - If they are under 18, entry is denied.

### **Example 4: Nested `if` Statements for Validation**

Nested `if` statements are useful when validating multiple conditions that depend on each other.

```typescript
let username: string = "admin";
let password: string = "12345";

if (username === "admin") {
  if (password === "12345") {
    console.log("Login successful.");
  } else {
    console.log("Incorrect password.");
  }
} else {
  console.log("Username does not exist.");
}
```

- Here:
  - First, it checks if the `username` is `"admin"`.
  - If true, it checks if the `password` is correct.
  - If the username is not `"admin"`, a "Username does not exist" message is printed.

### **Example 5: Nested `if` with a `else` Block**

You can also have a `else` block at the outer or inner levels of nested `if` statements.

```typescript
let age: number = 25;
let hasJob: boolean = false;
let hasCollegeDegree: boolean = true;

if (age >= 18) {
  if (hasJob) {
    console.log("You are employed.");
  } else if (hasCollegeDegree) {
    console.log("You are unemployed but have a degree.");
  } else {
    console.log("You are unemployed and do not have a degree.");
  }
} else {
  console.log("You are not old enough to work.");
}
```

- In this example:
  - The first `if` checks if the person is an adult.
  - Inside, it checks whether they have a job or a degree, and responds accordingly.
  - If neither condition is met, it assumes they are unemployed without a degree.
  - If they are under 18, a message is printed saying they are too young to work.

### **Example 6: Complex Nested `if` Conditions**

You can nest more than two levels of `if` statements for more complex scenarios.

```typescript
let age: number = 40;
let healthStatus: string = "good";
let country: string = "USA";

if (age >= 18) {
  if (healthStatus === "good") {
    if (country === "USA") {
      console.log("You are eligible for the program.");
    } else {
      console.log("This program is available only in the USA.");
    }
  } else {
    console.log("You are not eligible due to health concerns.");
  }
} else {
  console.log("You are too young for this program.");
}
```

- Here:
  - The first check is for age.
  - If the person is old enough, it checks if their health status is `"good"`.
  - If both conditions are true, it checks if they live in the `"USA"`, allowing eligibility for a program.
  - If the health status or country does not meet the conditions, a different message is shown.

### **Best Practices for Using Nested `if` Statements**

1. **Keep Code Readable**: While nesting `if` statements is sometimes necessary, too many levels of nesting can make code difficult to read. Try to simplify conditions or refactor the code into functions if it becomes too complex.

2. **Limit Nesting Depth**: Avoid excessive nesting. If you have too many nested `if` statements, consider using logical operators or breaking the logic into smaller, reusable functions.

3. **Use `else if` When Possible**: Instead of nesting `if` statements inside each other, you can often simplify by using `else if` for related conditions.

4. **Break Complex Conditions Into Smaller Pieces**: If a condition becomes complex, break it into smaller, meaningful checks that are easier to follow.

---

### **Summary**

- **Nested `if` statements** allow for more detailed and conditional branching in your code. They are useful when checking multiple conditions that depend on each other.
- You can nest as many `if` statements as needed, but avoid excessive nesting to maintain readability.
- Use **`else if`** for simpler alternatives to deeply nested `if` statements when conditions are related.
