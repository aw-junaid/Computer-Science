### TypeScript - Access Modifiers

In TypeScript, **access modifiers** control the visibility of class members (properties and methods). These modifiers allow you to specify whether a property or method can be accessed from outside the class, or if it is restricted to the class or subclass itself.

The three main **access modifiers** in TypeScript are:

1. **public**
2. **private**
3. **protected**

Each modifier provides different levels of access to the class members.

---

### **1. Public Modifier**

The `public` modifier is the **default** in TypeScript. Properties and methods marked as `public` can be accessed from anywhere: inside the class, outside the class, and in subclasses.

#### **Syntax:**

```typescript
class ClassName {
  public property: type;

  public method(): returnType {
    // method body
  }
}
```

#### **Example 1: Public Modifier**

```typescript
class Person {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public greet(): void {
    console.log(`Hello, my name is ${this.name}`);
  }
}

let person = new Person("Alice");
console.log(person.name);  // Accessible: Output: Alice
person.greet();            // Accessible: Output: Hello, my name is Alice
```

- **Explanation**:
  - Both the `name` property and the `greet` method are public, meaning they can be accessed from outside the `Person` class.

---

### **2. Private Modifier**

The `private` modifier restricts access to a class member to **only within the class**. It cannot be accessed from outside the class, nor can it be accessed from subclasses.

#### **Syntax:**

```typescript
class ClassName {
  private property: type;

  private method(): returnType {
    // method body
  }
}
```

#### **Example 2: Private Modifier**

```typescript
class Employee {
  private id: number;

  constructor(id: number) {
    this.id = id;
  }

  public showId(): void {
    console.log(`Employee ID: ${this.id}`);
  }
}

let emp = new Employee(101);
console.log(emp.id);      // Error: Property 'id' is private and only accessible within class 'Employee'.
emp.showId();            // Output: Employee ID: 101
```

- **Explanation**:
  - The `id` property is private, so it cannot be accessed from outside the class.
  - The `showId()` method is public, so it can access the private `id` property within the class and output it.

---

### **3. Protected Modifier**

The `protected` modifier is similar to `private`, but it allows access to the class members from **within the class** and **in subclasses**. However, it still prevents access from outside the class.

#### **Syntax:**

```typescript
class ClassName {
  protected property: type;

  protected method(): returnType {
    // method body
  }
}
```

#### **Example 3: Protected Modifier**

```typescript
class Animal {
  protected name: string;

  constructor(name: string) {
    this.name = name;
  }

  public introduce(): void {
    console.log(`I am a ${this.name}`);
  }
}

class Dog extends Animal {
  public bark(): void {
    console.log(`${this.name} barks!`);
  }
}

let dog = new Dog("Golden Retriever");
dog.bark();                // Output: Golden Retriever barks!
console.log(dog.name);     // Error: Property 'name' is protected and only accessible within class 'Animal' and its subclasses.
```

- **Explanation**:
  - The `name` property is `protected`, so it is not accessible from outside the `Animal` class.
  - However, it is accessible from the `Dog` class because `Dog` extends `Animal`.

---

### **4. Access Modifiers in Constructors**

You can use access modifiers directly in the constructor parameters to define the visibility of class members without manually declaring them inside the class body.

#### **Example 4: Using Access Modifiers in Constructors**

```typescript
class Product {
  constructor(public name: string, private price: number) {}

  public showDetails(): void {
    console.log(`Product: ${this.name}, Price: $${this.price}`);
  }
}

let product = new Product("Laptop", 1200);
console.log(product.name);  // Accessible: Output: Laptop
// console.log(product.price);  // Error: Property 'price' is private and only accessible within class 'Product'.
product.showDetails();      // Output: Product: Laptop, Price: $1200
```

- **Explanation**:
  - The `name` parameter is marked as `public`, so it is automatically created as a public property.
  - The `price` parameter is marked as `private`, so it is automatically created as a private property, restricting access to it from outside the class.

---

### **5. Readonly Modifier**

In addition to `public`, `private`, and `protected`, TypeScript also supports the `readonly` modifier, which makes properties immutable after their initial assignment, whether they are `public`, `private`, or `protected`.

#### **Example 5: Readonly Modifier**

```typescript
class Vehicle {
  readonly brand: string;

  constructor(brand: string) {
    this.brand = brand;
  }
}

let vehicle = new Vehicle("Tesla");
console.log(vehicle.brand);  // Output: Tesla
vehicle.brand = "BMW";       // Error: Cannot assign to 'brand' because it is a read-only property.
```

- **Explanation**:
  - The `brand` property is marked as `readonly`, meaning it can only be assigned a value once (in the constructor). Any further attempts to modify the property will result in an error.

---

### **6. Summary of Access Modifiers**

| Modifier   | Access Level                                            | Description                                               |
|------------|---------------------------------------------------------|-----------------------------------------------------------|
| `public`   | Accessible anywhere (inside the class, outside, and in subclasses) | Default modifier. No restrictions.                       |
| `private`  | Accessible only inside the class                        | Restricts access to the class itself.                      |
| `protected`| Accessible inside the class and in subclasses           | Restricts access to the class and its subclasses.         |
| `readonly` | Property can be assigned only once (during initialization) | Makes a property immutable after its initial assignment.   |

---

### **Example: Class with All Modifiers**

```typescript
class Account {
  public accountNumber: string;
  private balance: number;
  protected accountHolderName: string;

  constructor(accountNumber: string, balance: number, accountHolderName: string) {
    this.accountNumber = accountNumber;
    this.balance = balance;
    this.accountHolderName = accountHolderName;
  }

  public deposit(amount: number): void {
    this.balance += amount;
    console.log(`Deposited ${amount}. New balance is ${this.balance}`);
  }

  private updateBalance(amount: number): void {
    this.balance += amount;
  }

  protected displayAccountHolder(): void {
    console.log(`Account holder: ${this.accountHolderName}`);
  }
}

class SavingsAccount extends Account {
  constructor(accountNumber: string, balance: number, accountHolderName: string) {
    super(accountNumber, balance, accountHolderName);
  }

  public showDetails(): void {
    this.displayAccountHolder();  // Accessible: from the subclass
    console.log(`Account number: ${this.accountNumber}`);
  }
}

const account = new SavingsAccount("123456", 5000, "John Doe");
account.deposit(1000);         // Output: Deposited 1000. New balance is 6000
account.showDetails();         // Output: Account holder: John Doe, Account number: 123456
// console.log(account.balance);  // Error: Property 'balance' is private and only accessible within class 'Account'.
// account.displayAccountHolder(); // Error: Property 'displayAccountHolder' is protected and only accessible within class 'Account' and its subclasses.
```

- **Explanation**:
  - `accountNumber` is `public`, so it can be accessed from anywhere.
  - `balance` is `private`, so it is only accessible within the `Account` class.
  - `accountHolderName` is `protected`, so it is accessible within the `Account` class and `SavingsAccount` subclass.

---

### **Conclusion**

- **Access modifiers** in TypeScript help you control the visibility and accessibility of class members, promoting better encapsulation and organization of your code.
- **Public** members can be accessed anywhere.
- **Private** members are restricted to the class itself.
- **Protected** members are accessible within the class and its subclasses.
- **Readonly** properties ensure immutability after initialization.

By leveraging these modifiers, you can create more secure and maintainable TypeScript classes.
