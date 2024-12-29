### **The `@property` Decorator in Python**

The `@property` decorator in Python is a built-in decorator that provides a **Pythonic way** to define getter and setter methods. It allows you to define methods that can be accessed like attributes, which means you can access them without needing to call them explicitly as methods. This approach makes your code cleaner, more readable, and easier to use.

---

### **How `@property` Works**

- **Getter**: The `@property` decorator is applied to a method to make it a property. This allows the method to be accessed as an attribute.
- **Setter**: You can also define a setter method for a property using `@<property_name>.setter`, which allows you to control how the property is set (e.g., validating the value).

---

### **Basic Usage of `@property`**

#### **Example: Getter Method with `@property`**
```python
class Rectangle:
    def __init__(self, length, width):
        self.__length = length  # Private attribute
        self.__width = width    # Private attribute
    
    # Getter for length using property
    @property
    def length(self):
        return self.__length
    
    # Getter for width using property
    @property
    def width(self):
        return self.__width

# Create an object
rect = Rectangle(5, 3)

# Access properties as if they were regular attributes
print(rect.length)  # Output: 5
print(rect.width)   # Output: 3
```

In this example, `length` and `width` are defined as properties using `@property`, and they can be accessed directly like attributes. Even though they are methods, you access them like attributes without parentheses.

---

### **Setter Method with `@<property_name>.setter`**

To allow modification of a property, you can define a setter method using the `@<property_name>.setter` decorator. The setter method allows you to control how the value is set.

#### **Example: Setter Method with `@property`**
```python
class Rectangle:
    def __init__(self, length, width):
        self.__length = length  # Private attribute
        self.__width = width    # Private attribute
    
    # Getter for length using property
    @property
    def length(self):
        return self.__length
    
    # Setter for length using property
    @length.setter
    def length(self, value):
        if value <= 0:
            raise ValueError("Length must be greater than zero")
        self.__length = value
    
    # Getter for width using property
    @property
    def width(self):
        return self.__width
    
    # Setter for width using property
    @width.setter
    def width(self, value):
        if value <= 0:
            raise ValueError("Width must be greater than zero")
        self.__width = value

# Create an object
rect = Rectangle(5, 3)

# Access properties as if they were regular attributes
print(rect.length)  # Output: 5
print(rect.width)   # Output: 3

# Modify properties using setter methods
rect.length = 10    # Valid
print(rect.length)  # Output: 10

# Invalid setter example (raises ValueError)
# rect.length = -2  # Raises ValueError: Length must be greater than zero
```

In this example:
- The **getter** allows you to read the value of `length` and `width`.
- The **setter** allows you to update the values of `length` and `width`, with validation to ensure the new values are positive.

---

### **Advantages of Using `@property`**

1. **Cleaner Code**: You can access methods like regular attributes, which simplifies the interface.
2. **Encapsulation**: You can hide the internal implementation of a property (e.g., private variables) while exposing a simple API.
3. **Validation**: The setter allows you to validate or modify the data before it's set, ensuring the object maintains a valid state.
4. **Lazy Evaluation**: Getters can be used for **lazy evaluation**, meaning the property can be computed or fetched when needed.

---

### **Read-Only Property**

You can create a read-only property by only providing a **getter method** without a setter. This means the value can be accessed, but not modified.

#### **Example: Read-Only Property**
```python
class Circle:
    def __init__(self, radius):
        self.__radius = radius
    
    # Getter for radius using property
    @property
    def radius(self):
        return self.__radius
    
    # Read-only property: Area of the circle
    @property
    def area(self):
        return 3.14159 * (self.__radius ** 2)

# Create a Circle object
circle = Circle(5)

# Access read-only properties
print(circle.radius)  # Output: 5
print(circle.area)    # Output: 78.53975

# Attempting to set the read-only property will raise an error
# circle.radius = 10  # Raises AttributeError: can't set attribute
```

In this example:
- `radius` is a **read-only** property.
- `area` is also a **read-only** property that calculates the area based on `radius`.

---

### **Write-Only Property**

You can also create **write-only** properties by defining only the **setter** and not providing a getter. This allows the value to be set, but not accessed directly.

#### **Example: Write-Only Property**
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

# Attempting to access salary will raise an error
# print(employee.salary)  # Raises AttributeError: Salary is write-only!
```

In this example, `salary` is **write-only**, as we provide only a setter method and no getter.

---

### **Best Practices for Using `@property`**

1. **Use `@property` for calculated or read-only attributes**: If you need to compute a value based on other data, use `@property` to make the method behave like an attribute.
2. **Use setter for validation**: Always validate data before setting it to ensure the object remains in a valid state.
3. **Readability and simplicity**: Use `@property` to simplify your code. This makes your API easier to understand because users can access methods like attributes.

---

### **When Not to Use `@property`**

- If you need to perform an operation that requires input arguments, `@property` is not suitable because properties can't accept parameters beyond `self`.
- If performance is critical and you have complex calculations that need to be cached, consider using explicit getter methods or caching techniques instead of `@property`.

---
