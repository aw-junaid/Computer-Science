The `df` command in Linux is used to display disk space usage information for file systems mounted on the system. It provides details about the total disk space, used space, available space, and the file system's mount point.

The basic syntax of the `df` command is as follows:

```
df [options] [directory]
```

Here's a table explaining the main parameters and options of the `df` command:

| Parameter/Option | Description                                                                                         |
|------------------|-----------------------------------------------------------------------------------------------------|
| directory        | Optional. Specifies the directory or mount point for which you want to see disk space usage.        |
| -h, --human-readable | Print sizes in human-readable format (e.g., 1K, 234M, 2G).                                          |
| -H, --si         | Like -h, but uses powers of 1000 instead of 1024.                                                   |
| -T, --print-type | Print the file system type.                                                                         |
| -t, --type       | Limit the display to file systems of specific types (comma-separated).                              |
| --help           | Display help and exit.                                                                              |
| --version        | Output version information and exit.                                                                |

Now, let's see some examples of how to use the `df` command:

1. Display disk space usage for all mounted file systems:

```bash
df
```

This will show the disk space usage for all file systems mounted on the system.

2. Display disk space usage in human-readable format:

```bash
df -h
```

This will show disk space usage with sizes in a human-readable format (e.g., 1K, 234M, 2G).

3. Display disk space usage using powers of 1000:

```bash
df -H
```

This will display disk space usage using powers of 1000 instead of the default 1024.

4. Print the file system type along with disk space usage:

```bash
df -T
```

This will show the file system type for each mounted file system.

5. Limit the display to specific file system types (e.g., ext4, nfs):

```bash
df -t ext4,nfs
```

This will display disk space usage only for file systems of types ext4 and nfs.

6. Display disk space usage for a specific directory:

```bash
df /home
```

This will show the disk space usage for the /home directory.

The `df` command is useful for monitoring disk space usage and identifying file systems that may be running out of space. It helps administrators and users understand the disk space distribution across different partitions and file systems, allowing them to take appropriate actions to free up space or manage storage efficiently.
