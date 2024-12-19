In Scala, the **`break`** statement is used to exit from a loop prematurely, i.e., to break out of a loop before it has finished all its iterations. Unlike many other programming languages, Scala does not have a built-in `break` statement directly available in its syntax. However, it can be used through the `scala.util.control.Breaks` object, which provides the `break` method for controlling the flow of loops.

### Using `break` in Scala:
To use the `break` statement in Scala, you need to import `scala.util.control.Breaks._` and use the `breakable` block along with `break`.

### Syntax:
```scala
import scala.util.control.Breaks._

breakable {
  // Code that may call break
}
```

Inside the `breakable` block, you can call the `break` function to exit the loop.

### Example 1: Basic `break` Example
```scala
import scala.util.control.Breaks._

for (i <- 1 to 10) {
  if (i == 5) {
    break  // Exit the loop when i equals 5
  }
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
- The `break` statement causes the loop to exit as soon as `i` equals 5, so numbers `1` to `4` are printed, and the loop stops.

### Example 2: `break` with `while` Loop
```scala
import scala.util.control.Breaks._

var i = 1
breakable {
  while (i <= 10) {
    if (i == 6) {
      break  // Exit the loop when i equals 6
    }
    println(i)
    i += 1
  }
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
- The `break` statement exits the `while` loop when `i` equals 6, so only the numbers `1` to `5` are printed.

### Example 3: Nested Loops with `break`
```scala
import scala.util.control.Breaks._

breakable {
  for (i <- 1 to 5) {
    for (j <- 1 to 5) {
      if (i == 3 && j == 3) {
        break  // Exit the outer loop when i=3 and j=3
      }
      println(s"i = $i, j = $j")
    }
  }
}
```
**Output:**
```
i = 1, j = 1
i = 1, j = 2
i = 1, j = 3
i = 1, j = 4
i = 1, j = 5
i = 2, j = 1
i = 2, j = 2
i = 2, j = 3
i = 2, j = 4
i = 2, j = 5
```
- The `break` statement stops the outer loop when `i = 3` and `j = 3`. Since `break` breaks out of the nearest enclosing `breakable` block, the inner loop stops execution, but the outer loop is also terminated.

### Notes:
- The **`break`** statement can only be used inside a `breakable` block. Without the `breakable` block, calling `break` will result in a compile-time error.
- The `break` works in both **`for`** and **`while`** loops.
- If multiple nested loops are present, `break` will exit only from the loop in the nearest `breakable` block.

### Key Points:
- **Import `scala.util.control.Breaks._`** to use the `break` function.
- Use `breakable` blocks to wrap code where you may need to break out of loops.
- The `break` statement will exit from the loop that it is invoked in and immediately stops further iterations.
- `break` can be used to terminate **for** and **while** loops early, making it a powerful tool for controlling loop flow in situations where a condition is met and further iterations are unnecessary.

### Conclusion:
The **`break`** statement in Scala provides a way to exit loops early. Though Scala does not have a built-in `break` keyword like some other languages, the `scala.util.control.Breaks` object allows us to simulate this behavior in a controlled manner using `breakable` blocks. This can be useful in scenarios where you need to stop the loop immediately based on certain conditions.
