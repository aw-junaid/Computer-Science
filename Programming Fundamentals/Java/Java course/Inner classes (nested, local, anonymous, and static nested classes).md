In Java, **inner classes** are classes defined within another class. They are used to logically group classes, improve encapsulation, and increase code readability. Java supports four types of inner classes:

1. **Nested (Non-static) Inner Classes**
2. **Local Inner Classes**
3. **Anonymous Inner Classes**
4. **Static Nested Classes**

Let’s explore each type in detail.

---

### **1. Nested (Non-static) Inner Classes**
A **nested inner class** is a non-static class defined inside another class. It has access to all members (fields and methods) of the outer class, including private members.

#### **Key Features**:
- Can access outer class members directly.
- Cannot have static members (except static final fields).
- Must be instantiated using an instance of the outer class.

#### **Syntax**:
```java
class OuterClass {
    class InnerClass {
        // Inner class members
    }
}
```

#### **Example**:
```java
class Outer {
    private int outerField = 10;

    class Inner {
        void display() {
            System.out.println("Outer Field: " + outerField); // Access outer class field
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Outer outer = new Outer();
        Outer.Inner inner = outer.new Inner(); // Create inner class object
        inner.display();
    }
}
```
**Output**:
```
Outer Field: 10
```

---

### **2. Local Inner Classes**
A **local inner class** is a class defined inside a block of code (e.g., inside a method). It is only accessible within that block.

#### **Key Features**:
- Cannot have access modifiers (e.g., `public`, `private`).
- Can access final or effectively final local variables of the enclosing method.
- Cannot have static members.

#### **Syntax**:
```java
class OuterClass {
    void outerMethod() {
        class LocalInnerClass {
            // Local inner class members
        }
    }
}
```

#### **Example**:
```java
class Outer {
    void outerMethod() {
        final int localVar = 20;

        class LocalInner {
            void display() {
                System.out.println("Local Variable: " + localVar); // Access local variable
            }
        }

        LocalInner inner = new LocalInner();
        inner.display();
    }
}

public class Main {
    public static void main(String[] args) {
        Outer outer = new Outer();
        outer.outerMethod();
    }
}
```
**Output**:
```
Local Variable: 20
```

---

### **3. Anonymous Inner Classes**
An **anonymous inner class** is a class without a name, defined and instantiated in a single statement. It is often used to override methods of a class or interface.

#### **Key Features**:
- No explicit class definition.
- Can extend a class or implement an interface.
- Commonly used for event handling and thread creation.

#### **Syntax**:
```java
new SuperclassOrInterface() {
    // Override methods or define new ones
};
```

#### **Example**:
```java
interface Greeting {
    void greet();
}

public class Main {
    public static void main(String[] args) {
        Greeting greeting = new Greeting() {
            @Override
            public void greet() {
                System.out.println("Hello from anonymous inner class!");
            }
        };

        greeting.greet();
    }
}
```
**Output**:
```
Hello from anonymous inner class!
```

---

### **4. Static Nested Classes**
A **static nested class** is a static class defined inside another class. It does not have access to the instance members of the outer class.

#### **Key Features**:
- Can have static and non-static members.
- Does not require an instance of the outer class to be instantiated.
- Can access only static members of the outer class.

#### **Syntax**:
```java
class OuterClass {
    static class StaticNestedClass {
        // Static nested class members
    }
}
```

#### **Example**:
```java
class Outer {
    private static int staticField = 30;

    static class StaticNested {
        void display() {
            System.out.println("Static Field: " + staticField); // Access static field
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Outer.StaticNested nested = new Outer.StaticNested(); // Create static nested class object
        nested.display();
    }
}
```
**Output**:
```
Static Field: 30
```

---

### **5. Comparison of Inner Classes**

| Feature                | Nested Inner Class          | Local Inner Class           | Anonymous Inner Class       | Static Nested Class         |
|------------------------|-----------------------------|-----------------------------|-----------------------------|-----------------------------|
| **Access to Outer Class Members** | Yes (including private) | Yes (including private)     | Yes (including private)     | Only static members         |
| **Access Modifiers**   | Can have access modifiers   | No access modifiers         | No access modifiers         | Can have access modifiers   |
| **Static Members**     | Cannot have static members  | Cannot have static members  | Cannot have static members  | Can have static members     |
| **Instantiation**      | Requires outer class instance | Inside method only         | Defined and instantiated together | No outer class instance needed |
| **Use Case**           | Logical grouping            | Localized functionality     | Overriding methods          | Static utility classes      |

---

### **6. Example Program**
Here’s a complete example demonstrating all types of inner classes:

```java
class Outer {
    private int outerField = 10;
    private static int staticField = 20;

    // Nested inner class
    class Inner {
        void display() {
            System.out.println("Outer Field: " + outerField);
        }
    }

    // Local inner class
    void outerMethod() {
        final int localVar = 30;

        class LocalInner {
            void display() {
                System.out.println("Local Variable: " + localVar);
            }
        }

        LocalInner localInner = new LocalInner();
        localInner.display();
    }

    // Static nested class
    static class StaticNested {
        void display() {
            System.out.println("Static Field: " + staticField);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Nested inner class
        Outer outer = new Outer();
        Outer.Inner inner = outer.new Inner();
        inner.display();

        // Local inner class
        outer.outerMethod();

        // Static nested class
        Outer.StaticNested staticNested = new Outer.StaticNested();
        staticNested.display();

        // Anonymous inner class
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello from anonymous inner class!");
            }
        };
        runnable.run();
    }
}
```
**Output**:
```
Outer Field: 10
Local Variable: 30
Static Field: 20
Hello from anonymous inner class!
```

---

### **Conclusion**
Inner classes in Java provide a way to logically group classes, improve encapsulation, and increase code readability. By understanding the different types of inner classes—nested, local, anonymous, and static nested—you can choose the right approach for your specific use case. Whether you're organizing code, handling events, or creating utility classes, inner classes are a powerful tool in your Java programming toolkit. 
