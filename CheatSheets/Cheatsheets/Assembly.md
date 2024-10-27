An extended Assembly language cheat sheet that covers essential commands, syntax, and concepts. Since Assembly language varies significantly between different processors and architectures, this cheat sheet will focus primarily on x86 and x86-64 Assembly language (using the Intel syntax) as a commonly used architecture.

---

## **Basic Structure of an Assembly Program**

### 1. **Program Structure**

```assembly
section .data          ; Data section
    msg db 'Hello, World!', 0

section .text          ; Code section
global _start          ; Entry point

_start:                ; Main program starts here
    ; program code goes here
```

**Explanation**: An Assembly program typically consists of three sections: `.data` (for variables), `.bss` (for uninitialized data), and `.text` (for the code). The `_start` label indicates the entry point of the program.

---

## **Data Types and Declarations**

### 2. **Defining Data**

```assembly
section .data
    int_var db 10              ; Byte
    str_var db 'Hello', 0      ; String
    float_var dd 3.14          ; Double word (float)
```

**Explanation**: Data can be defined using `db` (define byte), `dw` (define word), `dd` (define double word), etc. Strings are null-terminated.

### 3. **Uninitialized Data**

```assembly
section .bss
    buffer resb 64             ; Reserve 64 bytes
```

**Explanation**: The `.bss` section is used for uninitialized data, and `resb` reserves a specified number of bytes.

---

## **Basic Instructions**

### 4. **Arithmetic Operations**

```assembly
mov eax, 5                   ; Move 5 into EAX
add eax, 2                   ; Add 2 to EAX (EAX = 7)
sub eax, 1                   ; Subtract 1 from EAX (EAX = 6)
mul ebx                      ; EAX = EAX * EBX (unsigned)
div ecx                      ; EAX = EAX / ECX (unsigned)
```

**Explanation**: Common arithmetic operations include `mov` (move), `add`, `sub`, `mul`, and `div`.

### 5. **Logical Operations**

```assembly
and eax, ebx                ; EAX = EAX AND EBX
or eax, ebx                 ; EAX = EAX OR EBX
xor eax, ebx                ; EAX = EAX XOR EBX
not eax                     ; EAX = NOT EAX
```

**Explanation**: Logical operations manipulate bits and include `and`, `or`, `xor`, and `not`.

### 6. **Comparison Operations**

```assembly
cmp eax, ebx                ; Compare EAX and EBX
je equal_label              ; Jump if equal
jne not_equal_label         ; Jump if not equal
jl less_label               ; Jump if less
jg greater_label            ; Jump if greater
```

**Explanation**: `cmp` compares two values and sets flags for conditional jumps like `je`, `jne`, `jl`, and `jg`.

---

## **Control Flow**

### 7. **Jump Instructions**

```assembly
jmp label                   ; Unconditional jump
call function               ; Call a function
ret                         ; Return from function
```

**Explanation**: `jmp` performs an unconditional jump to a label, while `call` jumps to a function and saves the return address. `ret` returns control to the caller.

### 8. **Conditional Jumps**

```assembly
cmp eax, ebx
je equal_label              ; Jump if equal
jne not_equal_label         ; Jump if not equal
```

**Explanation**: Conditional jumps depend on the result of the last `cmp` or `test` instruction.

---

## **Function Calls**

### 9. **Defining Functions**

```assembly
section .text
global my_function

my_function:
    ; function code
    ret
```

**Explanation**: Functions are defined with labels. Use `global` to make them accessible from other files.

### 10. **Calling Conventions**

```assembly
call my_function            ; Call function
```

**Explanation**: The `call` instruction transfers control to a function. The return address is stored on the stack.

---

## **Stack Operations**

### 11. **Using the Stack**

```assembly
push eax                    ; Push EAX onto the stack
pop ebx                     ; Pop the top value into EBX
```

**Explanation**: The `push` instruction adds an item to the top of the stack, and `pop` removes the top item.

### 12. **Stack Frame Setup**

```assembly
my_function:
    push ebp                ; Save base pointer
    mov ebp, esp            ; Set new base pointer
    ; function code
    mov esp, ebp            ; Restore stack pointer
    pop ebp                 ; Restore base pointer
    ret
```

**Explanation**: Setting up a stack frame involves saving the old base pointer and adjusting the stack pointer.

---

## **Input and Output**

### 13. **System Calls (Linux)**

```assembly
section .text
global _start

_start:
    ; write "Hello, World!" to stdout
    mov eax, 4              ; syscall number for sys_write
    mov ebx, 1              ; file descriptor (stdout)
    mov ecx, msg            ; pointer to message
    mov edx, 13             ; message length
    int 0x80                ; interrupt to call kernel
```

**Explanation**: Use system calls to perform I/O operations. The `int 0x80` instruction invokes the kernel.

---

## **String Operations**

### 14. **String Manipulation**

```assembly
section .data
    str db 'Hello, World!', 0

section .text
    mov eax, str            ; Load address of string
    ; String operations go here
```

**Explanation**: Strings can be manipulated using pointers, and operations may vary by architecture.

---

## **End of Program**

### 15. **Exiting the Program**

```assembly
section .text
global _start

_start:
    ; program code here
    mov eax, 1              ; syscall number for sys_exit
    xor ebx, ebx            ; return code 0
    int 0x80                ; exit program
```

**Explanation**: Use `sys_exit` to terminate a program. `xor ebx, ebx` sets the return code to 0.

---

## **Macros and Directives**

### 16. **Using Macros**

```assembly
%macro print_message 1
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, 13
    int 0x80
%endmacro
```

**Explanation**: Macros are defined with `%macro` and can simplify repetitive code.

### 17. **Assembly Directives**

```assembly
section .data
    db 10                   ; Define a byte
    dw 20                   ; Define a word
    dd 30                   ; Define a double word
```

**Explanation**: Directives are commands that instruct the assembler on how to process the code, such as `section`, `db`, `dw`, and `dd`.

---

## **Comments**

### 18. **Adding Comments**

```assembly
; This is a single-line comment

section .data             ; Data section
```

**Explanation**: Comments start with `;` and are ignored by the assembler.

---

This cheat sheet provides a comprehensive overview of the essential commands and concepts in Assembly language, particularly for x86/x86-64 architecture. Regular practice with these commands will help you become proficient in Assembly programming.
