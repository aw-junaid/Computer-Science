### Resource Management with Control Groups (cgroups) in Linux

Control Groups (cgroups) is a Linux kernel feature that allows the allocation and management of resources (CPU, memory, disk I/O, etc.) for processes. It allows administrators to limit, prioritize, and monitor resource usage on a per-process basis or for groups of processes.

In modern Linux systems, **systemd** integrates with cgroups to manage resources efficiently. This integration enables resource control on system services and processes in a structured and unified way.

### Key Concepts of cgroups:
1. **Cgroups (Control Groups)**: A mechanism for limiting, prioritizing, accounting for, and isolating resource usage of collections of processes.
2. **Subsystems (Controllers)**: Different types of resources that can be controlled, such as CPU, memory, block I/O, etc.
3. **Cgroup Hierarchy**: A tree structure where each node in the tree represents a group of processes, and resources are allocated to the processes in the node.

### Main Controllers (Subsystems) in cgroups:
- **cpu**: Controls CPU usage for processes.
- **memory**: Limits memory usage for processes.
- **blkio**: Controls block I/O (disk read/write) operations.
- **cpuset**: Assigns processes to specific CPUs or NUMA nodes.
- **devices**: Controls access to devices.
- **pids**: Limits the number of processes or threads that can be created.
- **freezer**: Suspends or resumes groups of processes.
- **net_cls**: Controls network bandwidth for processes.

---

### Managing Resources Using cgroups

#### 1. **Cgroup Basics:**
Cgroups are typically used to organize and control process groups. These groups can be limited in terms of resource usage, prioritized, and monitored.

#### 2. **Creating a Cgroup for Resource Management**

You can create and manage cgroups using the `/sys/fs/cgroup` directory, which is the default location for cgroup configurations in Linux.

1. **View existing cgroups**:
   You can see the current cgroups and their controllers by checking:
   ```bash
   ls /sys/fs/cgroup/
   ```

2. **Create a new cgroup**:
   To create a new cgroup for managing resources, you first need to choose which controller you want to use (e.g., `cpu`, `memory`).

   Example: Create a cgroup to manage CPU resources:
   ```bash
   sudo mkdir /sys/fs/cgroup/cpu/my_cgroup
   ```

3. **Set resource limits for the cgroup**:
   Once the cgroup is created, you can set resource limits.

   Example: Limit the CPU usage to 50% for the `my_cgroup`:
   ```bash
   echo 50000 > /sys/fs/cgroup/cpu/my_cgroup/cpu.cfs_quota_us
   ```

   This limits the CPU usage of the `my_cgroup` to 50% (50000 microseconds of every 100000 microseconds).

4. **Add processes to the cgroup**:
   You can add processes to a cgroup by writing their process IDs (PIDs) to the `cgroup.procs` file inside the cgroup directory.

   Example:
   ```bash
   echo <PID> > /sys/fs/cgroup/cpu/my_cgroup/cgroup.procs
   ```
   Replace `<PID>` with the process ID of the application you want to control.

---

### 3. **Managing Resources Using `systemd` and cgroups**

Since `systemd` uses cgroups under the hood, you can manage resources for services in a more user-friendly way using `systemctl` and `systemd` unit files. This avoids manually interacting with cgroup files.

#### 3.1. **Resource Management with `systemd`**

To manage resource limits on services (such as CPU, memory, and disk I/O), you can configure the `systemd` unit files.

1. **Edit the Service Unit File**:
   Use `systemctl` to override the unit file for a service (e.g., `httpd` for Apache).

   ```bash
   sudo systemctl edit httpd
   ```

   This opens an editor to modify the unit file with the `[Service]` section, where you can add resource control parameters.

