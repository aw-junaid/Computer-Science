An extended Swift cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes basic syntax, variables, control structures, functions, classes, protocols, error handling, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```swift
import Foundation

print("Hello, World!")
```

**Explanation**: This program uses the `print` function to display "Hello, World!" to the console. The `import Foundation` statement allows you to use functionalities from the Foundation framework.

---

## **2. Variables and Data Types**

### 2.1 Declaring Variables

```swift
var name: String = "Alice"           // Mutable variable
let age: Int = 25                    // Immutable constant
```

**Explanation**: `var` declares a mutable variable, while `let` declares an immutable constant. Swift is a strongly typed language, requiring explicit types or type inference.

### 2.2 Implicitly Typed Variables

```swift
var score = 100                       // Type inferred as Int
```

**Explanation**: Swift can infer the type of a variable from its initial value.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```swift
let number = 10

if number > 0 {
    print("Positive")
} else if number < 0 {
    print("Negative")
} else {
    print("Zero")
}
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Switch Statement

```swift
let fruit = "Apple"

switch fruit {
case "Apple":
    print("It's an apple!")
case "Banana":
    print("It's a banana!")
default:
    print("Unknown fruit")
}
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases.

### 3.3 For Loop

```swift
for i in 1...5 {
    print(i)
}
```

**Explanation**: The `for` loop iterates over a range of values. The `...` operator creates a closed range, including both endpoints.

### 3.4 While Loop

```swift
var count = 5

while count > 0 {
    print(count)
    count -= 1
}
```

**Explanation**: The `while` loop continues to execute as long as its condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```swift
func greet(name: String) {
    print("Hello, \(name)!")
}

// Calling the function
greet(name: "Alice")
```

**Explanation**: Functions are defined using the `func` keyword and can take parameters.

### 4.2 Returning Values

```swift
func add(a: Int, b: Int) -> Int {
    return a + b
}

// Using the function
let sum = add(a: 5, b: 3)
```

**Explanation**: Functions can return values, specified after the parameter list with `->`.

### 4.3 Function Overloading

```swift
func add(a: Int, b: Int) -> Int {
    return a + b
}

func add(a: Double, b: Double) -> Double {
    return a + b
}

// Using overloaded functions
let intSum = add(a: 5, b: 3)
let doubleSum = add(a: 5.5, b: 3.3)
```

**Explanation**: You can define multiple functions with the same name but different parameter types.

---

## **5. Classes and Structures**

### 5.1 Defining a Class

```swift
class Person {
    var name: String
    var age: Int

    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }

    func introduce() {
        print("My name is \(name) and I am \(age) years old.")
    }
}
```

**Explanation**: Classes can contain properties, methods, and an initializer (`init`) to create instances.

### 5.2 Creating an Object

```swift
let person = Person(name: "Alice", age: 25)
person.introduce() // Outputs: My name is Alice and I am 25 years old.
```

**Explanation**: Create an instance of a class using the `init` method.

### 5.3 Structures

```swift
struct Point {
    var x: Int
    var y: Int
}

let point = Point(x: 10, y: 20)
```

**Explanation**: Structures are similar to classes but are value types, meaning they are copied when assigned or passed.

### 5.4 Inheritance

```swift
class Student: Person {
    var major: String

    init(name: String, age: Int, major: String) {
        self.major = major
        super.init(name: name, age: age)
    }
}

// Creating an object of the derived class
let student = Student(name: "Alice", age: 25, major: "Computer Science")
```

**Explanation**: Inheritance allows a class to inherit properties and methods from another class.

---

## **6. Protocols**

### 6.1 Defining a Protocol

```swift
protocol Greetable {
    func greet() -> String
}

class Greeter: Greetable {
    func greet() -> String {
        return "Hello!"
    }
}
```

**Explanation**: Protocols define a blueprint of methods, properties, and other requirements.

### 6.2 Conforming to Protocols

```swift
let greeter = Greeter()
print(greeter.greet()) // Outputs: Hello!
```

**Explanation**: Classes or structs can conform to protocols and implement their requirements.

---

## **7. Optionals**

### 7.1 Declaring Optionals

```swift
var name: String? // Optional String
```

**Explanation**: Optionals allow a variable to hold either a value or `nil`, indicating the absence of a value.

### 7.2 Unwrapping Optionals

```swift
let name: String? = "Alice"

if let unwrappedName = name {
    print("Name is \(unwrappedName)")
} else {
    print("Name is nil")
}
```

**Explanation**: Use optional binding (`if let`) to safely unwrap optionals.

### 7.3 Forced Unwrapping

```swift
let unwrappedName = name! // Use with caution
```

**Explanation**: Forced unwrapping uses `!` to access the value of an optional, but it will crash if the optional is `nil`.

---

## **8. Error Handling**

### 8.1 Throwing Errors

```swift
enum CustomError: Error {
    case divisionByZero
}

func divide(_ a: Int, by b: Int) throws -> Int {
    if b == 0 {
        throw CustomError.divisionByZero
    }
    return a / b
}
```

**Explanation**: Use `throw` to indicate that a function can produce an error.

### 8.2 Handling Errors

```swift
do {
    let result = try divide(10, by: 0)
    print(result)
} catch CustomError.divisionByZero {
    print("Cannot divide by zero.")
} catch {
    print("An error occurred.")
}
```

**Explanation**: Use `do-catch` blocks to handle errors that may be thrown by functions.

---

## **9. Closures**

### 9.1 Defining a Closure

```swift
let greeting = { (name: String) -> String in
    return "Hello, \(name)!"
}

// Calling the closure
print(greeting("Alice")) // Outputs: Hello, Alice!
```

**Explanation**: Closures are self-contained blocks of functionality that can be passed around and used in your code.

### 9.2 Closures as Function Parameters

```swift
func performOperation(_ operation: (Int, Int) -> Int, a: Int, b: Int) {
    let result = operation(a, b)
    print("Result: \(result)")
}

performOperation({ $0 + $1 }, a: 5, b: 3) // Outputs: Result: 8
```

**Explanation**: You can pass closures as arguments to functions.

---

## **10. Collections**

### 10.1 Arrays

```swift
var fruits = ["Apple", "Banana", "Cherry"]
fruits.append("Date")
```

**Explanation**: Arrays are ordered collections of elements that can be mutable or immutable.

### 10.2 Dictionaries

```swift
var ages = ["Alice": 25, "Bob": 30]
ages["Charlie"] = 35 // Add new key-value pair
```

**Explanation**: Dictionaries store key-value pairs, allowing for quick access to values by their keys.

### 10.3 Sets

```swift
var uniqueNumbers: Set = [1, 2, 3, 4, 4, 5]
```

**Explanation**: Sets are unordered collections of unique elements.

---

## **11. Extensions**

### 11.1 Extending Types

```swift
extension Int {
    func squared() -> Int {
        return self * self
    }
}

// Using the extension
let number = 5
print(number.squared()) // Outputs: 25
```

**Explanation**: Extensions allow you to add new functionality to existing types.

---

## **12. Async/Await**

### 12.1 Asynchronous Functions

```swift
import Foundation

func fetchData() async throws -> String {
    //

 Simulate an asynchronous network call
    return "Data fetched"
}

// Using async function
Task {
    do {
        let data = try await fetchData()
        print(data) // Outputs: Data fetched
    } catch {
        print("Error fetching data.")
    }
}
```

**Explanation**: Async/await syntax simplifies working with asynchronous code, allowing for cleaner and more readable code.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in Swift. Regular practice with these concepts will help you become proficient in Swift programming.
