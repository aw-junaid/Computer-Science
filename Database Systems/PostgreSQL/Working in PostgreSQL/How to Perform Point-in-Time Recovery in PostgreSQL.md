Performing a Point-in-Time Recovery (PITR) in PostgreSQL allows you to restore a database to a specific point in time, using the Write-Ahead Logs (WAL) for precise recovery. Here's a step-by-step guide:

## 1. **Prerequisites**

Before performing PITR, ensure you have:

- A PostgreSQL server with archiving enabled (`wal_level = archive`).
- A base backup of the database you want to recover.
- A backup of the WAL files.

## 2. **Restoring a Base Backup**

Restore the base backup you created earlier. If you used `pg_basebackup`, it might look like this:

```shell
$ pg_basebackup -D /var/lib/postgresql/{version}/main --host=primary_ip --port=5432 --username=replication_user --password=password
```

## 3. **Setting up Recovery**

### a. Create a `recovery.conf` file

Create a `recovery.conf` file in the data directory:

```shell
$ sudo nano /var/lib/postgresql/{version}/main/recovery.conf
```

Add the following:

```conf
restore_command = 'cp /var/lib/postgresql/{version}/main/archive/%f %p'
recovery_target_time = 'YYYY-MM-DD HH:MI:SS'
```

Replace `'YYYY-MM-DD HH:MI:SS'` with the desired point in time for recovery.

### b. Set File Permissions

Ensure the PostgreSQL user has access to the recovery.conf file:

```shell
$ sudo chown postgres:postgres /var/lib/postgresql/{version}/main/recovery.conf
```

## 4. **Starting PostgreSQL**

Start PostgreSQL:

```shell
$ sudo systemctl start postgresql
```

The server will start in recovery mode and apply WAL logs up to the specified point in time.

## 5. **Monitoring Recovery**

Monitor the recovery process using the following SQL command:

```sql
SELECT * FROM pg_stat_wal_receiver;
```

## 6. **Completing Recovery**

Once the desired point in time is reached, recovery will complete automatically, and the server will be in normal operational mode.

## 7. **Stopping PostgreSQL**

Stop PostgreSQL:

```shell
$ sudo systemctl stop postgresql
```

## 8. **Cleaning Up**

Remove the `recovery.conf` file:

```shell
$ sudo rm /var/lib/postgresql/{version}/main/recovery.conf
```

## 9. **Additional Considerations**

- **Monitoring**: Implement a monitoring system to keep an eye on the recovery process.
- **Backup Strategy**: Continue with regular database backups and WAL archiving.

By following these steps, you can perform a Point-in-Time Recovery in PostgreSQL. Make sure to thoroughly test your recovery process to ensure it works as expected in a real-world scenario.
