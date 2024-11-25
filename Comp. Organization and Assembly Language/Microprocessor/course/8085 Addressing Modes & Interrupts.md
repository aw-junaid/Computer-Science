### **8085 Addressing Modes**

The **addressing modes** in the **8085 microprocessor** define how the operand (data or address) for an instruction is specified. In the 8085 microprocessor, there are **5 addressing modes**:

#### 1. **Immediate Addressing Mode**
   - **Description:** In this mode, the operand (data) is provided directly within the instruction itself.
   - **Example:** `MVI A, 32H`
     - This instruction moves the immediate value `32H` directly into the accumulator (A).
     - Here, `32H` is the operand and is given in the instruction itself.
  
#### 2. **Register Addressing Mode**
   - **Description:** The operand is located in one of the general-purpose registers (B, C, D, E, H, L).
   - **Example:** `MOV A, B`
     - This instruction moves the contents of register `B` into the accumulator `A`.
     - No memory address is involved; the data is directly in one of the registers.

#### 3. **Memory Addressing Mode**
   - **Description:** The operand is stored in a memory location, and the address of that memory location is provided by the instruction.
   - **Example:** `MOV A, M`
     - This instruction moves the contents of the memory location (pointed to by the HL register pair) into the accumulator `A`.
     - The memory location is addressed indirectly through the **HL register pair**.

#### 4. **Register Indirect Addressing Mode**
   - **Description:** The operand is located in a memory location, but the address of that memory location is stored in one of the register pairs (BC, DE, HL).
   - **Example:** `MOV A, M`
     - This instruction uses the HL register pair to point to a memory location, and the data from that memory address is moved into the accumulator.
     - This is an example of **register indirect** addressing.

#### 5. **Implicit Addressing Mode**
   - **Description:** In this mode, the operand is implied by the operation being performed. The instruction does not require an explicit operand or memory location.
   - **Example:** `CLC` (Clear Carry Flag)
     - This instruction does not require an operand. It implicitly clears the carry flag in the flag register.

---

### **8085 Interrupts**

The **8085 microprocessor** supports a variety of **interrupts**, which allow it to respond to external events and divert the processor’s execution to handle those events. Interrupts are an essential feature for real-time applications.

#### **Types of Interrupts in 8085**

1. **Maskable Interrupts (Software-controlled interrupts)**
   - These interrupts can be disabled or "masked" by setting or clearing certain control bits.
   - The maskable interrupts are:
     - **RST5.5**
     - **RST6.5**
     - **RST7.5**
     - **INTR** (Interrupt Request)

2. **Non-Maskable Interrupts**
   - These interrupts cannot be disabled by the control bits. They are high-priority and always interrupt the current execution.
   - **TRAP** is the only non-maskable interrupt in the 8085.

---

#### **Detailed Explanation of Interrupts**

1. **TRAP:**
   - **Priority:** Highest priority interrupt.
   - **Maskable:** No (Non-maskable).
   - **Triggering:** This interrupt is triggered by a low-level signal and cannot be disabled.
   - **Usage:** It is used for emergency situations where immediate attention from the CPU is required, such as critical hardware failure or power-down scenarios.
   - **Handling:** When the TRAP interrupt occurs, the program counter is saved, and the control is transferred to memory location `0024H`.

2. **RST7.5 (Restart Interrupt 7.5):**
   - **Priority:** High priority.
   - **Maskable:** Yes.
   - **Triggering:** It is a level-triggered interrupt.
   - **Handling:** It transfers control to memory location `003C`. It is a software-enabled interrupt and can be disabled by using the interrupt enable instructions.

3. **RST6.5 (Restart Interrupt 6.5):**
   - **Priority:** Medium priority.
   - **Maskable:** Yes.
   - **Triggering:** It is a level-triggered interrupt.
   - **Handling:** It transfers control to memory location `0038`.

4. **RST5.5 (Restart Interrupt 5.5):**
   - **Priority:** Medium priority.
   - **Maskable:** Yes.
   - **Triggering:** It is a level-triggered interrupt.
   - **Handling:** It transfers control to memory location `0034`.

5. **INTR (Interrupt Request):**
   - **Priority:** Lowest priority.
   - **Maskable:** Yes.
   - **Triggering:** This interrupt is edge-triggered, which means it is activated by the rising edge of the signal.
   - **Handling:** The microprocessor first checks if the interrupt is recognized and, if it is, transfers control to memory location `0024H`. This interrupt can be masked using the interrupt enable control instruction.

---

#### **Interrupt Handling in 8085**

When an interrupt occurs, the 8085 microprocessor performs the following steps to handle it:

1. **Interrupt Acknowledgment:**
   - The interrupt request is acknowledged, and the control unit checks if the interrupt is enabled.

2. **Program Counter Save:**
   - The microprocessor saves the current **program counter (PC)** value onto the **stack** to ensure it can resume the execution from where it left off once the interrupt is serviced.

3. **Control Transfer:**
   - The 8085 then transfers control to the address corresponding to the interrupt vector location (depending on the interrupt type).
   - For example, **TRAP** transfers control to `0024H`, while **RST7.5** transfers control to `003C`.

4. **Interrupt Service Routine (ISR):**
   - The appropriate Interrupt Service Routine (ISR) is executed to handle the interrupt. Once the ISR completes, the program execution returns to the original instruction after the interrupt.

5. **Return from Interrupt:**
   - The **return from interrupt** is typically done using the `RIM` (Read Interrupt Mask) instruction to check the interrupt status or `SIM` (Set Interrupt Mask) for masking interrupts.

---

### **Summary of 8085 Interrupts:**

| **Interrupt** | **Priority**    | **Maskable** | **Vector Address** | **Triggering Type**     |
|---------------|-----------------|--------------|--------------------|-------------------------|
| **TRAP**      | Highest         | No           | `0024H`            | Level Triggered        |
| **RST7.5**    | High            | Yes          | `003C`             | Level Triggered        |
| **RST6.5**    | Medium          | Yes          | `0038`             | Level Triggered        |
| **RST5.5**    | Medium          | Yes          | `0034`             | Level Triggered        |
| **INTR**      | Lowest          | Yes          | `0024`             | Edge Triggered         |

---

### **Conclusion:**

The **8085 microprocessor** provides several addressing modes and interrupt mechanisms to handle data and control flow efficiently in various applications. The **addressing modes** help in accessing operands and memory locations in different ways, and the **interrupt system** allows the processor to respond to real-time events and external signals, ensuring efficient multitasking and real-time control in embedded systems.
