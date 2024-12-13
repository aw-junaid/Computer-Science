### TypeScript - Objects

In TypeScript, **objects** are a fundamental data structure that allows you to group multiple related values together, such as properties and methods. Objects in TypeScript are similar to JavaScript objects but with added type annotations, allowing for better type safety and more structured code.

### **Basic Object Syntax**

You can define an object in TypeScript using curly braces `{}` and specifying its properties.

```typescript
let objectName: { property1: type; property2: type; } = {
  property1: value,
  property2: value
};
```

### **Example 1: Simple Object**

```typescript
let person: { name: string; age: number; } = {
  name: "Alice",
  age: 30
};

console.log(person.name);  // Output: Alice
console.log(person.age);   // Output: 30
```

- **Explanation**:
  - `person` is an object with two properties: `name` (of type `string`) and `age` (of type `number`).
  - The properties must match the defined types, and the object is created with corresponding values.

### **Example 2: Object with Optional Properties**

In TypeScript, you can make properties optional using the `?` operator. This means the property may or may not be present in the object.

```typescript
let employee: { name: string; age: number; position?: string } = {
  name: "Bob",
  age: 25
};

console.log(employee.name);      // Output: Bob
console.log(employee.position);  // Output: undefined (property is optional)
```

- **Explanation**:
  - The `position` property is optional, so it may be left out when creating the object. If omitted, it will be `undefined`.

### **Example 3: Object with Readonly Properties**

TypeScript also supports `readonly` properties, which can be set only once when the object is created and cannot be modified thereafter.

```typescript
let product: { readonly id: number; name: string } = {
  id: 101,
  name: "Laptop"
};

console.log(product.id);   // Output: 101
product.id = 102;         // Error: Cannot assign to 'id' because it is a read-only property.
```

- **Explanation**:
  - The `id` property is marked as `readonly`, so attempting to modify it will result in a compile-time error.

### **Example 4: Using Objects as Types**

In TypeScript, you can define a type for an object and then use it to create variables that must adhere to that structure.

```typescript
type Book = {
  title: string;
  author: string;
  pages: number;
};

let myBook: Book = {
  title: "1984",
  author: "George Orwell",
  pages: 328
};

console.log(myBook.title);   // Output: 1984
console.log(myBook.pages);   // Output: 328
```

- **Explanation**:
  - The `Book` type defines the structure for an object with properties `title`, `author`, and `pages`.
  - The `myBook` object must adhere to the `Book` type.

### **Example 5: Object with Method**

Objects in TypeScript can also contain methods (functions) as properties. Methods can be typed just like properties.

```typescript
let personWithGreeting: { name: string; greet(): void } = {
  name: "John",
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

personWithGreeting.greet();  // Output: Hello, my name is John
```

- **Explanation**:
  - The `greet` method is defined directly in the object, and it accesses the `name` property using `this`.

### **Example 6: Index Signatures**

In TypeScript, you can use **index signatures** to allow an object to have properties with dynamic names (keys) of a specific type.

```typescript
let dictionary: { [key: string]: number } = {
  apple: 1,
  banana: 2,
  cherry: 3
};

console.log(dictionary.apple);  // Output: 1
console.log(dictionary["banana"]);  // Output: 2
```

- **Explanation**:
  - The index signature `{ [key: string]: number }` allows the `dictionary` object to have any string key, with the value being a `number`.
  - The properties `apple`, `banana`, and `cherry` are dynamically created.

### **Example 7: Nested Objects**

TypeScript allows objects to contain other objects, enabling nested structures.

```typescript
let company: { name: string; address: { street: string; city: string } } = {
  name: "TechCorp",
  address: {
    street: "123 Tech Avenue",
    city: "TechCity"
  }
};

console.log(company.address.city);  // Output: TechCity
```

- **Explanation**:
  - The `company` object contains an `address` property, which itself is an object with `street` and `city` properties.
  - Nested objects can be accessed by chaining property names.

### **Example 8: Object Destructuring**

In TypeScript, you can destructure objects to extract values into variables.

```typescript
let person2: { name: string; age: number } = {
  name: "Alice",
  age: 30
};

let { name, age } = person2;
console.log(name);  // Output: Alice
console.log(age);   // Output: 30
```

- **Explanation**:
  - The `{ name, age }` syntax is used to destructure the `person2` object and assign its properties to individual variables.
  - This provides a concise way to access object properties.

### **Example 9: Objects with Type Aliases**

You can use **type aliases** to define the structure of an object. This can be useful when working with complex structures or reusable types.

```typescript
type Person = {
  name: string;
  age: number;
};

let person3: Person = {
  name: "David",
  age: 45
};

console.log(person3.name);  // Output: David
```

- **Explanation**:
  - The `Person` type alias is used to define the structure for the `person3` object.
  - This makes the code more reusable and readable.

### **Example 10: Object as Parameter in Functions**

Objects can be passed as parameters to functions in TypeScript, and you can specify the type of the object for type safety.

```typescript
type Product = {
  name: string;
  price: number;
};

function printProductDetails(product: Product): void {
  console.log(`Product Name: ${product.name}, Price: $${product.price}`);
}

let product1: Product = {
  name: "Smartphone",
  price: 799
};

printProductDetails(product1);  // Output: Product Name: Smartphone, Price: $799
```

- **Explanation**:
  - The `printProductDetails` function takes an object of type `Product` as its argument and prints its details.
  - This ensures that the passed object adheres to the correct structure.

### **Example 11: Merging Objects**

You can combine multiple objects using `Object.assign()` or the spread operator (`...`).

```typescript
let person1 = { name: "Alice", age: 30 };
let job = { position: "Engineer", company: "TechCorp" };

let personDetails = { ...person1, ...job };
console.log(personDetails);
// Output: { name: "Alice", age: 30, position: "Engineer", company: "TechCorp" }
```

- **Explanation**:
  - The spread operator (`...`) is used to merge `person1` and `job` objects into a new object `personDetails`.

### **Summary**

- **Objects** in TypeScript are collections of properties (key-value pairs) that can have any data type.
- You can define the **structure** of objects using type annotations or type aliases to provide better type safety.
- **Access modifiers** like `readonly` and optional properties (`?`) allow for more flexible and controlled object designs.
- TypeScript supports **destructuring**, **index signatures**, and **nested objects** for more complex and dynamic data structures.
- You can pass objects to functions as parameters, and use **spread operators** or `Object.assign()` to merge multiple objects into one.

By leveraging the power of type annotations, TypeScript helps you work with objects in a way that ensures correctness and clarity in your code.
