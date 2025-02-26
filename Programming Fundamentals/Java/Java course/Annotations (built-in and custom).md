### **Introduction to Annotations**

**Annotations** in Java are a form of metadata that provide information about the code to the compiler, runtime, or other tools. They can be applied to classes, methods, fields, parameters, and other program elements. Annotations do not directly affect the code's behavior but can be used by frameworks, libraries, or the Java runtime to influence behavior or generate additional code.

---

### **Built-in Annotations**

Java provides several built-in annotations in the `java.lang` and `java.lang.annotation` packages. Here are some commonly used ones:

---

#### **1. `@Override`**
- Indicates that a method is intended to override a method in a superclass.
- Helps catch errors at compile time if the method does not actually override anything.

```java
class Parent {
    void display() {
        System.out.println("Parent's display");
    }
}

class Child extends Parent {
    @Override
    void display() {
        System.out.println("Child's display");
    }
}
```

---

#### **2. `@Deprecated`**
- Marks a method, class, or field as deprecated, meaning it should no longer be used.
- The compiler generates a warning if the deprecated element is used.

```java
class OldClass {
    @Deprecated
    void oldMethod() {
        System.out.println("This method is deprecated");
    }
}

public class Main {
    public static void main(String[] args) {
        OldClass obj = new OldClass();
        obj.oldMethod(); // Generates a warning
    }
}
```

---

#### **3. `@SuppressWarnings`**
- Suppresses specific compiler warnings.
- Commonly used to suppress unchecked or deprecation warnings.

```java
import java.util.ArrayList;
import java.util.List;

public class Main {
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        List list = new ArrayList();
        list.add("Hello");
        System.out.println(list);
    }
}
```

---

#### **4. `@FunctionalInterface`**
- Indicates that an interface is intended to be a functional interface (i.e., it has exactly one abstract method).
- Used with lambda expressions and method references.

```java
@FunctionalInterface
interface MyFunctionalInterface {
    void myMethod();
}

public class Main {
    public static void main(String[] args) {
        MyFunctionalInterface obj = () -> System.out.println("Hello, Functional Interface!");
        obj.myMethod();
    }
}
```

---

### **Custom Annotations**

You can define your own annotations using the `@interface` keyword. Custom annotations can have elements (like methods) that can store values.

---

#### **1. Define a Custom Annotation**
```java
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME) // Specifies that the annotation is available at runtime
public @interface MyAnnotation {
    String value() default "Default Value";
    int count() default 1;
}
```

---

#### **2. Use the Custom Annotation**
```java
@MyAnnotation(value = "Custom Value", count = 5)
public class MyClass {
    @MyAnnotation(count = 3)
    public void myMethod() {
        System.out.println("Executing myMethod");
    }
}
```

---

#### **3. Process the Custom Annotation Using Reflection**
```java
import java.lang.annotation.Annotation;
import java.lang.reflect.Method;

public class AnnotationProcessingExample {
    public static void main(String[] args) throws Exception {
        // Get the Class object for MyClass
        Class<?> myClass = Class.forName("MyClass");

        // Check if the class has the annotation
        if (myClass.isAnnotationPresent(MyAnnotation.class)) {
            MyAnnotation annotation = myClass.getAnnotation(MyAnnotation.class);
            System.out.println("Class Annotation Value: " + annotation.value());
            System.out.println("Class Annotation Count: " + annotation.count());
        }

        // Process method annotations
        Method myMethod = myClass.getMethod("myMethod");
        if (myMethod.isAnnotationPresent(MyAnnotation.class)) {
            MyAnnotation methodAnnotation = myMethod.getAnnotation(MyAnnotation.class);
            System.out.println("Method Annotation Value: " + methodAnnotation.value());
            System.out.println("Method Annotation Count: " + methodAnnotation.count());
        }
    }
}
```

---

### **Meta-Annotations**

Meta-annotations are annotations that are applied to other annotations. They provide information about how the annotation should be processed.

---

#### **1. `@Retention`**
- Specifies how long the annotation is retained.
- Possible values:
  - `RetentionPolicy.SOURCE`: Discarded during compilation.
  - `RetentionPolicy.CLASS`: Retained in the class file but not at runtime.
  - `RetentionPolicy.RUNTIME`: Retained at runtime and can be accessed via reflection.

```java
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation {
    String value();
}
```

---

#### **2. `@Target`**
- Specifies the program elements to which the annotation can be applied.
- Possible values include `ElementType.TYPE`, `ElementType.METHOD`, `ElementType.FIELD`, etc.

```java
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target({ElementType.TYPE, ElementType.METHOD})
public @interface MyAnnotation {
    String value();
}
```

---

#### **3. `@Documented`**
- Indicates that the annotation should be included in the JavaDoc.

```java
import java.lang.annotation.Documented;

@Documented
public @interface MyAnnotation {
    String value();
}
```

---

#### **4. `@Inherited`**
- Indicates that the annotation is inherited by subclasses.

```java
import java.lang.annotation.Inherited;

@Inherited
public @interface MyAnnotation {
    String value();
}
```

---

### **Example: Custom Annotation with Meta-Annotations**

```java
import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@Documented
@Inherited
public @interface MyAnnotation {
    String value() default "Default Value";
    int count() default 1;
}
```

---

### **Best Practices**

1. **Use Annotations Judiciously**:
   - Avoid overusing annotations, as they can make the code harder to read.

2. **Document Annotations**:
   - Clearly document the purpose and usage of custom annotations.

3. **Handle Default Values**:
   - Provide meaningful default values for annotation elements.

4. **Test Annotation Processing**:
   - Ensure that annotations are processed correctly at runtime or compile time.

5. **Use Built-in Annotations**:
   - Leverage built-in annotations like `@Override` and `@Deprecated` to improve code quality.

---

By mastering annotations, you can enhance the functionality and flexibility of your Java applications. Annotations are widely used in frameworks like Spring, Hibernate, and JUnit to simplify configuration and enable advanced features.
