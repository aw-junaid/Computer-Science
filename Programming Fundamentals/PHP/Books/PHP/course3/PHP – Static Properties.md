### PHP – Static Properties

In PHP, **static properties** are variables that belong to the class itself, rather than to an instance of the class. This means that all instances of a class share the same static property, and it can be accessed directly through the class without needing to instantiate an object.

### Key Concepts:
1. **Shared by All Instances**: Static properties are shared across all instances of a class, unlike instance properties that are unique to each object.
2. **Accessed via Class Name**: You can access static properties using the class name, and also using the `self::` keyword inside the class.
3. **Cannot Access Instance Properties**: Static properties cannot access non-static (instance) properties or methods directly, because they are not tied to a specific object.
4. **Persistence Between Calls**: Static properties retain their values across method calls and class instances, making them useful for data that needs to persist or be shared globally.
5. **No Instantiation Required**: You can access static properties without creating an instance of the class.

### Defining and Using Static Properties

Static properties are defined using the `static` keyword. They are accessed using the `::` (double colon) operator, either inside the class using `self::`, or outside the class using the class name.

#### Syntax:
```php
class ClassName {
    public static $propertyName;
}
```

### Example of Static Property

```php
<?php
class Counter {
    // Static property
    public static $count = 0;
    
    // Static method to increment the count
    public static function increment() {
        self::$count++;
    }

    // Static method to get the count
    public static function getCount() {
        return self::$count;
    }
}

// Accessing and modifying static property without creating an instance
Counter::increment();
Counter::increment();

echo Counter::getCount();  // Output: 2
?>
```

### Explanation:
- The `Counter` class has a static property `$count`, initialized to `0`.
- The static method `increment()` increases the `$count` value.
- The static method `getCount()` retrieves the current value of `$count`.
- Static properties are accessed directly through the class name, and the value is shared across all calls to `increment()`.

### Accessing Static Properties Inside the Class

Inside the class, static properties should be accessed using the `self::` keyword, which refers to the class itself.

```php
<?php
class Database {
    public static $connection;
    
    public static function connect() {
        self::$connection = "Connected to Database";  // Using self:: to access static property
    }
    
    public static function getConnection() {
        return self::$connection;
    }
}

Database::connect();
echo Database::getConnection();  // Output: Connected to Database
?>
```

### Explanation:
- The `Database` class has a static property `$connection`.
- The `connect()` method initializes this static property, and the `getConnection()` method returns its value.
- Static properties can be accessed and modified using `self::$property` within the class.

### Modifying Static Properties

Static properties can be modified both inside and outside the class, as long as you use the class name and `::` syntax. Here's an example of modifying the static property from outside the class:

```php
<?php
class App {
    public static $appName = "My Application";
}

// Modifying the static property from outside the class
App::$appName = "Your Application";

echo App::$appName;  // Output: Your Application
?>
```

### Explanation:
- The static property `$appName` is modified directly from outside the class using `App::$appName = "Your Application"`.
- This is possible because static properties belong to the class itself, and can be accessed or modified without creating an object.

### Static Properties and Inheritance

Static properties are inherited by child classes, but they are not polymorphic. A subclass can access static properties from the parent class, but it cannot override or modify them in the same way instance properties can be overridden.

```php
<?php
class Animal {
    public static $species = "Generic Animal";
}

class Dog extends Animal {
    // Modifying the static property in the subclass
    public static function setSpecies($species) {
        self::$species = $species;
    }
}

echo Animal::$species;  // Output: Generic Animal

Dog::setSpecies("Dog");
echo Dog::$species;     // Output: Dog
echo Animal::$species;  // Output: Dog (Static properties are shared across all instances)
?>
```

### Explanation:
- The `Dog` class extends `Animal` and modifies the static property `$species`.
- Since static properties are shared among all instances of the class (and its subclasses), changes to static properties are reflected across all classes that access them.

### Static Properties vs Instance Properties

- **Static properties** are shared by all instances of the class. They are accessed via the class name or the `self::` keyword.
- **Instance properties** belong to specific instances of a class and are accessed via `$this->property`.

Here's an example comparing static and instance properties:

```php
<?php
class Car {
    public $color;             // Instance property
    public static $wheels = 4; // Static property

    public function __construct($color) {
        $this->color = $color;
    }
}

$car1 = new Car("Red");
$car2 = new Car("Blue");

echo $car1->color;       // Output: Red
echo $car2->color;       // Output: Blue

echo Car::$wheels;       // Output: 4 (shared by all instances)
?>
```

### Explanation:
- The `color` property is an instance property, so each car object has its own color.
- The `wheels` property is a static property, so it is shared by all instances of the `Car` class, and is accessed using `Car::$wheels`.

### Use Cases for Static Properties

- **Configuration Settings**: Static properties can be used to store configuration data that should be shared across all instances of a class.
- **Counters or States**: Static properties are useful for maintaining a count of instances or global states that persist across method calls and object instances.
- **Singleton Pattern**: Static properties are often used in the Singleton design pattern to hold the instance of the class that is created only once.

### Conclusion

- **Static properties** belong to the class, not to individual instances, and are shared across all instances.
- They are accessed using the class name or `self::` inside the class.
- Static properties retain their values across method calls, making them useful for storing global or shared information.
- While static properties can be inherited, they are not polymorphic and are shared across all instances, including those of subclasses.
