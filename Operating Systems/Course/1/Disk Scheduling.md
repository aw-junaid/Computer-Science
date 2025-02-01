**Disk Scheduling** refers to the method by which an operating system decides the order in which pending disk I/O requests (read or write operations) are processed. The primary goal of disk scheduling is to optimize the time it takes for the disk's read/write head to fulfill multiple requests, as disk operations can be relatively slow compared to CPU operations. Efficient scheduling helps minimize disk seek time, rotational latency, and overall response time.

### Key Concepts of Disk Scheduling

1. **Seek Time**:
   - The time it takes for the disk's read/write head to move to the track where data needs to be read or written.
   - Minimizing seek time is a major goal of disk scheduling algorithms.

2. **Rotational Latency**:
   - The time it takes for the disk platter to rotate and position the correct sector under the read/write head. It's related to the speed of the disk rotation (measured in RPM - Revolutions Per Minute).
   - This time can be reduced by organizing disk requests efficiently.

3. **Throughput**:
   - The total amount of data transferred over a period of time, often a key metric for disk performance.
   - Disk scheduling aims to maximize throughput while minimizing time spent waiting for the disk.

4. **Disk Arm Movement**:
   - The movement of the read/write arm is crucial in determining how fast I/O operations are completed.
   - Minimizing unnecessary arm movements between requests can significantly reduce overall disk I/O time.

---

### Disk Scheduling Algorithms

Disk scheduling algorithms aim to reduce the movement of the disk arm and, thereby, minimize seek time and rotational latency. Here are some of the most common disk scheduling algorithms:

---

#### 1. **First-Come, First-Served (FCFS)**

- **Description**: The simplest disk scheduling algorithm. Requests are processed in the order they arrive in the queue, without any reordering.
- **Advantages**: 
  - Easy to implement.
  - Fair, as each request is processed in the order it arrives.
- **Disadvantages**:
  - May result in inefficient disk arm movement, leading to longer seek times.
  - Can suffer from the "convoy effect," where a single request at the beginning of the queue delays all other requests.

---

#### 2. **Shortest Seek Time First (SSTF)**

- **Description**: The disk arm moves to the request that is closest to its current position (minimizing the seek time for each request).
- **Advantages**:
  - Reduces seek time on average compared to FCFS.
  - Efficient for workloads where requests are localized (i.e., close together).
- **Disadvantages**:
  - **Starvation**: Requests that are far from the current position may get starved (never processed), especially if new requests continuously arrive close to the current position.
  - May lead to poor performance in cases with widely scattered requests.

---

#### 3. **SCAN (Elevator Algorithm)**

- **Description**: The disk arm moves in one direction (either outward or inward) fulfilling all requests until it reaches the end of the disk, then reverses direction and processes the remaining requests.
- **Advantages**:
  - More efficient than FCFS, especially when requests are scattered across the disk.
  - Minimizes the movement of the disk arm by sweeping in one direction at a time.
- **Disadvantages**:
  - Starvation can occur for requests near the middle of the disk if the arm keeps moving toward the edges.
  - Not as optimal as some other algorithms in terms of average seek time.

---

#### 4. **C-SCAN (Circular SCAN)**

- **Description**: A variant of the SCAN algorithm, where the disk arm only moves in one direction (e.g., from the outermost track to the innermost track) and when it reaches the end, it jumps back to the beginning and starts again.
- **Advantages**:
  - Fairer than SCAN because requests at the far edges of the disk are processed.
  - Reduces the possibility of starvation.
- **Disadvantages**:
  - While it avoids the back-and-forth movement of SCAN, the "jumping" back to the starting position introduces some additional time overhead.
  
---

#### 5. **LOOK**

- **Description**: Similar to SCAN, but instead of always moving to the edges of the disk, the disk arm only moves as far as the last request in the current direction, then reverses.
- **Advantages**:
  - Reduces unnecessary movement to the disk’s ends, making it more efficient than SCAN in many cases.
  - Like SCAN, it minimizes seek time by moving toward the nearest request.
- **Disadvantages**:
  - Can still lead to starvation in certain cases, although not as severe as with SSTF.

---

#### 6. **C-LOOK (Circular LOOK)**

- **Description**: A variant of LOOK, where the arm moves to the furthest request in the current direction, then jumps directly to the closest request in the other direction, avoiding unnecessary movement.
- **Advantages**:
  - Efficient, as it avoids going to the far ends of the disk, while still processing all requests.
  - Reduces the time spent on disk arm movement compared to SCAN and LOOK.
- **Disadvantages**:
  - Similar to C-SCAN, the jumping back to the starting position introduces additional overhead.

---

#### 7. **Weighted Shortest Seek Time First (WSSTF)**

- **Description**: A variant of SSTF that assigns weights to requests based on their urgency or priority. The disk arm moves to the request with the shortest weighted seek time.
- **Advantages**:
  - Allows prioritization of certain requests, such as more time-sensitive operations.
  - Can be useful in environments where some requests have higher priority than others.
- **Disadvantages**:
  - More complex to implement than simple SSTF.
  - Can still suffer from starvation.

---

### Key Considerations in Disk Scheduling

1. **Request Arrival Patterns**:
   - In systems where I/O requests arrive in a burst, algorithms like SCAN or LOOK may outperform FCFS by avoiding long seek times between requests.
   - In scenarios where requests are evenly distributed across the disk, SSTF may lead to more efficient disk usage.

2. **Starvation**:
   - Some algorithms, like SSTF, are prone to starvation, where certain requests may never be processed because the disk arm constantly services closer requests. Scheduling algorithms like C-SCAN and C-LOOK help reduce starvation by periodically processing requests from all areas of the disk.

3. **Fairness**:
   - While FCFS is the fairest algorithm (every request is processed in order), others like SSTF, SCAN, and LOOK may prioritize certain requests over others, which could impact fairness.

4. **Throughput and Latency**:
   - Disk throughput (the rate at which data can be transferred) and latency (the time it takes to fulfill a request) are two critical metrics impacted by disk scheduling algorithms.
   - Efficient scheduling minimizes latency, thereby improving the overall performance of the system.

---

### Conclusion

Disk scheduling plays a crucial role in the performance of I/O-bound systems, especially when there are many requests for disk access. While simple algorithms like FCFS may be easy to implement, they can lead to inefficiencies. More advanced algorithms like SSTF, SCAN, and C-SCAN are often used to improve seek time and throughput, especially in high-performance environments. 

Choosing the right disk scheduling algorithm depends on the specific characteristics of the workload and the system requirements, such as the importance of fairness, the need to reduce seek time, and how requests are distributed across the disk.
