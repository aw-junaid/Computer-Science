### **Runtime Method Overriding in JavaScript**

In JavaScript, **runtime method overriding** happens when an object’s method is overridden at runtime, typically by an object or class that inherits from another. JavaScript’s dynamic nature allows method overriding to be flexible and resolved at runtime, based on the object’s actual type rather than the reference type.

Here are a few examples of how runtime method overriding works in JavaScript:

---

### **Example 1: Method Overriding via Inheritance**

In this example, a subclass overrides a method from the parent class.

```javascript
// Parent class
class Animal {
  speak() {
    console.log('Animal speaks');
  }
}

// Child class: Dog overrides speak() method
class Dog extends Animal {
  speak() {
    console.log('Dog barks');
  }
}

// Child class: Cat overrides speak() method
class Cat extends Animal {
  speak() {
    console.log('Cat meows');
  }
}

// Create instances of Dog and Cat
const dog = new Dog();
const cat = new Cat();

// Method overriding happens at runtime based on the object’s actual type
dog.speak(); // Output: Dog barks
cat.speak(); // Output: Cat meows
```

#### **Explanation**:
- The `Animal` class has a method `speak()`, which is overridden in both the `Dog` and `Cat` subclasses.
- When you call `dog.speak()` or `cat.speak()`, the method from the respective class is invoked at runtime, even though they are referenced as `Animal` objects.
- **Runtime method overriding** occurs because the method resolution depends on the actual object (whether it is a `Dog` or `Cat`), not on the reference type (`Animal`).

---

### **Example 2: Dynamically Changing an Object’s Method**

JavaScript allows you to modify an object’s methods at runtime. This means that methods can be changed or replaced after an object is created.

```javascript
// Initial object with a speak() method
const animal = {
  speak() {
    console.log('Animal speaks');
  }
};

// Calling the original method
animal.speak(); // Output: Animal speaks

// Dynamically override the speak method at runtime
animal.speak = function() {
  console.log('Animal roars');
};

// Calling the overridden method
animal.speak(); // Output: Animal roars
```

#### **Explanation**:
- The `animal` object initially has a `speak()` method that outputs `'Animal speaks'`.
- Later, the `speak()` method is overridden at runtime, changing the behavior to `'Animal roars'`.
- This shows that JavaScript allows method overriding not only through inheritance but also by directly modifying an object's methods at runtime.

---

### **Example 3: Method Overriding in a Prototype Chain**

JavaScript objects inherit from prototypes, and you can override methods in the prototype chain.

```javascript
// Base object with a speak method
const animal = {
  speak() {
    console.log('Animal speaks');
  }
};

// Dog object inherits from animal and overrides the speak method
const dog = Object.create(animal);
dog.speak = function() {
  console.log('Dog barks');
};

// Call speak method on both objects
animal.speak(); // Output: Animal speaks
dog.speak();    // Output: Dog barks
```

#### **Explanation**:
- The `dog` object is created using `Object.create(animal)` to inherit from the `animal` object.
- The `speak()` method in the `dog` object is overridden at runtime, so when you call `dog.speak()`, it outputs `'Dog barks'`.
- The `animal` object still has its original `speak()` method.
- **Runtime overriding** is achieved via the prototype chain, where the method resolution is dependent on the actual object (`dog` or `animal`).

---

### **Example 4: Polymorphism and Method Overriding in Collections**

Polymorphism is achieved through method overriding in JavaScript collections. This allows different object types to be treated uniformly while calling overridden methods at runtime.

```javascript
class Animal {
  speak() {
    console.log('Animal speaks');
  }
}

class Dog extends Animal {
  speak() {
    console.log('Dog barks');
  }
}

class Cat extends Animal {
  speak() {
    console.log('Cat meows');
  }
}

// Create instances of Dog and Cat
const dog = new Dog();
const cat = new Cat();

// Store both objects in a collection
const animals = [dog, cat];

// Call speak on each element in the collection
animals.forEach(animal => animal.speak());
```

**Output:**
```
Dog barks
Cat meows
```

#### **Explanation**:
- We create an array `animals` containing instances of `Dog` and `Cat`.
- Both classes override the `speak()` method.
- The method that gets called for each object is determined at runtime based on the actual object type, demonstrating **runtime method overriding**.

---

### **Example 5: Runtime Overriding with `Object.defineProperty`**

In JavaScript, you can dynamically define or redefine properties and methods using `Object.defineProperty()`, allowing you to override methods at runtime.

```javascript
const car = {
  drive() {
    console.log('Car is driving');
  }
};

// Override the drive method at runtime using Object.defineProperty
Object.defineProperty(car, 'drive', {
  value: function() {
    console.log('Car is speeding');
  }
});

car.drive(); // Output: Car is speeding
```

#### **Explanation**:
- Initially, the `car` object has a `drive()` method.
- Using `Object.defineProperty`, we redefine the `drive()` method at runtime, replacing the original method.
- This demonstrates how methods can be **overridden dynamically** using JavaScript’s powerful runtime capabilities.

---

### **Conclusion**

Runtime method overriding in JavaScript is a feature that enables flexibility in how methods are invoked, making it a crucial concept in object-oriented programming (OOP). It allows objects to dynamically override inherited methods, either through inheritance, direct assignment, or prototype chain manipulation. By leveraging JavaScript's dynamic nature, developers can create flexible and extensible systems that can adapt to changing requirements at runtime.
