An extended cheat sheet for Apache Kafka, covering commands, usage, and explanations to help you get started and work effectively with Kafka.

---

# **Apache Kafka Extended Cheat Sheet**

## **1. Prerequisites**

### 1.1 Install Kafka

Download and install Kafka from the official [Apache Kafka website](https://kafka.apache.org/downloads).

### 1.2 Start ZooKeeper

Kafka uses ZooKeeper for managing distributed brokers. Start ZooKeeper with the default configuration:

```bash
bin/zookeeper-server-start.sh config/zookeeper.properties
```

**Explanation**: This command starts a ZooKeeper server using the configuration file provided.

### 1.3 Start Kafka Server

After starting ZooKeeper, start the Kafka broker:

```bash
bin/kafka-server-start.sh config/server.properties
```

**Explanation**: This command starts the Kafka broker using the default configuration.

---

## **2. Creating Topics**

### 2.1 Create a Topic

**Command:**
```bash
bin/kafka-topics.sh --create --topic my-topic --bootstrap-server localhost:9092 --partitions 1 --replication-factor 1
```

**Explanation**: Creates a new topic named `my-topic` with 1 partition and a replication factor of 1. The `--bootstrap-server` option specifies the Kafka broker to connect to.

### 2.2 List Topics

**Command:**
```bash
bin/kafka-topics.sh --list --bootstrap-server localhost:9092
```

**Explanation**: Lists all topics currently available in the Kafka cluster.

### 2.3 Describe a Topic

**Command:**
```bash
bin/kafka-topics.sh --describe --topic my-topic --bootstrap-server localhost:9092
```

**Explanation**: Displays detailed information about the specified topic, including its partitions and replication status.

---

## **3. Producing Messages**

### 3.1 Produce Messages to a Topic

**Command:**
```bash
bin/kafka-console-producer.sh --topic my-topic --bootstrap-server localhost:9092
```

**Explanation**: Starts a console producer that allows you to send messages to the specified topic. After running this command, type your messages and press Enter to send them.

### 3.2 Send Messages from a File

**Command:**
```bash
bin/kafka-console-producer.sh --topic my-topic --bootstrap-server localhost:9092 --from-file messages.txt
```

**Explanation**: Sends messages to the topic from a specified file (`messages.txt`), with each line of the file treated as a separate message.

---

## **4. Consuming Messages**

### 4.1 Start a Consumer Group

**Command:**
```bash
bin/kafka-console-consumer.sh --topic my-topic --from-beginning --bootstrap-server localhost:9092
```

**Explanation**: Starts a console consumer that reads messages from the specified topic, starting from the beginning of the topic. The consumer will display the messages on the console.

### 4.2 Consume with a Consumer Group

**Command:**
```bash
bin/kafka-console-consumer.sh --topic my-topic --group my-group --bootstrap-server localhost:9092
```

**Explanation**: Starts a consumer with the specified consumer group (`my-group`). This allows multiple consumers in the same group to share the load of consuming messages from the topic.

---

## **5. Configuring Topics**

### 5.1 Alter Topic Configuration

**Command:**
```bash
bin/kafka-configs.sh --alter --entity-type topics --entity-name my-topic --add-config retention.ms=604800000 --bootstrap-server localhost:9092
```

**Explanation**: Alters the configuration of the topic named `my-topic` to set the retention period to 7 days (604800000 milliseconds).

### 5.2 Describe Topic Configuration

**Command:**
```bash
bin/kafka-configs.sh --describe --entity-type topics --entity-name my-topic --bootstrap-server localhost:9092
```

**Explanation**: Displays the current configuration for the specified topic.

---

## **6. Managing Consumer Groups**

### 6.1 List Consumer Groups

**Command:**
```bash
bin/kafka-consumer-groups.sh --list --bootstrap-server localhost:9092
```

**Explanation**: Lists all consumer groups in the Kafka cluster.

### 6.2 Describe a Consumer Group

**Command:**
```bash
bin/kafka-consumer-groups.sh --describe --group my-group --bootstrap-server localhost:9092
```

**Explanation**: Displays detailed information about the specified consumer group, including the current offset and lag for each partition.

---

## **7. Deleting Topics**

### 7.1 Delete a Topic

**Command:**
```bash
bin/kafka-topics.sh --delete --topic my-topic --bootstrap-server localhost:9092
```

**Explanation**: Deletes the specified topic from the Kafka cluster.

### 7.2 Enable Topic Deletion

To enable topic deletion, you need to set the following property in the `server.properties` file:

```properties
delete.topic.enable=true
```

**Explanation**: This configuration allows you to delete topics in Kafka.

---

## **8. Monitoring and Managing Kafka**

### 8.1 Check Broker Status

You can check the status of the Kafka broker by accessing the logs:

```bash
tail -f logs/server.log
```

**Explanation**: Displays the log output of the Kafka server, which can help you monitor the broker's status and troubleshoot issues.

### 8.2 Use JMX to Monitor Kafka

Kafka supports Java Management Extensions (JMX) for monitoring. You can enable JMX by setting the following in your `KAFKA_OPTS` environment variable:

```bash
export KAFKA_OPTS="-Dcom.sun.management.jmxremote -Dcom.sun.management.jmxremote.port=9999 -Dcom.sun.management.jmxremote.authenticate=false -Dcom.sun.management.jmxremote.ssl=false"
```

**Explanation**: This allows you to connect to the Kafka broker's JMX metrics, which can be monitored using tools like JConsole.

---

## **9. Common Kafka Command Options**

| Command                                  | Description                                                       |
|------------------------------------------|-------------------------------------------------------------------|
| `--bootstrap-server <broker>`           | Specifies the Kafka broker address to connect to.                |
| `--topic <topic-name>`                  | Specifies the name of the topic to produce or consume messages.   |
| `--partitions <number>`                  | Sets the number of partitions for the new topic.                 |
| `--replication-factor <number>`         | Sets the replication factor for the new topic.                   |
| `--from-beginning`                      | Consumes messages starting from the beginning of the topic.      |
| `--group <group-name>`                  | Specifies the consumer group for consuming messages.             |
| `--add-config <config>`                 | Adds or modifies a configuration for a topic or broker.          |
| `--delete`                              | Deletes a topic or consumer group.                               |
| `--describe`                            | Provides detailed information about topics or consumer groups.    |

---

## **10. Common Use Cases**

### 10.1 Stream Processing

Apache Kafka can be used with stream processing libraries like Kafka Streams or Apache Flink to process data in real time.

### 10.2 Log Aggregation

Kafka is commonly used for log aggregation, collecting logs from different services and making them available for analysis.

### 10.3 Real-time Analytics

Kafka can be integrated with systems like Apache Spark for real-time analytics of streaming data.

### 10.4 Data Integration

Kafka is often used to integrate different data sources and sinks, enabling data movement between systems in a reliable way.

---

## **Conclusion**

This Apache Kafka cheat sheet provides an overview of essential commands, configurations, and common use cases to help you work effectively with Kafka. Familiarizing yourself with these commands will enable you to manage and utilize Kafka efficiently for various messaging and streaming applications.
