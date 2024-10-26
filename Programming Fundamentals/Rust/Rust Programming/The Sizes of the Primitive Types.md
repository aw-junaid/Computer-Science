The sizes of primitive types in Rust are platform-dependent and can vary based on the architecture (32-bit or 64-bit) and the specific compiler being used. However, Rust provides a `std::mem::size_of` function that you can use to determine the size of a type in bytes.

Here are the typical sizes of some primitive types on a 64-bit system:

- `i8`: 1 byte
- `u8`: 1 byte
- `i16`: 2 bytes
- `u16`: 2 bytes
- `i32`: 4 bytes
- `u32`: 4 bytes
- `i64`: 8 bytes
- `u64`: 8 bytes
- `i128`: 16 bytes
- `u128`: 16 bytes
- `isize`: 8 bytes (64-bit systems)
- `usize`: 8 bytes (64-bit systems)
- `f32`: 4 bytes
- `f64`: 8 bytes
- `char`: 4 bytes (Unicode scalar value)

Please note that these sizes are not guaranteed to be the same on all systems and compilers. It's always recommended to use `std::mem::size_of` to obtain the size of a type programmatically.

```rust
fn main() {
    println!("Size of i32: {} bytes", std::mem::size_of::<i32>());
}
```

Keep in mind that Rust's type system ensures that the sizes and representations of types are consistent across platforms, making it easier to write cross-platform code without worrying about low-level details.
