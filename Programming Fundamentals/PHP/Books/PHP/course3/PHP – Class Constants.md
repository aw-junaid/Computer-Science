### PHP – Class Constants

In PHP, **class constants** are values that are defined within a class and remain constant (unchangeable) throughout the program. These constants are similar to regular constants in PHP, but they are specific to the class in which they are declared.

Class constants are typically used to define values that should remain the same for all instances of the class, such as configuration settings, error codes, or fixed values that belong to the class.

### Defining Class Constants

Class constants are defined using the `const` keyword, followed by the constant name and value. The constant name should follow the usual rules for constant naming, i.e., in uppercase letters by convention.

#### Syntax:
```php
class ClassName {
    const CONSTANT_NAME = 'value';
}
```

### Key Points:
- Class constants are accessed using the `ClassName::CONSTANT_NAME` syntax.
- Class constants cannot be changed once defined. They are **immutable**.
- They can be accessed without creating an instance of the class (i.e., statically).

### Example of Class Constants:

```php
<?php
class Car {
    // Defining a class constant
    const WHEELS = 4;
    const TYPE = 'Sedan';

    public function showDetails() {
        // Accessing class constants inside methods
        echo "This car has " . self::WHEELS . " wheels and is a " . self::TYPE . ".<br>";
    }
}

// Accessing class constants outside the class
echo "The car has " . Car::WHEELS . " wheels.<br>";
echo "The car is a " . Car::TYPE . ".<br>";

// Creating an object of the class
$car = new Car();
$car->showDetails();  // Output: This car has 4 wheels and is a Sedan.
?>
```

### Explanation:
- In this example, the `Car` class defines two constants, `WHEELS` and `TYPE`.
- We access these constants both **statically** (using `Car::WHEELS`) and **within methods** (using `self::WHEELS`).
- The `self::` keyword is used inside the class to refer to its own constants (and static methods or properties), while `ClassName::` is used outside the class to refer to constants.

### Access Modifiers for Class Constants

By default, class constants are **public**, meaning they can be accessed from anywhere. However, you can also specify the visibility of class constants using the access modifiers: `public`, `protected`, or `private`.

#### Example with Visibility Modifiers:

```php
<?php
class Vehicle {
    // Public constant (can be accessed from anywhere)
    public const TYPE = 'Vehicle';
    
    // Protected constant (can only be accessed inside the class and its subclasses)
    protected const MAX_SPEED = 120;
    
    // Private constant (can only be accessed within the class itself)
    private const MIN_SPEED = 0;
}

echo Vehicle::TYPE;  // Accessing public constant: Output - Vehicle
echo Vehicle::MAX_SPEED;  // Error: Cannot access protected constant
echo Vehicle::MIN_SPEED;  // Error: Cannot access private constant
?>
```

### Conclusion

- **Class constants** in PHP allow you to define values that are associated with a class and remain constant throughout the program.
- Constants are **immutable**, meaning they cannot be changed once set.
- You can define constants with different **visibility** (public, protected, or private) to control their accessibility.
- Constants are accessed using the class name (`ClassName::CONSTANT_NAME`) or `self::` within the class.
