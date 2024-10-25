The `free` command in Linux is used to display information about the system's memory usage. It provides details about the total available memory, used memory, free memory, and swap space utilization.

The basic syntax of the `free` command is as follows:

```
free [options]
```

Here's a table explaining the main options of the `free` command:

| Option       | Description                                                                                         |
|--------------|-----------------------------------------------------------------------------------------------------|
| -h, --human  | Show memory sizes in a human-readable format (e.g., MB, GB).                                       |
| -k, --kilo   | Show memory sizes in kilobytes (KB). Default unit is kilobytes.                                     |
| -m, --mega   | Show memory sizes in megabytes (MB). Default unit is kilobytes.                                     |
| -g, --giga   | Show memory sizes in gigabytes (GB). Default unit is kilobytes.                                     |
| -b, --bytes  | Show memory sizes in bytes. Default unit is kilobytes.                                              |
| -t, --total  | Show a total line, including the sum of all memory values.                                         |
| -s N, --seconds N | Update the display every N seconds. Default is 3 seconds.                                          |
| -V, --version| Output version information and exit.                                                               |

Now, let's see some examples of how to use the `free` command:

1. Display memory usage in human-readable format (MB, GB):

```bash
free -h
```

This will show memory usage information in a human-readable format with sizes in MB and GB.

2. Display memory usage in kilobytes:

```bash
free -k
```

This will display memory usage information with sizes in kilobytes.

3. Display memory usage in megabytes:

```bash
free -m
```

This will display memory usage information with sizes in megabytes.

4. Display memory usage in gigabytes:

```bash
free -g
```

This will display memory usage information with sizes in gigabytes.

5. Display memory usage in bytes:

```bash
free -b
```

This will display memory usage information with sizes in bytes.

6. Display memory usage with a total line:

```bash
free -t
```

This will show memory usage information along with a total line that sums up all memory values.

7. Update the display every 5 seconds:

```bash
free -s 5
```

This will continuously update the memory usage display every 5 seconds.

The `free` command is a valuable tool for monitoring system memory usage and can help diagnose memory-related issues or performance bottlenecks. It provides essential information for understanding how memory is utilized on the system.
