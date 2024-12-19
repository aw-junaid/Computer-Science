### Linux Admin - Log Management

Log management in Linux is an essential task for system administrators to monitor, troubleshoot, and maintain system health. Logs record system activities, application behavior, security events, and much more. In CentOS (and other Linux distributions), logs are typically stored in the `/var/log/` directory. Understanding how to manage logs, configure log rotation, and interpret logs is critical for maintaining system performance and security.

Below is an overview of log management practices on CentOS.

---

### 1. **Location of Logs in CentOS**

Most system logs are stored in the `/var/log/` directory. Some key log files include:

- `/var/log/messages`: General system messages and logs.
- `/var/log/secure`: Security-related messages, including authentication logs.
- `/var/log/auth.log`: Authentication events and sudo usage.
- `/var/log/cron`: Cron job execution logs.
- `/var/log/dmesg`: Boot messages and kernel logs.
- `/var/log/httpd/`: Apache web server logs (for HTTP servers).
- `/var/log/mysql/`: MySQL/MariaDB logs.
- `/var/log/maillog`: Email server logs.

#### Viewing Log Files

You can view log files using common text viewing tools such as:

- `cat`: To display the content of a file.
  
  ```bash
  cat /var/log/messages
  ```

- `less`/`more`: For scrolling through larger log files.
  
  ```bash
  less /var/log/messages
  ```

- `tail`: To view the last few lines of a log file (useful for real-time monitoring).
  
  ```bash
  tail /var/log/messages
  ```

- `tail -f`: For continuous monitoring of log file updates (real-time logging).
  
  ```bash
  tail -f /var/log/messages
  ```

---

### 2. **Log Rotation (Logrotate)**

Log rotation is essential for managing log file sizes, preventing them from consuming too much disk space. CentOS uses `logrotate` to automatically rotate, compress, and manage log files. 

#### 2.1. **Logrotate Configuration**

The main configuration file for logrotate is located at `/etc/logrotate.conf`. Additional configuration files are in `/etc/logrotate.d/` for specific applications.

#### 2.2. **Basic Logrotate Syntax**

A basic logrotate configuration looks like this:

```bash
/var/log/application.log {
    rotate 7                # Keep 7 old logs
    weekly                  # Rotate logs weekly
    compress                # Compress old logs
    missingok               # Don't generate an error if the log file is missing
    notifempty              # Don't rotate the log if it's empty
    create 0644 root root   # Permissions for the new log file
}
```

This configuration tells `logrotate` to rotate the log file `application.log`, keep the last 7 logs, rotate weekly, compress old logs, and create new log files with specific permissions.

#### 2.3. **Manually Running Logrotate**

You can manually run `logrotate` to check if everything is working correctly:

```bash
sudo logrotate /etc/logrotate.conf --debug
```

This will show a debug output of what `logrotate` would do without actually performing any actions.

To force a log rotation:

```bash
sudo logrotate /etc/logrotate.conf --force
```

---

### 3. **Centralized Log Management with Syslog**

`syslog` is a standard for logging system messages. On CentOS, `rsyslog` is the default syslog service, responsible for collecting and forwarding log messages to different destinations (local or remote). Logs are categorized by facility and severity.

#### 3.1. **Configure Syslog**

The `rsyslog` configuration file is located at `/etc/rsyslog.conf`. You can edit this file to modify log forwarding or logging rules.

To enable remote log forwarding, you would configure `rsyslog` to send logs to a remote server:

```bash
*.* @remote-server-ip:514
```

This sends all logs (`*.*`) to the remote syslog server over port 514.

#### 3.2. **Restarting rsyslog**

After editing `rsyslog.conf`, restart the `rsyslog` service:

```bash
sudo systemctl restart rsyslog
```

#### 3.3. **Log Levels**

Log messages are categorized by **facility** (the source of the log, such as kernel, user-level, or mail system) and **severity** (the importance of the log message, ranging from `emerg` for critical messages to `debug` for detailed debug messages).

Some common log levels are:

