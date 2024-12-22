### **Object-Oriented Programming (OOP) in PHP**

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of objects, which are instances of classes. In PHP, OOP allows you to model real-world entities using classes and objects, enabling you to write more modular, reusable, and maintainable code.

In PHP, OOP provides several key features such as classes, objects, inheritance, polymorphism, encapsulation, and abstraction.

---

### **1. Key Concepts of OOP in PHP**

#### **1.1 Classes and Objects**

- **Class**: A blueprint for creating objects. It defines properties (variables) and methods (functions) that objects of the class will have.
- **Object**: An instance of a class. It is created using the `new` keyword.

##### **Example: Creating a Class and Object**

```php
<?php
class Car {
    // Properties
    public $make;
    public $model;
    public $year;

    // Constructor
    public function __construct($make, $model, $year) {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    // Method
    public function getCarDetails() {
        return "Car: $this->make $this->model, Year: $this->year";
    }
}

// Create an object of the Car class
$myCar = new Car("Toyota", "Corolla", 2020);

// Access object properties and methods
echo $myCar->getCarDetails();  // Output: Car: Toyota Corolla, Year: 2020
?>
```

- **`$this`**: Refers to the current object instance.
- **`__construct()`**: The constructor method is automatically called when an object is created. It is used to initialize object properties.

---

#### **1.2 Encapsulation**

Encapsulation is the practice of restricting access to certain components of an object to protect its internal state. It involves using **visibility modifiers** such as `public`, `private`, and `protected`.

- **Public**: The property or method is accessible from outside the class.
- **Private**: The property or method is accessible only within the class.
- **Protected**: The property or method is accessible within the class and its subclasses.

##### **Example: Using Visibility Modifiers**

```php
<?php
class Car {
    // Public property
    public $make;

    // Private property
    private $model;

    // Constructor
    public function __construct($make, $model) {
        $this->make = $make;
        $this->model = $model;
    }

    // Public method
    public function getCarDetails() {
        return "Car: $this->make, Model: $this->model";
    }

    // Private method
    private function setModel($model) {
        $this->model = $model;
    }

    // Public method to update private property
    public function changeModel($newModel) {
        $this->setModel($newModel);
    }
}

$myCar = new Car("Toyota", "Corolla");
echo $myCar->getCarDetails();  // Output: Car: Toyota, Model: Corolla

// The following will cause an error because $model is private:
// echo $myCar->model;  

// This is correct because changeModel is a public method
$myCar->changeModel("Camry");
echo $myCar->getCarDetails();  // Output: Car: Toyota, Model: Camry
?>
```

---

#### **1.3 Inheritance**

Inheritance allows a class to inherit properties and methods from another class. This promotes code reusability and makes it easier to create new classes based on existing ones.

- **Parent class**: The class being inherited from.
- **Child class**: The class that inherits from the parent class.

##### **Example: Inheritance**

```php
<?php
// Parent class
class Vehicle {
    public $make;
    public $model;

    public function __construct($make, $model) {
        $this->make = $make;
        $this->model = $model;
    }

    public function getDetails() {
        return "Vehicle: $this->make $this->model";
    }
}

// Child class
class Car extends Vehicle {
    public $year;

    public function __construct($make, $model, $year) {
        parent::__construct($make, $model);  // Call parent constructor
        $this->year = $year;
    }

    public function getCarDetails() {
        return $this->getDetails() . ", Year: $this->year";
    }
}

$myCar = new Car("Toyota", "Corolla", 2020);
echo $myCar->getCarDetails();  // Output: Vehicle: Toyota Corolla, Year: 2020
?>
```

- **`extends`**: The `Car` class extends the `Vehicle` class, meaning `Car` inherits the properties and methods of `Vehicle`.
- **`parent::__construct()`**: Calls the constructor of the parent class.

---

#### **1.4 Polymorphism**

Polymorphism allows different classes to be treated as instances of the same class through inheritance. The most common type of polymorphism in PHP is **method overriding**, where a child class defines a method with the same name as a method in the parent class.

##### **Example: Polymorphism (Method Overriding)**

```php
<?php
class Animal {
    public function sound() {
        return "Animal makes a sound";
    }
}

class Dog extends Animal {
    public function sound() {
        return "Dog barks";
    }
}

class Cat extends Animal {
    public function sound() {
        return "Cat meows";
    }
}

$dog = new Dog();
echo $dog->sound();  // Output: Dog barks

$cat = new Cat();
echo $cat->sound();  // Output: Cat meows
?>
```

- The `sound()` method is overridden in the `Dog` and `Cat` classes to provide different behaviors.

---

#### **1.5 Abstraction**

Abstraction is the concept of hiding the complex implementation details and exposing only the necessary features of an object. In PHP, abstraction is typically achieved using **abstract classes** and **abstract methods**.

- **Abstract Class**: A class that cannot be instantiated directly and must be extended by another class.
- **Abstract Method**: A method defined in an abstract class without implementation, which must be implemented by the subclass.

##### **Example: Abstraction**

```php
<?php
abstract class Animal {
    // Abstract method (no implementation)
    abstract public function sound();

    // Regular method
    public function sleep() {
        return "Animal is sleeping";
    }
}

class Dog extends Animal {
    // Implement the abstract method
    public function sound() {
        return "Dog barks";
    }
}

$dog = new Dog();
echo $dog->sound();  // Output: Dog barks
echo $dog->sleep();  // Output: Animal is sleeping
?>
```

- **`abstract`**: Used to declare an abstract class or method.
- A class that extends an abstract class must implement all of its abstract methods.

---

### **2. Constructor and Destructor in OOP**

- **Constructor (`__construct`)**: Automatically called when an object is created. It is typically used to initialize properties.
- **Destructor (`__destruct`)**: Automatically called when an object is destroyed (e.g., when it goes out of scope). It is used for cleanup tasks.

##### **Example: Constructor and Destructor**

```php
<?php
class MyClass {
    public function __construct() {
        echo "Constructor is called<br>";
    }

    public function __destruct() {
        echo "Destructor is called<br>";
    }
}

$obj = new MyClass();  // Constructor is called
// Destructor will be called automatically when the script ends
?>
```

---

### **3. Interfaces**

An **interface** defines a contract that classes must follow. It only defines method signatures (without implementation), and any class implementing the interface must provide implementations for these methods.

##### **Example: Interface**

```php
<?php
interface Animal {
    public function sound();
}

class Dog implements Animal {
    public function sound() {
        return "Dog barks";
    }
}

class Cat implements Animal {
    public function sound() {
        return "Cat meows";
    }
}

$dog = new Dog();
echo $dog->sound();  // Output: Dog barks
?>
```

- **`interface`**: Defines the structure that implementing classes must follow.
- **`implements`**: Used to implement an interface in a class.

---

### **4. Summary of OOP Features in PHP**

1. **Classes and Objects**: Create reusable blueprints for objects, which contain properties and methods.
2. **Encapsulation**: Restrict access to an object's internal state, exposing only necessary methods.
3. **Inheritance**: Allow one class to inherit properties and methods from another class.
4. **Polymorphism**: Enable methods to behave differently depending on the object calling them.
5. **Abstraction**: Hide complex implementation details and expose only necessary functionality.
6. **Interfaces**: Define contracts that must be followed by implementing classes.

OOP in PHP makes it easier to manage complex applications, encourages code reuse, and enhances maintainability.
