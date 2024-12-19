### Linux Admin - Backup and Recovery

Backup and recovery are essential tasks in system administration to ensure that critical data and system configurations are safely stored and can be restored in the event of data loss, hardware failure, or other disasters. Linux offers a variety of backup tools and techniques to suit different needs.

In this guide, we will cover the core aspects of backup and recovery in Linux, specifically for CentOS.

---

### 1. **Backup Strategies**

Before diving into the specific tools, it’s important to consider a backup strategy. A good backup strategy includes the following:

- **Full Backups**: A complete copy of the data. Typically done once in a while to ensure everything is backed up.
- **Incremental Backups**: Only the changes (new or modified files) since the last backup. This saves space and time.
- **Differential Backups**: Captures all changes since the last full backup.
- **Scheduled Backups**: Automating backups at regular intervals, e.g., daily or weekly.

---

### 2. **Backup Tools in Linux**

There are several tools for performing backups in CentOS. These tools vary in features, complexity, and use cases.

#### 2.1. **rsync**

**`rsync`** is one of the most widely used tools for creating backups. It efficiently syncs files and directories between two locations, either on the same system or remotely over a network. It can perform both full and incremental backups.

##### 2.1.1. **Basic Syntax of rsync**

```bash
rsync -avh /source/directory/ /destination/directory/
```

- `-a`: Archive mode, which preserves permissions, timestamps, symbolic links, etc.
- `-v`: Verbose, provides more detailed output.
- `-h`: Human-readable, makes the output more readable (e.g., 1K, 1M).

##### 2.1.2. **Using rsync for Incremental Backups**

To do an incremental backup, use the `--link-dest` option to reference the previous backup:

```bash
rsync -avh --link-dest=/previous/backup /source/directory/ /destination/directory/
```

This will only copy the files that have changed since the last backup.

##### 2.1.3. **Backing Up to Remote Server**

You can use `rsync` over SSH to back up files to a remote server:

```bash
rsync -avz -e ssh /source/directory/ user@remote:/destination/directory/
```

- `-z`: Compress files during transfer.
- `-e ssh`: Use SSH for secure communication.

#### 2.2. **tar**

The **`tar`** (tape archive) command is another popular tool for creating backups, especially for full backups. It can compress data as it creates an archive.

##### 2.2.1. **Creating a tar Archive**

To create a full backup of a directory:

```bash
tar -cvpzf /path/to/backup/backup_name.tar.gz /path/to/directory/
```

- `-c`: Create a new archive.
- `-v`: Verbose, shows the files being archived.
- `-p`: Preserves the permissions.
- `-z`: Compress the archive using gzip.
- `-f`: Specifies the name of the archive.

##### 2.2.2. **Extracting a tar Archive**

To restore a backup:

```bash
tar -xvpzf /path/to/backup/backup_name.tar.gz -C /path/to/destination/
```

- `-x`: Extract the archive.
- `-C`: Specify the directory where the archive should be extracted.

#### 2.3. **dd Command**

The **`dd`** command is used for making block-level backups. It's commonly used for creating disk images or backups of entire disk partitions.

##### 2.3.1. **Backing Up a Disk or Partition**

To back up a disk (e.g., `/dev/sda`) to an image file:

```bash
sudo dd if=/dev/sda of=/path/to/backup/disk_backup.img bs=64K conv=noerror,sync
```

- `if`: Input file (the source disk or partition).
- `of`: Output file (the backup image).
- `bs`: Block size.
- `conv=noerror,sync`: Continue even if there are read errors and sync the data.

##### 2.3.2. **Restoring a Disk or Partition from Backup**

To restore the disk image to the original or new disk:

```bash
sudo dd if=/path/to/backup/disk_backup.img of=/dev/sda bs=64K
```

#### 2.4. **Backup with Bacula**

**Bacula** is an enterprise-level backup solution designed for large systems and networks. It includes a set of programs to manage backup, recovery, and verification of data across a network.

