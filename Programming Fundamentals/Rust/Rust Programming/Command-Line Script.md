Create a simple command-line script in Rust. In this example, we'll create a program that takes two integer arguments from the command line, adds them, and then prints the result.

Here's how you can do it:

1. Create a new Rust project using Cargo:

```bash
cargo new command_line_script
cd command_line_script
```

2. Open the `src/main.rs` file in a text editor.

3. Replace the contents of `src/main.rs` with the following code:

```rust
use std::env;

fn main() {
    // Get command-line arguments
    let args: Vec<String> = env::args().collect();

    // Check if there are enough arguments
    if args.len() < 3 {
        println!("Usage: {} <num1> <num2>", args[0]);
        return;
    }

    // Parse the arguments as integers
    let num1: i32 = args[1].parse().expect("Invalid number");
    let num2: i32 = args[2].parse().expect("Invalid number");

    // Perform addition
    let result = num1 + num2;

    // Print the result
    println!("{} + {} = {}", num1, num2, result);
}
```

4. Save the file.

5. Run the script using Cargo:

```bash
cargo run 5 7
```

Replace `5` and `7` with any two integer values you'd like to add.

This script uses the `env::args()` function to access the command-line arguments. It checks if there are enough arguments and then parses them as integers. If the parsing is successful, it performs the addition and prints the result. If there are not enough arguments or if the parsing fails, it provides a usage message or an error message accordingly.

You can customize this script or build upon it to create more complex command-line tools. The power of Rust's standard library and ecosystem can help you create robust and efficient command-line applications.
