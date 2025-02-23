In Java, **access modifiers** control the visibility and accessibility of classes, methods, and fields. They determine which parts of your code can access or modify certain elements. Java provides four access modifiers:

1. **`public`**
2. **`private`**
3. **`protected`**
4. **`default` (no modifier)**

Let’s explore each of these in detail.

---

### **1. `public` Access Modifier**
- The `public` access modifier makes a class, method, or field accessible from **anywhere**.
- It has the widest scope of all access modifiers.

#### **Example**:
```java
// Public class
public class MyClass {
    // Public field
    public int publicField = 10;

    // Public method
    public void publicMethod() {
        System.out.println("This is a public method.");
    }
}

// Accessing public members from another class
public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        System.out.println(obj.publicField); // Access public field
        obj.publicMethod(); // Call public method
    }
}
```
**Output**:
```
10
This is a public method.
```

---

### **2. `private` Access Modifier**
- The `private` access modifier restricts access to the **same class** only.
- It is used to encapsulate and hide the internal details of a class.

#### **Example**:
```java
class MyClass {
    // Private field
    private int privateField = 20;

    // Private method
    private void privateMethod() {
        System.out.println("This is a private method.");
    }

    // Public method to access private members
    public void accessPrivateMembers() {
        System.out.println(privateField); // Access private field
        privateMethod(); // Call private method
    }
}

public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        obj.accessPrivateMembers(); // Access private members via public method
    }
}
```
**Output**:
```
20
This is a private method.
```

---

### **3. `protected` Access Modifier**
- The `protected` access modifier allows access within the **same package** and by **subclasses** (even if they are in different packages).
- It is commonly used in inheritance.

#### **Example**:
```java
// Base class
class BaseClass {
    // Protected field
    protected int protectedField = 30;

    // Protected method
    protected void protectedMethod() {
        System.out.println("This is a protected method.");
    }
}

// Subclass in the same package
class SubClass extends BaseClass {
    void accessProtectedMembers() {
        System.out.println(protectedField); // Access protected field
        protectedMethod(); // Call protected method
    }
}

public class Main {
    public static void main(String[] args) {
        SubClass obj = new SubClass();
        obj.accessProtectedMembers(); // Access protected members via subclass
    }
}
```
**Output**:
```
30
This is a protected method.
```

---

### **4. `default` Access Modifier**
- The `default` access modifier (no keyword) allows access within the **same package** only.
- If no access modifier is specified, the member has default access.

#### **Example**:
```java
// Class with default access
class MyClass {
    // Default field
    int defaultField = 40;

    // Default method
    void defaultMethod() {
        System.out.println("This is a default method.");
    }
}

// Accessing default members from another class in the same package
public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        System.out.println(obj.defaultField); // Access default field
        obj.defaultMethod(); // Call default method
    }
}
```
**Output**:
```
40
This is a default method.
```

---

### **5. Summary of Access Modifiers**

| Access Modifier | Same Class | Same Package | Subclass (Different Package) | Different Package |
|-----------------|------------|--------------|------------------------------|-------------------|
| `public`        | Yes        | Yes          | Yes                          | Yes               |
| `protected`     | Yes        | Yes          | Yes                          | No                |
| `default`       | Yes        | Yes          | No                           | No                |
| `private`       | Yes        | No           | No                           | No                |

---

### **6. Best Practices**
1. **Encapsulation**: Use `private` for fields and provide `public` getter/setter methods to control access.
2. **Minimize Scope**: Use the most restrictive access modifier possible to reduce unintended access.
3. **Use `protected` for Inheritance**: Use `protected` for fields and methods that need to be accessible in subclasses.
4. **Avoid `default`**: Explicitly specify access modifiers instead of relying on the default.

---

### **7. Example Program**
Here’s a complete example demonstrating all access modifiers:

```java
// Public class
public class MyClass {
    // Public field
    public int publicField = 10;

    // Private field
    private int privateField = 20;

    // Protected field
    protected int protectedField = 30;

    // Default field
    int defaultField = 40;

    // Public method
    public void publicMethod() {
        System.out.println("This is a public method.");
    }

    // Private method
    private void privateMethod() {
        System.out.println("This is a private method.");
    }

    // Protected method
    protected void protectedMethod() {
        System.out.println("This is a protected method.");
    }

    // Default method
    void defaultMethod() {
        System.out.println("This is a default method.");
    }

    // Method to access private members
    public void accessPrivateMembers() {
        System.out.println("Private Field: " + privateField);
        privateMethod();
    }
}

// Subclass in the same package
class SubClass extends MyClass {
    void accessProtectedMembers() {
        System.out.println("Protected Field: " + protectedField);
        protectedMethod();
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();

        // Access public members
        System.out.println("Public Field: " + obj.publicField);
        obj.publicMethod();

        // Access private members via public method
        obj.accessPrivateMembers();

        // Access protected members via subclass
        SubClass subObj = new SubClass();
        subObj.accessProtectedMembers();

        // Access default members
        System.out.println("Default Field: " + obj.defaultField);
        obj.defaultMethod();
    }
}
```
**Output**:
```
Public Field: 10
This is a public method.
Private Field: 20
This is a private method.
Protected Field: 30
This is a protected method.
Default Field: 40
This is a default method.
```

---

### **Conclusion**
Access modifiers are essential for controlling the visibility and accessibility of classes, methods, and fields in Java. By using them effectively, you can enforce encapsulation, improve code security, and design robust, maintainable applications.
