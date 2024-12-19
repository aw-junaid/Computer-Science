### Linux Admin - Shell Scripting

Shell scripting is an essential skill for Linux system administrators. It allows you to automate tasks, manage system configurations, and streamline repetitive processes. Shell scripts are sequences of commands executed by the shell, and they can simplify complex operations, improving efficiency and reducing human error.

This guide will introduce you to the basics of shell scripting, commonly used scripting techniques, and how to write and execute shell scripts on CentOS Linux.

---

### 1. **Introduction to Shell Scripting**

A shell script is a file containing a series of commands that the Linux shell (e.g., Bash) interprets and executes. Shell scripts are usually written in plain text and can be executed directly from the terminal.

The most common shell for writing scripts on Linux systems, including CentOS, is **Bash (Bourne Again Shell)**. Other shells like Zsh and Fish can also be used, but Bash is the default on most Linux distributions.

---

### 2. **Basic Structure of a Shell Script**

A basic shell script contains the following components:

- **Shebang (#!)**: The first line of a script usually contains the shebang (`#!`), which tells the system which interpreter to use to execute the script. For a Bash script, it looks like:

  ```bash
  #!/bin/bash
  ```

  This ensures that the script is run with the Bash shell, regardless of the shell the user is using.

- **Commands**: After the shebang, the script contains the commands you want to execute. These can be any valid Linux commands or utilities.

- **Comments**: Comments in a shell script are written using the `#` symbol. Comments are ignored by the shell but are useful for documenting the script.

  ```bash
  # This is a comment
  ```

---

### 3. **Creating and Running a Simple Script**

To create and execute a simple shell script:

1. **Create a New Script File**: Use a text editor like `vi`, `nano`, or `gedit` to create a new shell script file. For example:

   ```bash
   nano myscript.sh
   ```

2. **Write the Script**: Add the shebang and commands to the script file. For example:

   ```bash
   #!/bin/bash
   echo "Hello, World!"
   ```

3. **Save and Exit**: Save the file and exit the editor (`Ctrl + X` in `nano`, followed by `Y` to confirm).

4. **Make the Script Executable**: By default, scripts are not executable. Use the `chmod` command to make the script executable:

   ```bash
   chmod +x myscript.sh
   ```

5. **Run the Script**: Execute the script using the following command:

   ```bash
   ./myscript.sh
   ```

   This should output:

   ```
   Hello, World!
   ```

---

### 4. **Variables in Shell Scripts**

Variables in shell scripts are used to store data that can be referenced later in the script.

- **Defining a Variable**: Variables are assigned using the `=` sign. No spaces should be around the `=` sign.

  ```bash
  name="John"
  ```

- **Accessing a Variable**: To access the value of a variable, use the `$` sign:

  ```bash
  echo "Hello, $name!"
  ```

- **Command Substitution**: You can store the output of a command in a variable using command substitution:

  ```bash
  current_date=$(date)
  echo "Today's date is $current_date"
  ```

---

### 5. **Control Structures**

Control structures like conditional statements and loops are used to control the flow of a script.

#### 5.1. **If-Else Statements**

The `if` statement allows you to execute code conditionally.

```bash
#!/bin/bash
number=10

if [ $number -gt 5 ]; then
  echo "Number is greater than 5"
else
  echo "Number is less than or equal to 5"
fi
```

- **Operators**: 
  - `-eq`: equal to
  - `-ne`: not equal to
  - `-gt`: greater than
  - `-lt`: less than

#### 5.2. **Case Statements**

A `case` statement allows you to match a variable against multiple conditions.

```bash
#!/bin/bash
echo "Enter a number:"
read number

case $number in
  1)
    echo "You entered one"
    ;;
  2)
    echo "You entered two"
    ;;
  *)
    echo "You entered something else"
    ;;
esac
```

#### 5.3. **Loops**

Loops are used for repeating tasks.

- **For Loop**: A `for` loop repeats a set of commands a specific number of times.

  ```bash
  #!/bin/bash
  for i in {1..5}; do
    echo "Iteration $i"
  done
  ```

- **While Loop**: A `while` loop repeats commands as long as a specified condition is true.

  ```bash
  #!/bin/bash
  count=1
  while [ $count -le 5 ]; do
    echo "Iteration $count"
    ((count++))
  done
  ```

---

### 6. **Functions in Shell Scripts**

Functions allow you to group commands together and reuse them in your script.

- **Defining a Function**:

  ```bash
  #!/bin/bash
  greet() {
    echo "Hello, $1!"
  }

  greet "Alice"
  ```

  In this example, `$1` refers to the first argument passed to the function. You can pass multiple arguments to a function.

- **Calling a Function**: To call a function, simply use its name.

---

### 7. **Handling User Input**

Shell scripts can take input from the user using the `read` command.

- **Reading Input**:

  ```bash
  #!/bin/bash
  echo "Enter your name:"
  read name
  echo "Hello, $name!"
  ```

- **Reading Multiple Variables**:

  ```bash
  #!/bin/bash
  echo "Enter your first and last name:"
  read first_name last_name
  echo "Hello, $first_name $last_name!"
  ```

---

### 8. **Error Handling**

You should handle errors in your scripts to ensure smooth execution and debugging.

- **Exit Status**: The exit status of a command indicates whether it was successful or not. By convention, an exit status of `0` means success, and any non-zero exit status indicates an error.

  ```bash
  if ! command; then
    echo "Error occurred"
  fi
  ```

- **Exit Command**: You can use the `exit` command to terminate the script or function with a specific exit status.

  ```bash
  exit 0   # Successful execution
  exit 1   # Error occurred
  ```

---

### 9. **File Handling**

You can read from and write to files in shell scripts.

- **Reading a File**:

  ```bash
  #!/bin/bash
  while read line; do
    echo "Line: $line"
  done < file.txt
  ```

- **Writing to a File**:

  ```bash
  #!/bin/bash
  echo "Hello, World!" > output.txt
  ```

- **Appending to a File**:

  ```bash
  #!/bin/bash
  echo "New line" >> output.txt
  ```

---

### 10. **Scheduling Scripts with Cron Jobs**

You can schedule shell scripts to run at specific intervals using `cron`. This is useful for automating regular tasks like backups, updates, or monitoring.

- **Edit the Cron Table**:

  ```bash
  crontab -e
  ```

- **Cron Job Syntax**:

  ```bash
  * * * * * /path/to/script.sh
  ```

  The five `*` represent the time and date fields:
  - Minute (0-59)
  - Hour (0-23)
  - Day of the month (1-31)
  - Month (1-12)
  - Day of the week (0-7, where both 0 and 7 represent Sunday)

---

### 11. **Debugging Shell Scripts**

To debug shell scripts, you can use the `-x` option to print each command as it is executed:

```bash
bash -x myscript.sh
```

Alternatively, you can add `set -x` at the beginning of your script to enable debugging:

```bash
#!/bin/bash
set -x
```

This will display each command and its arguments as they are executed, helping you identify issues in the script.

---

### Conclusion

Shell scripting is a powerful tool for automating tasks, managing configurations, and streamlining system administration. By learning how to create and run shell scripts, manage variables, control flow, handle user input, and debug your scripts, you can increase productivity and reduce manual intervention in everyday administrative tasks. With experience, you'll be able to create complex and efficient scripts that simplify your Linux administration work.
