### MariaDB - Backup Loading Methods

Loading a backup into MariaDB is the process of restoring data from a backup file to a MariaDB instance. There are several methods available to load backups, depending on how the backup was created and the format of the backup. This section will cover the various backup loading methods in MariaDB.

---

### 1. **Loading a Backup Created with `mysqldump` (Logical Backup)**

If you've backed up your MariaDB database using `mysqldump`, you will typically have a `.sql` file that contains SQL statements for recreating the schema and inserting the data. To restore this backup, you use the `mysql` command-line tool.

#### **Restoring from a `mysqldump` Backup:**

```bash
mysql -u username -p database_name < backup_file.sql
```

- `-u username`: The MariaDB username.
- `-p`: Prompts for the password.
- `database_name`: The name of the database to restore the backup into.
- `< backup_file.sql`: Redirects the SQL file into the `mysql` command for execution.

#### **Example:**

To restore the backup `my_database_backup.sql` into the `my_database`:

```bash
mysql -u root -p my_database < my_database_backup.sql
```

This command will execute the SQL statements in `my_database_backup.sql`, which includes `CREATE TABLE`, `INSERT`, and other necessary commands to restore the database.

#### **Important Notes:**
- If the database does not exist, you must create it before restoring the backup. Use the following command to create the database:

```sql
CREATE DATABASE my_database;
```

- If your backup includes stored procedures, triggers, or events, you may want to include the `--routines` or `--triggers` options when running `mysqldump` to ensure they are restored correctly.

---

### 2. **Restoring from a `mariabackup` Backup (Physical Backup)**

If you've used `mariabackup` to create a physical backup, you must follow a slightly different process. The backup consists of the raw data files of your MariaDB instance and must be restored to the data directory of a MariaDB server. Additionally, before using the backup, it must be "prepared" to apply the transaction logs and ensure consistency.

#### **Steps to Restore a `mariabackup` Backup:**

1. **Prepare the Backup:**

Before you can restore the `mariabackup` backup, you need to prepare it by applying the transaction logs.

```bash
mariabackup --prepare --target-dir=/path/to/backup
```

- `--prepare`: Prepares the backup by applying any changes (from the binary logs) to the backup files.

2. **Restore the Backup:**

After preparing the backup, copy the backup files into the MariaDB data directory.

```bash
mariabackup --copy-back --target-dir=/path/to/backup
```

- `--copy-back`: Copies the backup files from the specified directory (`/path/to/backup`) to the MariaDB data directory (e.g., `/var/lib/mysql`).

3. **Adjust File Permissions:**

Ensure the restored files have the correct ownership and permissions for the MariaDB server to access them.

```bash
chown -R mysql:mysql /var/lib/mysql
```

4. **Restart the MariaDB Server:**

Once the files are copied and permissions are set, restart the MariaDB server to complete the restoration.

```bash
systemctl restart mariadb
```

---

### 3. **Loading Backup Using Replication (Slave-based Backup Loading)**

If you've set up replication between MariaDB servers, you can perform a backup from the replication slave without interrupting the master server's operations. The slave will maintain an up-to-date copy of the master’s database, so you can use the slave as the backup source.

#### **Steps to Load Backup from a Replication Slave:**

1. **Ensure the Slave is Synchronized:**

Before taking a backup from the slave, ensure that the replication between the master and slave is up to date. You can check the replication status with:

```sql
SHOW SLAVE STATUS\G
```

Ensure that `Slave_IO_Running` and `Slave_SQL_Running` are both `Yes`.

2. **Create a Backup from the Slave:**

Once the slave is synchronized, use the same backup methods (`mysqldump` or `mariabackup`) to back up the slave's data. For example:

```bash
mysqldump -u root -p --all-databases > slave_backup.sql
```

3. **Restore the Backup to the Master or Another Server:**

To restore the backup on the master or another server, you can use the standard restore methods (e.g., `mysql` for `mysqldump` backups or `mariabackup` for physical backups).

---

### 4. **Loading a Backup Created with `mysqlpump` (Backup Tool)**

If you used the `mysqlpump` utility to back up your MariaDB database, you would restore the backup in a similar way to `mysqldump`. The key difference is that `mysqlpump` is optimized for parallel processing and can back up multiple databases at once.

#### **Restoring from a `mysqlpump` Backup:**

```bash
mysql -u username -p < backup_file.sql
```

The restore process is similar to `mysqldump`. After restoring the backup, ensure that the database is consistent and that the backup includes any required stored routines, triggers, and events.

---

### 5. **Loading from a Cloud-Based Backup**

If you have backed up your MariaDB data to a cloud storage provider such as Amazon S3, Google Cloud Storage, or Azure, you must first download the backup file from the cloud and then restore it using the appropriate method (e.g., `mysqldump`, `mariabackup`, or `mysqlpump`).

#### **Example: Restoring from Amazon S3:**

1. **Download the Backup File from S3:**

You can use the AWS CLI to download the backup file:

```bash
aws s3 cp s3://my-backups/my_database_backup.sql /path/to/local/backup
```

2. **Restore the Backup Using `mysql`:**

After downloading the backup, restore it using the `mysql` command:

```bash
mysql -u root -p my_database < /path/to/local/backup/my_database_backup.sql
```

---

### 6. **Automating Backup Loading (Using Cron Jobs or Scripts)**

To automate the backup loading process, you can use `cron` jobs (on Linux) or scheduled tasks (on Windows) to periodically restore backups, especially in the case of disaster recovery or when setting up new environments.

#### **Automated Backup Loading with Cron:**

1. Open the `cron` configuration:

```bash
crontab -e
```

2. Add a job to restore a backup at a specific time, for example, to restore a backup every Sunday at 2:00 AM:

```bash
0 2 * * 0 /usr/bin/mysql -u root -psecret my_database < /backups/my_database_backup.sql
```

---

### 7. **Restoring Specific Tables or Data (Selective Restore)**

Sometimes you may only want to restore specific tables or data from a backup. With `mysqldump`, you can extract specific tables from a backup file. You can also selectively restore individual tables from a full database backup by editing the SQL file to include only the necessary `CREATE TABLE` and `INSERT` statements.

#### **Restoring Specific Tables:**

To restore specific tables from a backup, simply edit the backup file to include only the SQL for the desired tables, and then load that SQL file:

```bash
mysql -u root -p my_database < my_database_partial_backup.sql
```

Alternatively, you can use `mysqldump` to back up specific tables:

```bash
mysqldump -u root -p my_database table1 table2 > my_database_partial_backup.sql
```

Then restore the backup file as usual.

---

### Conclusion

Restoring a MariaDB backup is a crucial part of database administration, ensuring that your data can be recovered in case of failure. The backup loading process depends on the type of backup method you have used:

- **Logical backups** (e.g., `mysqldump`, `mysqlpump`) are restored using the `mysql` command.
- **Physical backups** (e.g., `mariabackup`) require copying the data files back to the MariaDB data directory and applying transaction logs.
- **Replication-based backups** allow you to restore data from a synchronized slave server.
- **Cloud backups** require downloading the backup file from cloud storage and restoring it with the appropriate method.

By following the correct method for your backup type, you can ensure that your MariaDB databases are restored properly and efficiently.
