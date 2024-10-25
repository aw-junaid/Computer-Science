The `umask` command in Linux is used to set the default file permission mask for newly created files and directories. It helps control the permissions that are automatically applied when a new file or directory is created. The `umask` value is subtracted from the maximum permissions (usually 666 for files and 777 for directories) to determine the final permissions for the newly created files and directories.

Here's a table explaining the `umask` command parameters and options:

| Parameter  | Description                                        |
|------------|----------------------------------------------------|
| -S, --symbolic | Display the umask value in symbolic form (e.g., u=rwx, g=rx, o=rx). |
| -p, --pretty   | Display the umask value in a human-readable format (e.g., 0022).    |
| --help     | Display help information about the `umask` command.    |

Now, let's see some examples of how to use the `umask` command:

1. Set the `umask` value using an octal representation:

```bash
umask 0022
```

In this example, the `umask` value is set to `0022`, meaning that newly created files will have permissions of `644` (666 - 0022) and directories will have permissions of `755` (777 - 0022).

2. Set the `umask` value using a symbolic representation:

```bash
umask u=rwx,g=rx,o=rx
```

In this example, the `umask` value is set to `u=rwx,g=rx,o=rx`, meaning that newly created files will have permissions of `755` (777 - u=rwx) and directories will have permissions of `755` (777 - u=rwx).

3. Display the current `umask` value in symbolic form:

```bash
umask -S
```

Output:
```
u=rwx,g=rx,o=rx
```

This command displays the current `umask` value in symbolic form, showing the permissions that will be removed when creating new files and directories.

4. Display the current `umask` value in a human-readable format:

```bash
umask -p
```

Output:
```
0022
```

This command displays the current `umask` value in a human-readable format (octal representation).

By setting the appropriate `umask` value, you can control the default permissions for newly created files and directories, ensuring the security and privacy of sensitive data and avoiding unnecessary exposure of files and directories to other users.
