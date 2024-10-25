 **Here's a description of the communication between user-mode scheduling (UMS) and the Windows kernel:**

**1. UMS Initialization:**

- An application opting for UMS uses the `CreateUmsCompletionList` API to create a completion list, a data structure that acts as a bridge between user space and the kernel for thread management.
- The application then calls `CreateUmsThreadContext` to create UMS threads, which are associated with the completion list.

**2. Thread Yielding:**

- When a UMS thread voluntarily yields the CPU, it calls the `UmsThreadYield` API.
- This API doesn't directly involve the kernel scheduler. Instead, it signals other UMS threads within the same application, indicating that the CPU is available.
- The application's user-mode scheduler selects the next thread to run and resumes its execution.

**3. Blocking Operations:**

- When a UMS thread performs a blocking operation (e.g., I/O, waiting for a system event, or sleeping), it transitions back to kernel mode.
- The kernel takes over scheduling responsibility and places the thread in an appropriate wait queue.
- Once the blocking operation completes, the kernel notifies the completion list, signaling the application's user-mode scheduler to resume the thread.

**4. New Thread Creation:**

- When a UMS application creates a new UMS thread, it uses the `CreateUmsThread` API, which interacts with the kernel to allocate necessary resources and register the thread with the completion list.

**5. Termination:**

- When a UMS thread terminates, the application notifies the kernel using `UmsThreadUnregister`.
- The kernel releases associated resources and updates internal state accordingly.

**6. Asynchronous Notifications:**

- The kernel can asynchronously notify the UMS application of events like thread termination or completion of I/O operations.
- These notifications are delivered through the completion list, allowing the user-mode scheduler to react accordingly.

**7. Debugging and Introspection:**

- The Windows kernel provides APIs for debugging and introspection of UMS threads, such as `UmsThreadGetInfo` and `UmsThreadIsSuspended`.
- These APIs enable developers to examine the state of UMS threads and diagnose potential issues.

**Key Points:**

- UMS primarily operates within user space, but it relies on the kernel for certain operations, resource allocation, and asynchronous notifications.
- The completion list serves as a communication channel between user space and kernel space.
- UMS applications must carefully manage thread switching and synchronization within user space to ensure correct behavior and avoid deadlocks.
- The kernel provides APIs for debugging and introspection of UMS threads to aid in development and troubleshooting.
