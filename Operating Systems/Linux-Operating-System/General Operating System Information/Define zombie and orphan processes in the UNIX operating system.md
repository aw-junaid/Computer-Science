In the UNIX operating system, "zombie" and "orphan" processes are terms used to describe specific states of processes in the system.

1. **Zombie Process:**
   - A zombie process is a child process that has completed its execution but still has an entry in the process table. In UNIX, when a process finishes its execution, it becomes a zombie process until its parent process collects its exit status. The process table entry for a zombie process contains information about its termination, including the exit status, but the process itself no longer performs any useful work.

   - Zombie processes are typically short-lived, as the operating system expects the parent process to handle the termination of its child processes. Once the parent retrieves the exit status using the `wait()` system call, the zombie process is removed from the process table, and its resources are released.

2. **Orphan Process:**
   - An orphan process is a process whose parent process has terminated or is no longer active. Orphan processes continue to run in the system but are adopted by the special process called the "init" process (usually with process ID 1), which becomes their new parent. The init process periodically performs the `wait()` system call to collect exit statuses of orphaned child processes, preventing them from becoming zombies.

   - Orphan processes typically occur when a parent process exits without waiting for its child processes to complete. The operating system automatically reassigns the orphaned child processes to the init process, ensuring that they are eventually collected and their resources are released.

In summary:
- **Zombie Process:** A child process that has completed its execution but still has an entry in the process table, waiting for its exit status to be collected by the parent process.
  
- **Orphan Process:** A process whose parent process has terminated or is no longer active. Orphan processes are adopted by the init process, preventing them from becoming zombies and ensuring that their exit statuses are collected.
