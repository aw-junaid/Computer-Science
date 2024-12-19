In Scala, **loop statements** are used to execute a block of code repeatedly based on certain conditions. There are several types of loop statements available, including **`for`**, **`while`**, and **`do-while`**. Each loop type serves a specific purpose and offers different ways to iterate over a block of code.

### 1. **For Loop**
The `for` loop is one of the most commonly used loop constructs in Scala. It allows you to iterate over ranges, collections, or other iterable objects.

#### Basic `for` Loop Syntax:
```scala
for (i <- start to end) {
  // Code to execute for each iteration
}
```
- The `start to end` generates a **range** of values, and the loop iterates through each of these values.
- The `i <- start to end` syntax means that `i` will take on the values from `start` to `end` (inclusive).

#### Example:
```scala
for (i <- 1 to 5) {
  println(i)
}
```
**Output:**
```
1
2
3
4
5
```

#### For Loop with `until` (Exclusive Range):
The `until` method generates a **range** from `start` to `end - 1`, meaning the range is exclusive of the `end` value.

```scala
for (i <- 1 until 5) {
  println(i)
}
```
**Output:**
```
1
2
3
4
```

### 2. **For Loop with Collections**
You can use `for` loops to iterate over **collections** such as arrays, lists, sets, and maps.

#### Example with a List:
```scala
val list = List(10, 20, 30, 40, 50)
for (item <- list) {
  println(item)
}
```
**Output:**
```
10
20
30
40
50
```

#### Example with a Map:
```scala
val map = Map("a" -> 1, "b" -> 2, "c" -> 3)
for ((key, value) <- map) {
  println(s"$key -> $value")
}
```
**Output:**
```
a -> 1
b -> 2
c -> 3
```

### 3. **For Loop with Guards (Conditional Statements)**
You can include **guards** (conditions) within a `for` loop to filter values. Guards are placed after the iteration expression.

#### Example:
```scala
for (i <- 1 to 10 if i % 2 == 0) {
  println(i)
}
```
**Output:**
```
2
4
6
8
10
```

In this case, only even numbers from 1 to 10 are printed, because the guard `if i % 2 == 0` filters the results.

### 4. **For Loop with Yield**
The `yield` keyword in a `for` loop allows you to create a **new collection** from the results of the loop. It collects the output of each iteration into a new collection, such as a list, set, or map.

#### Example:
```scala
val numbers = List(1, 2, 3, 4, 5)
val doubledNumbers = for (num <- numbers) yield num * 2
println(doubledNumbers)  // Output: List(2, 4, 6, 8, 10)
```

In this case, `yield` creates a new list where each number is doubled.

### 5. **While Loop**
The `while` loop repeatedly executes a block of code as long as a condition evaluates to `true`. It is useful when you don't know how many times you need to loop in advance.

#### Syntax:
```scala
while (condition) {
  // Code to execute as long as the condition is true
}
```

#### Example:
```scala
var i = 1
while (i <= 5) {
  println(i)
  i += 1
}
```
**Output:**
```
1
2
3
4
5
```

In this example, the loop continues executing until the condition `i <= 5` becomes `false`.

### 6. **Do-While Loop**
The `do-while` loop is similar to the `while` loop, but with a key difference: the condition is checked **after** the block of code is executed. This ensures that the block of code is executed **at least once**.

#### Syntax:
```scala
do {
  // Code to execute
} while (condition)
```

#### Example:
```scala
var i = 1
do {
  println(i)
  i += 1
} while (i <= 5)
```
**Output:**
```
1
2
3
4
5
```

Here, the block of code inside the `do` block is executed first, and the condition is checked afterward to determine if the loop continues.

### 7. **Break and Continue Statements**
In Scala, `break` and `continue` are not directly available in loops like they are in other languages (e.g., C or Java). However, you can use a workaround with the `breakable` and `continue` methods from the `scala.util.control.Breaks` package.

#### Example of `break`:
```scala
import scala.util.control.Breaks._

var i = 1
breakable {
  for (i <- 1 to 10) {
    if (i == 5) {
      break  // Exit the loop when i is 5
    }
    println(i)
  }
}
```
**Output:**
```
1
2
3
4
```

In this example, the `break` exits the loop when `i` reaches 5.

#### Example of `continue`:
```scala
import scala.util.control.Breaks._

for (i <- 1 to 10) {
  if (i == 5) {
    // skip this iteration
    println("Skipping 5")
    // Continue to next iteration
  } else {
    println(i)
  }
}
```
**Output:**
```
1
2
3
4
Skipping 5
6
7
8
9
10
```

### Summary of Loop Types:

| **Loop Type**    | **Use Case**                                                     | **Example**                                           |
|------------------|-------------------------------------------------------------------|-------------------------------------------------------|
| `for`            | Iterating over a range or collection                              | `for (i <- 1 to 5) { println(i) }`                    |
| `while`          | Repeating code until a condition becomes false                    | `while (i <= 5) { println(i); i += 1 }`               |
| `do-while`       | Similar to `while`, but executes the block at least once          | `do { println(i); i += 1 } while (i <= 5)`            |
| `for with yield` | Creating a new collection based on the loop's result              | `val doubled = for (x <- nums) yield x * 2`           |
| `break`/`continue`| Used for controlling the flow inside loops (via `scala.util.control.Breaks`) | `breakable { for (i <- 1 to 10) { if (i == 5) break } }` |

### Conclusion:
Loop statements in Scala provide flexible ways to handle repetition of code based on conditions. `for` loops are ideal for iterating over ranges and collections, while `while` and `do-while` loops are great for situations where you need to repeat a block of code as long as a condition is true. `break` and `continue` provide additional control over loop execution. Understanding these loops and when to use each type is crucial for efficient Scala programming.
