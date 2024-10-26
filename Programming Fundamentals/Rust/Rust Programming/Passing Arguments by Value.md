In Rust, you can pass arguments to a function by value. When you pass a value by value, the function receives a copy of the original value, and any changes made to the parameter within the function do not affect the original value in the calling code.

Here's an example of passing arguments by value:

```rust
// Define a function that takes an 'i32' argument by value
fn double(x: i32) -> i32 {
    x * 2
}

fn main() {
    let number = 5;

    // Call the 'double' function and pass 'number' by value
    let doubled = double(number);

    println!("Original number: {}", number);
    println!("Doubled number: {}", doubled);
}
```

In this example, the `double` function takes an `i32` argument `x` by value. When you call the function and pass `number` by value, a copy of `number` is made, and the function doubles that copy. The original `number` variable remains unchanged in the calling code.

Passing arguments by value is useful when you want to work with a copy of the data without affecting the original. However, keep in mind that passing large data structures by value can be inefficient in terms of memory usage and performance. In such cases, you might prefer to pass values by reference using references or borrowing to avoid unnecessary copying.