2. **Add Resource Management Parameters**:
   You can add various parameters to limit the resource usage of the service:

   - **CPU Limit (`CPUQuota`)**: Limits the percentage of CPU the service can use.
     ```ini
     [Service]
     CPUQuota=50%
     ```

   - **Memory Limit (`MemoryMax`)**: Limits the maximum amount of memory the service can use.
     ```ini
     [Service]
     MemoryMax=512M
     ```

   - **I/O Limit (`IOWeight`)**: Controls how much I/O bandwidth the service gets relative to others.
     ```ini
     [Service]
     IOWeight=500
     ```

   - **CPU Affinity (`CPUAffinity`)**: Assigns the service to specific CPUs.
     ```ini
     [Service]
     CPUAffinity=0 1
     ```

   - **Limit Open Files (`LimitNOFILE`)**: Controls the maximum number of open files for the service.
     ```ini
     [Service]
     LimitNOFILE=1024
     ```

3. **Reload `systemd` and Restart the Service**:
   After modifying the unit file, reload the `systemd` configuration and restart the service to apply the resource limits:
   ```bash
   sudo systemctl daemon-reload
   sudo systemctl restart httpd
   ```

---

### 4. **Using cgroups with `cgcreate` and `cgexec` (Legacy)**

In older systems or if not using `systemd`, you can directly create and manage cgroups using the `cgroup-tools` package, which includes `cgcreate` and `cgexec`.

1. **Install cgroup-tools**:
   Install the `cgroup-tools` package if not already installed:
   ```bash
   sudo yum install libcgroup
   ```

2. **Create a cgroup**:
   Use the `cgcreate` command to create a new cgroup.

   Example: Create a cgroup named `my_cgroup` under the `cpu` subsystem:
   ```bash
   sudo cgcreate -g cpu:/my_cgroup
   ```

3. **Set Resource Limits**:
   Set a CPU limit for the cgroup:
   ```bash
   sudo cgset -r cpu.cfs_quota_us=50000 my_cgroup
   ```

4. **Execute a Command with Resource Limits**:
   Use `cgexec` to run a command under the resource constraints of the cgroup:
   ```bash
   sudo cgexec -g cpu:/my_cgroup <command>
   ```

   Replace `<command>` with the process or command you want to run within the cgroup.

---

### 5. **Monitoring cgroup Resource Usage**

To monitor the resource usage of processes in a cgroup, you can use the following tools:

1. **Check CPU usage of a cgroup**:
   View the current CPU usage of a cgroup by looking at the `cpuacct` statistics:
   ```bash
   cat /sys/fs/cgroup/cpu/my_cgroup/cpuacct.usage
   ```

2. **Monitor memory usage of a cgroup**:
   Check the memory usage of a cgroup:
   ```bash
   cat /sys/fs/cgroup/memory/my_cgroup/memory.usage_in_bytes
   ```

3. **Use `systemd-cgtop`**:
   The `systemd-cgtop` command can provide a real-time view of the resource usage of cgroups.
   ```bash
   sudo systemd-cgtop
   ```

4. **Use `top` with cgroups**:
   You can use `top` to filter processes by cgroup and see resource consumption by individual processes.

---

### 6. **Common Resource Management Commands**

| Command                                  | Description                                                                 |
|------------------------------------------|-----------------------------------------------------------------------------|
| `cgcreate -g <subsystem>:/<cgroup_name>`  | Create a new cgroup under a specified subsystem (e.g., CPU, memory).        |
| `cgset -r <parameter>=<value> <cgroup>`   | Set resource limits (e.g., CPU, memory) for a cgroup.                       |
| `cgexec -g <subsystem>:/<cgroup> <command>` | Run a command within a specific cgroup with resource limits.                |
| `systemd-cgtop`                          | Real-time monitoring of cgroup resource usage (CPU, memory, I/O).           |
| `cat /sys/fs/cgroup/<subsystem>/<cgroup>/cpuacct.usage` | View the CPU usage of a cgroup.                                           |
| `cat /sys/fs/cgroup/memory/my_cgroup/memory.usage_in_bytes` | View the memory usage of a cgroup.                                        |

---

### Conclusion

Control Groups (cgroups) provide a powerful and flexible way to manage system resources at the process level. With `systemd` integration, resource management for services becomes streamlined and manageable, offering administrators a simple way to enforce limits on CPU, memory, and I/O usage. 

Understanding cgroups and how they are integrated with `systemd` is essential for optimizing resource allocation and ensuring fair usage on multi-user systems.
