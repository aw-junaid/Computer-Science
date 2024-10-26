Input/Output (I/O) and error handling are crucial aspects of programming that Rust handles in a safe and efficient manner. Rust's standard library provides modules and functions for performing I/O operations and managing errors.

**Input/Output (I/O)**:

Rust's I/O operations are facilitated through the `std::io` module. You can use this module to read from and write to various I/O sources, such as the standard input/output, files, and more.

```rust
use std::io;

fn main() {
    // Reading from standard input
    let mut input = String::new();
    println!("Enter your name:");
    io::stdin().read_line(&mut input).expect("Failed to read line");
    println!("Hello, {}", input.trim());

    // Writing to standard output
    println!("This is a message written to stdout.");
}
```

In this example, we read a line of input from the user using `io::stdin().read_line()` and write a message to the standard output using `println!`.

**Error Handling**:

Rust encourages robust error handling through its `Result` and `Option` enums. Functions that can potentially encounter errors return a `Result` or `Option` type to indicate the success or failure of the operation.

```rust
use std::fs::File;

fn main() {
    let file_result = File::open("example.txt");
    
    match file_result {
        Ok(file) => {
            println!("File opened successfully.");
            // Process the file
        },
        Err(error) => {
            eprintln!("Error opening file: {}", error);
            // Handle the error
        }
    }
}
```

In this example, `File::open("example.txt")` returns a `Result<File, io::Error>`. We use a `match` expression to handle the result and either print a success message or handle the error.

**The `?` Operator**:

Rust provides the `?` operator, also known as the "try" operator, for concise error handling. It can be used within functions that return a `Result` to propagate errors automatically.

```rust
use std::fs::File;
use std::io::Read;

fn read_file() -> Result<String, io::Error> {
    let mut file = File::open("example.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    Ok(contents)
}

fn main() {
    match read_file() {
        Ok(contents) => println!("File contents: {}", contents),
        Err(error) => eprintln!("Error reading file: {}", error),
    }
}
```

In this example, the `read_file` function reads the contents of a file into a `String`. The `?` operator is used to automatically handle errors, simplifying the error handling code.

Rust's approach to I/O and error handling promotes safe and reliable code while minimizing the risk of runtime errors and unexpected behavior.
