### PHP – Encapsulation

**Encapsulation** is one of the four fundamental principles of Object-Oriented Programming (OOP) in PHP (the other three are inheritance, polymorphism, and abstraction). It is the concept of **restricting direct access** to an object's internal state and requiring all interaction with that state to occur through well-defined interfaces (methods). This ensures that the object's data is protected from unintended or harmful modifications and provides a clear structure for interacting with it.

Encapsulation typically involves **private** or **protected** properties and providing **public getter and setter methods** to control access to those properties.

### Key Concepts of Encapsulation

1. **Private and Protected Properties**: By marking properties as `private` or `protected`, you restrict direct access to those properties from outside the class.
   
2. **Getter and Setter Methods**: Public methods that allow controlled access to the private properties. A getter method retrieves the value of a property, and a setter method allows the value of the property to be modified.

3. **Data Hiding**: Encapsulation hides the internal state of the object from the outside world and provides an interface to interact with it.

### Benefits of Encapsulation:
- **Control over Data**: By using getters and setters, you can control how the data is accessed and modified, such as enforcing validation rules.
- **Data Integrity**: Ensures the integrity of the data by limiting direct access and modifications.
- **Flexibility**: If you need to change the internal implementation of a class, you can do so without affecting external code that uses the class.
- **Security**: By making some properties private, you protect them from unintended access and modification.

### Example of Encapsulation in PHP

```php
<?php
class Person {
    // Private properties
    private $name;
    private $age;

    // Constructor to initialize properties
    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    // Getter method for $name
    public function getName() {
        return $this->name;
    }

    // Setter method for $name
    public function setName($name) {
        $this->name = $name;
    }

    // Getter method for $age
    public function getAge() {
        return $this->age;
    }

    // Setter method for $age
    public function setAge($age) {
        if ($age > 0) {
            $this->age = $age;
        } else {
            echo "Age must be positive.";
        }
    }
}

// Creating an instance of the Person class
$person = new Person("John", 30);

// Accessing and modifying properties via getter and setter methods
echo $person->getName(); // Output: John
$person->setName("Jane");
echo $person->getName(); // Output: Jane

echo $person->getAge(); // Output: 30
$person->setAge(35);
echo $person->getAge(); // Output: 35
?>
```

### Explanation:
1. **Private Properties**: The `$name` and `$age` properties are private, meaning they cannot be accessed directly from outside the `Person` class.
2. **Getter and Setter Methods**: 
    - The `getName()` method is used to retrieve the value of the `$name` property.
    - The `setName()` method allows the `$name` property to be modified.
    - Similarly, `getAge()` and `setAge()` methods are used to access and modify the `$age` property, with validation added in `setAge()` to ensure the age is positive.
3. **Controlled Access**: The values of `$name` and `$age` can only be accessed and modified using the public getter and setter methods. This allows for validation, logging, or additional logic to be added as needed.

### Setter and Getter Method Naming Convention
In PHP, it is common to name getter and setter methods with the following conventions:
- `getPropertyName()` for getter methods.
- `setPropertyName()` for setter methods.

These methods allow you to interact with object properties in a controlled manner.

### Example with Validation (Advanced Encapsulation)

```php
<?php
class Product {
    private $price;
    private $quantity;

    // Constructor to initialize properties
    public function __construct($price, $quantity) {
        $this->setPrice($price);
        $this->setQuantity($quantity);
    }

    // Getter for price
    public function getPrice() {
        return $this->price;
    }

    // Setter for price with validation
    public function setPrice($price) {
        if ($price > 0) {
            $this->price = $price;
        } else {
            echo "Price must be positive.";
        }
    }

    // Getter for quantity
    public function getQuantity() {
        return $this->quantity;
    }

    // Setter for quantity with validation
    public function setQuantity($quantity) {
        if ($quantity >= 0) {
            $this->quantity = $quantity;
        } else {
            echo "Quantity cannot be negative.";
        }
    }

    // Method to calculate the total value
    public function calculateTotal() {
        return $this->price * $this->quantity;
    }
}

$product = new Product(100, 10);

echo "Product Price: " . $product->getPrice() . "\n"; // Output: 100
echo "Product Quantity: " . $product->getQuantity() . "\n"; // Output: 10
echo "Total Value: " . $product->calculateTotal() . "\n"; // Output: 1000

$product->setPrice(150);
$product->setQuantity(5);

echo "Updated Price: " . $product->getPrice() . "\n"; // Output: 150
echo "Updated Quantity: " . $product->getQuantity() . "\n"; // Output: 5
echo "Updated Total Value: " . $product->calculateTotal() . "\n"; // Output: 750
?>
```

### Explanation:
- In this example, the `Product` class encapsulates two private properties, `$price` and `$quantity`.
- The setter methods `setPrice()` and `setQuantity()` include validation checks to ensure that the price is positive and the quantity is not negative.
- The `calculateTotal()` method uses the encapsulated properties to compute the total value of the product.
- Access to and modification of these properties is done only through the getter and setter methods, enforcing rules and ensuring data integrity.

### 4. Encapsulation with Protected Properties

In some cases, you might want to allow derived classes (subclasses) to access certain properties while still hiding them from the outside world. In such cases, you can use **protected** access modifiers.

#### Example with Protected Properties

```php
<?php
class Employee {
    protected $name;
    protected $salary;

    public function __construct($name, $salary) {
        $this->name = $name;
        $this->salary = $salary;
    }
}

class Manager extends Employee {
    public function getSalary() {
        return $this->salary;  // Can access protected property in subclass
    }
}

$manager = new Manager("Alice", 5000);
echo $manager->getSalary(); // Output: 5000
?>
```

### Explanation:
- The `Employee` class has `protected` properties `$name` and `$salary`.
- The `Manager` class, which extends `Employee`, can access these protected properties, as protected members are accessible in child classes.
- However, these properties are not directly accessible from outside the class hierarchy.

### Conclusion

- **Encapsulation** is a key OOP principle that helps ensure the security and integrity of an object's data by restricting direct access to its internal state.
- By using **private** and **protected** properties and providing **getter** and **setter** methods, you can control how an object's data is accessed and modified.
- Encapsulation allows for better code organization, flexibility, and maintainability, as it helps enforce rules and logic for interacting with objects.
