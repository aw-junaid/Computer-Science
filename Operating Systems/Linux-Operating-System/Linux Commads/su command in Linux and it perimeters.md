The `su` command in Linux is used to switch or substitute users, allowing you to log in as a different user without logging out from the current session. By default, it switches to the superuser (root) account, but it can also be used to switch to any other user, provided you have the necessary credentials or privileges.

The basic syntax of the `su` command is as follows:

```
su [options] [username]
```

Here's a table explaining the main parameters and options of the `su` command:

| Parameter/Option | Description                                                                                                        |
|------------------|--------------------------------------------------------------------------------------------------------------------|
| username         | Optional. Specifies the username of the user to whom you want to switch (defaults to the root user if not given).  |
| -c command       | Execute a single command as the specified user (requires root access).                                              |
| -s shell         | Specify an alternative shell to use for the target user (requires root access).                                      |
| --help           | Display help and exit.                                                                                            |
| --version        | Output version information and exit.                                                                              |

Now, let's see some examples of how to use the `su` command:

1. Switch to the root user (superuser):

```bash
su
```

This will prompt you to enter the root user's password. After successful authentication, you will be logged in as the root user.

2. Switch to a different user (e.g., john):

```bash
su john
```

This will prompt you to enter the password for the user `john`. After successful authentication, you will be logged in as the user `john`.

3. Execute a single command as the root user:

```bash
su -c "ls /root"
```

This will run the `ls /root` command as the root user without switching to the root user's interactive shell.

4. Switch to a different user and specify an alternative shell:

```bash
su -s /bin/bash jane
```

This will switch to the user `jane` and use `/bin/bash` as the shell for the new session.

5. Open a login shell for the root user (source the root user's profile):

```bash
su -
```

This will switch to the root user and open a login shell, similar to `su` without any arguments.

The `su` command is commonly used to perform administrative tasks that require elevated privileges or to access resources limited to specific users. It's important to use the `su` command responsibly and only when necessary, as it grants full access to the target user's environment and files. Additionally, ensure that you have the correct credentials and permissions before using the `su` command.
