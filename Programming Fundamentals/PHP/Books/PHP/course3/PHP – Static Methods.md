### PHP – Static Methods

In PHP, **static methods** belong to the class itself rather than to instances of the class. This means they can be called directly on the class without needing to instantiate an object of that class. Static methods are useful when you need to perform operations that are independent of object instances, such as utility functions, configuration settings, or common behavior shared by all instances of the class.

### Key Concepts:
1. **Belong to the Class**: Static methods are associated with the class, not objects of the class.
2. **Accessed via the Class Name**: You can call static methods using the class name, rather than creating an instance of the class.
3. **Cannot Access Instance Variables**: Static methods can only access other static properties or methods within the class. They cannot access non-static properties or methods.
4. **Use `self` Keyword**: Within a static method, you can refer to other static properties or methods in the same class using `self::`.
5. **Static Variables**: Static methods can also work with static variables, which maintain their values between method calls.

### Defining and Using Static Methods

To define a static method, use the `static` keyword before the method definition.

#### Syntax:
```php
class ClassName {
    public static function methodName() {
        // method implementation
    }
}
```

### Example of Static Method

```php
<?php
class Calculator {
    // Static method to add two numbers
    public static function add($a, $b) {
        return $a + $b;
    }

    // Static method to multiply two numbers
    public static function multiply($a, $b) {
        return $a * $b;
    }
}

// Calling static methods without creating an instance
echo Calculator::add(5, 3);        // Output: 8
echo "<br>";
echo Calculator::multiply(4, 7);   // Output: 28
?>
```

### Explanation:
- The `Calculator` class contains two static methods: `add()` and `multiply()`.
- Both methods are called directly on the class using the `::` syntax, without creating an instance of `Calculator`.
- This is a common pattern for utility or helper methods that don't rely on object state.

### Accessing Static Properties

Static methods can also access static properties within the class. Static properties are variables that belong to the class, not instances of it.

```php
<?php
class Counter {
    public static $count = 0;  // Static property
    
    public static function increment() {
        self::$count++;  // Accessing static property
    }
    
    public static function getCount() {
        return self::$count;
    }
}

Counter::increment();
Counter::increment();

echo Counter::getCount();  // Output: 2
?>
```

### Explanation:
- The `Counter` class has a static property `$count`, which is shared by all instances of the class.
- The `increment()` method increases the `$count` property, and `getCount()` returns the current value of `$count`.
- The static property is accessed and modified via `self::$count` inside the static methods.

### Static Methods with `self::` Keyword

Inside a static method, you can use the `self::` keyword to reference other static methods or static properties in the same class.

```php
<?php
class Math {
    public static $pi = 3.14159;

    public static function areaOfCircle($radius) {
        return self::$pi * $radius * $radius;  // Using static property
    }

    public static function circumferenceOfCircle($radius) {
        return 2 * self::$pi * $radius;  // Using static property
    }
}

echo Math::areaOfCircle(5);           // Output: 78.53975
echo "<br>";
echo Math::circumferenceOfCircle(5);  // Output: 31.4159
?>
```

### Explanation:
- The `Math` class contains a static property `$pi`, which is accessed within the static methods using `self::$pi`.
- The static methods calculate the area and circumference of a circle using the static property.

### Static Methods and Inheritance

Static methods are inherited by child classes, but they cannot be overridden in the traditional sense. They can be redeclared in the subclass, but this would hide the parent method.

```php
<?php
class Animal {
    public static function sound() {
        echo "Generic animal sound.<br>";
    }
}

class Dog extends Animal {
    // Redeclaring the static method
    public static function sound() {
        echo "Bark!<br>";
    }
}

Animal::sound();  // Output: Generic animal sound.
Dog::sound();     // Output: Bark!
?>
```

### Explanation:
- The `sound()` method is declared as static in both the `Animal` and `Dog` classes.
- The `Dog` class redeclares the `sound()` method, and when calling `Dog::sound()`, the child class method is invoked.
- Static methods are not polymorphic (like instance methods), so redeclaring a static method does not override the parent method; it hides it.

### Limitations of Static Methods:
- **Cannot access instance methods/properties**: Static methods cannot access or modify instance methods or properties, as they are not tied to a specific object.
- **Not polymorphic**: Static methods do not follow the same polymorphism rules as instance methods. If a class redeclares a static method, it will hide the parent class's static method, rather than overriding it.

### When to Use Static Methods?

- **Utility Functions**: When the method performs a task that doesn’t depend on object state (e.g., math functions, string manipulation).
- **Singleton Pattern**: When implementing a Singleton pattern to ensure only one instance of a class exists, you often use static methods to access the single instance.
- **Global State**: When you need to maintain a global state that should be shared across all instances of a class, like a configuration setting or shared resource.

### Conclusion

- **Static methods** belong to a class rather than an instance, and can be accessed using the class name (`ClassName::methodName()`).
- They are ideal for utility functions or scenarios where the method does not depend on the object instance state.
- Static methods can access other static properties and methods using `self::`.
- They are inherited but not polymorphic, so redeclaring them in subclasses hides the parent’s static method.
