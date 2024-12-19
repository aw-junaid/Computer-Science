In Scala, the **`do-while` loop** is similar to the **`while` loop**, but with a key difference: the condition is checked **after** the loop executes, ensuring that the code inside the loop is always executed **at least once**. This is useful when you want the loop body to run at least once regardless of the condition.

### Syntax of the `do-while` Loop:
```scala
do {
  // Code to execute
} while (condition)
```

- **condition**: An expression that returns a Boolean value (`true` or `false`). After the loop body is executed, the condition is checked. If it's `true`, the loop will execute again. If it's `false`, the loop terminates.

### Key Difference Between `while` and `do-while` Loop:
- In a `while` loop, the condition is evaluated **before** the first iteration, so the body might not execute at all if the condition is `false` initially.
- In a `do-while` loop, the condition is evaluated **after** the first iteration, so the loop body will execute **at least once**, even if the condition is `false`.

### Example 1: Basic `do-while` Loop
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
- The loop executes the body first, printing `i` and incrementing it. After the first execution, the condition `i <= 5` is checked.
- The loop continues as long as `i <= 5`. Once `i` becomes `6`, the condition becomes `false`, and the loop terminates.

### Example 2: Using `do-while` to Ensure At Least One Execution
```scala
var sum = 0
var i = 1
do {
  sum += i
  i += 1
} while (i <= 5)
println(s"The sum of numbers from 1 to 5 is: $sum")
```
**Output:**
```
The sum of numbers from 1 to 5 is: 15
```
- Here, the loop starts with `i = 1`, and the sum is incremented with each iteration. Even if the condition had been `false` initially, the loop would have executed **at least once** before checking the condition.

### Example 3: `do-while` with a False Initial Condition
In this example, the condition is set to `false` initially, but the loop still runs once.

```scala
var i = 10
do {
  println(i)
  i += 1
} while (i < 5)
```
**Output:**
```
10
```
- The loop body runs **once** because the condition `i < 5` is checked after the first execution. Since `i` starts at `10`, the condition is `false`, so the loop terminates after one iteration.

### Example 4: Infinite `do-while` Loop (Controlled by `break`)
You can create an infinite loop with a `do-while` by using a condition that is always `true`. To stop the loop, you can use a `break` statement.

```scala
import scala.util.control.Breaks._

var i = 1
breakable {
  do {
    println(i)
    i += 1
    if (i > 5) break
  } while (true)
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
- The loop continues infinitely until the condition `i > 5` is met, at which point the `break` statement is used to exit the loop.

### Key Points:
- The **`do-while` loop** ensures that the code inside the loop is executed at least once, regardless of the condition.
- The **condition** is checked **after** each execution of the loop body.
- If the condition is `true`, the loop continues; if it's `false`, the loop terminates.
- This loop is useful when you need at least one execution of the loop before evaluating the condition.

### Comparison Between `while` and `do-while`:
| **Loop Type**        | **Condition Check**    | **First Execution**                  | **Use Case**                                                                 |
|----------------------|------------------------|--------------------------------------|-----------------------------------------------------------------------------|
| `while` loop         | Before each iteration  | May not execute if condition is `false` initially | When you want the loop to execute only if the condition is true from the start. |
| `do-while` loop      | After each iteration   | Executes at least once               | When you want the loop to execute at least once, regardless of the condition. |

### Conclusion:
The **`do-while` loop** is useful in scenarios where you want the loop body to execute at least once, such as in menus, input prompts, or cases where an initial operation must happen before any condition is checked. It provides a straightforward way to ensure that the code inside the loop executes before checking the loop condition.
