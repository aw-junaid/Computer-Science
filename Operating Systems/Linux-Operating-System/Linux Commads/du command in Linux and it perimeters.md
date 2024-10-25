The `du` command in Linux is used to estimate and display disk usage information for files and directories. It provides details about the disk space consumed by each file and directory, including the total size occupied by the specified directory and its subdirectories.

The basic syntax of the `du` command is as follows:

```
du [options] [directories]
```

Here's a table explaining the main parameters and options of the `du` command:

| Parameter/Option | Description                                                                                           |
|------------------|-------------------------------------------------------------------------------------------------------|
| directories      | Optional. Specifies the directories for which you want to see disk usage. If not given, the current directory is used. Multiple directories can be specified. |
| -h, --human-readable | Print sizes in human-readable format (e.g., 1K, 234M, 2G).                                          |
| -H, --si         | Like -h, but uses powers of 1000 instead of 1024.                                                   |
| -s, --summarize  | Display only the total size of each specified directory.                                            |
| -c, --total      | Produce a grand total of the disk usage for all specified directories.                              |
| -t, --threshold  | Set a size threshold; smaller items are not shown.                                                   |
| --max-depth=N    | Limit the depth of the directory tree that `du` will display.                                       |
| --help           | Display help and exit.                                                                              |
| --version        | Output version information and exit.                                                                |

Now, let's see some examples of how to use the `du` command:

1. Display disk usage for the current directory:

```bash
du
```

This will show the disk usage of the current directory and its subdirectories.

2. Display disk usage in human-readable format:

```bash
du -h
```

This will display disk usage with sizes in a human-readable format (e.g., 1K, 234M, 2G).

3. Display disk usage using powers of 1000:

```bash
du -H
```

This will display disk usage using powers of 1000 instead of the default 1024.

4. Display only the total size of each specified directory:

```bash
du -s /home/user1 /home/user2
```

This will show the total size of `/home/user1` and `/home/user2` directories separately.

5. Produce a grand total of the disk usage for all specified directories:

```bash
du -c /var/log /var/cache
```

This will display the disk usage of both `/var/log` and `/var/cache` directories separately and provide a grand total of their disk usage.

6. Set a size threshold to display items larger than a certain size:

```bash
du --threshold=1M /home/user3
```

This will show disk usage only for items larger than 1 megabyte (1M) within the `/home/user3` directory.

7. Limit the depth of the directory tree that `du` will display:

```bash
du --max-depth=2 /opt
```

This will display disk usage for the `/opt` directory and its immediate subdirectories.

The `du` command is useful for analyzing disk space usage, identifying large files or directories, and monitoring storage usage across the file system. It helps users and system administrators identify potential disk space issues and take necessary actions to manage disk space efficiently.
