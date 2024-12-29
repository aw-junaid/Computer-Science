### **Getters and Setters in Python**

In Object-Oriented Programming (OOP), **getters** and **setters** are methods used to access (get) or modify (set) private attributes of a class. This technique is used to enforce **encapsulation** by controlling access to the private data of objects.

---

### **Why Use Getters and Setters?**

- **Encapsulation**: Protect the internal state of an object by restricting direct access to its attributes.
- **Validation**: Allow validation of data before setting it, ensuring that the object remains in a valid state.
- **Read-only or Write-only**: You can make some attributes read-only or write-only by providing only getters or setters, respectively.

---

### **Traditional Getter and Setter Methods**

#### **Syntax**
```python
class ClassName:
    def __init__(self):
        self.__attribute = value
    
    def get_attribute(self):  # Getter
        return self.__attribute

    def set_attribute(self, value):  # Setter
        self.__attribute = value
```

- **Getter**: A method to get the value of a private attribute.
- **Setter**: A method to set the value of a private attribute, with optional validation.

#### **Example**
```python
class Person:
    def __init__(self, name, age):
        self.__name = name  # Private attribute
        self.__age = age    # Private attribute
    
    # Getter for name
    def get_name(self):
        return self.__name
    
    # Setter for name
    def set_name(self, name):
        self.__name = name
    
    # Getter for age
    def get_age(self):
        return self.__age
    
    # Setter for age with validation
    def set_age(self, age):
        if age < 0:
            print("Age cannot be negative!")
        else:
            self.__age = age

# Create an object
person = Person("Alice", 25)

# Access attributes via getter methods
print(person.get_name())  # Output: Alice

# Modify attributes via setter methods
person.set_name("Bob")
print(person.get_name())  # Output: Bob

person.set_age(30)  # Valid age
print(person.get_age())  # Output: 30

person.set_age(-5)  # Invalid age, prints error message
```

---

### **Property Decorators (Pythonic Approach)**

Python provides a **cleaner and more Pythonic** way to define getters and setters using the `@property` decorator for getters and `@<property_name>.setter` for setters. This allows you to access the getter and setter methods like normal attributes, without explicitly calling them as methods.

#### **Getter with `@property`**
The `@property` decorator allows you to define a method as a property, enabling it to be accessed like an attribute.

#### **Setter with `@<property_name>.setter`**
The `@<property_name>.setter` decorator allows you to define a setter for a property, enabling you to control how the value is set.

---

### **Example Using Property Decorators**
```python
class Person:
    def __init__(self, name, age):
        self.__name = name  # Private attribute
        self.__age = age    # Private attribute
    
    # Getter for name using property decorator
    @property
    def name(self):
        return self.__name
    
    # Setter for name using property decorator
    @name.setter
    def name(self, value):
        self.__name = value
    
    # Getter for age using property decorator
    @property
    def age(self):
        return self.__age
    
    # Setter for age with validation using property decorator
    @age.setter
    def age(self, value):
        if value < 0:
            print("Age cannot be negative!")
        else:
            self.__age = value

# Create an object
person = Person("Alice", 25)

# Access attributes as if they were regular attributes
print(person.name)  # Output: Alice
print(person.age)   # Output: 25

# Modify attributes via setter methods
person.name = "Bob"
print(person.name)  # Output: Bob

person.age = 30     # Valid age
print(person.age)   # Output: 30

person.age = -5     # Invalid age, prints error message
```

---

### **Advantages of Using Property Decorators**

1. **Cleaner Code**: You can access methods like attributes without explicitly calling getter/setter functions.
2. **Encapsulation**: You can still control access to the underlying private data while maintaining a simple interface.
3. **Validation**: The setter method allows you to easily add data validation without breaking the external interface.

---

### **Read-Only Properties**
A property can be defined with only a getter, making it **read-only**. The user can read the value but cannot modify it.

```python
class Circle:
    def __init__(self, radius):
        self.__radius = radius
    
    # Read-only property for radius
    @property
    def radius(self):
        return self.__radius
    
    # Area is a read-only property calculated from radius
    @property
    def area(self):
        return 3.14159 * (self.__radius ** 2)

# Create a Circle object
circle = Circle(5)

print(circle.radius)  # Output: 5
print(circle.area)    # Output: 78.53975

# Trying to modify the read-only property will raise an error
# circle.radius = 10  # Raises AttributeError
```

---

### **Write-Only Properties**
You can define a property with only a setter, making it **write-only**. The user can set the value but cannot access it directly.

```python
class Employee:
    def __init__(self):
        self.__salary = 0
    
    # Write-only property for salary
    @property
    def salary(self):
        raise AttributeError("Salary is write-only!")
    
    @salary.setter
    def salary(self, value):
        if value < 0:
            print("Salary cannot be negative!")
        else:
            self.__salary = value

# Create an Employee object
employee = Employee()

# Set salary using setter
employee.salary = 50000
# Trying to get salary directly will raise an error
# print(employee.salary)  # Raises AttributeError: Salary is write-only!
```

---

### **Best Practices for Getters and Setters**

1. **Use `@property` for cleaner code**: It allows you to access methods as if they were attributes.
2. **Encapsulation**: Keep private attributes and control access to them through getter and setter methods.
3. **Validation**: Always validate the values in the setter to ensure object integrity.
