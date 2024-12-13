### TypeScript - Strings

In TypeScript, strings are used to represent textual data. TypeScript builds on JavaScript's `string` type, which supports operations such as concatenation, template literals, and string manipulation methods. Strings in TypeScript are immutable, meaning their values cannot be changed once they are created.

---

### 1. **Declaring Strings**

You can declare strings using either single quotes (`'`), double quotes (`"`), or backticks (`` ` ``) for template literals.

#### Example: String Declarations

```typescript
let singleQuoteString: string = 'Hello, World!';
let doubleQuoteString: string = "TypeScript is great!";
let templateLiteralString: string = `This is a string with ${singleQuoteString}`;
```

- **`singleQuoteString`** and **`doubleQuoteString`** are declared using single and double quotes respectively.
- **`templateLiteralString`** uses backticks to allow embedding expressions inside the string with `${}`.

---

### 2. **String Operations**

TypeScript supports common string operations like concatenation, searching, and splitting, just like in JavaScript.

#### Example: String Operations

```typescript
let str1: string = "Hello";
let str2: string = "World";

let concatenated: string = str1 + " " + str2;   // Concatenation
let upperCaseStr: string = str1.toUpperCase();  // Convert to uppercase
let lowerCaseStr: string = str2.toLowerCase();  // Convert to lowercase
let strLength: number = str1.length;            // Get string length
let includesHello: boolean = str1.includes("Hel"); // Check if substring exists
```

- **Concatenation** is done using the `+` operator.
- **`toUpperCase()`** converts the string to uppercase.
- **`toLowerCase()`** converts the string to lowercase.
- **`length`** gives the number of characters in the string.
- **`includes()`** checks if a substring exists within the string.

---

### 3. **Template Literals (String Interpolation)**

Template literals (using backticks) are a powerful feature in TypeScript that allows for string interpolation, meaning you can embed variables or expressions directly within a string.

#### Example: Template Literals

```typescript
let name: string = "Alice";
let age: number = 30;

let greeting: string = `Hello, my name is ${name} and I am ${age} years old.`;
console.log(greeting);  // "Hello, my name is Alice and I am 30 years old."
```

- Variables or expressions inside `${}` are evaluated and inserted into the string.

Template literals also support multi-line strings without needing escape characters for newlines:

```typescript
let multilineString: string = `This is
a multi-line
string.`;
```

---

### 4. **String Methods**

TypeScript provides many built-in string methods to manipulate strings, just like JavaScript.

#### Example: String Methods

```typescript
let str: string = " TypeScript ";

let trimmed: string = str.trim();           // "TypeScript", removes leading and trailing whitespace
let startsWithT: boolean = str.startsWith(" T");  // true
let endsWithS: boolean = str.endsWith("S ");   // true
let substring: string = str.substring(1, 5); // "ypeS"
```

- **`trim()`** removes whitespace from both ends of the string.
- **`startsWith()`** checks if the string starts with a specified substring.
- **`endsWith()`** checks if the string ends with a specified substring.
- **`substring()`** extracts a substring between two indexes.

---

### 5. **Escape Characters**

You can use escape characters in strings to represent special characters like newlines, tabs, or quotes.

#### Example: Escape Characters

```typescript
let escapedString: string = "This is a \"quoted\" word";
let newLineString: string = "This is a line\nThis is another line";
let tabbedString: string = "This is\tindented";
```

- **`\"`** represents a double quote.
- **`\n`** represents a new line.
- **`\t`** represents a tab character.

---

### 6. **String Indexing and Access**

In TypeScript, you can access individual characters of a string using bracket notation (although this is not recommended for longer strings, as it can be less readable).

#### Example: String Indexing

```typescript
let str: string = "Hello";

let firstChar: string = str[0];   // "H"
let lastChar: string = str[str.length - 1];  // "o"
```

You can access characters using zero-based indexing. However, note that strings are **immutable**, so you cannot change individual characters directly (e.g., `str[0] = "h";` will throw an error).

---

### 7. **String Conversion**

You can convert other data types to strings using `String()` or `toString()` methods.

#### Example: Converting to Strings

```typescript
let num: number = 42;
let bool: boolean = true;

let numStr: string = String(num);  // "42"
let boolStr: string = bool.toString();  // "true"
```

- **`String()`** can convert various types like numbers or booleans into strings.
- **`toString()`** is a method available on most objects in JavaScript and TypeScript to convert them to string representation.

---

### 8. **String Split and Join**

You can split a string into an array of substrings and then join them back into a single string.

#### Example: Split and Join

```typescript
let sentence: string = "TypeScript is amazing";
let words: string[] = sentence.split(" ");  // ["TypeScript", "is", "amazing"]
let joined: string = words.join("-");       // "TypeScript-is-amazing"
```

- **`split()`** breaks a string into an array of substrings based on a delimiter.
- **`join()`** combines elements of an array into a single string, separated by a specified delimiter.

---

### 9. **String Matching and Regular Expressions**

TypeScript provides full support for regular expressions to match patterns within strings.

#### Example: Regular Expressions with Strings

```typescript
let text: string = "The quick brown fox";

let match: boolean = /quick/.test(text);   // true
let replaced: string = text.replace("fox", "dog"); // "The quick brown dog"
```

- **`test()`** checks if the regular expression matches the string.
- **`replace()`** replaces a matched substring with another string.

Regular expressions in TypeScript are the same as in JavaScript, allowing for complex string searching and manipulation.

---

### 10. **String Immutability**

Strings in TypeScript (and JavaScript) are **immutable**, meaning once they are created, their values cannot be changed. Any operation that seems to modify a string will instead return a new string with the changes.

#### Example: Immutability

```typescript
let str: string = "Hello";
str[0] = "h";   // Error: Cannot assign to '0' because it is a read-only property.
```

Instead, you can create a modified string by using string methods like `replace()` or `substring()`.

---

### 11. **TypeScript String Literal Types**

TypeScript allows you to define string literal types, which restrict a variable to a specific string value.

#### Example: String Literal Types

```typescript
let direction: "left" | "right" = "left";  // Only "left" or "right" allowed
```

In this example, `direction` can only be `"left"` or `"right"`. This feature is useful for type safety in cases like function arguments where only a limited set of string values are valid.

---

### Conclusion

Strings in TypeScript are a powerful and flexible type, offering a variety of operations for manipulation, comparison, and formatting. With features like template literals, regular expressions, and methods for string transformation, TypeScript provides all the tools needed to work with text data effectively. Understanding these operations is essential for handling and processing strings in any TypeScript-based application.