- `emerg`: Emergency messages, usually critical system failures.
- `alert`: Requires immediate attention.
- `crit`: Critical conditions.
- `err`: Error conditions.
- `warning`: Warning messages.
- `notice`: Normal but significant conditions.
- `info`: Informational messages.
- `debug`: Debugging messages.

You can specify the log level to control what gets logged.

---

### 4. **Journal Logs with `systemd` (Journalctl)**

CentOS 7 and newer versions use `systemd` as the default init system. With `systemd`, logs are stored in the **journal**, a binary log format, which can be accessed using the `journalctl` command.

#### 4.1. **Viewing Logs with journalctl**

- To view all system logs:

  ```bash
  sudo journalctl
  ```

- To view logs for a specific service, for example, the SSH service:

  ```bash
  sudo journalctl -u sshd
  ```

- To show logs for a specific time period, such as logs from today:

  ```bash
  sudo journalctl --since today
  ```

- To follow logs in real-time:

  ```bash
  sudo journalctl -f
  ```

#### 4.2. **Filter Logs by Priority Level**

You can filter logs by priority level:

```bash
sudo journalctl -p err    # Show only error logs
sudo journalctl -p info   # Show informational logs
```

#### 4.3. **Persistent Logging**

By default, the `systemd` journal stores logs temporarily in memory. To enable persistent logging (saving logs on disk), create the directory `/var/log/journal` and restart the `systemd-journald` service:

```bash
sudo mkdir /var/log/journal
sudo systemctl restart systemd-journald
```

This will ensure that logs are stored in `/var/log/journal` and persist even after a reboot.

---

### 5. **Log Monitoring and Alerting**

You can set up monitoring and alerting systems to notify you when certain log events occur. This is useful for proactive system management, especially for security or performance issues.

#### 5.1. **Using `logwatch` for Log Monitoring**

**`logwatch`** is a log parsing and monitoring tool that generates reports based on system logs.

To install **logwatch**:

```bash
sudo yum install logwatch -y
```

To generate a report:

```bash
sudo logwatch --detail High --service All --range today
```

This will generate a detailed report of all system services for the current day.

#### 5.2. **Using `swatch` for Real-time Log Monitoring**

**`swatch`** is a tool that can be used to monitor log files in real time and alert administrators when certain patterns appear in the logs.

To install **swatch**:

```bash
sudo yum install swatch -y
```

#### 5.3. **Using `fail2ban` for Security Logging**

**`fail2ban`** is a log-parsing tool that automatically bans IP addresses based on certain log patterns (e.g., multiple failed login attempts).

To install **fail2ban**:

```bash
sudo yum install fail2ban -y
```

Start and enable the service:

```bash
sudo systemctl start fail2ban
sudo systemctl enable fail2ban
```

It will monitor log files like `/var/log/secure` and take action based on pre-configured rules.

---

### 6. **Automated Log Cleanup**

Logs can accumulate quickly, so it’s essential to periodically clean up old logs. You can configure automatic log cleanup with `logrotate` or by manually removing logs older than a certain period.

#### 6.1. **Automating Cleanup with Logrotate**

Logrotate automatically removes old logs based on the configuration in `/etc/logrotate.conf` and `/etc/logrotate.d/`. For example:

```bash
/var/log/messages {
    rotate 4
    weekly
    compress
    delaycompress
    missingok
    notifempty
    olddir /var/log/old
}
```

This configuration ensures that only 4 weeks' worth of `messages` logs are kept.

#### 6.2. **Manual Log Cleanup**

To manually delete log files older than a specific number of days, you can use the `find` command. For example, to delete log files older than 30 days:

```bash
find /var/log -name "*.log" -type f -mtime +30 -exec rm -f {} \;
```

---

### Conclusion

Log management is an integral part of Linux administration. By using tools like `logrotate`, `journalctl`, `syslog`, and `logwatch`, you can ensure that logs are properly managed, rotated, and monitored. Setting up log forwarding and monitoring allows for better troubleshooting, security auditing, and system maintenance. Regular log review and automated log rotation are crucial for keeping the system healthy and preventing log files from consuming excessive disk space.
