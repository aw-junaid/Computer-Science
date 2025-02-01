# **Uniprocessor Scheduling**

**Uniprocessor scheduling** refers to the management of the CPU in a system that has a single processing unit (or processor). The goal of uniprocessor scheduling is to allocate CPU time efficiently among different processes or tasks to ensure that the system performs well, meets deadlines (in real-time systems), and maximizes CPU utilization. It involves selecting which process will run on the CPU at any given time, ensuring that the system remains responsive and efficient.

### **Key Concepts in Uniprocessor Scheduling**

1. **Process States**
   - **Ready**: A process that is ready to execute, waiting for CPU time.
   - **Running**: A process that is currently executing on the CPU.
   - **Blocked/Waiting**: A process that is waiting for an event (e.g., I/O) to occur before it can proceed.

2. **Scheduling Criteria**
   - **CPU Utilization**: The percentage of time the CPU is being used for executing processes.
   - **Throughput**: The number of processes completed in a given time frame.
   - **Turnaround Time**: The total time taken for a process to complete, from submission to completion.
   - **Waiting Time**: The time a process spends in the ready queue waiting to be executed.
   - **Response Time**: The time it takes from submitting a request until the system starts responding (important in interactive systems).
   - **Fairness**: Ensuring that all processes get a fair share of the CPU.

3. **CPU Scheduling Algorithms**
   Scheduling algorithms are used to decide which process will run next. Here are some common types of CPU scheduling algorithms:

### **Types of Scheduling Algorithms**

1. **First-Come, First-Served (FCFS) Scheduling**
   - **FCFS** is the simplest scheduling algorithm where processes are executed in the order they arrive in the ready queue.
   - **Advantages**:
     - Simple and easy to implement.
   - **Disadvantages**:
     - **Convoy Effect**: Long processes can delay short processes.
     - Not optimal for average waiting time.

2. **Shortest Job Next (SJN) / Shortest Job First (SJF) Scheduling**
   - **SJF** schedules processes based on the length of their next CPU burst. The process with the shortest burst time is selected next.
   - **Preemptive version** is called **Shortest Remaining Time First (SRTF)**.
   - **Advantages**:
     - Minimizes average waiting time.
     - Optimal for processes with predictable CPU bursts.
   - **Disadvantages**:
     - Requires knowledge of the process’s next CPU burst, which is often not available.
     - Starvation of longer processes can occur.

3. **Round Robin (RR) Scheduling**
   - **RR** is a preemptive scheduling algorithm where each process is assigned a fixed time slice or quantum. After the time quantum expires, the process is moved to the end of the ready queue, and the next process is scheduled.
   - **Advantages**:
     - Fair and ensures that all processes get a fair share of CPU time.
     - Good for time-sharing systems.
   - **Disadvantages**:
     - The time quantum must be carefully chosen. If it’s too small, the system might spend too much time on context switching; if it’s too large, the system might behave like FCFS.

4. **Priority Scheduling**
   - **Priority Scheduling** assigns a priority to each process, and the process with the highest priority is executed first.
   - **Preemptive version** allows a process with higher priority to preempt a running process.
   - **Advantages**:
     - Can be tailored to give more important processes higher priority.
   - **Disadvantages**:
     - **Starvation** can occur for low-priority processes.
     - It can be difficult to determine the right priority values.

5. **Multilevel Queue Scheduling**
   - **Multilevel Queue Scheduling** divides processes into different queues based on their properties (e.g., foreground vs background, interactive vs batch). Each queue has its own scheduling algorithm.
   - **Advantages**:
     - Provides flexibility in scheduling based on process types.
   - **Disadvantages**:
     - Complex to implement and manage.

6. **Multilevel Feedback Queue Scheduling**
   - A variant of **multilevel queue scheduling**, **Multilevel Feedback Queue (MLFQ)** allows processes to move between queues based on their behavior (e.g., time spent in CPU).
   - It is designed to prioritize interactive tasks while ensuring that CPU-bound tasks eventually get CPU time.
   - **Advantages**:
     - Can dynamically adjust priorities based on process behavior, providing better responsiveness and fairness.
   - **Disadvantages**:
     - Complex to implement and tune the parameters for queue demotion and promotion.

### **Context Switching**

- **Context switching** occurs when the CPU switches from executing one process to another. During a context switch, the state (context) of the current process is saved, and the state of the next process is loaded.
- Context switching introduces overhead, so the system tries to minimize unnecessary context switches.
- Efficient context switching is important in preemptive scheduling algorithms like Round Robin and Priority Scheduling.

### **Preemptive vs. Non-preemptive Scheduling**

- **Preemptive Scheduling**: The operating system can forcibly take the CPU away from a running process in favor of another. Algorithms like Round Robin and Priority Scheduling (preemptive) are preemptive.
  - **Advantages**: 
    - Better response times for interactive applications.
    - Improved fairness in allocating CPU time.
  - **Disadvantages**: 
    - Can cause higher overhead due to frequent context switching.
  
- **Non-preemptive Scheduling**: Once a process starts running, it runs to completion or until it voluntarily yields the CPU. FCFS and non-preemptive Priority Scheduling are examples.
  - **Advantages**:
    - Lower overhead as context switching is less frequent.
  - **Disadvantages**:
    - Poor response time for interactive systems.
    - Possibility of process starvation.

### **Scheduling in Real-Time Systems**

In real-time systems, certain processes must complete by specific deadlines. These systems often use real-time scheduling algorithms, such as:

1. **Rate Monotonic Scheduling (RMS)**
   - Processes are assigned priorities based on their periodicity. The process with the shortest period gets the highest priority.
   - **Advantages**:
     - Simple and predictable.
   - **Disadvantages**:
     - Can lead to poor CPU utilization in certain cases.

2. **Earliest Deadline First (EDF) Scheduling**
   - Processes with the earliest deadlines are given the highest priority.
   - **Advantages**:
     - Optimal in terms of meeting deadlines.
   - **Disadvantages**:
     - Difficult to implement efficiently.

### **Performance Metrics**

- **CPU Utilization**: The percentage of time the CPU is actively executing processes.
- **Turnaround Time**: The time taken from when a process is submitted until it completes.
- **Waiting Time**: The total time a process spends waiting in the ready queue.
- **Response Time**: The time between submitting a request and receiving the first response (important for interactive systems).

### **Summary**

Uniprocessor scheduling is a key part of operating systems, determining how the single CPU is allocated to various processes. The effectiveness of scheduling algorithms can significantly impact system performance, responsiveness, and efficiency. The choice of scheduling algorithm depends on system requirements, such as fairness, throughput, turnaround time, and responsiveness. Key algorithms include FCFS, Round Robin, SJF, and Priority Scheduling, each with their own advantages and drawbacks. In addition, real-time systems require specialized algorithms like Rate Monotonic Scheduling and Earliest Deadline First to meet stringent timing requirements.
