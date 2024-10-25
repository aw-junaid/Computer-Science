The `nice` command in Linux is used to run a program with a specified priority. It allows you to adjust the scheduling priority of a process, which determines how much CPU time the process will receive compared to other processes on the system. The `nice` command is often used to set a lower or higher priority for a process, affecting its CPU usage and responsiveness.

The basic syntax of the `nice` command is as follows:

```
nice [OPTION] [COMMAND [ARG]...]
```

Here's a table explaining the main parameters and options of the `nice` command:

| Parameter/Option | Description                                                                                                                     |
|------------------|---------------------------------------------------------------------------------------------------------------------------------|
| -n, --adjustment | Specifies the priority adjustment value. The lower the value, the higher the priority (range: -20 to 19, default: 10).        |
| --help           | Display help and exit.                                                                                                          |
| --version        | Output version information and exit.                                                                                            |

Now, let's see some examples of how to use the `nice` command:

1. Run a program with a specific priority:

```bash
nice -n 10 command
```

This will run the `command` with a priority of 10, which is the default nice value. It means the process will have a normal priority.

2. Run a program with a lower priority:

```bash
nice -n 15 command
```

This will run the `command` with a priority of 15, which is a lower value. The process will be given less CPU time compared to other processes.

3. Run a program with a higher priority:

```bash
nice -n -5 command
```

This will run the `command` with a priority of -5, which is a higher value. The process will be given more CPU time, making it more responsive.

4. Check the current priority of a process:

```bash
nice -n command
```

This will display the current priority (nice value) of the `command` without actually running it.

The `nice` command is commonly used when running CPU-intensive tasks, background processes, or tasks that should have a specific priority in terms of CPU usage. It is often utilized in combination with other commands to control process scheduling on the system.
