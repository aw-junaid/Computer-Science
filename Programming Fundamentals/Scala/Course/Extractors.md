### Scala - Extractors

**Extractors** in Scala are a powerful and essential feature for pattern matching, particularly when you need to extract values from objects during a match. They are the key to making Scala’s pattern matching even more flexible and powerful, and they allow you to "extract" information from complex objects.

An extractor is an object with a method `unapply`. The `unapply` method is used to extract the components of an object and is what allows pattern matching to deconstruct the object.

### Basic Syntax of Extractor

```scala
object MyExtractor {
  def unapply(value: Any): Option[(T1, T2)] = {
    // Logic to extract the components from the value
    // Return Some(tuple) if successful or None if no match
  }
}
```

- **`unapply`**: The method that performs the extraction. It typically returns an `Option` containing the extracted value(s), or `None` if there is no match.
  - If the object matches, `unapply` returns `Some(value)` where `value` can be a tuple or other extracted values.
  - If there is no match, `unapply` returns `None`.
  
### Example of Extractor

Let’s create an extractor to match a simple case class `Person` and extract the fields:

```scala
case class Person(name: String, age: Int)

object PersonExtractor {
  def unapply(person: Person): Option[(String, Int)] = {
    if (person.age >= 18) Some(person.name, person.age) // Match adults only
    else None
  }
}
```

- **`unapply`**: In this extractor, if the `Person` is an adult (age >= 18), the `unapply` method will return `Some(name, age)`. Otherwise, it returns `None`.

Now, you can use the extractor in a pattern match:

```scala
val person = Person("Alice", 30)

person match {
  case PersonExtractor(name, age) => println(s"Adult: $name, $age")
  case _ => println("Not an adult")
}
```

This will output:

```
Adult: Alice, 30
```

### Extractors with Multiple Parameters

You can use extractors with multiple parameters. For example, if you want to extract the components of a `Rectangle` object:

```scala
case class Rectangle(width: Int, height: Int)

object RectangleExtractor {
  def unapply(rect: Rectangle): Option[(Int, Int)] = Some(rect.width, rect.height)
}

val rect = Rectangle(5, 10)

rect match {
  case RectangleExtractor(width, height) => println(s"Width: $width, Height: $height")
  case _ => println("Not a rectangle")
}
```

This would print:

```
Width: 5, Height: 10
```

### Extractors with Guards

You can add **guards** (additional conditions) to an extractor to match only under specific conditions:

```scala
object PositiveExtractor {
  def unapply(value: Int): Option[Int] = {
    if (value > 0) Some(value)
    else None
  }
}

val number = 10

number match {
  case PositiveExtractor(n) => println(s"Positive number: $n")
  case _ => println("Non-positive number")
}
```

This will output:

```
Positive number: 10
```

If you were to match a negative number, it would fall through to the second case and print `"Non-positive number"`.

### Extractors with Complex Logic

Extractors can contain more complex logic. For example, let’s create an extractor that matches strings containing both letters and digits:

```scala
object AlphaNumericExtractor {
  def unapply(s: String): Option[(String, String)] = {
    val letters = s.filter(_.isLetter)
    val digits = s.filter(_.isDigit)
    if (letters.nonEmpty && digits.nonEmpty) Some(letters, digits)
    else None
  }
}

val str = "abc123"

str match {
  case AlphaNumericExtractor(letters, digits) => 
    println(s"Letters: $letters, Digits: $digits")
  case _ => println("Not alphanumeric")
}
```

This would print:

```
Letters: abc, Digits: 123
```

### Extractors and Case Classes

In Scala, case classes automatically come with an extractor for pattern matching. For example, consider this case class:

```scala
case class Point(x: Int, y: Int)

val point = Point(10, 20)

point match {
  case Point(x, y) => println(s"Point at ($x, $y)")
  case _ => println("Not a Point")
}
```

This will output:

```
Point at (10, 20)
```

The `Point` case class has an automatic extractor, which is equivalent to:

```scala
object Point {
  def unapply(p: Point): Option[(Int, Int)] = Some((p.x, p.y))
}
```

### Custom Extractor Example with `Option`

You can also use extractors with `Option` types to safely extract values:

```scala
object SafeExtractor {
  def unapply(value: Option[Int]): Option[Int] = value match {
    case Some(v) if v > 10 => Some(v)
    case _ => None
  }
}

val someValue: Option[Int] = Some(20)

someValue match {
  case SafeExtractor(v) => println(s"Value greater than 10: $v")
  case None => println("Value is not present or too small")
}
```

This will print:

```
Value greater than 10: 20
```

### Extractors as Functions

Sometimes extractors can be used as functions to simplify code. For example, you can use an extractor in a for-comprehension:

```scala
object EvenExtractor {
  def unapply(x: Int): Boolean = x % 2 == 0
}

val numbers = List(1, 2, 3, 4, 5)

val evenNumbers = for {
  EvenExtractor(n) <- numbers
} yield n

println(evenNumbers)  // Output: List(2, 4)
```

In this example, the extractor `EvenExtractor` is used to match even numbers within the list.

### Summary of Extractors
1. **Extractors** are objects with an `unapply` method that help in pattern matching by extracting values from objects.
2. **`unapply`**: The method that does the extraction. It returns `Some(value)` if the match is successful, or `None` if it is not.
3. **Case classes** automatically provide extractors.
4. **Guards** can be used with extractors to add additional conditions.
5. **Extractors** can be used for complex matching and deconstruction, even allowing for logic beyond simple matching.

By using extractors, you can perform powerful pattern matching and data extraction, which is often used in scenarios like parsing, validation, or matching data structures.
