# Process vs. Program: Understanding the Difference

## Program

### Definition

A **program** is a set of instructions written in a high-level programming language that performs a specific task when executed. It is a passive entity, typically stored on disk as an executable file, and doesn't have an active presence in the computer's memory until it is loaded. Programs serve as a blueprint for tasks but lack the dynamic, runtime characteristics associated with active execution.

### Characteristics

- **Static Nature:** Programs are static and do not change. They are a collection of code and data stored in a file, waiting to be executed.
  
- **Storage:** Stored on disk or other storage media as an executable file (e.g., .exe, .jar, or .py).

- **Example:** A text editor application, a web browser executable, or a game software.

## Process

### Definition

A **process**, on the other hand, is an active, dynamic entity that represents the execution of a program. When a program is loaded into the computer's memory and starts running, it becomes a process. A program can give rise to multiple processes, each with its own memory space and execution state, allowing concurrent execution of the same program.

### Characteristics

- **Dynamic Nature:** Processes are dynamic and undergo changes during execution. They have an active presence in the computer's memory.

- **Execution State:** Involves program counter, registers, and memory space. A process encapsulates the program's code, data, and the state of the processor.

- **Concurrency:** Multiple instances of a program (processes) can run concurrently.

- **Example:** If you open multiple instances of a text editor, each instance is a separate process.

## Relationship

- **One-to-Many:** One program can give rise to multiple processes. For example, launching the same program multiple times creates distinct processes for each instance.

- **Execution:** A program is a passive entity, while a process is an active, running instance of that program.

- **Resource Allocation:** Each process has its own resources, such as memory space and system resources, but they may share the same code (program) in memory.

In summary, a program is a static set of instructions, while a process is a dynamic execution of those instructions in the computer's memory. Multiple processes can be spawned from a single program, each operating independently and concurrently.
