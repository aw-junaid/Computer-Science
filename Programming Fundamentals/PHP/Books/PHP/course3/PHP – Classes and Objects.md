### PHP – Classes and Objects

In PHP, **Classes** and **Objects** are fundamental concepts in Object-Oriented Programming (OOP). A **class** is a blueprint for creating objects, and an **object** is an instance of a class. These concepts allow you to structure your code more effectively by grouping related properties and methods together.

### 1. **Class**

A class is a user-defined blueprint for creating objects. It defines the properties (attributes) and methods (functions) that the objects created from the class will have.

#### Syntax to define a class:
```php
class ClassName {
    // Properties (variables)
    public $property;

    // Constructor method
    public function __construct($property) {
        $this->property = $property;
    }

    // Methods (functions)
    public function display() {
        echo "The property value is: " . $this->property;
    }
}
```

- **`class`**: Keyword used to define a class.
- **`public`**: Access modifier for properties and methods. You can also use `private` or `protected` for restricted access.
- **`__construct()`**: Constructor method that is called when a new object is instantiated.

### 2. **Object**

An object is an instance of a class. It is created using the `new` keyword and represents a real-world entity with properties and behaviors defined by the class.

#### Syntax to create an object:
```php
$objectName = new ClassName($propertyValue);
$objectName->display();  // Call the method
```

### Example: Creating a Simple Class and Object

```php
<?php
// Define a class
class Car {
    // Properties
    public $brand;
    public $model;

    // Constructor to initialize properties
    public function __construct($brand, $model) {
        $this->brand = $brand;
        $this->model = $model;
    }

    // Method to display car details
    public function display() {
        echo "The car is a " . $this->brand . " " . $this->model;
    }
}

// Create an object of the Car class
$car1 = new Car("Toyota", "Corolla");
$car1->display();  // Output: The car is a Toyota Corolla
?>
```

- **Explanation**: In this example, we define a `Car` class with two properties (`$brand` and `$model`) and a method `display()` that prints out the car's brand and model. We then create an object `$car1` from the `Car` class and call the `display()` method.

### 3. **Access Modifiers**

Access modifiers control the visibility of properties and methods. The three main access modifiers are:
- **`public`**: The property or method can be accessed from anywhere (inside or outside the class).
- **`private`**: The property or method can only be accessed within the class in which it is defined.
- **`protected`**: The property or method can be accessed within the class and by classes that inherit from it.

#### Example: Using Access Modifiers

```php
<?php
class Car {
    public $brand;  // Accessible from anywhere
    private $model; // Accessible only within the class

    public function __construct($brand, $model) {
        $this->brand = $brand;
        $this->model = $model;
    }

    public function display() {
        echo "The car is a " . $this->brand . " " . $this->model;
    }

    // Getter method for private property $model
    public function getModel() {
        return $this->model;
    }
}

// Create an object
$car1 = new Car("Toyota", "Corolla");
$car1->display();  // Output: The car is a Toyota Corolla

// Access private property through the getter method
echo $car1->getModel();  // Output: Corolla
?>
```

### 4. **Constructors and Destructors**

- **Constructor (`__construct()`)**: A special method that is automatically called when an object is created. It is typically used for initializing object properties.

- **Destructor (`__destruct()`)**: A special method that is automatically called when an object is destroyed. It is used to release resources or perform cleanup tasks.

#### Example: Constructor and Destructor

```php
<?php
class Car {
    public $brand;
    public $model;

    // Constructor
    public function __construct($brand, $model) {
        $this->brand = $brand;
        $this->model = $model;
        echo "A new car is created: " . $this->brand . " " . $this->model . "<br>";
    }

    // Destructor
    public function __destruct() {
        echo "The car " . $this->brand . " " . $this->model . " is being destroyed.<br>";
    }
}

// Create an object
$car1 = new Car("Toyota", "Corolla");

// When the script ends, the destructor is called automatically
?>
```

- **Explanation**: The constructor is called when `$car1` is created, and the destructor is called when `$car1` is destroyed (typically when the script ends or the object is no longer needed).

### 5. **Inheritance**

Inheritance allows one class to inherit properties and methods from another class. The class that is inherited from is called the **parent class**, and the class that inherits is called the **child class**.

- **Parent Class**: The class whose properties and methods are inherited.
- **Child Class**: The class that inherits properties and methods from the parent class.

#### Example: Inheritance

```php
<?php
class Vehicle {
    public $brand;
    
    public function __construct($brand) {
        $this->brand = $brand;
    }

    public function display() {
        echo "This vehicle is a " . $this->brand . "<br>";
    }
}

class Car extends Vehicle {
    public $model;
    
    public function __construct($brand, $model) {
        parent::__construct($brand);  // Call the parent constructor
        $this->model = $model;
    }

    public function display() {
        echo "This car is a " . $this->brand . " " . $this->model . "<br>";
    }
}

$car1 = new Car("Toyota", "Corolla");
$car1->display();  // Output: This car is a Toyota Corolla
?>
```

- **Explanation**: The `Car` class inherits from the `Vehicle` class. The `Car` class can access the properties and methods of the `Vehicle` class. In the constructor of `Car`, the `parent::__construct()` method is used to call the parent class's constructor.

### 6. **Static Properties and Methods**

Static properties and methods belong to the class itself rather than instances of the class. They are accessed using the `::` operator without creating an object.

#### Example: Static Property and Method

```php
<?php
class Car {
    public static $brand = "Toyota";  // Static property

    // Static method
    public static function display() {
        echo "The brand of the car is " . self::$brand . "<br>";
    }
}

// Accessing static property and method without creating an object
echo Car::$brand;  // Output: Toyota
Car::display();    // Output: The brand of the car is Toyota
?>
```

- **Explanation**: The static property `$brand` and static method `display()` can be accessed without creating an instance of the `Car` class. The `self::` keyword is used to access static members of the class.

### 7. **Abstract Classes**

An **abstract class** cannot be instantiated on its own. It is meant to be inherited by other classes. Abstract classes can have abstract methods, which must be implemented by the child class.

#### Example: Abstract Class

```php
<?php
abstract class Animal {
    public $name;

    abstract public function makeSound();  // Abstract method (must be implemented by child class)

    public function setName($name) {
        $this->name = $name;
    }
}

class Dog extends Animal {
    public function makeSound() {
        echo $this->name . " barks!<br>";
    }
}

$dog = new Dog();
$dog->setName("Rex");
$dog->makeSound();  // Output: Rex barks!
?>
```

- **Explanation**: The `Animal` class is abstract and contains an abstract method `makeSound()`. The `Dog` class must implement this method, and an instance of `Dog` can be created.

---

### Summary of Key Concepts

- **Class**: Defines the blueprint for creating objects, including properties and methods.
- **Object**: An instance of a class.
- **Constructor**: Special method to initialize object properties.
- **Destructor**: Special method to clean up when an object is destroyed.
- **Inheritance**: Mechanism where a child class inherits properties and methods from a parent class.
- **Static Members**: Properties and methods that belong to the class, not instances.
- **Abstract Classes**: Classes that cannot be instantiated but can be inherited.

Using classes and objects in PHP makes your code more modular, reusable, and easier to maintain. OOP allows you to organize and structure your code logically, making it easier to scale and extend.
