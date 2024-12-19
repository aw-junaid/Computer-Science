### Linux Admin - Package Management

Package management is an essential part of system administration in Linux. It allows system administrators to easily install, upgrade, and remove software packages on a system. In CentOS (and other Red Hat-based distributions), package management is handled using **YUM** (Yellowdog Updater, Modified) or **DNF** (Dandified YUM) in CentOS 8 and later. These tools interact with software repositories to install, update, and manage software.

This guide will cover how to manage software packages on CentOS using YUM and DNF, including installing, removing, updating, and configuring repositories.

---

### 1. **Package Management Overview**

Linux packages are typically distributed as **RPM (Red Hat Package Manager)** files, which contain precompiled binaries, configuration files, and scripts necessary for installing and configuring software. The **RPM package manager** is used to manage individual packages, while **YUM** and **DNF** serve as front-end tools to automate and manage dependencies.

CentOS, as a RHEL-based distribution, uses **RPM** for package installation and management.

---

### 2. **Package Management Tools**

#### 2.1. **YUM (CentOS 7 and earlier)**

In CentOS 7 and earlier, **YUM** is the default package manager.

**Basic YUM Commands**:

- **Install a package**:

  ```bash
  sudo yum install package-name
  ```

- **Remove a package**:

  ```bash
  sudo yum remove package-name
  ```

- **Update a package**:

  ```bash
  sudo yum update package-name
  ```

- **Update all packages**:

  ```bash
  sudo yum update
  ```

- **List installed packages**:

  ```bash
  sudo yum list installed
  ```

- **Search for a package**:

  ```bash
  sudo yum search package-name
  ```

- **List available updates**:

  ```bash
  sudo yum list updates
  ```

- **Clean YUM cache**:

  ```bash
  sudo yum clean all
  ```

#### 2.2. **DNF (CentOS 8 and later)**

CentOS 8 and later use **DNF** (Dandified YUM), which is the successor of YUM, offering improved performance, better dependency resolution, and enhanced features. DNF commands are similar to YUM commands but more efficient.

**Basic DNF Commands**:

- **Install a package**:

  ```bash
  sudo dnf install package-name
  ```

- **Remove a package**:

  ```bash
  sudo dnf remove package-name
  ```

- **Update a package**:

  ```bash
  sudo dnf update package-name
  ```

- **Update all packages**:

  ```bash
  sudo dnf update
  ```

- **List installed packages**:

  ```bash
  sudo dnf list installed
  ```

- **Search for a package**:

  ```bash
  sudo dnf search package-name
  ```

- **List available updates**:

  ```bash
  sudo dnf check-update
  ```

- **Clean DNF cache**:

  ```bash
  sudo dnf clean all
  ```

---

### 3. **Installing Software Packages**

Installing software packages is a simple process using either YUM or DNF. You can install packages from the default repositories or from external repositories.

#### 3.1. **Install a Package**

To install a package, use the `install` command. For example, to install **vim**:

- **Using YUM** (CentOS 7 and earlier):

  ```bash
  sudo yum install vim
  ```

- **Using DNF** (CentOS 8 and later):

  ```bash
  sudo dnf install vim
  ```

The package manager will automatically resolve dependencies and install any required packages.

#### 3.2. **Installing Multiple Packages**

To install multiple packages at once, list them separated by spaces:

- **Using YUM**:

  ```bash
  sudo yum install vim wget curl
  ```

- **Using DNF**:

  ```bash
  sudo dnf install vim wget curl
  ```

#### 3.3. **Install Specific Version of a Package**

To install a specific version of a package, use the following syntax:

- **Using YUM**:

  ```bash
  sudo yum install package-name-version
  ```

- **Using DNF**:

  ```bash
  sudo dnf install package-name-version
  ```

Example:

```bash
sudo yum install vim-8.0.1234
```

This installs a specific version of Vim.

---

### 4. **Removing Software Packages**

When you no longer need a package, you can remove it using the `remove` or `erase` command.

#### 4.1. **Remove a Package**

- **Using YUM** (CentOS 7 and earlier):

  ```bash
  sudo yum remove package-name
  ```

