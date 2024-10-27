An extended Scala cheat sheet covering essential commands, syntax, and concepts. This cheat sheet includes basic syntax, data types, control structures, functions, collections, object-oriented features, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```scala
object HelloWorld {
  def main(args: Array[String]): Unit = {
    println("Hello, World!")
  }
}
```

**Explanation**: This defines an object `HelloWorld` with a `main` method that prints "Hello, World!" to the console.

---

## **2. Data Types**

### 2.1 Basic Types

```scala
val num: Int = 42           // Integer
val str: String = "Hello"   // String
val bool: Boolean = true    // Boolean
```

**Explanation**: Scala has several basic data types, including `Int`, `String`, and `Boolean`.

### 2.2 Type Inference

```scala
val inferredNum = 42       // Type inferred as Int
```

**Explanation**: Scala can automatically infer types, making the code more concise.

### 2.3 Collections

#### 2.3.1 Lists

```scala
val list: List[Int] = List(1, 2, 3, 4)
```

**Explanation**: Lists are immutable sequences.

#### 2.3.2 Arrays

```scala
val array: Array[Int] = Array(1, 2, 3, 4)
```

**Explanation**: Arrays are mutable sequences.

#### 2.3.3 Maps

```scala
val map: Map[String, Int] = Map("Alice" -> 25, "Bob" -> 30)
```

**Explanation**: Maps are collections of key-value pairs.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```scala
val age = 18

if (age >= 18) {
  println("Adult")
} else {
  println("Minor")
}
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Match Statement

```scala
val fruit = "Apple"

fruit match {
  case "Apple" => println("It's an apple!")
  case "Banana" => println("It's a banana!")
  case _ => println("Unknown fruit")
}
```

**Explanation**: The `match` statement is similar to `switch` in other languages, providing pattern matching.

### 3.3 For Loop

```scala
for (i <- 1 to 5) {
  println(i)
}
```

**Explanation**: The `for` loop iterates over a range of values.

### 3.4 While Loop

```scala
var count = 5

while (count > 0) {
  println(count)
  count -= 1
}
```

**Explanation**: The `while` loop continues to execute as long as its condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```scala
def add(a: Int, b: Int): Int = {
  a + b
}

// Calling the function
val sum = add(5, 3)
println(sum)  // Outputs: 8
```

**Explanation**: Functions are defined using the `def` keyword and can specify parameter types and return types.

### 4.2 Default Parameters

```scala
def greet(name: String, greeting: String = "Hello"): String = {
  s"$greeting, $name"
}

println(greet("Alice"))  // Outputs: Hello, Alice
```

**Explanation**: You can set default values for function parameters.

### 4.3 Variable-Length Arguments

```scala
def sumAll(nums: Int*): Int = {
  nums.sum
}

println(sumAll(1, 2, 3, 4))  // Outputs: 10
```

**Explanation**: Use `*` to allow a variable number of arguments.

---

## **5. Object-Oriented Features**

### 5.1 Defining Classes

```scala
class Animal(val name: String) {
  def makeSound(): Unit = {
    println(s"$name makes a sound.")
  }
}

val dog = new Animal("Dog")
dog.makeSound()  // Outputs: Dog makes a sound.
```

**Explanation**: Use the `class` keyword to define a class and `new` to create an instance.

### 5.2 Inheritance

```scala
class Dog(override val name: String) extends Animal(name) {
  override def makeSound(): Unit = {
    println(s"$name barks.")
  }
}

val labrador = new Dog("Labrador")
labrador.makeSound()  // Outputs: Labrador barks.
```

**Explanation**: Use `extends` to inherit from another class and `override` to modify a method.

### 5.3 Case Classes

```scala
case class Person(name: String, age: Int)

val alice = Person("Alice", 25)
println(alice)  // Outputs: Person(Alice,25)
```

**Explanation**: Case classes provide a concise way to define classes with immutable fields, automatic `equals`, `hashCode`, and `toString` methods.

---

## **6. Collections**

### 6.1 Lists

```scala
val fruits = List("Apple", "Banana", "Cherry")

