### TypeScript - Variables

In TypeScript, variables can be declared using the same syntax as JavaScript, but with additional type annotations to enhance type safety and improve code clarity. TypeScript introduces three ways to declare variables: `let`, `const`, and `var`. However, it adds the ability to explicitly specify the types of variables, making it more powerful than JavaScript.

Here’s a breakdown of how variables are declared and used in TypeScript:

---

### 1. **`let` Keyword**
The `let` keyword is used to declare variables that can be reassigned later in the code.

- **Syntax**:
    ```typescript
    let variableName: type = value;
    ```

- **Example**:
    ```typescript
    let name: string = "John";
    let age: number = 25;
    let isActive: boolean = true;

    // Reassignable
    name = "Alice";  // Valid reassignment
    age = 30;        // Valid reassignment
    ```

- **Key Points**:
    - TypeScript infers the type based on the initial value if no type is specified.
    - Can be reassigned (mutable).

---

### 2. **`const` Keyword**
The `const` keyword is used to declare variables that cannot be reassigned after their initial value is set.

- **Syntax**:
    ```typescript
    const variableName: type = value;
    ```

- **Example**:
    ```typescript
    const pi: number = 3.14;
    const isFinished: boolean = false;

    // Cannot be reassigned
    // pi = 3.14159;  // Error: Cannot assign to 'pi' because it is a constant.
    ```

- **Key Points**:
    - The value assigned to a `const` variable is **immutable**, but if it is an object or array, the contents can still be modified.
    - The type can be inferred or explicitly declared.

---

### 3. **`var` Keyword (Deprecated)**
The `var` keyword is the older way of declaring variables in JavaScript and is still supported in TypeScript for compatibility. However, it has some issues that make it less recommended for modern TypeScript development.

- **Issues with `var`**:
    - `var` has **function scope**, not block scope like `let` and `const`, which can cause unexpected behaviors.
    - It allows redeclarations within the same scope, which can lead to errors in larger codebases.

- **Example**:
    ```typescript
    var message: string = "Hello!";
    var message: string = "World!";  // Valid, but not recommended.
    ```

- **Recommendation**:
    - Use `let` or `const` instead of `var` in modern TypeScript code for better scoping and error prevention.

---

### 4. **Type Annotations**
Type annotations allow you to explicitly define the type of a variable, which can be beneficial for type safety. TypeScript will raise an error if the assigned value does not match the specified type.

- **Basic Type Annotations**:
    ```typescript
    let name: string = "John";
    let age: number = 25;
    let isActive: boolean = true;
    ```

- **Array Types**:
    You can specify that a variable is an array of a particular type by using the following syntax:
    ```typescript
    let numbers: number[] = [1, 2, 3, 4];
    let names: string[] = ["Alice", "Bob", "Charlie"];
    ```

    Or you can use the generic `Array` type:
    ```typescript
    let numbers: Array<number> = [1, 2, 3, 4];
    ```

- **Object Types**:
    You can define an object type using either inline type annotations or interfaces.
    ```typescript
    let person: { name: string, age: number } = { name: "John", age: 25 };
    ```

---

### 5. **Type Inference**
TypeScript is capable of **type inference**, meaning it can automatically deduce the type of a variable based on its assigned value without needing explicit type annotations.

- **Example**:
    ```typescript
    let name = "Alice";  // TypeScript infers the type as string
    let age = 30;        // TypeScript infers the type as number
    ```

- **Key Points**:
    - TypeScript will infer the type based on the initial value if no type is explicitly declared.
    - It’s still a good practice to use type annotations when possible, especially in complex codebases.

---

### 6. **Union Types**
A variable can hold multiple types of values by using **union types**. Union types are declared using the pipe (`|`) symbol.

- **Example**:
    ```typescript
    let value: string | number;
    value = "Hello";  // Valid
    value = 42;       // Valid
    // value = true;  // Error: Type 'boolean' is not assignable to type 'string | number'
    ```

- **Key Points**:
    - Union types are useful when a variable can hold multiple types but not just any type.

---

### 7. **Nullable Types**
By default, variables in TypeScript cannot be `null` or `undefined` unless explicitly declared as such.

- **Example**:
    ```typescript
    let name: string | null = null;  // Valid
    let age: number | undefined = undefined;  // Valid
    ```

- **Key Points**:
    - TypeScript has stricter rules about `null` and `undefined` compared to JavaScript.
    - You must explicitly allow `null` or `undefined` in a type annotation to use them.

---

### 8. **Readonly Variables**
TypeScript allows you to mark variables as `readonly`, which means they cannot be reassigned after their initial value is set.

- **Example**:
    ```typescript
    readonly numberArray: number[] = [1, 2, 3];
    numberArray = [4, 5, 6];  // Error: Index signature in type 'readonly number[]' only permits reading
    ```

- **Key Points**:
    - `readonly` ensures immutability for arrays and objects.
    - Useful for situations where you want to guarantee that a variable’s value cannot change after initialization.

---

### 9. **Destructuring with Type Annotations**
TypeScript allows you to use **destructuring** to extract values from arrays or objects, and you can add type annotations during the destructuring process.

- **Array Destructuring**:
    ```typescript
    let numbers: number[] = [10, 20, 30];
    let [first, second]: [number, number] = numbers;
    ```

- **Object Destructuring**:
    ```typescript
    let person = { name: "Alice", age: 30 };
    let { name, age }: { name: string, age: number } = person;
    ```

---

### Summary of Variable Declaration

| Declaration | Syntax                        | Key Characteristics              | Example                         |
|-------------|-------------------------------|----------------------------------|---------------------------------|
| **`let`**   | `let variableName: type`       | Mutable, block-scoped            | `let age: number = 30;`         |
| **`const`** | `const variableName: type`     | Immutable, block-scoped          | `const pi: number = 3.14;`      |
| **`var`**   | `var variableName: type`       | Function-scoped (avoid using)    | `var x: number = 10;`           |

---

### Conclusion
TypeScript provides a rich set of features for working with variables. The ability to define types explicitly, use type inference, and ensure better handling of nullable values and complex types (like arrays, objects, and union types) greatly enhances code safety and maintainability. Using `let` and `const` is recommended over `var`, as they offer better scoping and prevent common pitfalls.
