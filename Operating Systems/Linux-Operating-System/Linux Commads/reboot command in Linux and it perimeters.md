The `reboot` command in Linux is used to reboot or restart the system. It safely shuts down all running processes and then restarts the system, bringing it back up in a fresh state.

The basic syntax of the `reboot` command is as follows:

```
reboot [options]
```

Here's a table explaining the main options of the `reboot` command:

| Option   | Description                                                                                   |
|----------|-----------------------------------------------------------------------------------------------|
| --help   | Display help and exit.                                                                        |
| --version| Output version information and exit.                                                          |

Now, let's see some examples of how to use the `reboot` command:

1. Safely reboot the system:

```bash
reboot
```

This will initiate a system reboot, shutting down all running processes and restarting the system.

2. Reboot the system immediately without a delay:

```bash
reboot --no-wait
```

This will initiate an immediate reboot without any delay.

3. Display a warning message before rebooting:

```bash
reboot --message "The system will be rebooted in 5 minutes."
```

This will display the specified message as a warning before initiating the reboot.

Please note that the `reboot` command requires superuser (root) privileges to execute. It is important to ensure that you have saved any unsaved work and closed applications properly before initiating a system reboot.

The `reboot` command is a powerful tool for restarting the system and should be used with caution to avoid any data loss or disruption to running processes. It is typically used when you need to apply system updates, change system configurations, or troubleshoot certain issues that require a fresh start. Always use the `reboot` command responsibly and ensure that there are no critical tasks or ongoing processes that may be affected by the restart.
