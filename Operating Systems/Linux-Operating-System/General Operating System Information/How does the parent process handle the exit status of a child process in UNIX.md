In UNIX, the parent process handles the exit status of a child process using the `wait()` or `waitpid()` system calls. These system calls allow the parent process to collect information about the termination status of its child processes. Here's a brief overview of how the parent process handles the exit status of a child process:

1. **`wait()` System Call:**
   - The `wait()` system call is a blocking call that causes the parent process to wait until one of its child processes terminates. When a child process terminates, its exit status and process ID are collected by the parent through the `wait()` system call.

   ```c
   #include <sys/wait.h>

   pid_t wait(int *status);
   ```

   - The `status` parameter is a pointer to an integer where the exit status of the terminated child process will be stored.

2. **`waitpid()` System Call:**
   - The `waitpid()` system call provides more flexibility than `wait()` by allowing the parent process to wait for a specific child process or for any child process in a specified process group. It also supports options for non-blocking behavior.

   ```c
   #include <sys/wait.h>

   pid_t waitpid(pid_t pid, int *status, int options);
   ```

   - The `pid` parameter specifies which child process to wait for. If `pid` is set to -1, the call waits for any child process. The `status` parameter stores the exit status, and the `options` parameter provides additional behavior options.

3. **Checking Exit Status:**
   - After the `wait()` or `waitpid()` call returns, the parent process can check the exit status of the terminated child process. The exit status contains information about how the child process terminated, such as whether it exited normally or encountered an error.

   - The `WIFEXITED(status)` macro checks if the child process terminated normally, and `WEXITSTATUS(status)` retrieves the exit status.

   ```c
   if (WIFEXITED(status)) {
       // Child process terminated normally
       int exit_status = WEXITSTATUS(status);
       // Process exit_status as needed
   }
   ```

   - Other macros, such as `WIFSIGNALED(status)`, `WTERMSIG(status)`, and `WCOREDUMP(status)`, provide information about abnormal terminations due to signals.

4. **Handling Multiple Child Processes:**
   - If a parent has multiple child processes, it can use a loop to repeatedly call `wait()` or `waitpid()` to collect exit statuses for each terminated child process.

   ```c
   while ((pid = wait(&status)) > 0) {
       // Process exit status
   }
   ```

5. **Non-Blocking Behavior:**
   - To avoid blocking the parent process while waiting for child processes, the `waitpid()` system call can be used with the `WNOHANG` option. This allows the parent to continue executing other tasks while periodically checking for terminated child processes.

   ```c
   pid_t pid = waitpid(-1, &status, WNOHANG);
   if (pid > 0) {
       // Process exit status
   }
   ```

By using these system calls and associated macros, the parent process in UNIX can effectively handle the exit status of its child processes, allowing it to respond appropriately to the termination of child tasks and avoid leaving them in the zombie state.
