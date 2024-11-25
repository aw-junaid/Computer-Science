### **8087 Numeric Data Processor (FPU)**

The **8087** was a **Floating Point Unit (FPU)** co-processor developed by **Intel** to complement the **8086** and **8088** microprocessors. Its primary function was to handle **floating-point arithmetic** operations (such as addition, subtraction, multiplication, division, and square root), which were computationally expensive on the 8086/8088, as these processors only supported **integer arithmetic**. The 8087 significantly accelerated these operations, making it especially useful for applications involving scientific calculations, engineering, and graphics.

### **Overview of the 8087 FPU**

- The **8087** co-processor works alongside the **8086** or **8088** microprocessors. It does not replace the main CPU but assists it by handling floating-point operations.
- The **8087** is an external coprocessor and communicates with the **8086**/**8088** via a dedicated bus interface.
- The **8087** supports single-precision (32-bit) and double-precision (64-bit) floating-point operations.

### **Key Features of the 8087**

1. **Floating-Point Arithmetic Support**:
   - The 8087 supports a variety of floating-point operations such as addition, subtraction, multiplication, division, square roots, trigonometric functions (sine, cosine, etc.), and logarithmic functions (log, exp).
   - It also handles **rounded**, **truncated**, and **scaled** arithmetic results.

2. **Internal Stack**:
   - The 8087 has an **internal 8-level stack** that holds floating-point numbers. The stack is organized in a Last-In-First-Out (LIFO) fashion, where the most recently used data is on top of the stack.
   - The stack allows the 8087 to store intermediate results and supports **push** and **pop** operations.

3. **Precision**:
   - **Single precision** (32 bits) and **double precision** (64 bits) floating-point numbers are supported.
   - The 8087 provides high precision for floating-point calculations, with **64-bit double precision** being the default mode.

4. **Operation Speed**:
   - The 8087 is much faster at floating-point operations than the **8086/8088** processors, as the microprocessors could not handle floating-point calculations natively. For example, the 8087 can perform floating-point additions, subtractions, and multiplications at a much higher rate than the 8086.

5. **Math Functions**:
   - The 8087 performs advanced mathematical operations such as:
     - Arithmetic operations (addition, subtraction, multiplication, division)
     - Trigonometric operations (sine, cosine, tangent, etc.)
     - Logarithmic operations (log, natural log, etc.)
     - Square root calculations
     - Comparison operations (e.g., greater than, less than)

6. **Exception Handling**:
   - The 8087 has **exception handling** capabilities for handling errors such as **overflow**, **underflow**, **divide-by-zero**, and invalid operations.
   - It uses a status word to monitor exceptions and set flags that can be read by the CPU to handle errors appropriately.

7. **Mode of Operation**:
   - The 8087 supports **two modes** of operation: **emulation mode** and **native mode**.
   - In **emulation mode**, the 8087 emulates floating-point operations through software, which is slower.
   - In **native mode**, the 8087 executes the floating-point operations directly in hardware, making it much faster.

### **8087 Architecture**

The 8087's architecture is designed to complement the 8086/8088 microprocessor and allows seamless interaction between the two. The 8087's **key components** are:

1. **Arithmetic Unit**:
   - The arithmetic unit performs all floating-point operations, including addition, subtraction, multiplication, and division.
   
2. **Registers and Stack**:
   - The 8087 has **8 registers (ST(0) to ST(7))** that hold floating-point numbers. These registers form the stack, where each register holds a **single-precision** or **double-precision** floating-point number.
   
3. **Control Unit**:
   - The control unit manages the flow of instructions between the 8086 and 8087 and coordinates the execution of floating-point operations.
   - It uses **control words** and **status words** to manage operations and exceptions.
   
4. **Status Word**:
   - The status word in the 8087 contains flags for condition codes such as **zero, overflow, underflow**, and **invalid operation**.
   
5. **Instruction Set**:
   - The 8087 has a dedicated instruction set to handle floating-point arithmetic, including instructions like **FADD**, **FSUB**, **FMUL**, **FDIV**, **FSQRT**, and others.

### **8087 Instruction Set**

The 8087 instruction set is designed to handle floating-point operations, as well as data transfer and control instructions.

#### **Common Instructions in the 8087**

- **FADD (Floating-point Addition)**:
  - Adds two floating-point numbers and stores the result in the destination register.
  - Example: `FADD ST(0), ST(1)` (Adds the contents of **ST(1)** to **ST(0)** and stores the result in **ST(0)**).

- **FSUB (Floating-point Subtraction)**:
  - Subtracts one floating-point number from another and stores the result in the destination register.
  - Example: `FSUB ST(0), ST(1)` (Subtracts **ST(1)** from **ST(0)** and stores the result in **ST(0)**).

- **FMUL (Floating-point Multiplication)**:
  - Multiplies two floating-point numbers and stores the result in the destination register.
  - Example: `FMUL ST(0), ST(1)` (Multiplies **ST(0)** by **ST(1)** and stores the result in **ST(0)**).

- **FDIV (Floating-point Division)**:
  - Divides one floating-point number by another and stores the result in the destination register.
  - Example: `FDIV ST(0), ST(1)` (Divides **ST(0)** by **ST(1)** and stores the result in **ST(0)**).

- **FSQRT (Floating-point Square Root)**:
  - Computes the square root of the floating-point number in the specified register.
  - Example: `FSQRT ST(0)` (Computes the square root of **ST(0)** and stores the result in **ST(0)**).

- **FCHS (Floating-point Change Sign)**:
  - Changes the sign of the floating-point number in the specified register.
  - Example: `FCHS ST(0)` (Changes the sign of **ST(0)**).

- **FCOM (Floating-point Compare)**:
  - Compares two floating-point numbers and sets the status flags.
  - Example: `FCOM ST(0), ST(1)` (Compares **ST(0)** with **ST(1)**).

- **FSTP (Floating-point Store and Pop)**:
  - Stores the contents of the top register to memory and then pops the stack.
  - Example: `FSTP [MemoryLocation]` (Stores the contents of **ST(0)** to the specified memory location and pops the stack).

### **Interfacing the 8087 with the 8086**

To use the 8087 with the 8086, the 8086 must have the **coprocessor interface** and **control signals**. These signals are used to communicate with the 8087, which allows the **8086** to issue floating-point instructions to the **8087**, which in turn performs the calculations and returns the result. 

- The **8086** sends **control and data** signals to the 8087 to trigger operations.
- The 8087 performs the calculations and places the results in the **8087's internal stack**.
- The 8086 retrieves the results when needed.

### **Conclusion**

The **8087 Numeric Data Processor** is an essential coprocessor for the **8086** and **8088** microprocessors, providing hardware support for fast and efficient floating-point arithmetic. It greatly accelerates scientific and engineering calculations by offloading the computationally intensive floating-point operations from the main processor. With its internal stack and powerful instruction set, the 8087 enhances the performance of applications requiring high precision and large-scale mathematical operations.
