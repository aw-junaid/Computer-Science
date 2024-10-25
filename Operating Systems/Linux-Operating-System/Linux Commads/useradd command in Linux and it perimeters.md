The `useradd` command in Linux is used to create a new user account on the system. It allows system administrators to add new users with specific user IDs (UIDs) and group IDs (GIDs), assign home directories, and set the default shell for the new user.

The basic syntax of the `useradd` command is as follows:

```
useradd [options] <username>
```

Here's a table explaining the main parameters and options of the `useradd` command:

| Parameter       | Description                                                                                                 |
|-----------------|-------------------------------------------------------------------------------------------------------------|
| <username>      | Specifies the username for the new user account.                                                            |
| -u <UID>        | Optional. Specifies the user ID (UID) for the new user account.                                              |
| -g <GID>        | Optional. Specifies the primary group ID (GID) for the new user account.                                     |
| -d <directory>  | Optional. Specifies the home directory for the new user account.                                             |
| -s <shell>      | Optional. Specifies the default shell for the new user account.                                              |
| -m             | Optional. Creates the home directory for the new user account if it does not exist.                          |
| -c <comment>    | Optional. Specifies a comment or description for the new user account.                                       |
| -e <expiry_date>| Optional. Specifies the account expiry date for the new user account in YYYY-MM-DD format.           |
| -r             | Optional. Creates a system account with a UID lower than 1000 and without a home directory.                  |
| --help          | Display help and exit.                                                                                     |
| --version       | Output version information and exit.                                                                       |

Now, let's see some examples of how to use the `useradd` command:

1. Create a new user with default settings:

```bash
sudo useradd john
```

This command will create a new user account with the username `john`. By default, the user ID (UID) will be automatically assigned, and the primary group will have the same name as the username (`john`).

2. Create a new user with custom UID and GID:

```bash
sudo useradd -u 1001 -g developers alice
```

This command will create a new user account with the username `alice`, a custom user ID (UID) of `1001`, and the primary group `developers`.

3. Create a new user with a specified home directory and default shell:

```bash
sudo useradd -d /home/bob -s /bin/bash bob
```

This command will create a new user account with the username `bob`, a home directory of `/home/bob`, and the default shell `/bin/bash`.

4. Create a system account:

```bash
sudo useradd -r -s /bin/false -d /nonexistent myservice
```

This command will create a system account named `myservice` with a UID lower than 1000, a default shell of `/bin/false`, and no home directory (`/nonexistent`).

Please note that the `useradd` command is typically used with administrative privileges (using `sudo`) since creating new user accounts requires superuser privileges. Additionally, some Linux distributions might use different user management tools, such as `adduser` or `usermod`, which offer more interactive and user-friendly interfaces for managing user accounts.
