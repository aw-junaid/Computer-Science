The `at` command in Linux is used to schedule one-time or recurring tasks to be executed at a specified time. It allows users to run commands or scripts at a later time without the need for them to be actively logged in or the terminal to be open.

The basic syntax of the `at` command is as follows:

```
at <time> [options]
```

Here's a table explaining the main parameters and options of the `at` command:

| Parameter       | Description                                                                                                  |
|-----------------|--------------------------------------------------------------------------------------------------------------|
| time            | Specifies the time at which the command should be executed. The time can be specified in various formats.  |
| -f <file>       | Reads the command to be executed from the specified file instead of reading from standard input.           |
| -m              | Sends an email to the user after the command is executed.                                                  |
| -q <queue>      | Specifies the scheduling queue for the job (by default, it uses `a` queue for immediate execution).        |
| -l              | Lists the user's pending jobs.                                                                              |
| -d <job>        | Deletes the specified job from the queue.                                                                   |
| -V              | Display version information and exit.                                                                       |
| -h              | Display help and exit.                                                                                      |

Now, let's see some examples of how to use the `at` command:

1. Schedule a command to be executed at a specific time:

```bash
at 2:30 PM
at> echo "Hello, this is a scheduled task" > ~/task_output.txt
at> <EOT>
```

This example will execute the `echo` command and write "Hello, this is a scheduled task" to the `task_output.txt` file at 2:30 PM.

2. Schedule a command to be executed at a specific date and time:

```bash
at 8:00 AM tomorrow
at> /path/to/my_script.sh
at> <EOT>
```

This example will execute the `my_script.sh` script at 8:00 AM tomorrow.

3. Schedule a command to be executed and send an email notification:

```bash
at 10:00 PM
at> echo "Backup completed" | mail -s "Backup Status" user@example.com
at> <EOT>
```

This example will execute the `echo` command and send an email with the message "Backup completed" to `user@example.com` at 10:00 PM.

4. List the user's pending jobs:

```bash
at -l
```

This command will list all the pending `at` jobs scheduled by the current user.

5. Delete a pending job:

```bash
at -d 1
```

This command will delete the `at` job with ID 1 from the queue.

The `at` command is a useful tool for scheduling one-time or recurring tasks in Linux, making it convenient for automation and task management.
