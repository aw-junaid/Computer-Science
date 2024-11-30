### PHP – Design Patterns

A **Design Pattern** is a general, reusable solution to a commonly occurring problem in software design. They represent best practices and are solutions that have been refined and optimized over time. Design patterns help in writing cleaner, more maintainable, and flexible code. They can be applied in a variety of contexts to improve software architecture, and PHP developers often make use of these patterns to solve common issues in web application development.

Design patterns are typically classified into three main types:
1. **Creational Patterns**: Deal with object creation mechanisms, trying to create objects in a manner suitable to the situation.
2. **Structural Patterns**: Deal with object composition, creating relationships between objects to form larger structures.
3. **Behavioral Patterns**: Deal with object collaboration and responsibilities, how objects communicate with each other.

Here’s an overview of some popular design patterns in PHP:

---

### **1. Creational Patterns**

#### **a. Singleton Pattern**
The **Singleton Pattern** ensures that a class has only one instance and provides a global point of access to that instance.

- **Use Case**: It is useful when you want to control access to shared resources, such as a database or a configuration object.

- **Example**:

```php
class Singleton {
    private static $instance = null;

    private function __construct() {
        // Prevent direct instantiation
    }

    public static function getInstance() {
        if (self::$instance === null) {
            self::$instance = new Singleton();
        }
        return self::$instance;
    }
}

// Usage
$instance1 = Singleton::getInstance();
$instance2 = Singleton::getInstance();
var_dump($instance1 === $instance2);  // bool(true)
```

#### **b. Factory Pattern**
The **Factory Pattern** defines an interface for creating an object but allows subclasses to alter the type of objects that will be created.

- **Use Case**: It is useful when the exact type of the object to be created is determined at runtime.

- **Example**:

```php
interface Car {
    public function getCarType();
}

class Sedan implements Car {
    public function getCarType() {
        return "Sedan";
    }
}

class SUV implements Car {
    public function getCarType() {
        return "SUV";
    }
}

class CarFactory {
    public static function createCar($type) {
        if ($type === 'sedan') {
            return new Sedan();
        } elseif ($type === 'suv') {
            return new SUV();
        }
        return null;
    }
}

// Usage
$car = CarFactory::createCar('sedan');
echo $car->getCarType();  // Sedan
```

#### **c. Abstract Factory Pattern**
The **Abstract Factory Pattern** provides an interface for creating families of related or dependent objects without specifying their concrete classes.

- **Use Case**: When there is a need to create multiple types of objects that belong to a common family (e.g., a GUI toolkit with buttons, windows, and textboxes).

- **Example**:

```php
interface Button {
    public function render();
}

interface Window {
    public function render();
}

class MacButton implements Button {
    public function render() {
        return "Rendering Mac button";
    }
}

class MacWindow implements Window {
    public function render() {
        return "Rendering Mac window";
    }
}

class WindowsButton implements Button {
    public function render() {
        return "Rendering Windows button";
    }
}

class WindowsWindow implements Window {
    public function render() {
        return "Rendering Windows window";
    }
}

interface GUIFactory {
    public function createButton(): Button;
    public function createWindow(): Window;
}

class MacFactory implements GUIFactory {
    public function createButton(): Button {
        return new MacButton();
    }
    public function createWindow(): Window {
        return new MacWindow();
    }
}

class WindowsFactory implements GUIFactory {
    public function createButton(): Button {
        return new WindowsButton();
    }
    public function createWindow(): Window {
        return new WindowsWindow();
    }
}

// Usage
$factory = new MacFactory();
$button = $factory->createButton();
echo $button->render();  // Rendering Mac button
```

---

### **2. Structural Patterns**

#### **a. Adapter Pattern**
The **Adapter Pattern** allows incompatible interfaces to work together by creating an adapter class that can bridge the gap between them.

- **Use Case**: When you need to make two incompatible interfaces work together.

