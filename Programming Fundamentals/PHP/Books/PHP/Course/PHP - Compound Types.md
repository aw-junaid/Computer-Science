PHP - Compound TypesIn PHP, **compound types** refer to data types that can hold multiple values. These types are more complex than scalar types (such as integers, strings, floats, and booleans). The two main compound types in PHP are **arrays** and **objects**.

### 1. **Arrays**

Arrays in PHP are ordered maps, meaning they store values in an ordered manner and associate each value with a key. PHP arrays can be indexed (using numbers) or associative (using strings or other data types as keys).

#### **Indexed Arrays**
Indexed arrays use numeric keys to store elements.

```php
<?php
// Indexed array with numbers
$fruits = array("Apple", "Banana", "Cherry");
echo $fruits[0];  // Outputs: Apple
?>
```

You can also use the `[]` shorthand to create indexed arrays:

```php
<?php
$fruits = ["Apple", "Banana", "Cherry"];
echo $fruits[1];  // Outputs: Banana
?>
```

#### **Associative Arrays**
Associative arrays use named keys (strings or other types) to store values, rather than numeric indexes.

```php
<?php
// Associative array with strings as keys
$person = array("name" => "John", "age" => 30);
echo $person["name"];  // Outputs: John
?>
```

#### **Multidimensional Arrays**
A multidimensional array is an array of arrays. It allows for the creation of complex structures like matrices or tables.

```php
<?php
// Multidimensional array
$contacts = array(
    "John" => array("phone" => "123-4567", "email" => "john@example.com"),
    "Jane" => array("phone" => "987-6543", "email" => "jane@example.com")
);
echo $contacts["John"]["email"];  // Outputs: john@example.com
?>
```

#### **Array Functions**
PHP provides many functions to manipulate arrays, such as:

- `array_push()` – Adds one or more elements to the end of an array.
- `array_pop()` – Removes the last element from an array.
- `array_merge()` – Merges two or more arrays.
- `array_slice()` – Extracts a slice of an array.
- `count()` – Counts the number of elements in an array.

Example:

```php
<?php
$fruits = ["Apple", "Banana", "Cherry"];
array_push($fruits, "Date");
print_r($fruits);  // Outputs: Array ( [0] => Apple [1] => Banana [2] => Cherry [3] => Date )
?>
```

### 2. **Objects**

Objects in PHP are instances of classes. A class defines a blueprint for an object, and an object is an instance of that class. Objects are used to encapsulate data and methods that manipulate the data.

#### **Creating a Class and Object**

```php
<?php
class Car {
    public $make;
    public $model;
    public $year;

    // Constructor to initialize the properties
    public function __construct($make, $model, $year) {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    // Method to display car details
    public function display() {
        echo "Car: $this->year $this->make $this->model";
    }
}

// Creating an object of the class
$car1 = new Car("Toyota", "Camry", 2020);
$car1->display();  // Outputs: Car: 2020 Toyota Camry
?>
```

#### **Object Properties and Methods**
- **Properties** are variables that belong to an object. They hold data related to that object.
- **Methods** are functions that are defined within the class and can be called on objects of that class.

```php
<?php
class Dog {
    public $name;
    public $breed;

    public function __construct($name, $breed) {
        $this->name = $name;
        $this->breed = $breed;
    }

    public function bark() {
        echo "$this->name says Woof!";
    }
}

$dog = new Dog("Buddy", "Golden Retriever");
$dog->bark();  // Outputs: Buddy says Woof!
?>
```

#### **Inheritance and Object-Oriented Programming**
PHP supports object-oriented programming (OOP), which allows you to define parent and child classes. A child class inherits the properties and methods of the parent class.

```php
<?php
class Animal {
    public $name;

    public function __construct($name) {
        $this->name = $name;
    }

    public function speak() {
        echo "$this->name makes a sound.";
    }
}

class Dog extends Animal {
    public function speak() {
        echo "$this->name barks.";
    }
}

$dog = new Dog("Rex");
$dog->speak();  // Outputs: Rex barks.
?>
```

#### **Object Functions**
PHP provides functions to work with objects, such as:

- `get_class()` – Gets the name of the class of an object.
- `method_exists()` – Checks if a method exists in a class.
- `property_exists()` – Checks if a property exists in an object.

Example:

```php
<?php
$car = new Car("Honda", "Civic", 2022);
echo get_class($car);  // Outputs: Car
?>
```

### **Comparison: Arrays vs Objects**

| Feature             | **Arrays**                          | **Objects**                           |
|---------------------|-------------------------------------|---------------------------------------|
| **Structure**        | Ordered collections of values (key-value pairs) | Instances of classes with properties and methods |
| **Data Handling**    | Stores and manipulates data in a linear or multi-dimensional structure | Stores data and functions in an object-oriented way |
| **Key Types**        | Can use integers or strings as keys | Properties are named and accessed via methods |
| **Access**           | `$array[key]`                       | `$object->property` or `$object->method()` |
| **Mutability**       | Values can be changed directly     | Values are changed via setter methods or directly if public |
| **Usage**            | Suitable for lists, tables, or mappings | Suitable for more structured data with behavior |

### **Summary of Compound Types**

- **Arrays**: Can be indexed, associative, or multidimensional. They allow storing multiple values under one variable and can be accessed using keys or indices. PHP provides many built-in functions for working with arrays.
- **Objects**: Instances of a class, used for modeling more complex data structures. Objects encapsulate both data (properties) and behavior (methods), making them suitable for object-oriented programming.

These compound types are foundational for managing and structuring data in PHP applications, allowing for both simple collections and complex, behavior-driven models.
