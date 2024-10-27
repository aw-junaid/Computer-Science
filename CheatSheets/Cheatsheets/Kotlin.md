An extended Kotlin cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes variables, data types, control structures, functions, classes, collections, coroutines, and more.

---

## **Basic Syntax**

### 1. **Hello World Program**

```kotlin
fun main() {
    println("Hello, World!")
}
```

**Explanation**: Every Kotlin program starts with a `main()` function, which is the entry point. The `println()` function is used to display output to the console.

---

## **Variables**

### 2. **Declaring Variables**

```kotlin
var a = 10            // Mutable variable
val b = 20            // Immutable variable (cannot be reassigned)
```

**Explanation**: Use `var` for mutable variables (can be reassigned) and `val` for immutable variables (read-only).

### 3. **Type Inference**

```kotlin
val c: Int = 30       // Explicit type declaration
val d = 40            // Type inferred as Int
```

**Explanation**: Kotlin supports type inference, meaning the compiler can deduce the type based on the assigned value.

---

## **Data Types**

### 4. **Primitive Data Types**

```kotlin
val age: Int = 25               // Integer
val height: Double = 5.9       // Double
val name: String = "Alice"      // String
val isStudent: Boolean = true    // Boolean
```

**Explanation**: Kotlin has several built-in data types, including integers, doubles, strings, and booleans.

### 5. **Nullable Types**

```kotlin
var nullableName: String? = null // Nullable type
```

**Explanation**: Use the `?` operator to declare a variable that can hold a null value. This is part of Kotlin's null safety features.

---

## **Control Structures**

### 6. **If-Else Statement**

```kotlin
if (a > b) {
    println("a is greater than b")
} else if (a < b) {
    println("a is less than b")
} else {
    println("a is equal to b")
}
```

**Explanation**: Kotlin uses `if`, `else if`, and `else` for conditional branching. The `if` statement can also return a value.

### 7. **When Expression**

```kotlin
when (a) {
    1 -> println("One")
    2 -> println("Two")
    else -> println("Other")
}
```

**Explanation**: The `when` expression is a versatile conditional structure that can replace `switch` statements.

### 8. **For Loop**

```kotlin
for (i in 1..5) {
    println(i)
}

for (fruit in fruits) {      // For-each loop
    println(fruit)
}
```

**Explanation**: Use `for` loops to iterate over a range or collection. The `in` keyword is used to define the range.

---

## **Functions**

### 9. **Defining Functions**

```kotlin
fun add(a: Int, b: Int): Int {
    return a + b
}

val result = add(5, 3)         // Calling the function
```

**Explanation**: Functions are defined using the `fun` keyword, and you can specify parameter types and return types.

### 10. **Single Expression Functions**

```kotlin
fun add(a: Int, b: Int) = a + b  // Single-expression function
```

**Explanation**: For simple functions, you can omit the curly braces and return type when the function consists of a single expression.

### 11. **Default Parameters**

```kotlin
fun greet(name: String, greeting: String = "Hello") {
    println("$greeting, $name!")
}

greet("Alice")                  // Outputs: Hello, Alice!
greet("Bob", "Hi")             // Outputs: Hi, Bob!
```

**Explanation**: You can provide default values for parameters, allowing them to be optional.

### 12. **Vararg Parameters**

```kotlin
fun printNumbers(vararg numbers: Int) {
    for (number in numbers) {
        println(number)
    }
}

printNumbers(1, 2, 3, 4)        // Outputs: 1, 2, 3, 4
```

**Explanation**: Use `vararg` to accept a variable number of arguments.

---

## **Classes and Objects**

### 13. **Defining a Class**

```kotlin
class Person(val name: String, var age: Int) { // Primary constructor
    fun greet() {
        println("Hello, my name is $name and I am $age years old.")
    }
}

val person = Person("Alice", 25) // Create an instance
person.greet()                   // Outputs: Hello, my name is Alice and I am 25 years old.
```

**Explanation**: Classes can have properties and methods. You can define a primary constructor directly in the class header.

### 14. **Getters and Setters**

```kotlin
class Rectangle(var width: Double, var height: Double) {
    var area: Double
        get() = width * height  // Getter
        set(value) {
            height = value / width  // Setter
        }
}
```

**Explanation**: You can define custom getters and setters to control access to properties.

---

## **Collections**

### 15. **Using Lists**

```kotlin
val fruits: List<String> = listOf("Apple", "Banana", "Cherry") // Immutable list
val mutableFruits: MutableList<String> = mutableListOf("Apple", "Banana") // Mutable list
mutableFruits.add("Cherry")
```

**Explanation**: Use `listOf()` for immutable lists and `mutableListOf()` for mutable lists.

### 16. **Using Maps**

```kotlin
val scores: Map<String, Int> = mapOf("Alice" to 90, "Bob" to 85) // Immutable map
val mutableScores: MutableMap<String, Int> = mutableMapOf("Alice" to 90) // Mutable map
mutableScores["Bob"] = 85
```

**Explanation**: Maps are collections of key-value pairs, where keys are unique.

### 17. **Using Sets**

```kotlin
val uniqueFruits: Set<String> = setOf("Apple", "Banana", "Apple") // Immutable set
val mutableUniqueFruits: MutableSet<String> = mutableSetOf("Apple", "Banana") // Mutable set
```

**Explanation**: Sets are unordered collections of unique items.

---

## **Lambda Expressions**

### 18. **Using Lambdas**

```kotlin
val square: (Int) -> Int = { x -> x * x }
println(square(5)) // Outputs: 25
```

**Explanation**: Lambda expressions are anonymous functions that can be used as values.

### 19. **Higher-Order Functions**

```kotlin
fun performOperation(operation: (Int, Int) -> Int, a: Int, b: Int): Int {
    return operation(a, b)
}

val sum = performOperation({ x, y -> x + y }, 5, 3) // Passing a lambda
println(sum) // Outputs: 8
```

**Explanation**: Higher-order functions take other functions as parameters or return functions.

---

## **Coroutines**

### 20. **Using Coroutines**

```kotlin
import kotlinx.coroutines.*

fun main() = runBlocking { // Start a coroutine scope
    launch { // Launch a new coroutine
        delay(1000L) // Non-blocking delay for 1 second
        println("World!")
    }
    println("Hello,") // This line will be printed first
}
```

**Explanation**: Coroutines are used for asynchronous programming. The `runBlocking` function blocks the current thread until the coroutine completes.

---

## **Error Handling**

### 21. **Try-Catch**

```kotlin
try {
    val result = riskyFunction() // Function that might throw
} catch (e: Exception) {
    println("Error: ${e.message}")
} finally {
    println("This runs regardless of an error.")
}
```

**Explanation**: Use `try-catch` for exception handling. The `finally` block executes after the try and catch, regardless of an error.

---

## **Extension Functions**

### 22. **Defining Extension Functions**

```kotlin
fun String.removeSpaces(): String {
    return this.replace(" ", "")
}

val result = "Hello World".removeSpaces() // Calls the extension function
println(result) // Outputs: HelloWorld
```

**Explanation**: Extension functions allow you to add new functions to existing classes without modifying their code.

---

## **Data Classes**

### 23. **Using Data Classes**

```kotlin
data class User(val name: String, val age: Int)

val user = User("Alice", 25)
println(user) // Outputs: User(name=Alice, age=25)
```

**Explanation**: Data classes automatically provide `toString()`, `equals()`, and `hashCode()` methods, making them useful for holding data.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in Kotlin. Regular practice with these concepts will help you become proficient in Kotlin programming.
