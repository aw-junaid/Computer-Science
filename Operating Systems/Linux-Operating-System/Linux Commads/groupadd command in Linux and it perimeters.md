The `groupadd` command in Linux is used to create a new group on the system. Groups in Linux are used to manage sets of users with common access rights to files, directories, and other resources. The `groupadd` command allows system administrators to create new groups with specific group IDs (GIDs) and manage group-related settings.

The basic syntax of the `groupadd` command is as follows:

```
groupadd [options] <groupname>
```

Here's a table explaining the main parameters and options of the `groupadd` command:

| Parameter    | Description                                                                                    |
|--------------|------------------------------------------------------------------------------------------------|
| <groupname>  | Specifies the name of the group to be created.                                                  |
| -g <GID>     | Optional. Specifies the numeric group ID (GID) for the new group.                              |
| -r           | Optional. Creates a system group with a GID less than 1000.                                    |
| --help       | Display help and exit.                                                                        |
| --version    | Output version information and exit.                                                          |

Now, let's see some examples of how to use the `groupadd` command:

1. Create a new group with the default settings:

```bash
sudo groupadd developers
```

This command will create a new group named `developers` with a default GID assigned automatically.

2. Create a new group with a specific GID:

```bash
sudo groupadd -g 1001 marketing
```

This command will create a new group named `marketing` with a specific GID of `1001`.

3. Create a system group:

```bash
sudo groupadd -r sysadmins
```

This command will create a system group named `sysadmins` with a GID less than 1000. System groups are typically used for system-related tasks and should have GIDs lower than regular user groups.

4. Create multiple groups:

```bash
sudo groupadd sales finance hr
```

This command will create three groups named `sales`, `finance`, and `hr`.

Please note that the `groupadd` command is typically used with administrative privileges (using `sudo`) since creating groups requires superuser privileges. Additionally, the group ID (GID) should be unique and not clash with existing groups on the system. It's essential to choose appropriate GIDs to avoid conflicts and to follow best practices in managing user and group accounts on your Linux system.
