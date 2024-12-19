Here's an example of a **Makefile** that demonstrates various concepts like variables, rules, dependencies, pattern rules, and more advanced features. The example will focus on a simple project with C source files that are compiled into object files and then linked into an executable.

### Project Structure

Let's assume the following project structure:

```
project/
├── Makefile
├── src/
│   ├── main.c
│   ├── utils.c
├── include/
│   ├── utils.h
└── build/
```

- `main.c` and `utils.c` are the source files.
- `utils.h` is the header file.
- The object files will be created in the `build/` directory.

### Example Makefile

```makefile
# Makefile for a simple C project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Final target executable
TARGET = my_program

# Default target (what is built when 'make' is run)
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to create object files from C source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean target to remove build artifacts
.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Install target (for example purposes)
.PHONY: install
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Debugging: show all variables (useful for understanding Makefile's behavior)
.PHONY: show-vars
show-vars:
	@echo "SRC: $(SRC)"
	@echo "OBJ: $(OBJ)"
	@echo "TARGET: $(TARGET)"
```

### Explanation of the Makefile

1. **Variables**:
   - `CC`: The C compiler (`gcc`).
   - `CFLAGS`: Compiler flags (`-Wall` for all warnings and `-g` for debugging symbols).
   - `SRC_DIR`, `OBJ_DIR`, `INC_DIR`: Directories for source files, object files, and headers.
   - `SRC`: A list of all C source files in the `src/` directory (using `wildcard`).
   - `OBJ`: A list of object files in the `build/` directory. This is created by replacing the `.c` extension with `.o` and changing the directory from `src/` to `build/`.

2. **Default Target (`all`)**:
   - The default target is `all`, which depends on the `$(TARGET)` (the executable). This means that running `make` will build the executable by compiling all object files and linking them together.

3. **Target to Build the Executable**:
   - The target `$(TARGET)` depends on the object files (`$(OBJ)`). The rule specifies that the object files should be linked together using `$(CC)` to create the final executable (`my_program`).

4. **Pattern Rule for Object Files**:
   - This rule tells `make` how to compile `.c` files into `.o` files. It uses a pattern rule where `$(OBJ_DIR)/%.o` corresponds to `$(SRC_DIR)/%.c`. The `$<` is an automatic variable representing the first prerequisite (the `.c` file), and `$@` represents the target (the `.o` file).
   - The `-I$(INC_DIR)` flag tells the compiler to look for header files in the `include/` directory.

5. **Clean Target**:
   - The `clean` target is marked as `.PHONY` (because it doesn't correspond to a file) and removes all object files and the executable. This is useful for cleaning up the project.

6. **Install Target**:
   - The `install` target copies the final executable (`$(TARGET)`) to `/usr/local/bin/` (a typical location for executables). This target is also `.PHONY` because it doesn’t correspond to a file.

7. **Debugging: Show Variables**:
   - The `show-vars` target prints out the values of key variables, which can be useful for debugging or understanding how `make` interprets the Makefile.

### How to Use the Makefile

1. **Build the project**:
   To compile the project, simply run:
   ```bash
   make
   ```

   This will compile the `.c` files into `.o` object files and then link them into the `my_program` executable.

2. **Clean the build**:
   To clean the build artifacts (object files and executable), run:
   ```bash
   make clean
   ```

3. **Install the executable**:
   To copy the executable to `/usr/local/bin/`, run:
   ```bash
   sudo make install
   ```

4. **Debug the Makefile**:
   To see the values of variables in the Makefile, run:
   ```bash
   make show-vars
   ```

### Summary

This **Makefile** is a simple but complete example of how to build a C project with multiple source files. It demonstrates:
- The use of variables for flexibility.
- Pattern rules to handle multiple files with a single rule.
- The use of built-in automatic variables (`$<`, `$@`, etc.).
- Custom targets like `clean`, `install`, and `show-vars`.
- Dependency management to ensure efficient recompilation based on file changes.

You can expand this Makefile to fit larger projects by adding more targets, functions, and conditional statements as needed.
