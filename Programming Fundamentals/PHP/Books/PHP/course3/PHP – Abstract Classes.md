### PHP – Abstract Classes

An **abstract class** in PHP is a class that cannot be instantiated directly. It is meant to be subclassed by other classes. Abstract classes are used to define the structure for other classes and to implement some methods, while leaving other methods unimplemented for the child classes to define.

### Key Concepts:
1. **Abstract Methods**: Methods in an abstract class that do not have a body. Child classes must implement these methods.
2. **Abstract Class**: A class that can contain both **abstract methods** (without implementation) and **concrete methods** (with implementation).
3. **Cannot Instantiate**: An abstract class cannot be instantiated on its own; it must be subclassed.

### Defining an Abstract Class

To define an abstract class, use the `abstract` keyword before the `class` keyword. To define an abstract method, use the `abstract` keyword before the method declaration.

#### Syntax:
```php
abstract class ClassName {
    // Abstract method (does not have a body)
    abstract public function someMethod();
    
    // Regular method (has a body)
    public function regularMethod() {
        echo "This is a regular method.<br>";
    }
}
```

### Example of Abstract Class

```php
<?php
// Defining an abstract class
abstract class Animal {
    // Abstract method with no implementation
    abstract public function makeSound();

    // Regular method with implementation
    public function breathe() {
        echo "I am breathing.<br>";
    }
}

// Defining a child class that extends the abstract class
class Dog extends Animal {
    // Implementing the abstract method
    public function makeSound() {
        echo "Woof! Woof!<br>";
    }
}

class Cat extends Animal {
    // Implementing the abstract method
    public function makeSound() {
        echo "Meow! Meow!<br>";
    }
}

// Creating instances of the child classes
$dog = new Dog();
$dog->makeSound();  // Output: Woof! Woof!
$dog->breathe();    // Output: I am breathing.

$cat = new Cat();
$cat->makeSound();  // Output: Meow! Meow!
$cat->breathe();    // Output: I am breathing.
?>
```

### Explanation:
- The `Animal` class is an abstract class that contains one **abstract method** (`makeSound()`) and one **regular method** (`breathe()`).
- The `Dog` and `Cat` classes **extend** the `Animal` class and **implement** the `makeSound()` method. Each child class provides its own implementation of the `makeSound()` method.
- We **cannot create an instance of the `Animal` class** directly, but we can instantiate the `Dog` and `Cat` classes, which inherit from it.

---

### Characteristics of Abstract Classes:
1. **Cannot Be Instantiated**: You cannot create an object of an abstract class directly.
    ```php
    $animal = new Animal();  // Error: Cannot instantiate abstract class Animal
    ```
2. **Abstract Methods Must Be Implemented**: Any class that extends an abstract class must implement all of its abstract methods, unless the subclass is also abstract.
3. **Concrete Methods**: An abstract class can have regular methods with implemented behavior. These methods can be inherited by child classes.
4. **Abstract Methods in Child Classes**: If a subclass does not implement all the abstract methods of its parent class, it must be declared abstract as well.

---

### Example of Abstract Class with Multiple Abstract Methods:

```php
<?php
abstract class Shape {
    // Abstract method for calculating area
    abstract public function calculateArea();
    
    // Abstract method for calculating perimeter
    abstract public function calculatePerimeter();
}

class Circle extends Shape {
    private $radius;

    public function __construct($radius) {
        $this->radius = $radius;
    }

    // Implementing calculateArea() for Circle
    public function calculateArea() {
        return pi() * pow($this->radius, 2);
    }

    // Implementing calculatePerimeter() for Circle
    public function calculatePerimeter() {
        return 2 * pi() * $this->radius;
    }
}

class Square extends Shape {
    private $side;

    public function __construct($side) {
        $this->side = $side;
    }

    // Implementing calculateArea() for Square
    public function calculateArea() {
        return pow($this->side, 2);
    }

    // Implementing calculatePerimeter() for Square
    public function calculatePerimeter() {
        return 4 * $this->side;
    }
}

// Creating objects of Circle and Square
$circle = new Circle(5);
echo "Circle Area: " . $circle->calculateArea() . "<br>";  // Output: Circle Area: 78.539816339745
echo "Circle Perimeter: " . $circle->calculatePerimeter() . "<br>";  // Output: Circle Perimeter: 31.415926535897

$square = new Square(4);
echo "Square Area: " . $square->calculateArea() . "<br>";  // Output: Square Area: 16
echo "Square Perimeter: " . $square->calculatePerimeter() . "<br>";  // Output: Square Perimeter: 16
?>
```

### Explanation:
- The `Shape` class is an abstract class with two abstract methods: `calculateArea()` and `calculatePerimeter()`.
- Both `Circle` and `Square` classes **inherit** from the `Shape` class and implement the abstract methods with their own specific logic.
- When instantiated, the `Circle` and `Square` objects can use these methods to calculate the area and perimeter.

---

### When to Use Abstract Classes?

You would use abstract classes when:
1. You want to define a common interface (abstract methods) for multiple child classes, but also want to allow child classes to implement their own version of these methods.
2. You want to provide common functionality that can be inherited by subclasses (concrete methods in abstract classes).
3. You want to force subclasses to implement specific methods, ensuring a certain structure across related classes.

### Conclusion:
- **Abstract classes** provide a way to define the blueprint for other classes, ensuring that certain methods are implemented by the subclasses.
- **Abstract methods** in an abstract class must be implemented by any non-abstract class that inherits from it.
- Abstract classes allow you to combine both **abstract methods** and **regular methods** that can be inherited by child classes.
