In Linux, the shadow password system is a method for enhancing the security of user account passwords by storing the password hashes in a separate file called the "shadow file." The shadow file is usually located at `/etc/shadow` and is accessible only to the root user, providing an extra layer of protection against unauthorized access to password hashes.

To use the shadow password system in Linux, follow these steps:

1. Check if Shadow Passwords are Enabled:
Most modern Linux distributions use shadow passwords by default. To check if shadow passwords are enabled on your system, open the `/etc/login.defs` file and look for the following line:

```bash
ENCRYPT_METHOD SHA512
```

If you find this line or a similar one with `SHA512` or other encryption methods, shadow passwords are already enabled. If not, consider enabling it or check the documentation for your specific distribution.

2. Create User Accounts:
To create user accounts, you can use the `useradd` or `adduser` command. The shadow password system will be automatically used for new user accounts.

```bash
sudo useradd username
```

or

```bash
sudo adduser username
```

3. Set User Passwords:
When you create a new user account, the system will prompt you to set a password for that account.

If you need to change a password for an existing user, you can use the `passwd` command:

```bash
sudo passwd username
```

The system will prompt you to enter and confirm the new password for the user.

4. Verify Shadow Password Storage:
You can check the `/etc/shadow` file to see if the user's password hash is stored there:

```bash
sudo cat /etc/shadow
```

The output will show lines for each user, containing information about their password hashes and other account-related settings.

Please note that the shadow password system is generally enabled by default in modern Linux distributions, and it is recommended to keep it enabled for better security. Manually modifying the `/etc/shadow` file or its permissions is not recommended, as it can lead to security vulnerabilities or password issues.

Using the shadow password system helps protect the system against unauthorized access to password hashes and improves overall password security by making it more challenging for attackers to crack user passwords.
