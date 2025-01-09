### **Duck Typing in Ruby**

**Duck typing** is a concept in Ruby (and other dynamically typed languages) where the type of an object is determined by the **methods** it responds to, rather than its explicit class or inheritance. The term comes from the saying, "If it looks like a duck and quacks like a duck, it must be a duck." In Ruby, this means that if an object behaves like a certain type (i.e., it has the required methods), it is treated as that type, regardless of the class it belongs to.

In essence, Ruby doesn't require an object to be an instance of a specific class to call a method on it. As long as the object **responds to the expected methods**, it can be used.

---

### **1. Basics of Duck Typing**

In duck typing, the **type of an object is determined by what methods it can respond to**. Instead of checking an object's class, Ruby simply checks whether the object supports the required behavior (method calls).

#### **Example: Duck Typing**
```ruby
class Dog
  def speak
    puts "Woof!"
  end
end

class Cat
  def speak
    puts "Meow!"
  end
end

def make_sound(animal)
  animal.speak  # No need to check if it's a Dog or Cat
end

dog = Dog.new
cat = Cat.new

make_sound(dog)  # Outputs: Woof!
make_sound(cat)  # Outputs: Meow!
```

- Here, the `make_sound` method calls `animal.speak`, regardless of whether `animal` is a `Dog`, `Cat`, or any other object that has a `speak` method.
- Ruby doesn't care about the type of the object as long as it **responds to the `speak` method**. This is duck typing in action.

---

### **2. No Need for Explicit Inheritance**

Duck typing in Ruby eliminates the need for an object to inherit from a specific class or module to behave in a certain way. Instead of using inheritance hierarchies, Ruby focuses on whether the object can respond to the required methods.

#### **Example: Using Duck Typing Instead of Inheritance**
```ruby
class Car
  def drive
    puts "Driving the car!"
  end
end

class Bike
  def drive
    puts "Riding the bike!"
  end
end

def travel(vehicle)
  vehicle.drive  # It doesn't matter if it's a Car or Bike
end

car = Car.new
bike = Bike.new

travel(car)  # Outputs: Driving the car!
travel(bike)  # Outputs: Riding the bike!
```

- The `travel` method does not need to check if the object is a `Car` or `Bike`; it simply calls the `drive` method on whatever object is passed to it.
- This is possible because both `Car` and `Bike` "look like" objects that can `drive`, so Ruby doesn't care about their class.

---

### **3. Checking for Methods with `respond_to?`**

To check if an object supports a certain method (i.e., whether it "looks like" the expected type), you can use the `respond_to?` method. This method returns `true` if the object can respond to the specified method.

#### **Example: Using `respond_to?`**
```ruby
class Dog
  def speak
    puts "Woof!"
  end
end

dog = Dog.new
puts dog.respond_to?(:speak)  # Outputs: true
puts dog.respond_to?(:fly)    # Outputs: false
```

- `respond_to?(:speak)` returns `true` because the `dog` object has a `speak` method.
- `respond_to?(:fly)` returns `false` because the `dog` object does not have a `fly` method.

---

### **4. Duck Typing and Flexibility**

Duck typing makes Ruby very **flexible** and allows objects to behave in many ways, even if they do not share a common parent class or module. It enables Ruby programs to focus more on **behavior** than on **types** or **class hierarchies**.

#### **Example: Flexible Behavior**
```ruby
class Human
  def walk
    puts "Walking on two legs."
  end
end

class Robot
  def walk
    puts "Walking on wheels."
  end
end

def go_for_a_walk(walker)
  walker.walk  # Works with any object that responds to `walk`
end

human = Human.new
robot = Robot.new

go_for_a_walk(human)  # Outputs: Walking on two legs.
go_for_a_walk(robot)   # Outputs: Walking on wheels.
```

- Both `Human` and `Robot` classes have different implementations of `walk`, but both objects are treated the same in the `go_for_a_walk` method as long as they respond to `walk`.
- This demonstrates the **flexibility** of duck typing, where the focus is on what an object **can do**, not what it **is**.

---

### **5. The Power of Duck Typing in Ruby**

Duck typing allows for **loose coupling** in Ruby programs. You don’t need to know the exact type of an object to interact with it as long as it responds to the correct methods. This makes Ruby code very **dynamic** and **flexible**, especially in cases where you don’t need to be concerned with the object’s class.

#### **Example: Passing Multiple Objects**
```ruby
class Car
  def move
    puts "The car is moving."
  end
end

class Plane
  def move
    puts "The plane is flying."
  end
end

def transport(vehicle)
  vehicle.move  # No need to check the class of the object
end

car = Car.new
plane = Plane.new

transport(car)   # Outputs: The car is moving.
transport(plane)  # Outputs: The plane is flying.
```

- `transport` can accept both `Car` and `Plane` objects because they both **respond to** the `move` method.
- This approach **decouples** the behavior from the specific class, allowing for more **generic and reusable code**.

---

### **6. Duck Typing vs. Static Typing**

In statically typed languages (like Java or C++), you typically need to define an object's type explicitly using inheritance, interfaces, or explicit type declarations. In contrast, Ruby uses duck typing, which eliminates the need for explicit type checking. This can lead to more **concise** and **flexible** code, but it also means that errors related to missing methods are typically caught **at runtime**, not during compilation.

#### **Duck Typing in Ruby: Advantages and Disadvantages**

- **Advantages**:
  - **Flexibility**: Methods can accept objects of any class as long as they implement the required behavior.
  - **Loose Coupling**: No need for rigid class hierarchies or interfaces, making the code easier to maintain and extend.
  - **Concise Code**: No need to explicitly declare types, leading to shorter and more readable code.

- **Disadvantages**:
  - **Runtime Errors**: Since types are determined at runtime, errors (such as calling a method that doesn’t exist) are not detected until the code is executed.
  - **Less Explicit**: For new developers or in complex projects, it can be harder to determine what methods an object should have, leading to potential confusion.

---

### **7. Conclusion**

Duck typing in Ruby allows objects to be treated based on the methods they implement rather than their class or type. This gives Ruby a lot of **flexibility** and **expressiveness**, as you can pass objects of different classes to methods as long as they respond to the necessary methods.

Key takeaways:
- Duck typing is about the **behavior** (methods) an object can perform, not the class it belongs to.
- You can use `respond_to?` to check if an object supports a method.
- Duck typing enables **flexibility** and **reusability** in Ruby code.
