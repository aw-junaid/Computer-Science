### Scala - Pattern Matching

**Pattern matching** is one of the most powerful features in Scala. It allows you to match on the structure of data, making it a versatile tool for handling complex types, conditionally executing code, and destructuring data in a clean and concise manner.

In Scala, **pattern matching** is used with `match` expressions, similar to `switch` statements in other languages, but more powerful and flexible. It works with various types like `Option`, `List`, `Tuple`, `Case classes`, and more.

### Basic Syntax

The general syntax for pattern matching in Scala is as follows:

```scala
value match {
  case pattern1 => expression1
  case pattern2 => expression2
  case patternN => expressionN
}
```

- **`value`**: The value you're trying to match.
- **`case pattern => expression`**: Each `case` defines a pattern to match, and the expression gets executed if the pattern matches.

### Example: Basic Pattern Matching

```scala
val number = 3

number match {
  case 1 => println("One")
  case 2 => println("Two")
  case 3 => println("Three")
  case _ => println("Other")  // Wildcard case, matches anything else
}
```

In this example:
- If `number` is 3, it matches the third case and prints "Three".
- If it doesn't match any of the other cases, it will match the wildcard `_` case and print "Other".

### Wildcard (`_`)

The wildcard pattern `_` is used to match anything, essentially acting as a catch-all for any unmatched case. 

```scala
val fruit = "Apple"

fruit match {
  case "Banana" => println("Banana")
  case "Apple" => println("Apple")
  case _ => println("Other fruit")
}
```

This would print `"Apple"` because `fruit` matches the string `"Apple"`.

### Matching on Literal Values

You can match on literal values:

```scala
val x = 5

x match {
  case 1 => println("It's one!")
  case 5 => println("It's five!")
  case 10 => println("It's ten!")
  case _ => println("It's something else!")
}
```

### Matching with Variables

You can also match on variables, where you capture the value and bind it to a variable:

```scala
val x = 10

x match {
  case 1 => println("One")
  case v => println(s"Matched with value: $v")  // Binds the value to v
}
```

In this example, `v` will capture the value of `x` (which is 10), and the output will be: `"Matched with value: 10"`.

### Matching on Types (Type Patterns)

You can match based on the type of the value:

```scala
val obj: Any = "Hello"

obj match {
  case s: String => println(s"String: $s")
  case i: Int => println(s"Int: $i")
  case _ => println("Other type")
}
```

In this example, if `obj` is a `String`, it will match and print `"String: Hello"`. If it's an `Int`, it would print `"Int: ..."`.

### Matching with Case Classes

Case classes are often used with pattern matching in Scala because they automatically have a `unapply` method, which makes it easy to deconstruct them.

```scala
case class Person(name: String, age: Int)

val person = Person("Alice", 30)

person match {
  case Person("Alice", 30) => println("Matched Alice, 30")
  case Person(name, age) => println(s"Matched person: $name, $age")
  case _ => println("No match")
}
```

In this example, the first case checks if the `Person` has the name `"Alice"` and age `30`. The second case uses variables `name` and `age` to match any other `Person` and extract their properties.

### Matching Lists

You can also pattern match on lists to access elements and check their structure.

```scala
val numbers = List(1, 2, 3)

numbers match {
  case Nil => println("Empty list")
  case x :: xs => println(s"Head: $x, Tail: $xs")
}
```

In this example:
- `Nil` represents an empty list.
- `x :: xs` is a pattern that matches a non-empty list, where `x` is the first element (head) and `xs` is the remainder of the list (tail).

### Matching Tuples

You can also pattern match on tuples:

```scala
val tuple = (1, "Scala")

tuple match {
  case (1, "Scala") => println("It's a tuple with 1 and Scala!")
  case (x, y) => println(s"Tuple with values: $x and $y")
}
```

### Guard Conditions (if conditions)

You can use **guards** in your pattern matching to add additional conditions for a case to match:

```scala
val x = 20

x match {
  case n if n < 10 => println("Less than 10")
  case n if n >= 10 && n < 20 => println("Between 10 and 20")
  case n if n >= 20 => println("Greater than or equal to 20")
}
```

In this example, the guard `if n < 10` ensures that the first case only matches if `n` is less than 10.

### Matching with Option

Pattern matching is frequently used with `Option` to handle cases where a value may be present or absent.

```scala
val someValue: Option[Int] = Some(42)

someValue match {
  case Some(x) => println(s"Found value: $x")
  case None => println("No value found")
}
```

Here, `Some(x)` matches if the `Option` contains a value, and `None` matches if the `Option` is empty.

### Matching on Sealed Traits

One of the most powerful uses of pattern matching is with **sealed traits** (or sealed abstract classes). Sealing a class restricts its inheritance to the same file, ensuring that the pattern matching is exhaustive.

```scala
sealed trait Shape
case class Circle(radius: Double) extends Shape
case class Rectangle(width: Double, height: Double) extends Shape
case class Square(side: Double) extends Shape

val shape: Shape = Circle(5.0)

shape match {
  case Circle(radius) => println(s"Circle with radius: $radius")
  case Rectangle(width, height) => println(s"Rectangle with width: $width and height: $height")
  case Square(side) => println(s"Square with side: $side")
}
```

In this example, the `Shape` trait is sealed, so Scala can ensure that all the possible subclasses of `Shape` are accounted for in the pattern match.

### Conclusion

- **Pattern Matching** in Scala is a powerful feature that allows you to destructure, decompose, and match complex data structures in a concise and readable way.
- It can be used on primitive values, case classes, collections, types, and more.
- **Guards** can be used to add conditions to a match.
- **Sealed traits** allow for exhaustive pattern matching, ensuring that all cases are covered.
- **`Option`** and other types like **List** and **Tuple** work seamlessly with pattern matching, making it a versatile tool in Scala programming.
