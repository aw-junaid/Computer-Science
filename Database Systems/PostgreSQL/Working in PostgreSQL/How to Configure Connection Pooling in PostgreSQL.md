Configuring connection pooling in PostgreSQL can greatly improve the performance of your application by efficiently managing database connections. One popular connection pooling tool for PostgreSQL is PgBouncer. Here's a step-by-step guide on how to set up PgBouncer:

## Installing and Configuring PgBouncer

### 1. **Install PgBouncer**

You can install PgBouncer using a package manager or by downloading and compiling the source code.

For example, on Ubuntu, you can use:

```bash
sudo apt-get install pgbouncer
```

### 2. **Edit PgBouncer Configuration**

Open the PgBouncer configuration file, typically located at `/etc/pgbouncer/pgbouncer.ini`, and make the following changes:

```ini
[databases]
* = host=your_database_host port=your_database_port dbname=your_database_name

[pgbouncer]
listen_addr = 127.0.0.1
listen_port = 6432
auth_type = md5
auth_file = /etc/pgbouncer/userlist.txt
admin_users = postgres

logfile = /var/log/postgresql/pgbouncer.log
pidfile = /var/run/postgresql/pgbouncer.pid

; Increase max client connections
max_client_conn = 1000

; Increase default pool size
default_pool_size = 20

; Set log verbosity (0 = off, 3 = detailed)
log_connections = 0
log_disconnections = 0
```

### 3. **Create an Auth File**

Create a file for authentication at `/etc/pgbouncer/userlist.txt`. Add a line with the following format:

```
"username" "password"
```

For example:

```text
pgbouncer "password"
```

### 4. **Configure PostgreSQL**

Open `pg_hba.conf` of your PostgreSQL server, usually located at `/etc/postgresql/{version}/main/pg_hba.conf`. Add an entry for local connections:

```text
host    all             all             127.0.0.1/32            md5
```

### 5. **Start PgBouncer**

Start PgBouncer:

```bash
sudo service pgbouncer start
```

### 6. **Connect to PgBouncer**

In your application, connect to PgBouncer on `localhost` at port `6432` instead of directly connecting to PostgreSQL.

## Testing Connection Pooling

You can test the connection pooling by checking the number of active connections in PgBouncer using the following SQL query:

```sql
SHOW POOLS;
```

This will show you information about the current connections.

Remember to monitor the performance of your application and database to ensure that the connection pooling is effectively improving performance.
