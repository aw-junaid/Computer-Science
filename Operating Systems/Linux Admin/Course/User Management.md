User management is a critical aspect of Linux system administration, enabling administrators to control access, permissions, and security on the system. Below are the essential commands and concepts for managing users and groups in CentOS (and other Linux distributions).

### 1. **User Management Commands**

- **`useradd`**: Adds a new user to the system.
  - `useradd username` (creates a user with the name `username`)
  - `useradd -m username` (creates a user with a home directory)
  - `useradd -d /path/to/home username` (creates a user with a specific home directory)

- **`usermod`**: Modifies an existing user's account.
  - `usermod -aG groupname username` (adds the user `username` to the group `groupname`)
  - `usermod -d /new/home/directory username` (changes the home directory of the user)
  - `usermod -L username` (locks the user's account, preventing login)
  - `usermod -U username` (unlocks the user's account)

- **`userdel`**: Deletes a user account from the system.
  - `userdel username` (removes the user `username`)
  - `userdel -r username` (removes the user and their home directory)

- **`passwd`**: Changes the password for a user.
  - `passwd username` (changes the password for `username`)
  - `passwd` (changes the current user's password)

- **`chage`**: Changes user password expiry information.
  - `chage -l username` (lists password expiry details)
  - `chage -E YYYY-MM-DD username` (sets the expiration date of the user’s password)

### 2. **Group Management Commands**

- **`groupadd`**: Adds a new group to the system.
  - `groupadd groupname` (creates a new group called `groupname`)

- **`groupdel`**: Deletes a group from the system.
  - `groupdel groupname` (removes the group `groupname`)

- **`usermod -aG`**: Adds a user to a group.
  - `usermod -aG groupname username` (adds `username` to `groupname`)

- **`gpasswd`**: Assigns a password to a group.
  - `gpasswd groupname` (sets or changes the password for `groupname`)

- **`groups`**: Displays the groups a user belongs to.
  - `groups username` (lists groups for the user `username`)
  - `groups` (lists groups for the current user)

### 3. **Viewing User and Group Information**

- **`id`**: Displays user and group information.
  - `id username` (shows the user ID (UID), group ID (GID), and groups for the user `username`)
  - `id` (shows the current user's UID, GID, and group memberships)

- **`getent`**: Retrieves entries from databases like `/etc/passwd` and `/etc/group`.
  - `getent passwd` (lists all users in the system)
  - `getent group` (lists all groups in the system)

- **`cat /etc/passwd`**: Displays all user accounts on the system.
  - `cat /etc/passwd` (displays the user account information from the `/etc/passwd` file)

- **`cat /etc/group`**: Displays all groups on the system.
  - `cat /etc/group` (displays the group information from the `/etc/group` file)

### 4. **Locking and Unlocking User Accounts**

- **`passwd -l`**: Locks a user account, preventing login.
  - `passwd -l username` (locks the `username` account)

- **`passwd -u`**: Unlocks a previously locked account.
  - `passwd -u username` (unlocks the `username` account)

- **`usermod -L`**: Locks the user account.
  - `usermod -L username` (locks the `username` account)

- **`usermod -U`**: Unlocks the user account.
  - `usermod -U username` (unlocks the `username` account)

### 5. **Changing File Ownership and Permissions**

- **`chown`**: Changes the owner and group of a file or directory.
  - `chown user:group filename` (changes the ownership of `filename` to `user` and group to `group`)
  - `chown -R user:group directory` (changes ownership recursively for all files and subdirectories)

- **`chmod`**: Changes the permissions of a file or directory.
  - `chmod 755 filename` (sets the permissions to rwxr-xr-x)
  - `chmod -R 700 directory` (sets restrictive permissions for all files inside a directory)

### 6. **Sudo and Root Access**

- **`sudo`**: Executes a command as another user, usually as root.
  - `sudo command` (runs the command as root)
  - `sudo su` (switches to the root user)
  
- **`visudo`**: Edits the sudoers file to configure user privileges.
  - `visudo` (opens the sudoers file for editing)

  The sudoers file contains configurations that determine which users can run specific commands as root or other users. For example:
  - `username ALL=(ALL) ALL` (gives `username` permission to run all commands as any user)
  - `username ALL=(ALL) NOPASSWD: ALL` (allows `username` to run commands without entering a password)

### 7. **Managing User Sessions**

- **`whoami`**: Displays the current logged-in user.
  - `whoami`

- **`w`**: Displays who is logged in and their activities.
  - `w` (lists all logged-in users and their activities)

- **`who`**: Displays who is logged into the system.
  - `who` (lists logged-in users)

- **`last`**: Shows the last logins of users.
  - `last` (lists the most recent logins)
  - `last -a` (shows login IP address)

- **`lastlog`**: Shows the most recent login of all users.
  - `lastlog` (displays the last login times for all users)

- **`logout`**: Logs out from the current user session.

### 8. **Creating User Home Directories**

- **`mkdir`**: Creates a directory for a user manually.
  - `mkdir /home/username` (creates a home directory for `username`)
  
- **`useradd -m username`**: Automatically creates a home directory for a user.
  - `useradd -m username` (creates a home directory and adds the user `username`)

### 9. **Password Policies**

- **`pam_tally2`**: Manages login attempts and account locking.
  - `pam_tally2` (displays login attempts and locks)

- **`faillock`**: Controls failed login attempts and account locking.
  - `faillock --user username` (shows failed login attempts for a user)
  - `faillock --reset` (resets the failed login counter)

- **`chage`**: Changes password expiry details.
  - `chage -l username` (lists password expiration details for a user)
  - `chage -E YYYY-MM-DD username` (sets an expiration date for a user's password)

### 10. **Creating System Accounts**

System accounts are accounts used by the system and applications. These accounts typically don’t have a home directory and are not meant for logging in.

- **`useradd -r`**: Adds a system user.
  - `useradd -r username` (creates a system user)

---

### Summary
- **Creating users**: `useradd username`
- **Modifying users**: `usermod`
- **Deleting users**: `userdel username`
- **Creating groups**: `groupadd groupname`
- **Modifying groups**: `usermod -aG groupname username`
- **Changing passwords**: `passwd username`
- **File permissions**: `chmod`, `chown`
- **Locking/unlocking users**: `passwd -l`, `passwd -u`

Effective user and group management ensures that only authorized users can access system resources, and that their permissions are correctly set for security.
