### **8051 Microcontroller Interrupts**

Interrupts are a key feature in microcontrollers, allowing them to respond to external or internal events by temporarily halting the current program execution and transferring control to an interrupt service routine (ISR). The **8051 microcontroller** supports **5 interrupt sources**, which can be triggered by various conditions like external signals, timers, or serial communication events.

These interrupts enable the 8051 to perform tasks like **handling external events**, **timing operations**, and **communication** without constant monitoring from the main program. Once the interrupt service routine completes, control is returned to the main program.

---

### **Interrupt Sources in the 8051**

The **8051 microcontroller** supports the following interrupt sources:

1. **External Interrupt 0 (INT0)**  
2. **Timer Interrupt 0 (T0)**  
3. **External Interrupt 1 (INT1)**  
4. **Timer Interrupt 1 (T1)**  
5. **Serial Communication Interrupt (RI/TI)**  

Each interrupt has an associated interrupt vector that tells the microcontroller where to jump when the interrupt occurs.

---

### **8051 Interrupts Overview**

| Interrupt Source        | Interrupt Type | Interrupt Priority | Vector Address     | Description                                                   |
|-------------------------|----------------|--------------------|---------------------|---------------------------------------------------------------|
| **INT0 (External 0)**    | **External**   | **Low**            | **0x0003**           | Triggered by an external signal. Can be used for push buttons or sensors. |
| **T0 (Timer 0)**         | **Timer**      | **Low**            | **0x000B**           | Triggered when Timer 0 overflows. Used for time delays or event counting. |
| **INT1 (External 1)**    | **External**   | **Low**            | **0x0013**           | Triggered by a second external signal, similar to INT0. |
| **T1 (Timer 1)**         | **Timer**      | **Low**            | **0x001B**           | Triggered when Timer 1 overflows. Used for additional timing functions. |
| **Serial (RI/TI)**       | **Serial**     | **High**           | **0x0023**           | Triggered by serial data reception (RI) or transmission (TI). |

---

### **Interrupt Control Registers**

There are two primary control registers for handling interrupts in the **8051**:

1. **Interrupt Enable Register (IE)**:  
   This register controls whether each interrupt source is enabled or disabled. If the bit corresponding to an interrupt is set to **1**, the interrupt is enabled.

   | Bit | Description                |
   |-----|----------------------------|
   | **7** | **EA** (Global Interrupt Enable) - Enables or disables all interrupts. |
   | **6** | **ES** (Serial Interrupt Enable) - Enables serial communication interrupts. |
   | **5** | **ET1** (Timer 1 Interrupt Enable) - Enables Timer 1 interrupt. |
   | **4** | **EX1** (External Interrupt 1 Enable) - Enables INT1 interrupt. |
   | **3** | **ET0** (Timer 0 Interrupt Enable) - Enables Timer 0 interrupt. |
   | **2** | **EX0** (External Interrupt 0 Enable) - Enables INT0 interrupt. |
   | **1-0** | Reserved |

2. **Interrupt Priority Register (IP)**:  
   This register controls the priority of interrupts. Higher priority interrupts can interrupt lower priority ones if both are pending.

   | Bit | Description                |
   |-----|----------------------------|
   | **7** | **PS** (Serial Interrupt Priority) - Controls priority of serial interrupt. |
   | **6** | **PT1** (Timer 1 Interrupt Priority) - Controls priority of Timer 1 interrupt. |
   | **5** | **PX1** (External Interrupt 1 Priority) - Controls priority of INT1 interrupt. |
   | **4** | **PT0** (Timer 0 Interrupt Priority) - Controls priority of Timer 0 interrupt. |
   | **3** | **PX0** (External Interrupt 0 Priority) - Controls priority of INT0 interrupt. |
   | **2-0** | Reserved |

---

### **Interrupt Vector Table**

When an interrupt is triggered, the **8051** microcontroller uses the interrupt vector table to jump to the appropriate memory location for the Interrupt Service Routine (ISR). Each interrupt source is mapped to a specific address in the memory:

| Interrupt Source        | Vector Address (16-bit)   | Description                              |
|-------------------------|---------------------------|------------------------------------------|
| **INT0 (External 0)**    | **0x0003**                | Address of the ISR for INT0.             |
| **T0 (Timer 0)**         | **0x000B**                | Address of the ISR for Timer 0 overflow. |
| **INT1 (External 1)**    | **0x0013**                | Address of the ISR for INT1.             |
| **T1 (Timer 1)**         | **0x001B**                | Address of the ISR for Timer 1 overflow. |
| **Serial (RI/TI)**       | **0x0023**                | Address of the ISR for Serial Communication. |

When an interrupt occurs, the **8051** looks up the interrupt source and jumps to the corresponding memory location. The interrupt service routine (ISR) must be programmed to handle the interrupt and then return control to the main program.

---

### **Interrupt Priorities**

In the **8051 microcontroller**, interrupts can have priorities, but the priority handling is **fixed** in the standard **8051**:

- **External interrupts (INT0 and INT1)**: These have the **lowest priority**.
- **Timer interrupts (T0 and T1)**: These also have **low priority**, but they can interrupt the external interrupts if needed.
- **Serial interrupt (RI/TI)**: This has the **highest priority**.

However, the **8051** supports **maskable interrupts**, meaning that they can be disabled globally by setting the **EA** bit of the **IE register** to **0**.

---

### **Interrupt Handling Process**

1. **Interrupt Request**:  
   An interrupt request (IRQ) is generated by a source such as an external device or a timer overflow.

2. **Interrupt Acknowledgment**:  
   If the interrupt is enabled and globally unmasked (EA = 1), the microcontroller acknowledges the interrupt and jumps to the corresponding ISR.

3. **ISR Execution**:  
   The microcontroller executes the **interrupt service routine (ISR)**. This is a special piece of code written to handle the interrupt (e.g., reading data, changing output, etc.).

4. **Return from Interrupt**:  
   After completing the ISR, the **8051** returns to the main program by executing a **RET** instruction. This restores the program counter to where it was before the interrupt occurred.

---

### **Example: External Interrupt 0 (INT0)**

Assume an external interrupt (e.g., a button press) is connected to **INT0** (P3.2).

1. When a button is pressed, an interrupt request is sent to **INT0**.
2. The **8051** acknowledges the interrupt and jumps to the ISR located at **0x0003** (address for INT0).
3. The ISR executes a predefined set of operations (e.g., toggle a light, read a sensor, etc.).
4. After the ISR completes, the **8051** continues executing the main program from where it was interrupted.

---

### **Conclusion**

Interrupts in the **8051 microcontroller** are essential for making the system responsive to real-time events such as external signals, timer overflows, or serial data transmission. By enabling and managing interrupts, you can build more efficient systems that react to inputs without constantly polling or checking for events. The **8051** offers a robust interrupt structure with various sources and priorities, allowing you to customize the handling of different events based on your application's requirements.
