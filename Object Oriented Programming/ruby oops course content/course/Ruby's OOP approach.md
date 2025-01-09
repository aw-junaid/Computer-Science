Ruby is a **pure object-oriented language**, meaning everything in Ruby is an object, including numbers, strings, and even `nil`. Its object-oriented programming (OOP) approach is designed to be flexible, easy to use, and developer-friendly, enabling you to create reusable, maintainable, and scalable code.

Here’s an overview of Ruby's OOP approach:

---

### **1. Everything is an Object**
- In Ruby, **everything is an object**, including primitives like numbers and strings.
- Objects are instances of classes, and every operation is a method call.

**Example**:
```ruby
5.class     # Outputs: Integer
"hello".class  # Outputs: String
nil.class   # Outputs: NilClass
```

---

### **2. Classes and Objects**
- Ruby allows you to define **classes** as blueprints for creating objects. Each object is an instance of a class.
- Classes can have **instance variables** and **methods** that define an object’s properties and behavior.

**Example**:
```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  def greet
    puts "Hello, my name is #{@name}, and I am #{@age} years old."
  end
end

person = Person.new("Alice", 25)
person.greet  # Outputs: Hello, my name is Alice, and I am 25 years old.
```

---

### **3. Encapsulation**
- Ruby uses access modifiers (`public`, `protected`, and `private`) to implement encapsulation, controlling how methods can be accessed.

**Example**:
```ruby
class Account
  def initialize(balance)
    @balance = balance
  end

  def deposit(amount)
    @balance += amount
  end

  def display_balance
    puts "Your balance is #{@balance}."
  end

  private

  def secret_code
    "1234"
  end
end

account = Account.new(100)
account.deposit(50)
account.display_balance  # Outputs: Your balance is 150.
# account.secret_code     # Raises an error: private method `secret_code' called
```

---

### **4. Inheritance**
- Ruby supports **single inheritance**, allowing a class to inherit from one parent class. Subclasses inherit methods and attributes from the parent class.

**Example**:
```ruby
class Animal
  def speak
    puts "I make a sound."
  end
end

class Dog < Animal
  def speak
    puts "Bark!"
  end
end

dog = Dog.new
dog.speak  # Outputs: Bark!
```

---

### **5. Polymorphism**
- Ruby supports **polymorphism** through **method overriding** and **duck typing**.  
  Duck typing relies on the object’s behavior (methods it implements) rather than its class.

**Example** (Duck Typing):
```ruby
class Dog
  def speak
    puts "Bark!"
  end
end

class Cat
  def speak
    puts "Meow!"
  end
end

def make_speak(animal)
  animal.speak
end

make_speak(Dog.new)  # Outputs: Bark!
make_speak(Cat.new)  # Outputs: Meow!
```

---

### **6. Modules and Mixins**
- Ruby supports **modules**, which are collections of methods that can be included in classes.  
  Modules provide a way to share functionality without using inheritance (via mixins).

**Example**:
```ruby
module Flyable
  def fly
    puts "I can fly!"
  end
end

class Bird
  include Flyable
end

bird = Bird.new
bird.fly  # Outputs: I can fly!
```

---

### **7. Open Classes**
- In Ruby, classes are **open**, meaning you can add or modify methods in existing classes at runtime.

**Example**:
```ruby
class String
  def shout
    self.upcase + "!"
  end
end

puts "hello".shout  # Outputs: HELLO!
```

---

### **8. Singleton Methods**
- Ruby supports defining methods for a single instance of an object, called **singleton methods**.

**Example**:
```ruby
dog = Object.new

def dog.bark
  puts "Woof!"
end

dog.bark  # Outputs: Woof!
```

---

### **9. Dynamic and Flexible Design**
- Ruby emphasizes flexibility, allowing developers to write **dynamic code** using techniques like metaprogramming.
- Metaprogramming allows you to define methods dynamically or modify existing behavior at runtime.

**Example**:
```ruby
class DynamicExample
  define_method(:say_hello) do |name|
    puts "Hello, #{name}!"
  end
end

example = DynamicExample.new
example.say_hello("Ruby")  # Outputs: Hello, Ruby!
```

---

### **10. Key Principles of Ruby's OOP**
- **Simplicity**: Ruby makes writing OOP code intuitive and straightforward.
- **Duck Typing**: Focuses on what objects can do (methods implemented) rather than their class.
- **Mixins**: Ruby encourages code reuse through modules instead of forcing deep inheritance trees.
- **Dynamic Nature**: You can modify or extend behavior at runtime, making Ruby highly flexible.

---

### **Why Ruby’s OOP is Unique**
- Ruby combines traditional OOP principles with **dynamic programming features**, making it easier to write clean and maintainable code.
- Its syntax is simple and highly readable, often described as natural language.
- Emphasizes **developer happiness** by enabling quick prototyping and clean, expressive designs.
