A comprehensive Spring Boot cheat sheet that includes essential commands, configurations, and explanations to help you work effectively with Spring Boot.

---

# **Spring Boot Extended Cheat Sheet**

## **1. Prerequisites**

### 1.1 Java Installation

**Command:**
```bash
java -version
```
**Explanation**: Checks the installed Java version. Spring Boot requires Java 8 or higher.

### 1.2 Maven Installation

**Command:**
```bash
mvn -version
```
**Explanation**: Checks the installed Maven version. Maven is typically used to manage Spring Boot projects.

## **2. Creating a Spring Boot Project**

### 2.1 Using Spring Initializr

- Go to [Spring Initializr](https://start.spring.io/).
- Select the project metadata (Group, Artifact, Name, etc.).
- Choose the dependencies you need (e.g., Spring Web, Spring Data JPA).
- Click "Generate" to download the project as a ZIP file.
- Unzip and navigate into the project directory.

### 2.2 Create a New Spring Boot Project Using Command Line (Maven)

**Command:**
```bash
mvn archetype:generate -DgroupId=com.example -DartifactId=myapp -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
```
**Explanation**: Generates a new Maven project with specified group and artifact IDs.

---

## **3. Project Structure Overview**

- **`src/main/java`**: Contains Java source code.
- **`src/main/resources`**: Contains application properties and static resources.
- **`src/test/java`**: Contains test classes.
- **`pom.xml`**: The Maven project file that manages dependencies.

---

## **4. Running a Spring Boot Application**

### 4.1 Running the Application

**Command:**
```bash
mvn spring-boot:run
```
**Explanation**: Starts the Spring Boot application using Maven.

### 4.2 Running the Application from the Jar File

**Command:**
```bash
java -jar target/myapp-0.0.1-SNAPSHOT.jar
```
**Explanation**: Runs the packaged JAR file of the Spring Boot application.

### 4.3 Build the Application

**Command:**
```bash
mvn clean package
```
**Explanation**: Cleans the previous builds and packages the application into a JAR file.

---

## **5. Application Configuration**

### 5.1 Application Properties

In `src/main/resources/application.properties`, you can set various configurations:

```properties
server.port=8080
spring.datasource.url=jdbc:mysql://localhost:3306/mydb
spring.datasource.username=root
spring.datasource.password=password
```
**Explanation**: Configures server port and database connection properties.

### 5.2 YAML Configuration

Alternatively, you can use YAML in `application.yml`:

```yaml
server:
  port: 8080

spring:
  datasource:
    url: jdbc:mysql://localhost:3306/mydb
    username: root
    password: password
```
**Explanation**: Uses YAML syntax for configuration.

---

## **6. Creating a RESTful API**

### 6.1 Create a Simple REST Controller

In `src/main/java/com/example/myapp/controller/MyController.java`:

```java
package com.example.myapp.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MyController {

    @GetMapping("/hello")
    public String hello() {
        return "Hello, World!";
    }
}
```
**Explanation**: Defines a REST controller with a simple endpoint that returns "Hello, World!".

---

## **7. Dependency Management**

### 7.1 Add Dependencies in `pom.xml`

To add dependencies, include them in the `<dependencies>` section of your `pom.xml`:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-jpa</artifactId>
</dependency>
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <scope>runtime</scope>
</dependency>
```
**Explanation**: Adds web and JPA starters and MySQL connector as dependencies.

---

## **8. Working with JPA**

### 8.1 Create an Entity

In `src/main/java/com/example/myapp/model/MyEntity.java`:

```java
package com.example.myapp.model;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

@Entity
public class MyEntity {

    @Id
    @GeneratedValue
    private Long id;
    private String name;

    // Getters and setters
}
```
**Explanation**: Defines a JPA entity with an auto-generated ID.

### 8.2 Create a Repository

In `src/main/java/com/example/myapp/repository/MyEntityRepository.java`:

```java
package com.example.myapp.repository;

import com.example.myapp.model.MyEntity;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MyEntityRepository extends JpaRepository<MyEntity, Long> {
}
```
**Explanation**: Creates a repository interface for the entity.

### 8.3 Use the Repository in a Service

In `src/main/java/com/example/myapp/service/MyEntityService.java`:

```java
package com.example.myapp.service;

import com.example.myapp.model.MyEntity;
import com.example.myapp.repository.MyEntityRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MyEntityService {

    @Autowired
    private MyEntityRepository repository;

    public List<MyEntity> findAll() {
        return repository.findAll();
    }
}
```
**Explanation**: Defines a service to interact with the repository.

---

## **9. Spring Boot DevTools**

### 9.1 Add DevTools Dependency

Add the following dependency to `pom.xml` for live reload:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-devtools</artifactId>
    <scope>runtime</scope>
    <optional>true</optional>
</dependency>
```
**Explanation**: Adds Spring Boot DevTools to enable live reloading during development.

---

## **10. Testing**

### 10.1 Writing a Unit Test

In `src/test/java/com/example/myapp/MyControllerTest.java`:

```java
package com.example.myapp;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.test.web.servlet.MockMvc;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@WebMvcTest
public class MyControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Test
    public void testHello() throws Exception {
        mockMvc.perform(get("/hello"))
                .andExpect(status().isOk());
    }
}
```
**Explanation**: Defines a simple test for the REST controller to check the `/hello` endpoint.

### 10.2 Running Tests

**Command:**
```bash
mvn test
```
**Explanation**: Runs all the tests in the project.

---

## **11. Packaging and Running the Application**

### 11.1 Build the Application

**Command:**
```bash
mvn clean package
```
**Explanation**: Cleans and builds the application, creating a JAR file in the `target` directory.

### 11.2 Run the JAR File

**Command:**
```bash
java -jar target/myapp-0.0.1-SNAPSHOT.jar
```
**Explanation**: Runs the packaged Spring Boot application.

---

## **12. Actuator**

### 12.1 Add Actuator Dependency

Add the following dependency to `pom.xml`:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-actuator</artifactId>
</dependency>
```
**Explanation**: Adds the Spring Boot Actuator for monitoring and managing the application.

### 12.2 Configure Actuator Endpoints

In `application.properties`, enable endpoints:

```properties
management.endpoints.web.exposure.include=*
```
**Explanation**: Exposes all actuator endpoints.

---

## **13. Common Spring Boot Annotations**

| Annotation                         | Description                                                        |
|------------------------------------|--------------------------------------------------------------------|
| `@SpringBootApplication`           | Marks the main class of a Spring Boot application.                 |
| `@RestController`                  | Indicates that the class is a REST controller.                     |
| `@GetMapping`, `@PostMapping`     | Shorthand for `@RequestMapping(method = RequestMethod.GET/POST)`.  |
| `@Service`                         | Marks a service class in the service layer.                        |
| `@Repository`                      | Marks a class as a Data Access Object (DAO).                       |
| `@Autowired`                       | Allows Spring to inject dependencies.                              |
| `@Entity`                          | Marks a class as a JPA entity.                                    |
| `@Configuration`                   | Indicates that a class declares one or more `@Bean` methods.      |
| `@Value`                           | Injects values from properties files into fields.                  |

---

This cheat sheet provides a comprehensive overview of how to use Spring Boot, covering common commands, configurations, and tips.
