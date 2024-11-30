### Object-Oriented Programming (OOP) in PHP

Object-Oriented Programming (OOP) is a programming paradigm that uses objects and classes. PHP supports OOP features such as classes, objects, inheritance, encapsulation, and polymorphism. OOP allows you to structure your code more efficiently, making it easier to manage and maintain.

### Key Concepts in OOP

1. **Class**:
   - A class is a blueprint for creating objects. It defines the properties (variables) and methods (functions) that the objects created from the class will have.
   
   ```php
   class Car {
       public $color;
       public $model;
       
       // Constructor
       public function __construct($color, $model) {
           $this->color = $color;
           $this->model = $model;
       }

       // Method
       public function display() {
           echo "The car is a " . $this->color . " " . $this->model;
       }
   }
   ```

2. **Object**:
   - An object is an instance of a class. When a class is instantiated, an object is created, and you can use its properties and methods.

   ```php
   $car1 = new Car("Red", "Toyota");
   $car1->display();  // Output: The car is a Red Toyota
   ```

3. **Constructor**:
   - The constructor is a special method that is automatically called when a new object is created. It is commonly used for initializing properties.

   ```php
   class Car {
       public $color;
       public $model;

       public function __construct($color, $model) {
           $this->color = $color;
           $this->model = $model;
       }
   }
   ```

4. **Access Modifiers**:
   - PHP supports three types of access modifiers: `public`, `private`, and `protected`.
     - **`public`**: Properties and methods can be accessed from anywhere.
     - **`private`**: Properties and methods can only be accessed within the class.
     - **`protected`**: Properties and methods can be accessed within the class and by subclasses.

   ```php
   class Car {
       public $color;   // Public property
       private $model;  // Private property

       public function setModel($model) {
           $this->model = $model;  // Set private property
       }

       public function getModel() {
           return $this->model;  // Access private property
       }
   }
   ```

5. **Inheritance**:
   - Inheritance allows a class to use methods and properties from another class. The child class inherits all public and protected members of the parent class.

   ```php
   class Animal {
       public $name;

       public function __construct($name) {
           $this->name = $name;
       }

       public function speak() {
           echo $this->name . " makes a sound";
       }
   }

   class Dog extends Animal {
       public function speak() {
           echo $this->name . " barks";
       }
   }

   $dog = new Dog("Rex");
   $dog->speak();  // Output: Rex barks
   ```

6. **Polymorphism**:
   - Polymorphism allows methods to have the same name but behave differently depending on the object. This is achieved by overriding methods in child classes.

   ```php
   class Animal {
       public function speak() {
           echo "Animal makes a sound";
       }
   }

   class Dog extends Animal {
       public function speak() {
           echo "Dog barks";
       }
   }

   class Cat extends Animal {
       public function speak() {
           echo "Cat meows";
       }
   }

   $animal = new Dog();
   $animal->speak();  // Output: Dog barks

   $animal = new Cat();
   $animal->speak();  // Output: Cat meows
   ```

7. **Encapsulation**:
   - Encapsulation involves restricting access to certain details of an object's implementation and only exposing a controlled interface. This is done using access modifiers and getter/setter methods.

   ```php
   class Person {
       private $name;

       public function setName($name) {
           $this->name = $name;
       }

       public function getName() {
           return $this->name;
       }
   }

   $person = new Person();
   $person->setName("John");
   echo $person->getName();  // Output: John
   ```

8. **Abstract Classes**:
   - An abstract class cannot be instantiated. It is meant to be inherited by other classes. It can contain abstract methods, which must be implemented by any subclass.

   ```php
   abstract class Animal {
       public $name;
       
       abstract public function speak();
   }

   class Dog extends Animal {
       public function speak() {
           echo $this->name . " barks";
       }
   }

   $dog = new Dog();
   $dog->name = "Rex";
   $dog->speak();  // Output: Rex barks
   ```

9. **Interfaces**:
   - An interface defines a contract that classes must follow. A class can implement one or more interfaces, and it must define all methods declared in the interface.

   ```php
   interface Animal {
       public function speak();
   }

   class Dog implements Animal {
       public function speak() {
           echo "Dog barks";
       }
   }

   $dog = new Dog();
   $dog->speak();  // Output: Dog barks
   ```

10. **Traits**:
    - Traits are used to include methods in a class without using inheritance. They help reduce code duplication.

    ```php
    trait AnimalTrait {
        public function speak() {
            echo "Animal makes a sound";
        }
    }

    class Dog {
        use AnimalTrait;
    }

    $dog = new Dog();
    $dog->speak();  // Output: Animal makes a sound
    ```

### Example: Full OOP Example in PHP

```php
<?php
// Defining the Parent Class (Vehicle)
class Vehicle {
    public $brand;
    public $model;

    public function __construct($brand, $model) {
        $this->brand = $brand;
        $this->model = $model;
    }

    public function displayInfo() {
        echo "This is a " . $this->brand . " " . $this->model . "<br>";
    }
}

// Defining the Child Class (Car) that inherits from Vehicle
class Car extends Vehicle {
    public $fuelType;

    public function __construct($brand, $model, $fuelType) {
        parent::__construct($brand, $model);
        $this->fuelType = $fuelType;
    }

    public function displayInfo() {
        echo "This is a " . $this->brand . " " . $this->model . " with " . $this->fuelType . " fuel.<br>";
    }
}

// Creating an Object (Instance) of Car
$car = new Car("Toyota", "Corolla", "Petrol");
$car->displayInfo();  // Output: This is a Toyota Corolla with Petrol fuel.
?>
```

### Key Benefits of OOP in PHP:

1. **Reusability**: Classes and objects allow code to be reused across different parts of an application.
2. **Maintainability**: OOP makes it easier to maintain and modify code by organizing it into logical blocks (classes and methods).
3. **Scalability**: As your application grows, OOP provides a structured way to extend functionality without disrupting existing code.
4. **Encapsulation**: Hides internal details and exposes only the necessary interface, making the system easier to use.
5. **Polymorphism**: The ability to use a unified interface for different data types, which improves flexibility.

By understanding and applying OOP concepts, you can create more efficient, modular, and maintainable PHP applications.
