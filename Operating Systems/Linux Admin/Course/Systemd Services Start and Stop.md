`systemd` is the default system and service manager for most modern Linux distributions, including CentOS, RHEL, and Ubuntu. It is used to manage system services, which are often referred to as "units" in `systemd`. The main commands for managing services (starting, stopping, enabling, disabling, etc.) are typically run with `systemctl`.

### Key `systemctl` Commands for Managing Services

#### 1. **Start a Service**
To start a service immediately, use the `start` command:
```bash
systemctl start <service_name>
```
- Example: To start the Apache web server (httpd):
  ```bash
  systemctl start httpd
  ```

#### 2. **Stop a Service**
To stop a running service, use the `stop` command:
```bash
systemctl stop <service_name>
```
- Example: To stop the Apache web server:
  ```bash
  systemctl stop httpd
  ```

#### 3. **Restart a Service**
To restart a service, use the `restart` command. This is useful when you need to apply changes (such as configuration updates) to a running service:
```bash
systemctl restart <service_name>
```
- Example: To restart the Apache web server:
  ```bash
  systemctl restart httpd
  ```

#### 4. **Reload a Service**
If a service supports reloading (reloading its configuration without restarting), use the `reload` command:
```bash
systemctl reload <service_name>
```
- Example: To reload the Apache web server (this applies new configurations without stopping the service):
  ```bash
  systemctl reload httpd
  ```

#### 5. **Enable a Service to Start at Boot**
If you want a service to start automatically when the system boots, use the `enable` command:
```bash
systemctl enable <service_name>
```
- Example: To enable Apache to start on boot:
  ```bash
  systemctl enable httpd
  ```

#### 6. **Disable a Service from Starting at Boot**
If you want to prevent a service from starting automatically at boot, use the `disable` command:
```bash
systemctl disable <service_name>
```
- Example: To disable Apache from starting on boot:
  ```bash
  systemctl disable httpd
  ```

#### 7. **Check the Status of a Service**
To check the status of a service, use the `status` command:
```bash
systemctl status <service_name>
```
- Example: To check the status of Apache:
  ```bash
  systemctl status httpd
  ```
This will show whether the service is running, its process ID (PID), any error messages, and other useful details.

#### 8. **Show All Active Services**
To view all active services, use the following:
```bash
systemctl list-units --type=service
```
This will list all currently running services, their status, and other information.

#### 9. **Check if a Service is Enabled or Disabled**
To check if a service is enabled to start at boot, use:
```bash
systemctl is-enabled <service_name>
```
- Example: To check if Apache is enabled:
  ```bash
  systemctl is-enabled httpd
  ```

#### 10. **Mask a Service**
Masking a service completely disables it and prevents it from being started manually or automatically. Use `mask` if you want to block a service from running entirely.
```bash
systemctl mask <service_name>
```
- Example: To mask Apache:
  ```bash
  systemctl mask httpd
  ```

#### 11. **Unmask a Service**
To reverse the mask and allow a service to be started again, use the `unmask` command:
```bash
systemctl unmask <service_name>
```
- Example: To unmask Apache:
  ```bash
  systemctl unmask httpd
  ```

#### 12. **Viewing Service Logs**
`systemd` keeps logs of service activity, and these can be accessed using the `journalctl` command. To view logs for a specific service:
```bash
journalctl -u <service_name>
```
- Example: To view logs for Apache:
  ```bash
  journalctl -u httpd
  ```

You can also use additional flags like `-f` for live logs (similar to `tail -f`):
```bash
journalctl -u httpd -f
```

---

### Summary of Common `systemctl` Commands

| Command                              | Description                                                   |
|--------------------------------------|---------------------------------------------------------------|
| `systemctl start <service_name>`     | Starts the service immediately.                               |
| `systemctl stop <service_name>`      | Stops the service immediately.                                |
| `systemctl restart <service_name>`   | Restarts the service (useful for configuration changes).      |
| `systemctl reload <service_name>`    | Reloads the service configuration (if supported).            |
| `systemctl enable <service_name>`    | Enables the service to start at boot.                         |
| `systemctl disable <service_name>`   | Disables the service from starting at boot.                   |
| `systemctl status <service_name>`    | Shows the status of the service (running, stopped, etc.).     |
| `systemctl list-units --type=service`| Lists all active services.                                    |
| `systemctl is-enabled <service_name>`| Checks if the service is enabled to start at boot.            |
| `systemctl mask <service_name>`      | Disables and prevents the service from being started.         |
| `systemctl unmask <service_name>`    | Reverses the masking and allows the service to start again.   |
| `journalctl -u <service_name>`       | Views logs for the specified service.                         |

---

### Additional Notes:
- Services are defined as "units" in `systemd`, and they are generally located in `/etc/systemd/system/` or `/lib/systemd/system/`.
- When you create or modify service files, it's important to reload `systemd` to recognize the changes:  
  ```bash
  systemctl daemon-reload
  ```
  
By mastering these `systemd` commands, you can efficiently manage and control services on your Linux system, ensuring that everything starts, stops, and behaves as expected.