fruits.foreach(println)  // Outputs each fruit
```

**Explanation**: Lists are immutable collections that can be traversed using methods like `foreach`.

### 6.2 Map Operations

```scala
val scores = Map("Alice" -> 90, "Bob" -> 85)

scores.foreach { case (name, score) =>
  println(s"$name scored $score")
}
```

**Explanation**: Maps can be iterated using pattern matching in the `foreach` method.

### 6.3 Filtering Collections

```scala
val evenNumbers = List(1, 2, 3, 4, 5, 6).filter(_ % 2 == 0)
println(evenNumbers)  // Outputs: List(2, 4, 6)
```

**Explanation**: Use `filter` to create a new collection based on a predicate.

---

## **7. Traits and Mixins**

### 7.1 Defining a Trait

```scala
trait Walker {
  def walk(): Unit = {
    println("Walking...")
  }
}

class Human extends Walker {
  def speak(): Unit = {
    println("Hello!")
  }
}

val person = new Human()
person.walk()  // Outputs: Walking...
```

**Explanation**: Traits are like interfaces that can have concrete implementations. Classes can mix in traits.

### 7.2 Mixing Traits

```scala
trait Flyer {
  def fly(): Unit = {
    println("Flying...")
  }
}

class Bird extends Animal("Sparrow") with Flyer

val bird = new Bird
bird.makeSound()  // Outputs: Sparrow makes a sound.
bird.fly()        // Outputs: Flying...
```

**Explanation**: A class can extend one superclass and mix in multiple traits.

---

## **8. Pattern Matching**

### 8.1 Basic Pattern Matching

```scala
val number = 2

number match {
  case 1 => println("One")
  case 2 => println("Two")
  case _ => println("Unknown")
}
```

**Explanation**: Pattern matching can be used to branch logic based on the value of a variable.

### 8.2 Matching on Types

```scala
def process(value: Any): Unit = {
  value match {
    case s: String => println(s"String: $s")
    case i: Int    => println(s"Integer: $i")
    case _         => println("Unknown type")
  }
}

process("Hello")  // Outputs: String: Hello
process(42)       // Outputs: Integer: 42
```

**Explanation**: You can match on types to handle different data types differently.

---

## **9. Implicits**

### 9.1 Implicit Parameters

```scala
implicit val defaultGreeting: String = "Hello"

def greet(implicit greeting: String): Unit = {
  println(greeting)
}

greet  // Outputs: Hello
```

**Explanation**: Implicit parameters are automatically passed to functions if an implicit value is in scope.

### 9.2 Implicit Conversions

```scala
implicit def intToString(i: Int): String = i.toString

val str: String = 42  // Implicitly converts Int to String
println(str)  // Outputs: 42
```

**Explanation**: Implicit conversions allow you to convert one type to another automatically.

---

## **10. File I/O**

### 10.1 Reading from a File

```scala
import scala.io.Source

val filename = "data.txt"
val lines = Source.fromFile(filename).getLines()

for (line <- lines) {
  println(line)
}
```

**Explanation**: Use `scala.io.Source` to read lines from a file.

### 10.2 Writing to a File

```scala
import java.io.PrintWriter

val writer = new PrintWriter("output.txt")
writer.write("Hello, Scala!")
writer.close()
```

**Explanation**: Use `PrintWriter` to write text to a file.

---

## **11. Testing with ScalaTest**

### 11.1 Setting Up ScalaTest

Add ScalaTest to your `build.sbt`:

```sbt
libraryDependencies += "org.scalatest" %% "scalatest" %

 "3.2.10" % Test
```

### 11.2 Writing a Test

```scala
import org.scalatest.flatspec.AnyFlatSpec

class MathSpec extends AnyFlatSpec {
  "A Math function" should "add two numbers" in {
    assert(1 + 1 === 2)
  }
}
```

**Explanation**: ScalaTest is a popular testing framework for writing tests in a readable format.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in Scala. Regular practice with these concepts will help you become proficient in Scala programming.
