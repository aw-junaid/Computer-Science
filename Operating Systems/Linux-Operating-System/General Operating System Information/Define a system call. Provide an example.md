# System Call: Interface Between User Programs and Operating System

A **system call** is a mechanism that allows a user-level program (an application or a process) to request a service from the operating system. These services typically involve operations that require privileged access, such as interacting with hardware devices, managing files, or performing other low-level tasks. System calls provide a controlled entry point into the kernel, enabling user programs to execute operations that would otherwise be restricted.

## Key Characteristics of System Calls:

1. **Privileged Operations:**
   - System calls provide a way for user programs to perform privileged operations that require elevated access rights, which are typically restricted to the operating system kernel.

2. **Interface Between User Space and Kernel Space:**
   - System calls act as the interface between the user space (where user programs run) and the kernel space (where the operating system resides). They allow user programs to request services and resources from the kernel.

3. **Controlled Access:**
   - System calls are the only sanctioned means for user programs to access operating system services. They help maintain control over system resources and ensure the security and stability of the system.

4. **Switching Context:**
   - When a system call is invoked, the control switches from user mode to kernel mode, allowing the operating system to execute the requested service on behalf of the user program.

## Example of a System Call: Writing to a File

Let's take the example of a system call for writing to a file, which involves interactions with the operating system's file management functions.

### C Programming Example:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // File control options
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Open a file for writing
    int fileDescriptor = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (fileDescriptor == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
    const char *data = "Hello, System Call!";
    ssize_t bytesWritten = write(fileDescriptor, data, strlen(data));

    if (bytesWritten == -1) {
        perror("Error writing to the file");
        close(fileDescriptor);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fileDescriptor);

    return 0;
}
```

In this example, the `open` system call is used to open a file for writing, and the `write` system call is used to write data to the file. These system calls provide an interface for the user program to interact with the file system through the operating system kernel.
