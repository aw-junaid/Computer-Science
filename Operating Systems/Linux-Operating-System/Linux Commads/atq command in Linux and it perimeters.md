The `atq` command in Linux is used to display a list of pending `at` jobs in the queue. When you schedule tasks using the `at` command, they are added to a queue to be executed at the specified time or date. The `atq` command allows you to view the list of pending jobs in the queue.

The basic syntax of the `atq` command is as follows:

```
atq [options]
```

Here's a table explaining the main parameters and options of the `atq` command:

| Parameter       | Description                                                                                   |
|-----------------|-----------------------------------------------------------------------------------------------|
| -q <queue>      | Display jobs in the specified queue (by default, it shows jobs in all queues).               |
| --help          | Display help and exit.                                                                        |
| --version       | Output version information and exit.                                                          |

Now, let's see some examples of how to use the `atq` command:

1. Display all pending `at` jobs in all queues:

```bash
atq
```

Sample output:
```
1   Tue Jul 20 15:30:00 2023 a user
2   Tue Jul 20 17:00:00 2023 a user
```

In this example, two `at` jobs are in the queue, and their details, including job ID, execution time, and owner (user), are displayed.

2. Display pending `at` jobs in a specific queue:

```bash
atq -q a
```

Sample output:
```
1   Tue Jul 20 15:30:00 2023 a user
```

This command will display pending `at` jobs in the `a` queue.

3. Display pending `at` jobs in all queues with timestamps:

```bash
atq -n
```

Sample output:
```
1   2023-07-20 15:30 a user
2   2023-07-20 17:00 a user
```

This command will show pending `at` jobs in all queues along with the date and time of execution.

The `atq` command is useful for checking which jobs are scheduled for future execution. You can use it to verify the status of scheduled tasks and make adjustments as needed.