To install **Bacula**:

```bash
sudo yum install bacula-director bacula-storage bacula-console bacula-client -y
```

Bacula requires detailed configuration for the director, storage daemon, and client to handle backup operations.

#### 2.5. **Backup with Amanda**

**Amanda** (Advanced Maryland Automatic Network Disk Archiver) is an open-source backup solution that can back up multiple systems.

To install **Amanda**:

```bash
sudo yum install amanda-server amanda-client -y
```

After installation, you'll need to configure the server and clients using the `/etc/amanda/` directory configuration files.

---

### 3. **Scheduling Backups**

To automate backups on CentOS, you can use `cron` to schedule tasks.

#### 3.1. **Scheduling with Cron**

Edit the cron table for your user or root:

```bash
crontab -e
```

To schedule a backup at 2 AM every day:

```bash
0 2 * * * /usr/bin/rsync -avh /source/directory /backup/directory/
```

This schedules the `rsync` backup to run daily at 2 AM.

---

### 4. **Backup Verification**

It's crucial to verify that backups have been successfully created and can be restored. This can be done through:

- **Test restores**: Periodically restore data from backup to ensure it works.
- **Checksum comparison**: Compare file checksums before and after backup to verify integrity.

For example, to verify the integrity of a `tar` archive:

```bash
tar -tvf /path/to/backup/backup_name.tar.gz
```

---

### 5. **Backup Storage Options**

You should consider where to store your backups. Some options include:

- **Local Storage**: Backups stored on the same machine or a separate storage device.
- **Network Storage**: Backup to a network-attached storage (NAS) or server.
- **Cloud Storage**: Backup to services like Amazon S3, Google Cloud Storage, or others.
- **Offsite Storage**: Ensures that backups are available in case of physical damage to the primary location (disasters, theft, etc.).

---

### 6. **Disaster Recovery**

In case of a failure, a disaster recovery process should be in place to restore the system or data. This involves having backup copies of critical files, configurations, and system images.

#### 6.1. **System Recovery**

- **Restoring from `tar` or `rsync` backups**: Use the respective commands to restore files from backup.
- **Using `dd` for full disk recovery**: A disk image created with `dd` can be restored to a new disk in case of a failure.

#### 6.2. **Automated Recovery**

- **Bootable Backup Disks**: Ensure that there is a bootable backup disk image in case the system becomes unbootable.
- **RAID Configurations**: In case of disk failure, RAID can help in automatic recovery of data.

---

### 7. **Cloud Backup Solutions**

For greater redundancy and reliability, many organizations use cloud backup services. Here are a few tools to manage backups to cloud services:

#### 7.1. **Rclone**

**Rclone** is a command-line tool that can manage backups to many cloud storage providers, such as Google Drive, AWS S3, and Dropbox.

To install **rclone**:

```bash
curl https://rclone.org/install.sh | sudo bash
```

#### 7.2. **CloudBerry Backup**

**CloudBerry** provides a comprehensive backup solution with support for cloud storage providers. It allows you to schedule backups and manage cloud backup storage from a single interface.

---

### 8. **Backup Best Practices**

- **Regular Backups**: Automate and schedule regular backups.
- **Offsite/Cloud Backup**: Ensure backups are stored offsite or in the cloud to protect against disasters.
- **Test Restores**: Regularly test backup restores to ensure the integrity and reliability of backups.
- **Backup Critical Data**: Always prioritize backing up critical system files, configurations, and databases.
- **Encryption**: Consider encrypting sensitive backups to protect data during storage and transit.

---

### Conclusion

Backup and recovery are crucial tasks for ensuring data integrity and system uptime. Linux provides a range of tools, from simple utilities like `rsync` and `tar` to more complex solutions like **Bacula** and **Amanda**. A solid backup strategy, including automation, offsite storage, and disaster recovery plans, is essential for mitigating data loss risks and ensuring business continuity.
