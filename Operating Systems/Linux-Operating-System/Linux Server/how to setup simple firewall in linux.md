To set up a simple firewall in Linux, you can use the built-in firewall management tool called `iptables` or the higher-level front-end utility `ufw` (Uncomplicated Firewall). `ufw` provides a simpler interface for managing `iptables` rules.

Here's how to set up a simple firewall using `ufw`:

1. Check Firewall Status (optional):
Before enabling the firewall, check if it is already active:
```bash
sudo ufw status
```

2. Install `ufw` (if not installed):
`ufw` may already be installed on your system. If not, install it using your package manager:

For Debian/Ubuntu:
```bash
sudo apt update
sudo apt install ufw
```

For CentOS/RHEL:
```bash
sudo yum install ufw
```

3. Enable Firewall:
Enable the firewall:
```bash
sudo ufw enable
```

4. Allow Specific Services (optional):
To allow specific services, you can use the service names or port numbers. For example, to allow SSH and HTTP, use:
```bash
sudo ufw allow ssh
sudo ufw allow http
```

5. Deny Incoming Connections (optional):
By default, `ufw` denies all incoming connections. If you want to explicitly deny specific services, you can use:
```bash
sudo ufw deny ftp
```

6. Check Firewall Rules:
To see the list of current firewall rules:
```bash
sudo ufw status
```

7. Disable Firewall (if needed):
If you need to disable the firewall:
```bash
sudo ufw disable
```

Remember, `ufw` provides a simple way to manage basic firewall rules. However, if you need more complex rules or customization, you can use `iptables` directly. Be cautious when setting up firewall rules to avoid locking yourself out of the system. Always make sure you understand the impact of the rules you are applying.

Here's a basic example using `iptables` directly to allow SSH (port 22) and HTTP (port 80):

1. Check Firewall Status (optional):
```bash
sudo iptables -L
```

2. Allow SSH (port 22):
```bash
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
```

3. Allow HTTP (port 80):
```bash
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```

4. Deny all other incoming connections (optional):
```bash
sudo iptables -A INPUT -j DROP
```

Remember to save the `iptables` rules to apply them on system reboot. The specific method to save rules depends on your Linux distribution. Consult your distribution's documentation for more information.
