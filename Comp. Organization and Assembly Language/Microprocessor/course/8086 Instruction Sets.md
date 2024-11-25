### **8086 Microprocessor Instruction Set**

The **Intel 8086** microprocessor has a comprehensive set of instructions that are classified based on the operation they perform. These instructions allow for a wide variety of operations such as data transfer, arithmetic operations, logical operations, control operations, and more. The instruction set is divided into several categories:

### **1. Data Transfer Instructions**
These instructions are used to move data between registers, memory, and I/O devices.

- **MOV**: Moves data from a source to a destination.
  - Example: `MOV AX, BX` (Moves the contents of **BX** into **AX**).
- **PUSH**: Pushes the data onto the stack.
  - Example: `PUSH AX` (Pushes the contents of **AX** onto the stack).
- **POP**: Pops the data from the stack.
  - Example: `POP AX` (Pops the data from the stack into **AX**).
- **IN**: Reads data from an I/O port into a register.
  - Example: `IN AL, 30h` (Reads a byte of data from I/O port 30h into **AL**).
- **OUT**: Sends data from a register to an I/O port.
  - Example: `OUT 30h, AL` (Sends the contents of **AL** to I/O port 30h).
- **XCHG**: Exchanges data between two operands.
  - Example: `XCHG AX, BX` (Exchanges the contents of **AX** and **BX**).

---

### **2. Arithmetic Instructions**
These instructions are used to perform arithmetic operations.

- **ADD**: Adds two operands and stores the result in the destination operand.
  - Example: `ADD AX, BX` (Adds the contents of **BX** to **AX** and stores the result in **AX**).
- **SUB**: Subtracts the source operand from the destination operand.
  - Example: `SUB AX, BX` (Subtracts **BX** from **AX** and stores the result in **AX**).
- **MUL**: Multiplies an operand with the **AX** register (unsigned multiplication).
  - Example: `MUL BX` (Multiplies **AX** by **BX**, stores the result in **DX:AX**).
- **IMUL**: Multiplies an operand with the **AX** register (signed multiplication).
  - Example: `IMUL BX` (Signed multiplication of **AX** and **BX**).
- **DIV**: Divides the contents of **DX:AX** by a specified operand (unsigned division).
  - Example: `DIV BX` (Divides **DX:AX** by **BX**, stores the quotient in **AX** and remainder in **DX**).
- **IDIV**: Divides the contents of **DX:AX** by a specified operand (signed division).
  - Example: `IDIV BX` (Signed division of **DX:AX** by **BX**).
- **INC**: Increments a register or memory location by 1.
  - Example: `INC AX` (Increments **AX** by 1).
- **DEC**: Decrements a register or memory location by 1.
  - Example: `DEC BX` (Decrements **BX** by 1).

---

### **3. Logical Instructions**
These instructions perform logical operations such as AND, OR, XOR, etc.

- **AND**: Performs bitwise AND operation on two operands.
  - Example: `AND AX, BX` (Performs a bitwise AND of **AX** and **BX** and stores the result in **AX**).
- **OR**: Performs bitwise OR operation on two operands.
  - Example: `OR AX, BX` (Performs a bitwise OR of **AX** and **BX** and stores the result in **AX**).
- **XOR**: Performs bitwise XOR operation on two operands.
  - Example: `XOR AX, BX` (Performs a bitwise XOR of **AX** and **BX** and stores the result in **AX**).
- **NOT**: Performs a bitwise NOT operation on an operand (inverts all bits).
  - Example: `NOT AX` (Inverts all bits in **AX**).
- **TEST**: Performs a bitwise AND operation between two operands but does not store the result. It only affects the flags.
  - Example: `TEST AX, BX` (Performs AND between **AX** and **BX** and updates the flags).

---

### **4. Control Flow Instructions**
These instructions control the execution flow of the program.

- **JMP**: Unconditional jump to a specified address.
  - Example: `JMP 1000h` (Unconditionally jumps to the address 1000h).
- **CALL**: Calls a procedure (subroutine).
  - Example: `CALL 2000h` (Calls the procedure located at address 2000h).
- **RET**: Returns from a procedure.
  - Example: `RET` (Returns from the current procedure).
- **JZ**: Jumps if the Zero Flag (ZF) is set.
  - Example: `JZ 3000h` (Jumps to 3000h if the Zero Flag is set).
- **JNZ**: Jumps if the Zero Flag (ZF) is not set.
  - Example: `JNZ 4000h` (Jumps to 4000h if the Zero Flag is not set).
- **JC**: Jumps if the Carry Flag (CF) is set.
  - Example: `JC 5000h` (Jumps to 5000h if the Carry Flag is set).
- **JNC**: Jumps if the Carry Flag (CF) is not set.
  - Example: `JNC 6000h` (Jumps to 6000h if the Carry Flag is not set).
- **JAE**: Jumps if the Carry Flag (CF) or Zero Flag (ZF) is set (jump if above or equal).
  - Example: `JAE 7000h` (Jumps to 7000h if **AX** ≥ **BX**).

---

### **5. String Instructions**
These instructions perform operations on strings, which are sequences of bytes or words in memory.

- **MOVSB**: Moves a byte from the source to the destination.
  - Example: `MOVSB` (Moves a byte from the source string to the destination string).
- **MOVSW**: Moves a word from the source to the destination.
  - Example: `MOVSW` (Moves a word from the source string to the destination string).
- **CMPSB**: Compares a byte from the source string with a byte from the destination string.
  - Example: `CMPSB` (Compares a byte from the source string to a byte from the destination string).
- **CMPSW**: Compares a word from the source string with a word from the destination string.
  - Example: `CMPSW` (Compares a word from the source string to a word from the destination string).
- **SCASB**: Scans a byte in the destination string and compares it with the accumulator (AL).
  - Example: `SCASB` (Scans a byte in the destination string and compares it with **AL**).
- **LODSB**: Loads a byte from the source string into the accumulator.
  - Example: `LODSB` (Loads a byte from the source string into **AL**).
- **STOSB**: Stores a byte from the accumulator into the destination string.
  - Example: `STOSB` (Stores a byte from **AL** into the destination string).

---

### **6. Stack Instructions**
These instructions perform operations on the stack.

- **PUSH**: Pushes the contents of a register or memory location onto the stack.
  - Example: `PUSH AX` (Pushes the contents of **AX** onto the stack).
- **POP**: Pops the contents of the top of the stack into a register or memory location.
  - Example: `POP AX` (Pops the contents from the top of the stack into **AX**).

---

### **7. Flag Control Instructions**
These instructions control or modify the processor's status flags.

- **CLC**: Clears the Carry Flag (CF).
  - Example: `CLC` (Clears the Carry Flag).
- **STC**: Sets the Carry Flag (CF).
  - Example: `STC` (Sets the Carry Flag).
- **CLI**: Clears the Interrupt Flag (IF).
  - Example: `CLI` (Disables interrupts).
- **STI**: Sets the Interrupt Flag (IF).
  - Example: `STI` (Enables interrupts).
- **CMC**: Complements the Carry Flag (CF).
  - Example: `CMC` (Inverts the Carry Flag).

---

### **Conclusion**

The **8086** microprocessor has a rich set of instructions that allow it to perform a wide range of operations on data. These instructions are critical for developing applications that require efficient data handling, arithmetic processing, and control flow management. The instruction set supports operations on both byte and word (16-bit) data and provides ample flexibility for different types of tasks and programming paradigms.
