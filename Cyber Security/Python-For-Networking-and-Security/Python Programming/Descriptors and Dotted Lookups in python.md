Descriptors and dotted lookups are advanced topics in Python that involve customizing attribute access and modification behavior. They are used to control how attributes are accessed, assigned, or deleted within an object. Descriptors are objects that define the behavior of attribute access, and dotted lookups refer to the process of accessing attributes using dot notation (`object.attribute`).

**Descriptors:**

Descriptors are a mechanism that allows you to define custom behavior for attribute access, assignment, or deletion. They are usually implemented as classes with special methods like `__get__`, `__set__`, and `__delete__`. Descriptors are often used to create computed attributes, properties, or manage the behavior of attributes.

Here's a basic example of a descriptor:

```python
class Descriptor:
    def __get__(self, instance, owner):
        return f"Getting value: {instance._value}"

    def __set__(self, instance, value):
        instance._value = value

class MyClass:
    def __init__(self, value):
        self._value = value

    descriptor = Descriptor()

obj = MyClass(42)
print(obj.descriptor)   # Output: Getting value: 42

obj.descriptor = 100
print(obj.descriptor)   # Output: Getting value: 100
```

In this example, the `Descriptor` class defines custom behavior for getting and setting the attribute. The `__get__` method is called when the attribute is accessed, and the `__set__` method is called when the attribute is assigned.

**Dotted Lookups:**

Dotted lookups refer to the process of accessing attributes using dot notation. Python follows a sequence of attribute resolution steps to find the appropriate attribute in an object. The sequence includes searching the instance dictionary, class dictionary, and base classes in a specific order.

```python
class A:
    x = 10

class B(A):
    pass

class C(B):
    y = 20

obj = C()
print(obj.x)  # Output: 10 (found in class A)
print(obj.y)  # Output: 20 (found in class C)
```

In this example, `obj.x` is found in class `A`, and `obj.y` is found in class `C`.

Descriptors and dotted lookups provide powerful ways to customize attribute access and manage attribute behavior in Python classes. While descriptors offer fine-grained control over attribute behavior, dotted lookups define the order in which attributes are searched for within an object's class hierarchy.
