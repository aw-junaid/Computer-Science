### **Interrupts in Computer Architecture**  

An **interrupt** is a signal that temporarily halts the normal execution of a program to allow the CPU to handle a higher-priority task (such as handling I/O, errors, or system calls). Once the interrupt is handled, normal execution resumes.  

---

## **Types of Interrupts**  

### **1. Hardware Interrupts**  
Triggered by external hardware devices (e.g., keyboard, mouse, disk, network).  
- **Maskable Interrupts (IRQ - Interrupt Request):** Can be enabled/disabled using special instructions.  
- **Non-Maskable Interrupts (NMI):** Cannot be ignored (e.g., power failure, memory error).  

### **2. Software Interrupts**  
Triggered by the execution of specific instructions.  
- **System Calls (e.g., `int 0x80` in Linux for system calls).**  
- **Exception Handling (e.g., division by zero, invalid opcode).**  

### **3. Exceptions (Faults, Traps, Aborts)**  
- **Faults:** Can be recovered (e.g., page fault).  
- **Traps:** Execute a handler and resume execution (e.g., system calls).  
- **Aborts:** Fatal errors that halt execution (e.g., memory corruption).  

---

## **Interrupt Handling Process**  

1. **Interrupt Occurs**  
   - CPU detects an interrupt signal.  
2. **Save CPU State**  
   - Registers, Program Counter (PC), and Flags are saved.  
3. **Jump to Interrupt Service Routine (ISR)**  
   - CPU fetches the Interrupt Vector Table (IVT) to locate the ISR.  
4. **Execute ISR**  
   - Handles the interrupt (e.g., reading a keystroke).  
5. **Restore CPU State**  
   - Resumes execution from where it was interrupted.  

---

## **Assembly Example (x86 - Software Interrupt for System Call)**  
```assembly
section .text
    global _start

_start:
    mov eax, 1       ; syscall number for exit
    mov ebx, 0       ; exit status
    int 0x80         ; call kernel (Linux system call)
```
This code makes a system call using **`int 0x80`**, requesting the Linux kernel to terminate the program.

---
