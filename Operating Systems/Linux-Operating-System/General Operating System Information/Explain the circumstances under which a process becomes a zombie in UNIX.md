A process becomes a zombie in UNIX under specific circumstances, and it typically involves the interaction between a parent process and its child process. The key events leading to the creation of a zombie process are as follows:

1. **Forking a Child Process:**
   - The process starts when a parent process uses the `fork()` system call to create a new child process. The child process is an exact copy of the parent process, including its code, data, and file descriptors.

2. **Child Process Completes Execution:**
   - The child process performs its tasks and completes its execution. At this point, the child process enters the "zombie" state.

3. **Exit Status is Not Collected:**
   - In a well-designed program, the parent process is responsible for collecting the exit status of its child processes. This is typically done using the `wait()` or `waitpid()` system call, which retrieves the exit status of a terminated child process.

4. **Parent Process Fails to Call wait():**
   - If the parent process neglects to call `wait()` or `waitpid()` to collect the exit status of its child process, the child process remains in the zombie state. The child's process table entry contains information about its termination, but the system retains this entry until the parent acknowledges the termination.

5. **Parent Process Terminates Without Collecting Exit Status:**
   - The situation becomes more critical if the parent process terminates before collecting the exit status of its child process. In this case, the responsibility for cleaning up the zombie process falls to the init process (usually with process ID 1).

6. **Init Process Adopts Zombie Process:**
   - The init process periodically performs the `wait()` system call to collect exit statuses of orphaned child processes. Orphan processes are those whose parent has terminated. The init process adopts the zombie process, retrieves its exit status, and removes its entry from the process table.

7. **Zombie Process is Reaped:**
   - Once the init process collects the exit status of the zombie process, the zombie is officially reaped, and its process table entry is removed. The system releases the resources associated with the zombie process.

To avoid the creation of zombie processes, it is crucial for parent processes to responsibly collect the exit status of their child processes using `wait()` or `waitpid()`. This ensures that the child processes are properly cleaned up, preventing them from lingering in the zombie state. The init process acts as a safeguard by adopting orphaned processes and ensuring their exit statuses are collected.
