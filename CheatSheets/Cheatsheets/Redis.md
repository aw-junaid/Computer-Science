A comprehensive Docker Redis cheat sheet that covers essential commands, configurations, and explanations for using Redis with Docker.

---

# **Docker Redis Extended Cheat Sheet**

## **1. Getting Started with Docker and Redis**

### 1.1 Install Docker

Ensure Docker is installed on your machine. You can refer to the official documentation for installation instructions: [Install Docker](https://docs.docker.com/get-docker/).

### 1.2 Pull the Redis Image

**Command:**
```bash
docker pull redis
```
**Explanation**: Downloads the latest Redis image from Docker Hub.

### 1.3 List Docker Images

**Command:**
```bash
docker images
```
**Explanation**: Lists all Docker images available on your local machine.

---

## **2. Running a Redis Container**

### 2.1 Run a Basic Redis Container

**Command:**
```bash
docker run --name redis-container -d redis
```
**Explanation**: Runs a new Redis container named `redis-container` in detached mode.

### 2.2 Run a Redis Container with Custom Port Mapping

**Command:**
```bash
docker run --name redis-container -p 6379:6379 -d redis
```
**Explanation**: Maps port `6379` on the host to port `6379` in the container, allowing external access to Redis.

### 2.3 Run a Redis Container with a Specific Version

**Command:**
```bash
docker run --name redis-container -d redis:6.0
```
**Explanation**: Runs a Redis container using version `6.0` of the image.

---

## **3. Managing Redis Containers**

### 3.1 List Running Containers

**Command:**
```bash
docker ps
```
**Explanation**: Lists all currently running Docker containers.

### 3.2 List All Containers (Including Stopped)

**Command:**
```bash
docker ps -a
```
**Explanation**: Lists all Docker containers, including those that are stopped.

### 3.3 Stop a Redis Container

**Command:**
```bash
docker stop redis-container
```
**Explanation**: Stops the specified Redis container.

### 3.4 Start a Stopped Redis Container

**Command:**
```bash
docker start redis-container
```
**Explanation**: Starts a previously stopped Redis container.

### 3.5 Remove a Redis Container

**Command:**
```bash
docker rm redis-container
```
**Explanation**: Deletes the specified container from your system.

---

## **4. Accessing the Redis Container**

### 4.1 Open a Redis CLI Inside the Container

**Command:**
```bash
docker exec -it redis-container redis-cli
```
**Explanation**: Opens an interactive Redis CLI session inside the running Redis container.

### 4.2 Connect to Redis from the Host

**Command:**
```bash
redis-cli -h localhost -p 6379
```
**Explanation**: Connects to the Redis server running in the container from your host machine using the `redis-cli`.

---

## **5. Data Persistence**

### 5.1 Run a Redis Container with a Volume

**Command:**
```bash
docker run --name redis-container -v /my/own/datadir:/data -d redis
```
**Explanation**: Creates a volume that maps the host directory `/my/own/datadir` to the container’s `/data` directory, ensuring data persistence.

### 5.2 Use Docker Named Volumes

**Command:**
```bash
docker run --name redis-container -v redis_data:/data -d redis
```
**Explanation**: Creates a named volume called `redis_data` for persistent storage of Redis data.

---

## **6. Configuration Options**

### 6.1 Run Redis with Custom Configuration

**Command:**
```bash
docker run --name redis-container -v /my/own/redis.conf:/usr/local/etc/redis/redis.conf -d redis redis-server /usr/local/etc/redis/redis.conf
```
**Explanation**: Runs a Redis container using a custom configuration file located at `/my/own/redis.conf`.

### 6.2 Set Password for Redis

**Command:**
```bash
docker run --name redis-container -d redis --requirepass mypassword
```
**Explanation**: Runs a Redis container and sets a password (`mypassword`) for client connections.

---

## **7. Backing Up and Restoring Data**

### 7.1 Backup Redis Data

**Command:**
```bash
docker exec redis-container redis-cli save
```
**Explanation**: Forces Redis to perform a save operation, creating a dump file (dump.rdb) in the `/data` directory.

### 7.2 Copy the Backup to the Host

**Command:**
```bash
docker cp redis-container:/data/dump.rdb /my/backup/location/
```
**Explanation**: Copies the `dump.rdb` file from the Redis container to a specified location on the host.

### 7.3 Restore Redis Data

To restore data, you would place the `dump.rdb` file in the `/data` directory of a Redis container and restart it. 

**Command:**
```bash
docker cp /my/backup/location/dump.rdb redis-container:/data/
docker restart redis-container
```
**Explanation**: Copies the backup file into the container and restarts the Redis server, which automatically loads the data from `dump.rdb`.

---

## **8. Networking**

### 8.1 Create a User-Defined Network

**Command:**
```bash
docker network create my-network
```
**Explanation**: Creates a custom Docker network called `my-network`.

### 8.2 Run a Redis Container in a Custom Network

**Command:**
```bash
docker run --name redis-container --network my-network -d redis
```
**Explanation**: Runs a Redis container on the specified custom network.

---

## **9. Docker Compose for Redis**

### 9.1 Create a Docker Compose File (`docker-compose.yml`)

```yaml
version: '3.8'
services:
  redis:
    image: redis
    ports:
      - "6379:6379"
    volumes:
      - redis_data:/data

volumes:
  redis_data:
```
**Explanation**: Defines a Docker Compose configuration for running a Redis service with specified volume for data persistence.

### 9.2 Start Services with Docker Compose

**Command:**
```bash
docker-compose up -d
```
**Explanation**: Starts all services defined in the `docker-compose.yml` file in detached mode.

### 9.3 Stop Services with Docker Compose

**Command:**
```bash
docker-compose down
```
**Explanation**: Stops and removes all containers defined in the `docker-compose.yml` file.

---

## **10. Useful Commands**

### 10.1 View Container Logs

**Command:**
```bash
docker logs redis-container
```
**Explanation**: Displays the logs of the specified Redis container, useful for monitoring and debugging.

### 10.2 Monitor Container Resources

**Command:**
```bash
docker stats redis-container
```
**Explanation**: Displays a live stream of resource usage statistics for the specified container.

---

This cheat sheet provides a comprehensive overview of how to use Docker with Redis, covering common commands, configurations, and tips.
