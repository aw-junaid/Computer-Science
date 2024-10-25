 **Here's how user-mode scheduling (UMS) handles thread creation and termination in Windows:**

**1. Thread Creation:**

- **Application Request:** A UMS-enabled application initiates thread creation using the `CreateUmsThread` API.
- **Kernel Interaction:** This API invokes a system call, transitioning into kernel mode to allocate necessary resources and register the new thread with the kernel.
- **Thread Context:** The kernel allocates a thread context for the UMS thread, which includes its stack, registers, and other thread-specific data.
- **Completion List:** The kernel associates the newly created thread with the application's completion list, which serves as the communication channel for thread management.
- **Return to User Space:** Once the kernel completes these steps, it returns control to the application in user space, providing a handle to the newly created UMS thread.

**2. Thread Termination:**

- **Application Notification:** When a UMS thread terminates, either voluntarily or due to an exception, the application notifies the kernel using the `UmsThreadUnregister` API.
- **Kernel Cleanup:** The kernel releases resources associated with the terminated thread, including its thread context and any held kernel objects.
- **Completion List Update:** The kernel updates its internal state and the completion list to reflect the thread's termination.
- **Asynchronous Notification:** If necessary, the kernel asynchronously notifies the application of the thread's termination through the completion list, allowing the user-mode scheduler to adjust its scheduling decisions.

**Key Points:**

- UMS applications initiate thread creation and termination, but they rely on the kernel for resource allocation, registration, and cleanup.
- The completion list plays a crucial role in coordinating thread management between user space and kernel space.
- UMS applications have more control over thread scheduling within their own context, but they still depend on the kernel for certain operations and asynchronous notifications.
- The kernel ensures proper resource management and thread state transitions, maintaining system stability and integrity.
