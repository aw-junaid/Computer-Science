### **Introduction to Unit Testing with JUnit**

**JUnit** is a widely used testing framework for Java that simplifies the process of writing and running unit tests. Unit tests are small, isolated tests that verify the correctness of individual components (e.g., methods or classes) in your code. JUnit provides annotations, assertions, and test runners to make unit testing efficient and effective.

---

### **Key Features of JUnit**

1. **Annotations**:
   - Simplify test creation with annotations like `@Test`, `@Before`, `@After`, etc.

2. **Assertions**:
   - Provide methods to verify expected outcomes (e.g., `assertEquals`, `assertTrue`).

3. **Test Runners**:
   - Execute tests and report results.

4. **Parameterized Tests**:
   - Run the same test with different inputs.

5. **Integration**:
   - Works seamlessly with build tools like Maven and Gradle.

---

### **JUnit Annotations**

| Annotation       | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `@Test`          | Marks a method as a test method.                                            |
| `@Before`        | Marks a method to run before each test.                                     |
| `@After`         | Marks a method to run after each test.                                      |
| `@BeforeClass`   | Marks a method to run once before all tests in the class.                   |
| `@AfterClass`    | Marks a method to run once after all tests in the class.                    |
| `@Ignore`        | Ignores a test method.                                                      |
| `@Parameterized` | Marks a test class or method as a parameterized test.                       |

---

### **JUnit Assertions**

Assertions are used to verify expected outcomes in tests. Common assertion methods include:

| Method                          | Description                                                                 |
|---------------------------------|-----------------------------------------------------------------------------|
| `assertEquals(expected, actual)` | Asserts that two values are equal.                                          |
| `assertTrue(condition)`         | Asserts that a condition is true.                                           |
| `assertFalse(condition)`        | Asserts that a condition is false.                                          |
| `assertNull(object)`            | Asserts that an object is null.                                             |
| `assertNotNull(object)`         | Asserts that an object is not null.                                         |
| `assertSame(expected, actual)`  | Asserts that two objects refer to the same instance.                        |
| `assertNotSame(expected, actual)`| Asserts that two objects do not refer to the same instance.                 |
| `assertThrows(exception, executable)` | Asserts that an executable throws a specific exception.                |

---

### **Example: Writing Unit Tests with JUnit**

Below is an example of a simple Java class and its corresponding unit tests.

#### **1. Add JUnit Dependency (Maven)**
```xml
<dependency>
    <groupId>junit</groupId>
    <artifactId>junit</artifactId>
    <version>4.13.2</version>
    <scope>test</scope>
</dependency>
```

#### **2. Java Class to Test**
```java
public class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public int subtract(int a, int b) {
        return a - b;
    }

    public int multiply(int a, int b) {
        return a * b;
    }

    public int divide(int a, int b) {
        if (b == 0) {
            throw new IllegalArgumentException("Cannot divide by zero");
        }
        return a / b;
    }
}
```

#### **3. Unit Test Class**
```java
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

public class CalculatorTest {
    private Calculator calculator;

    @Before
    public void setUp() {
        calculator = new Calculator();
    }

    @Test
    public void testAdd() {
        assertEquals(5, calculator.add(2, 3));
    }

    @Test
    public void testSubtract() {
        assertEquals(1, calculator.subtract(3, 2));
    }

    @Test
    public void testMultiply() {
        assertEquals(6, calculator.multiply(2, 3));
    }

    @Test
    public void testDivide() {
        assertEquals(2, calculator.divide(6, 3));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testDivideByZero() {
        calculator.divide(6, 0);
    }
}
```

---

### **Running Tests**

1. **Using an IDE**:
   - Most IDEs (e.g., IntelliJ IDEA, Eclipse) provide built-in support for running JUnit tests.

2. **Using Maven**:
   - Run the following command to execute tests:
     ```bash
     mvn test
     ```

3. **Using Gradle**:
   - Run the following command to execute tests:
     ```bash
     gradle test
     ```

---

### **Advanced JUnit Features**

#### **1. Parameterized Tests**
Parameterized tests allow you to run the same test with different inputs.

```java
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import java.util.Arrays;
import java.util.Collection;
import static org.junit.Assert.assertEquals;

@RunWith(Parameterized.class)
public class CalculatorParameterizedTest {
    private int a;
    private int b;
    private int expected;

    public CalculatorParameterizedTest(int a, int b, int expected) {
        this.a = a;
        this.b = b;
        this.expected = expected;
    }

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
            {1, 2, 3},
            {2, 3, 5},
            {3, 4, 7}
        });
    }

    @Test
    public void testAdd() {
        Calculator calculator = new Calculator();
        assertEquals(expected, calculator.add(a, b));
    }
}
```

#### **2. Test Suites**
Test suites allow you to group multiple test classes together.

```java
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({
    CalculatorTest.class,
    CalculatorParameterizedTest.class
})
public class CalculatorTestSuite {
}
```

---

### **Best Practices**

1. **Write Small, Focused Tests**:
   - Each test should verify a single behavior or scenario.

2. **Use Descriptive Test Names**:
   - Name tests to clearly describe what they are testing (e.g., `testAddPositiveNumbers`).

3. **Isolate Tests**:
   - Ensure tests do not depend on each other or shared state.

4. **Use Assertions**:
   - Always use assertions to verify expected outcomes.

5. **Test Edge Cases**:
   - Include tests for edge cases (e.g., null values, empty collections).

6. **Keep Tests Fast**:
   - Avoid slow operations (e.g., database access) in unit tests.

---

By mastering JUnit, you can ensure the correctness and reliability of your Java code. Unit testing is a critical practice in modern software development, and JUnit makes it easy to implement.