- **Using DNF** (CentOS 8 and later):

  ```bash
  sudo dnf remove package-name
  ```

This will uninstall the specified package and its dependencies if no other installed packages require them.

#### 4.2. **Removing Unused Dependencies**

After removing a package, there may be unused dependencies left on the system. You can remove them using the `autoremove` command.

- **Using YUM**:

  ```bash
  sudo yum autoremove
  ```

- **Using DNF**:

  ```bash
  sudo dnf autoremove
  ```

This will automatically remove packages that were installed as dependencies but are no longer needed.

---

### 5. **Updating Software Packages**

Keeping packages up-to-date is crucial for security and stability. To update packages, you can use the following commands.

#### 5.1. **Update All Packages**

To update all installed packages to their latest versions:

- **Using YUM** (CentOS 7 and earlier):

  ```bash
  sudo yum update
  ```

- **Using DNF** (CentOS 8 and later):

  ```bash
  sudo dnf update
  ```

#### 5.2. **Update Specific Package**

To update a specific package:

- **Using YUM** (CentOS 7 and earlier):

  ```bash
  sudo yum update package-name
  ```

- **Using DNF** (CentOS 8 and later):

  ```bash
  sudo dnf update package-name
  ```

---

### 6. **Managing Software Repositories**

Linux package managers rely on repositories, which are collections of software packages. By default, CentOS uses official repositories, but you can add additional repositories like **EPEL (Extra Packages for Enterprise Linux)** for extra software.

#### 6.1. **List Enabled Repositories**

To list the currently enabled repositories:

- **Using YUM** (CentOS 7 and earlier):

  ```bash
  sudo yum repolist
  ```

- **Using DNF** (CentOS 8 and later):

  ```bash
  sudo dnf repolist
  ```

#### 6.2. **Add a Repository**

To add a repository, you can use the `yum` or `dnf` commands along with the appropriate repository configuration file.

- **Adding the EPEL Repository** (for CentOS 7):

  ```bash
  sudo yum install epel-release
  ```

- **Adding the EPEL Repository** (for CentOS 8):

  ```bash
  sudo dnf install epel-release
  ```

Once added, you can install packages from the new repository.

#### 6.3. **Disable/Enable a Repository**

You can disable or enable repositories temporarily by using the `--disablerepo` or `--enablerepo` option.

- **Disable a repository temporarily**:

  ```bash
  sudo yum install package-name --disablerepo=repository-name
  ```

- **Enable a repository temporarily**:

  ```bash
  sudo yum install package-name --enablerepo=repository-name
  ```

- **Using DNF** (CentOS 8):

  ```bash
  sudo dnf install package-name --disablerepo=repository-name
  sudo dnf install package-name --enablerepo=repository-name
  ```

---

### 7. **RPM (Red Hat Package Manager)**

While YUM and DNF are higher-level package managers, **RPM** is the underlying tool that handles package installation, removal, and queries directly.

#### 7.1. **Install an RPM Package**

To install a `.rpm` package manually:

```bash
sudo rpm -ivh package-name.rpm
```

#### 7.2. **Remove an RPM Package**

To remove an installed `.rpm` package:

```bash
sudo rpm -e package-name
```

#### 7.3. **Query Installed Packages**

To query installed packages:

```bash
rpm -q package-name
```

---

### 8. **Package Management Best Practices**

- **Keep the system updated**: Regularly update packages to ensure security patches and bug fixes are applied.
- **Clean YUM/DNF cache**: Over time, the cache can grow large. Clean it regularly to free up space:
  
  ```bash
  sudo yum clean all
  ```

  or

  ```bash
  sudo dnf clean all
  ```

- **Use repositories wisely**: Stick to official repositories or trusted third-party repositories like EPEL to ensure the security and integrity of your system.
- **Install software only when necessary**: Avoid cluttering your system with unnecessary software to maintain its efficiency and security.

---

### Conclusion

Package management is a core skill for Linux administrators. In CentOS, YUM (CentOS 7 and earlier) and DNF (CentOS 8 and later) are powerful tools for installing, updating, and removing software packages. By understanding how to manage repositories, install and update packages, and clean up the system, administrators can ensure that their systems remain secure, efficient, and up-to-date.
