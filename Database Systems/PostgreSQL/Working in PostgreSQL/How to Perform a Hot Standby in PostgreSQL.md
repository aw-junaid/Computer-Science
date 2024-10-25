Performing a hot standby in PostgreSQL involves setting up a standby server that can take over in case the primary (master) server fails. This is achieved through streaming replication, where the standby server continuously receives transaction logs from the primary server. Here are the steps to perform a hot standby in PostgreSQL:

## 1. **Prerequisites**

Before setting up a hot standby, ensure you have:

- Two PostgreSQL servers (primary and standby)
- Access to both servers
- Replication user with appropriate privileges

## 2. **Configuring Primary (Master) Server**

### a. Enable WAL (Write-Ahead Logging)

Edit the `postgresql.conf` file on the primary server:

```shell
$ sudo nano /etc/postgresql/{version}/main/postgresql.conf
```

Ensure the following lines are set:

```conf
wal_level = replica
max_wal_senders = 10
wal_keep_segments = 10
```

### b. Create Replication User

Connect to the primary server and create a replication user:

```sql
CREATE USER replication_user REPLICATION LOGIN CONNECTION LIMIT 10 ENCRYPTED PASSWORD 'password';
```

### c. Restart Primary Server

Restart the primary server to apply the configuration changes.

## 3. **Backup and Restore Data**

Create a base backup of the primary server and restore it on the standby. You can use tools like `pg_basebackup` or other backup methods.

## 4. **Configuring Standby (Replica) Server**

### a. Configure `recovery.conf`

Create a `recovery.conf` file in the standby's data directory:

```shell
$ sudo nano /var/lib/postgresql/{version}/main/recovery.conf
```

Add the following:

```conf
standby_mode = 'on'
primary_conninfo = 'host=primary_ip port=5432 user=replication_user password=password'
restore_command = 'cp /var/lib/postgresql/{version}/main/archive/%f %p'
```

Replace `primary_ip` with the IP address of the primary server.

### b. Adjust Permissions

Ensure the standby server has the necessary permissions to read from the primary's WAL archives.

```shell
$ sudo chown -R postgres:postgres /var/lib/postgresql/{version}/main/archive/
```

### c. Start Standby Server

Start the standby server:

```shell
$ sudo systemctl start postgresql
```

## 5. **Monitor Hot Standby**

Check the status of the hot standby using the following SQL command on the standby:

```sql
SELECT * FROM pg_stat_replication;
```

## 6. **Failover (Optional)**

In case the primary server fails, promote the standby to become the new primary.

## 7. **Additional Considerations**

- **Monitoring**: Implement a monitoring system to keep an eye on replication status.
- **Backup Strategy**: Continue with regular database backups for both primary and standby.

By following these steps, you can set up a hot standby in PostgreSQL for high availability and failover capabilities. Remember to thoroughly test your setup and have a clear plan for handling failover scenarios.
