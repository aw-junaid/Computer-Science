### **Overriding Methods in Python**

**Method Overriding** occurs when a subclass defines a method that has the same name and signature as a method in its parent class, effectively replacing or modifying the behavior of the parent class's method. This is one of the core concepts in inheritance and allows you to customize or extend the functionality of inherited methods in subclasses.

---

### **Why Use Method Overriding?**
- **Customization**: Overriding allows you to provide a new, more specific implementation of a method in the subclass.
- **Polymorphism**: It allows different subclasses to have their own specific implementation of the same method, leading to polymorphism (the ability to treat objects of different types in a uniform way).

---

### **Syntax for Overriding Methods**

When you override a method in a subclass, you define a method with the same name as the method in the parent class. The new method in the subclass will be called instead of the one from the parent class.

```python
class ParentClass:
    def method_name(self):
        # Parent class implementation
        pass

class ChildClass(ParentClass):
    def method_name(self):
        # Overridden method in the child class
        pass
```

---

### **Example of Overriding Methods**

Let's take an example where we have a parent class `Animal` and a subclass `Dog` that overrides the `speak()` method.

```python
# Parent class
class Animal:
    def speak(self):
        return "Animal makes a sound"

# Subclass Dog that overrides the speak method
class Dog(Animal):
    def speak(self):
        return "Dog barks"

# Subclass Cat that overrides the speak method
class Cat(Animal):
    def speak(self):
        return "Cat meows"

# Create instances
animal = Animal()
dog = Dog()
cat = Cat()

# Call the overridden method in each class
print(animal.speak())  # Output: Animal makes a sound
print(dog.speak())     # Output: Dog barks
print(cat.speak())     # Output: Cat meows
```

### **Explanation:**
1. The `Animal` class defines a `speak()` method.
2. The `Dog` and `Cat` classes override the `speak()` method with their own implementations.
3. When you call the `speak()` method on an instance of `Dog`, the `Dog` version of the method is executed, and similarly for `Cat`.

---

### **Calling the Parent Class Method**

Sometimes, you might want to call the parent class's method in addition to the overridden method in the child class. You can do this using the `super()` function.

#### **Example: Calling Parent Method Using `super()`**

```python
class Animal:
    def speak(self):
        return "Animal makes a sound"

class Dog(Animal):
    def speak(self):
        # Call the parent class's speak method
        parent_speak = super().speak()
        return f"{parent_speak} but Dog barks."

# Create an instance of Dog
dog = Dog()
print(dog.speak())  # Output: Animal makes a sound but Dog barks.
```

Here, `super().speak()` calls the `speak()` method from the parent class (`Animal`), and then we add the behavior specific to the `Dog` class.

---

### **Overriding Methods with Arguments**

When overriding a method, the signature (parameters) of the method must remain the same. You can still add additional functionality or modify the behavior based on the arguments passed.

```python
class Animal:
    def speak(self, sound="makes a sound"):
        return f"Animal {sound}"

class Dog(Animal):
    def speak(self, sound="barks"):
        return f"Dog {sound}"

# Create instances
animal = Animal()
dog = Dog()

# Call methods
print(animal.speak())     # Output: Animal makes a sound
print(dog.speak())        # Output: Dog barks
print(dog.speak("howls")) # Output: Dog howls
```

In this example:
- The `Animal` class has a method that takes a `sound` argument.
- The `Dog` class overrides `speak()` and provides its own default value for `sound`, but it can still accept arguments.

---

### **Overriding with `super()` and Arguments**

You can use `super()` to call the parent class’s method with arguments.

```python
class Animal:
    def speak(self, sound="makes a sound"):
        return f"Animal {sound}"

class Dog(Animal):
    def speak(self, sound="barks"):
        parent_speak = super().speak(sound)
        return f"{parent_speak} but Dog barks."

# Create an instance of Dog
dog = Dog()
print(dog.speak())         # Output: Animal barks but Dog barks.
print(dog.speak("howls"))  # Output: Animal howls but Dog barks.
```

In this case, `super().speak(sound)` calls the `speak()` method from the `Animal` class, passing the `sound` argument.

---

### **When to Override Methods?**

- **Customization**: Override methods when you need to change the behavior of the parent class for the subclass.
- **Polymorphism**: When you have multiple subclasses, you might want them to behave differently for the same method, while maintaining a uniform interface.
- **Code Reusability**: Instead of writing the same logic in each subclass, override the parent method when you need to add custom logic without rewriting the entire method.

---

### **Key Points to Remember About Method Overriding:**

1. **Method Signature**: The method name and the parameters must remain the same when overriding.
2. **Polymorphism**: Method overriding enables polymorphism, allowing different classes to have their own version of a method.
3. **Calling Parent Methods**: You can call the parent class's method using `super()` if you want to keep the functionality of the parent class and extend it in the child class.
4. **Method Resolution Order (MRO)**: In case of multiple inheritance, Python uses the method resolution order (MRO) to determine the order in which methods are called.

---