- **Example**:

```php
interface OldSystem {
    public function oldRequest();
}

class OldSystemImplementation implements OldSystem {
    public function oldRequest() {
        return "Old System Request";
    }
}

interface NewSystem {
    public function newRequest();
}

class Adapter implements NewSystem {
    private $oldSystem;

    public function __construct(OldSystem $oldSystem) {
        $this->oldSystem = $oldSystem;
    }

    public function newRequest() {
        return $this->oldSystem->oldRequest();
    }
}

// Usage
$oldSystem = new OldSystemImplementation();
$adapter = new Adapter($oldSystem);
echo $adapter->newRequest();  // Old System Request
```

#### **b. Composite Pattern**
The **Composite Pattern** allows you to compose objects into tree structures to represent part-whole hierarchies. This pattern lets clients treat individual objects and compositions of objects uniformly.

- **Use Case**: When you need to treat both simple and complex objects uniformly, especially when dealing with hierarchical structures.

- **Example**:

```php
interface Component {
    public function operation();
}

class Leaf implements Component {
    public function operation() {
        return "Leaf operation";
    }
}

class Composite implements Component {
    private $children = [];

    public function add(Component $component) {
        $this->children[] = $component;
    }

    public function operation() {
        $result = "Composite operation\n";
        foreach ($this->children as $child) {
            $result .= $child->operation() . "\n";
        }
        return $result;
    }
}

// Usage
$leaf1 = new Leaf();
$leaf2 = new Leaf();
$composite = new Composite();
$composite->add($leaf1);
$composite->add($leaf2);
echo $composite->operation();
```

---

### **3. Behavioral Patterns**

#### **a. Observer Pattern**
The **Observer Pattern** is used when one object (the subject) needs to notify other objects (observers) of state changes.

- **Use Case**: When multiple objects need to be updated when a particular object’s state changes (e.g., in event-driven programming or UI updates).

- **Example**:

```php
interface Observer {
    public function update($message);
}

class ConcreteObserver implements Observer {
    public function update($message) {
        echo "Received message: $message\n";
    }
}

class Subject {
    private $observers = [];

    public function addObserver(Observer $observer) {
        $this->observers[] = $observer;
    }

    public function notify($message) {
        foreach ($this->observers as $observer) {
            $observer->update($message);
        }
    }
}

// Usage
$observer = new ConcreteObserver();
$subject = new Subject();
$subject->addObserver($observer);
$subject->notify("Hello, Observers!");
```

#### **b. Strategy Pattern**
The **Strategy Pattern** defines a family of algorithms, encapsulates each one, and makes them interchangeable. The strategy pattern allows the algorithm to vary independently from clients that use it.

- **Use Case**: When you want to define a set of algorithms and make them interchangeable, based on runtime conditions.

- **Example**:

```php
interface PaymentStrategy {
    public function pay($amount);
}

class CreditCardPayment implements PaymentStrategy {
    public function pay($amount) {
        echo "Paid $amount using Credit Card\n";
    }
}

class PayPalPayment implements PaymentStrategy {
    public function pay($amount) {
        echo "Paid $amount using PayPal\n";
    }
}

class PaymentContext {
    private $strategy;

    public function __construct(PaymentStrategy $strategy) {
        $this->strategy = $strategy;
    }

    public function executePayment($amount) {
        $this->strategy->pay($amount);
    }
}

// Usage
$payment = new PaymentContext(new PayPalPayment());
$payment->executePayment(100);
```

---

### Conclusion

Design patterns help developers create flexible, reusable, and maintainable software. By applying appropriate design patterns, PHP developers can avoid reinventing the wheel and ensure that their codebase is more efficient, scalable, and easier to manage.

In PHP, these design patterns can be applied to solve various problems that arise during application development. Whether you’re building a simple app or a large-scale enterprise system, knowing and using design patterns will improve the quality of your code and make collaboration easier.
