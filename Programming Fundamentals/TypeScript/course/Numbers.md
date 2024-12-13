### TypeScript - Numbers

In TypeScript, numbers are a fundamental data type that represent numeric values. TypeScript builds on JavaScript's number system, which supports both integer and floating-point numbers. TypeScript provides a set of features for working with numbers, including type annotations, arithmetic operations, and built-in methods.

---

### 1. **Declaring Numbers**

TypeScript infers the type of a variable as `number` when a numeric value is assigned, or you can explicitly annotate the type.

#### Example: Number Type Declaration

```typescript
let age: number = 30;   // Explicit annotation
let height = 5.9;       // TypeScript infers number type
```

In this example:
- `age` is explicitly declared as a `number`.
- `height` is inferred as a `number` because it is assigned a floating-point value.

---

### 2. **Integer and Floating-Point Numbers**

TypeScript uses the same number type to represent both integers and floating-point numbers (decimals). The type is just `number` for both, unlike some other languages that differentiate between `int` and `float`.

#### Example: Integer and Floating-Point Numbers

```typescript
let integer: number = 42;         // Integer
let float: number = 3.14;         // Floating-point number
let negative: number = -100.5;    // Negative floating-point number
```

Here:
- `integer` stores an integer.
- `float` stores a floating-point number.
- `negative` stores a negative floating-point number.

---

### 3. **Arithmetic Operations with Numbers**

You can perform basic arithmetic operations such as addition, subtraction, multiplication, and division with numbers in TypeScript.

#### Example: Arithmetic Operations

```typescript
let a: number = 10;
let b: number = 5;

let sum = a + b;          // 15
let difference = a - b;   // 5
let product = a * b;      // 50
let quotient = a / b;     // 2
let remainder = a % b;    // 0
```

In this example:
- `sum` is the result of adding `a` and `b`.
- `difference` is the result of subtracting `b` from `a`.
- `product` is the result of multiplying `a` and `b`.
- `quotient` is the result of dividing `a` by `b`.
- `remainder` is the remainder of dividing `a` by `b`.

---

### 4. **Number Methods and Properties**

TypeScript supports the built-in `Number` object and its methods for working with numbers. These methods are inherited from JavaScript.

#### Example: Number Methods

```typescript
let num: number = 123.456;

let rounded = Math.round(num);         // 123, rounds to nearest integer
let floor = Math.floor(num);           // 123, rounds down to nearest integer
let ceil = Math.ceil(num);             // 124, rounds up to nearest integer
let power = Math.pow(2, 3);            // 8, calculates 2 raised to the power of 3
let abs = Math.abs(-50);               // 50, returns the absolute value
let random = Math.random();            // Generates a random number between 0 and 1
```

In this example:
- `Math.round()` rounds a number to the nearest integer.
- `Math.floor()` rounds a number down to the nearest integer.
- `Math.ceil()` rounds a number up to the nearest integer.
- `Math.pow()` calculates a number raised to a power.
- `Math.abs()` returns the absolute value of a number.
- `Math.random()` generates a random number between 0 and 1.

---

### 5. **Special Numbers in JavaScript and TypeScript**

JavaScript and TypeScript support special numeric values such as `NaN`, `Infinity`, and `-Infinity`.

#### Example: Special Numbers

```typescript
let notANumber: number = NaN;         // NaN (Not a Number)
let positiveInfinity: number = Infinity;   // Infinity
let negativeInfinity: number = -Infinity; // -Infinity

console.log(notANumber);        // NaN
console.log(positiveInfinity);  // Infinity
console.log(negativeInfinity);  // -Infinity
```

- `NaN` represents a value that is "Not a Number", often the result of an invalid mathematical operation (e.g., `0 / 0`).
- `Infinity` represents positive infinity, which results from operations like division by zero (e.g., `1 / 0`).
- `-Infinity` represents negative infinity.

---

### 6. **BigInt (For Larger Integers)**

In addition to the `number` type, TypeScript (in line with JavaScript) also supports the `BigInt` type, which is designed to represent very large integers that exceed the range of the `number` type.

#### Example: BigInt

```typescript
let largeNumber: BigInt = 1234567890123456789012345678901234567890n;
let anotherBigInt: BigInt = BigInt(123456789012345678901234567890);

console.log(largeNumber);        // 1234567890123456789012345678901234567890n
console.log(anotherBigInt);      // 123456789012345678901234567890n
```

- You can create `BigInt` by appending `n` to a number literal or by calling `BigInt()` constructor.
- `BigInt` is particularly useful when working with very large integers (e.g., in financial applications, cryptography, or scientific computing).

---

### 7. **TypeScript Type Assertion with Numbers**

TypeScript allows type assertion to override the inferred type. If you know that a value is a number, but TypeScript doesn’t infer it correctly, you can use a type assertion.

#### Example: Type Assertion

```typescript
let someValue: any = 42;
let numValue: number = <number>someValue;  // Type assertion using the angle-bracket syntax
let anotherNumValue: number = someValue as number; // Type assertion using `as`
```

Both methods assert that `someValue` is a `number`, and TypeScript treats it as such.

---

### 8. **Number Parsing and Conversion**

In TypeScript, you can parse strings into numbers or convert numbers to strings using built-in methods.

#### Example: Parsing and Converting Numbers

```typescript
let str: string = "123.45";
let parsedInt: number = parseInt(str);     // Converts to integer, 123
let parsedFloat: number = parseFloat(str); // Converts to float, 123.45

let num: number = 100;
let numToString: string = num.toString();  // Converts number to string, "100"
```

- `parseInt()` parses a string and returns an integer.
- `parseFloat()` parses a string and returns a floating-point number.
- `toString()` converts a number to its string representation.

---

### 9. **Number Limits and Precision**

The `number` type in JavaScript (and TypeScript) is based on IEEE 754 double-precision floating-point format, which can handle numbers ranging from approximately `-1.8 × 10^308` to `1.8 × 10^308`. However, it has limited precision (about 15-16 digits).

#### Example: Precision Issues

```typescript
let largeNumber: number = 123456789123456789;
console.log(largeNumber); // 123456789123456780 (lost precision)
```

In this case, the number exceeds the precision limit, so the value is rounded.

---

### Conclusion

In TypeScript, numbers are handled in the same way as in JavaScript, with the `number` type being used for both integers and floating-point numbers. TypeScript provides strong support for arithmetic operations, built-in methods for number manipulation, and special values such as `NaN` and `Infinity`. Additionally, for extremely large integers, you can use the `BigInt` type. Despite TypeScript's powerful number handling, it’s important to be mindful of precision limitations when working with very large or very small numbers.
