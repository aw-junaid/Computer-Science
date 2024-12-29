### **Attributes and Methods in Object-Oriented Programming (OOP)**

In OOP, **attributes** and **methods** define the structure and behavior of an object. They are the building blocks of a class.

---

### **Attributes**

Attributes are the **data** or **variables** that describe the properties of an object. They represent the **state** of an object.

- **Instance Attributes**: Defined within the `__init__` method and unique to each object.  
- **Class Attributes**: Shared across all instances of a class. Defined directly in the class but outside any methods.

#### **Examples of Attributes**
```python
class Car:
    # Class attribute
    wheels = 4

    def __init__(self, brand, color):
        # Instance attributes
        self.brand = brand
        self.color = color

# Creating objects
car1 = Car("Toyota", "Red")
car2 = Car("Honda", "Blue")

# Accessing attributes
print(car1.brand)  # Output: Toyota
print(car2.color)  # Output: Blue
print(Car.wheels)  # Output: 4
```

---

### **Methods**

Methods are **functions** defined inside a class that describe the behavior of an object. They operate on the object’s attributes and can perform specific actions.

- **Instance Methods**: Operate on instance attributes. Require `self` as their first parameter.
- **Class Methods**: Operate on class attributes. Use the `@classmethod` decorator and require `cls` as their first parameter.
- **Static Methods**: Perform general tasks and do not depend on class or instance attributes. Use the `@staticmethod` decorator.

#### **Examples of Methods**
```python
class Circle:
    def __init__(self, radius):
        self.radius = radius  # Instance attribute

    # Instance method
    def area(self):
        return 3.14 * self.radius ** 2

    # Class method
    @classmethod
    def description(cls):
        return "This is a Circle class"

    # Static method
    @staticmethod
    def pi():
        return 3.14

# Creating an object
circle1 = Circle(5)

# Calling methods
print(circle1.area())  # Output: 78.5 (Instance method)
print(Circle.description())  # Output: This is a Circle class (Class method)
print(Circle.pi())  # Output: 3.14 (Static method)
```

---

### **Key Differences**

| **Feature**       | **Attributes**                          | **Methods**                          |
|--------------------|------------------------------------------|---------------------------------------|
| **Definition**     | Data stored in an object                | Functions defining behavior           |
| **Scope**          | Instance or Class level                 | Instance, Class, or Static            |
| **Access**         | `object.attribute`                     | `object.method()`                     |
| **Example**        | `car.color`                            | `car.drive()`                         |

---

### **Summary**

- **Attributes** define what an object **has** (e.g., `brand`, `color` of a car).  
- **Methods** define what an object **does** (e.g., `drive`, `stop` of a car).  

