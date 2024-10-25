# Setting Up Replication in PostgreSQL

Setting up replication in PostgreSQL allows you to create copies of a database to enhance availability, distribute load, or serve as backups. Here is a step-by-step guide on how to set up replication in PostgreSQL:

## 1. **Understanding Replication**

Replication in PostgreSQL involves maintaining a copy of a database (the master) on another server (the replica). There are two types of replication in PostgreSQL: synchronous and asynchronous.

- **Synchronous Replication**: Transactions are only considered committed once they have been written to the master and at least one replica.

- **Asynchronous Replication**: Transactions are considered committed as soon as they're written to the master, and replication to the replicas happens afterwards.

## 2. **Prerequisites**

Before setting up replication, ensure you have:

- Two PostgreSQL servers (master and replica)
- Access to both servers
- Replication user with appropriate privileges

## 3. **Configuring Master Server**

### a. Enable WAL (Write-Ahead Logging)

Edit the `postgresql.conf` file on the master server:

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

Connect to the master server and create a replication user:

```sql
CREATE USER replication_user REPLICATION LOGIN CONNECTION LIMIT 10 ENCRYPTED PASSWORD 'password';
```

## 4. **Backup and Restore Data**

Create a base backup of the master server and restore it on the replica. You can use tools like `pg_basebackup` or other backup methods.

## 5. **Configuring Replica Server**

### a. Configure `recovery.conf`

Create a `recovery.conf` file in the replica's data directory:

```shell
$ sudo nano /var/lib/postgresql/{version}/main/recovery.conf
```

Add the following:

```conf
standby_mode = 'on'
primary_conninfo = 'host=master_ip port=5432 user=replication_user password=password'
restore_command = 'cp /var/lib/postgresql/{version}/main/archive/%f %p'
```

### b. Adjust Permissions

Ensure the replica server has the necessary permissions to read from the master's WAL archives.

```shell
$ sudo chown -R postgres:postgres /var/lib/postgresql/{version}/main/archive/
```

### c. Start Replica Server

Start the replica server:

```shell
$ sudo systemctl start postgresql
```

## 6. **Monitor Replication**

Check the status of replication using the following SQL command on the master:

```sql
SELECT * FROM pg_stat_replication;
```

## 7. **Failover (Optional)**

In case the master server fails, promote the replica to become the new master.

## 8. **Additional Considerations**

- **Monitoring**: Implement a monitoring system to keep an eye on replication status.
- **Backup Strategy**: Continue with regular database backups for both master and replica.

By following these steps, you can set up replication in PostgreSQL for better availability and data redundancy. Keep in mind that replication adds complexity, so ensure you have a thorough understanding of your infrastructure and PostgreSQL configuration.
