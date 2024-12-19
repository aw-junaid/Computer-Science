### Linux Admin - System Updates

System updates are a critical part of system administration, ensuring that your system stays secure, stable, and up-to-date with the latest features and bug fixes. Linux distributions, including CentOS, have built-in package management tools that simplify the process of updating the operating system (OS) and installed software.

This guide will cover how to manage system updates in CentOS using various tools and practices.

---

### 1. **Package Management in CentOS**

CentOS, being a derivative of Red Hat Enterprise Linux (RHEL), uses the **YUM (Yellowdog Updater, Modified)** package manager for installing, updating, and removing packages. In CentOS 8 and later, **DNF (Dandified YUM)** is used as the default package manager, which is backward-compatible with YUM but offers improved performance and features.

#### 1.1. **Using YUM (CentOS 7 and earlier)**

To update the system using **YUM**:

- **Update all packages**:

  ```bash
  sudo yum update
  ```

  This command will fetch and install the latest versions of all installed packages.

- **Update a specific package**:

  ```bash
  sudo yum update package-name
  ```

- **List available updates**:

  ```bash
  sudo yum list updates
  ```

- **Check for specific package update**:

  ```bash
  sudo yum list updates | grep package-name
  ```

- **Clean up the YUM cache** (removes old metadata and cached packages):

  ```bash
  sudo yum clean all
  ```

#### 1.2. **Using DNF (CentOS 8 and later)**

To update the system using **DNF** (the default package manager in CentOS 8 and later):

- **Update all packages**:

  ```bash
  sudo dnf update
  ```

- **Update a specific package**:

  ```bash
  sudo dnf update package-name
  ```

- **List available updates**:

  ```bash
  sudo dnf check-update
  ```

- **Check for specific package update**:

  ```bash
  sudo dnf check-update package-name
  ```

- **Clean up the DNF cache**:

  ```bash
  sudo dnf clean all
  ```

---

### 2. **Automatic Updates**

Automating updates ensures that your system remains up-to-date without manual intervention. This is especially useful for security patches.

#### 2.1. **Enabling Automatic Updates with `dnf-automatic` (CentOS 8)**

CentOS 8 uses the **`dnf-automatic`** package for automating updates. Here's how to enable it:

1. Install the `dnf-automatic` package:

   ```bash
   sudo dnf install dnf-automatic
   ```

2. Enable and start the **dnf-automatic** service:

   ```bash
   sudo systemctl enable --now dnf-automatic.timer
   ```

   This will schedule automatic updates to run at regular intervals (daily by default).

3. You can configure the frequency of automatic updates by editing the `dnf-automatic` configuration file:

   ```bash
   sudo vi /etc/dnf/automatic.conf
   ```

   The configuration file allows you to modify settings like whether to automatically apply updates or just check for them, as well as when updates should be applied.

#### 2.2. **Enabling Automatic Updates with `yum-cron` (CentOS 7)**

CentOS 7 uses **`yum-cron`** to automate updates:

1. Install `yum-cron`:

   ```bash
   sudo yum install yum-cron
   ```

2. Enable and start the **yum-cron** service:

   ```bash
   sudo systemctl enable --now yum-cron
   ```

3. Configure the frequency and behavior of automatic updates by editing the `yum-cron` configuration file:

   ```bash
   sudo vi /etc/yum/yum-cron.conf
   ```

   In this configuration file, you can specify whether to download and apply updates automatically or just check for updates.

---

### 3. **Security Updates**

Security patches and updates are vital for maintaining the integrity and security of your system. In CentOS, security updates can be managed separately from regular package updates.

#### 3.1. **Installing Only Security Updates**

You can install only the security updates using `dnf` or `yum`.

- **Using `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf update --security
  ```

- **Using `yum` (CentOS 7 and earlier)**:

  Install the `yum-plugin-security` package to enable security updates:

  ```bash
  sudo yum install yum-plugin-security
  ```

  Then, run the following command to update only the security-related packages:

  ```bash
  sudo yum update --security
  ```

#### 3.2. **Viewing Available Security Updates**

You can view the available security updates before applying them:

- **Using `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf updateinfo list security
  ```

- **Using `yum` (CentOS 7 and earlier)**:

  ```bash
  sudo yum list-sec
  ```

---

### 4. **Kernel Updates**

Linux kernel updates are sometimes handled separately because they require a system reboot. Updating the kernel can improve hardware support, security, and performance.

#### 4.1. **Updating the Kernel**

- **Using `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf update kernel
  ```

- **Using `yum` (CentOS 7 and earlier)**:

  ```bash
  sudo yum update kernel
  ```

After updating the kernel, you need to reboot the system for the changes to take effect:

```bash
sudo reboot
```

#### 4.2. **Checking the Current Kernel Version**

To check your current kernel version:

```bash
uname -r
```

---

### 5. **Update Packages for Specific Repositories**

If you want to update packages from specific repositories (e.g., EPEL, RPM Fusion), you can use the `--enablerepo` option with `dnf` or `yum`.

- **For `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf --enablerepo=epel update
  ```

- **For `yum` (CentOS 7 and earlier)**:

  ```bash
  sudo yum --enablerepo=epel update
  ```

This ensures that only the specified repositories are used for the update process.

---

### 6. **Package Group Updates**

Sometimes, packages are installed as part of a group, such as "Development Tools" or "Web Server". You can update all packages in a group using the following command.

- **Using `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf groupupdate "Development Tools"
  ```

- **Using `yum` (CentOS 7 and earlier)**:

  ```bash
  sudo yum groupupdate "Development Tools"
  ```

---

### 7. **Reverting Updates**

In some cases, you may want to roll back an update if it causes issues. CentOS supports package downgrades, but you need to be cautious when reverting updates.

#### 7.1. **Downgrading a Package**

- **Using `dnf` (CentOS 8 and later)**:

  ```bash
  sudo dnf downgrade package-name
  ```

- **Using `yum` (CentOS 7 and earlier)**:

  ```bash
  sudo yum downgrade package-name
  ```

This will install the previous version of the package, as long as it is available in the repository.

#### 7.2. **Removing an Update**

If a package update has caused issues and you need to remove it, you can uninstall it:

```bash
sudo yum remove package-name  # CentOS 7 and earlier
```

```bash
sudo dnf remove package-name  # CentOS 8 and later
```

---

### 8. **Logs and Update History**

You can check the history of updates and package installations using the following tools:

- **View update history with `dnf`** (CentOS 8 and later):

  ```bash
  sudo dnf history
  ```

- **View update history with `yum`** (CentOS 7 and earlier):

  ```bash
  sudo yum history
  ```

---

### Conclusion

Keeping a Linux system up-to-date is essential for security, stability, and performance. Using tools like `dnf` and `yum` on CentOS, you can manage package updates, automate the update process, apply security patches, and manage kernel updates. Regular system updates help ensure your server runs smoothly and remains protected from vulnerabilities. Always test updates in a controlled environment and schedule regular backups to avoid data loss during updates.
