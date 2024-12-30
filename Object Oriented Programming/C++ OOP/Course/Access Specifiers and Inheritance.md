### **Access Specifiers and Inheritance in C++**

In C++, **access specifiers** define the accessibility of members (variables, functions) of a class. They determine how and where members of a class can be accessed from other parts of the program. The three main access specifiers are:

- **`public`**: Members are accessible from anywhere.
- **`protected`**: Members are accessible within the class and by derived classes.
- **`private`**: Members are only accessible within the class itself.

When inheritance is involved, the access level of the members inherited from the base class is influenced by the type of inheritance and the access specifier applied to it. Let's go over how **access specifiers** work in the context of **inheritance**.

---

### **1. Public Inheritance**
When a class is inherited publicly, the public and protected members of the base class retain their access levels in the derived class. However, private members of the base class are not inherited.

#### **Syntax**:
```cpp
class Derived : public Base {
    // Derived class members
};
```

#### **Example**:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }
    
protected:
    int protectedVar;
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }

private:
    int privateVar;
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }
};

class Derived : public Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible (public member)
        publicMethod();    // Accessible (public method)
        
        protectedVar = 20; // Accessible (protected member)
        protectedMethod(); // Accessible (protected method)
        
        // privateVar = 30;  // Not Accessible (private member)
        // privateMethod();  // Not Accessible (private method)
    }
};

int main() {
    Derived d;
    d.accessBase();
    return 0;
}
```

**Output:**
```
Public method of Base class
Protected method of Base class
```

**Explanation**:
- In **public inheritance**, the public and protected members of the base class (`publicVar`, `publicMethod`, `protectedVar`, and `protectedMethod`) are accessible in the derived class.
- The private members (`privateVar`, `privateMethod`) are not accessible in the derived class.

---

### **2. Protected Inheritance**
In **protected inheritance**, the public and protected members of the base class become **protected** in the derived class. This means that they can be accessed by the derived class and further derived classes, but not by code outside the inheritance hierarchy.

#### **Syntax**:
```cpp
class Derived : protected Base {
    // Derived class members
};
```

#### **Example**:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }
    
protected:
    int protectedVar;
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }

private:
    int privateVar;
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }
};

class Derived : protected Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible (public member, but becomes protected)
        publicMethod();    // Accessible (public method, but becomes protected)
        
        protectedVar = 20; // Accessible (protected member)
        protectedMethod(); // Accessible (protected method)
        
        // privateVar = 30;  // Not Accessible (private member)
        // privateMethod();  // Not Accessible (private method)
    }
};

int main() {
    Derived d;
    d.accessBase();
    // d.publicVar = 10; // Error: publicVar is now protected in Derived class
    return 0;
}
```

**Explanation**:
- In **protected inheritance**, the public members of the base class become **protected** in the derived class.
- As a result, they cannot be accessed directly from outside the derived class (e.g., `d.publicVar` in `main()` would cause an error).
- Private members of the base class are still inaccessible.

---

### **3. Private Inheritance**
In **private inheritance**, all members (public, protected, and private) of the base class become **private** in the derived class. This means they can only be accessed within the derived class and are not accessible to outside code or even further derived classes.

#### **Syntax**:
```cpp
class Derived : private Base {
    // Derived class members
};
```

#### **Example**:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }
    
protected:
    int protectedVar;
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }

private:
    int privateVar;
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }
};

class Derived : private Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible (becomes private in Derived)
        publicMethod();    // Accessible (becomes private in Derived)
        
        protectedVar = 20; // Accessible (becomes private in Derived)
        protectedMethod(); // Accessible (becomes private in Derived)
        
        // privateVar = 30;  // Not Accessible (private member)
        // privateMethod();  // Not Accessible (private method)
    }
};

int main() {
    Derived d;
    d.accessBase();
    // d.publicVar = 10;  // Error: publicVar is now private in Derived class
    return 0;
}
```

**Explanation**:
- In **private inheritance**, all inherited members from the base class (including public and protected members) become **private** in the derived class.
- These members are not accessible outside the derived class or by any further derived classes.

---

### **Access Specifiers Summary in Inheritance**

| **Base Class Member** | **Public Inheritance** | **Protected Inheritance** | **Private Inheritance** |
|-----------------------|------------------------|---------------------------|-------------------------|
| **Public Members**     | Accessible (public)     | Accessible (protected)    | Accessible (private)    |
| **Protected Members**  | Accessible (protected)  | Accessible (protected)    | Accessible (private)    |
| **Private Members**    | Not Accessible          | Not Accessible            | Not Accessible          |

---

### **Example with All Three Inheritance Types**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }

protected:
    int protectedVar;
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }

private:
    int privateVar;
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }
};

// Public inheritance
class PublicDerived : public Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible
        protectedVar = 20; // Accessible
        // privateVar = 30;  // Not Accessible
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible
        protectedVar = 20; // Accessible
        // privateVar = 30;  // Not Accessible
    }
};

// Private inheritance
class PrivateDerived : private Base {
public:
    void accessBase() {
        publicVar = 10;    // Accessible
        protectedVar = 20; // Accessible
        // privateVar = 30;  // Not Accessible
    }
};

int main() {
    PublicDerived p;
    p.accessBase();
    // p.publicVar = 10;  // Accessible

    ProtectedDerived pr;
    pr.accessBase();
    // pr.publicVar = 10; // Error: publicVar is protected in ProtectedDerived

    PrivateDerived priv;
    priv.accessBase();
    // priv.publicVar = 10; // Error: publicVar is private in PrivateDerived

    return 0;
}
```

---

### **Conclusion**

- **Public inheritance**: The inherited members retain their original access levels (public, protected) in the derived class.
- **Protected inheritance**: Public and protected members of the base class become protected in the derived class.
- **Private inheritance**: All inherited members become private in the derived class, and are not accessible outside.

Access specifiers allow you to control how the members of a class can be accessed and modified, especially when you are designing a class hierarchy with inheritance.
