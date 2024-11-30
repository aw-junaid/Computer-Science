### PHP – Inheritance

**Inheritance** is a fundamental concept in Object-Oriented Programming (OOP) that allows a class (child class) to inherit properties and methods from another class (parent class). This promotes code reuse, as the child class can use or override the functionality defined in the parent class without having to rewrite the same code.

In PHP, inheritance is implemented using the `extends` keyword, which allows one class to inherit from another.

---

### Key Concepts of Inheritance

1. **Parent Class (Base Class)**: The class whose properties and methods are inherited by another class.
2. **Child Class (Derived Class)**: The class that inherits the properties and methods from the parent class.

### 1. **Basic Inheritance**

A child class inherits all the **public** and **protected** members (properties and methods) of the parent class, but not the **private** members.

#### Syntax:
```php
class ParentClass {
    // Parent class code
}

class ChildClass extends ParentClass {
    // Child class code
}
```

#### Example:
```php
<?php
// Parent class
class Vehicle {
    public $brand;
    public $model;

    public function __construct($brand, $model) {
        $this->brand = $brand;
        $this->model = $model;
    }

    public function display() {
        echo "This is a " . $this->brand . " " . $this->model;
    }
}

// Child class inherits from Vehicle
class Car extends Vehicle {
    public function carDetails() {
        echo "Car details: " . $this->brand . " " . $this->model;
    }
}

// Create an object of the child class
$car = new Car("Toyota", "Corolla");
$car->display();  // Output: This is a Toyota Corolla
$car->carDetails();  // Output: Car details: Toyota Corolla
?>
```

- **Explanation**: The `Car` class inherits the properties `$brand` and `$model`, and the method `display()` from the `Vehicle` class. The `carDetails()` method is unique to the `Car` class.

---

### 2. **Overriding Methods**

A child class can **override** a method that is inherited from the parent class. This means the child class can provide its own implementation for a method that was originally defined in the parent class.

#### Syntax:
```php
class ParentClass {
    public function methodName() {
        // Parent method code
    }
}

class ChildClass extends ParentClass {
    public function methodName() {
        // Overridden child method code
    }
}
```

#### Example of Method Overriding:
```php
<?php
class Animal {
    public function sound() {
        echo "Animal makes a sound.";
    }
}

class Dog extends Animal {
    // Overriding the sound method
    public function sound() {
        echo "Dog barks.";
    }
}

$dog = new Dog();
$dog->sound();  // Output: Dog barks.
?>
```

- **Explanation**: In the above example, the `Dog` class overrides the `sound()` method from the `Animal` class to provide its own specific behavior.

---

### 3. **Using `parent` Keyword**

You can call the parent class's method or constructor from the child class using the `parent` keyword. This is especially useful when you want to extend or modify the behavior of an inherited method.

#### Example with `parent` Keyword:
```php
<?php
class Vehicle {
    public $brand;

    public function __construct($brand) {
        $this->brand = $brand;
    }

    public function display() {
        echo "This is a " . $this->brand . " vehicle.<br>";
    }
}

class Car extends Vehicle {
    public function __construct($brand, $model) {
        parent::__construct($brand);  // Calling the parent class constructor
        $this->model = $model;
    }

    public function display() {
        parent::display();  // Calling the parent class method
        echo "This is a " . $this->model . " model.<br>";
    }
}

$car = new Car("Toyota", "Camry");
$car->display();  // Output: This is a Toyota vehicle. This is a Camry model.
?>
```

- **Explanation**: The `Car` class calls the parent class's constructor using `parent::__construct()` and the `display()` method using `parent::display()`. This allows the `Car` class to extend the functionality of the `Vehicle` class without completely replacing it.

---

### 4. **Accessing Parent Class Properties**

In PHP, the child class has access to public and protected properties of the parent class, but cannot access private properties directly.

#### Example of Accessing Parent Properties:
```php
<?php
class Person {
    public $name;
    protected $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }
}

class Student extends Person {
    public function showInfo() {
        echo "Name: " . $this->name . "<br>";  // Can access public property
        echo "Age: " . $this->age . "<br>";    // Can access protected property
    }
}

$student = new Student("Alice", 21);
$student->showInfo();  // Output: Name: Alice, Age: 21
?>
```

- **Explanation**: The `Student` class inherits both the `name` (public) and `age` (protected) properties from the `Person` class and can access them within its own methods.

---

### 5. **Constructor Inheritance**

If a parent class has a constructor, the child class does not automatically inherit the constructor. However, you can use the `parent::__construct()` to call the parent constructor from the child class.

#### Example of Constructor Inheritance:
```php
<?php
class Animal {
    public $type;

    public function __construct($type) {
        $this->type = $type;
    }
}

class Dog extends Animal {
    public $breed;

    public function __construct($type, $breed) {
        parent::__construct($type);  // Calling the parent class constructor
        $this->breed = $breed;
    }

    public function display() {
        echo "This is a " . $this->type . " and its breed is " . $this->breed . ".";
    }
}

$dog = new Dog("Mammal", "Labrador");
$dog->display();  // Output: This is a Mammal and its breed is Labrador.
?>
```

- **Explanation**: The `Dog` class calls the `Animal` class's constructor using `parent::__construct()` to initialize the `type` property before setting its own `breed` property.

---

### 6. **Access Modifiers and Inheritance**

When using inheritance, the child class inherits the **public** and **protected** properties and methods from the parent class, but not the **private** ones. A child class cannot override private methods or access private properties directly.

#### Example of Accessing Private Members:
```php
<?php
class ParentClass {
    private $privateVar = "I am private";

    public function show() {
        echo $this->privateVar;
    }
}

class ChildClass extends ParentClass {
    public function display() {
        // Cannot access private property directly
        // echo $this->privateVar;  // Error: Cannot access private property
        $this->show();  // Can access through public method
    }
}

$child = new ChildClass();
$child->display();  // Output: I am private
?>
```

- **Explanation**: The `ChildClass` cannot access the private property `$privateVar` directly but can call the public `show()` method from the parent class to display the value.

---

### 7. **Multiple Inheritance in PHP**

PHP does not support **multiple inheritance** (i.e., a class cannot inherit from more than one class directly). However, PHP supports **interfaces** and **traits**, which provide a way to mimic multiple inheritance by allowing classes to implement multiple interfaces or use multiple traits.

#### Example of Multiple Inheritance using Interfaces:
```php
<?php
interface Engine {
    public function startEngine();
}

interface Wheels {
    public function rotate();
}

class Car implements Engine, Wheels {
    public function startEngine() {
        echo "Engine started.<br>";
    }

    public function rotate() {
        echo "Wheels rotating.<br>";
    }
}

$car = new Car();
$car->startEngine();  // Output: Engine started.
$car->rotate();       // Output: Wheels rotating.
?>
```

- **Explanation**: The `Car` class implements both the `Engine` and `Wheels` interfaces, effectively inheriting functionality from two sources.

---

### Conclusion

- **Inheritance** in PHP allows you to create a new class based on an existing class, enabling code reuse and the extension of functionality.
- The **child class** inherits properties and methods from the **parent class**.
- You can **override** inherited methods and use the `parent` keyword to access the parent class's methods or constructor.
- In PHP, inheritance is single, but you can use **interfaces** and **traits** for a form of multiple inheritance.
