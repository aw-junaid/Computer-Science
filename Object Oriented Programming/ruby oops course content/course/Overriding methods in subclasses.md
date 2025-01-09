### **Overriding Methods in Subclasses**

In **Object-Oriented Programming (OOP)**, **method overriding** allows a subclass to provide its own implementation of a method that is already defined in its parent class. This means the subclass can **redefine** the behavior of a method inherited from the parent class to suit its specific needs.

In Ruby, method overriding is quite straightforward. When a subclass defines a method with the same name as one in the parent class, the subclass method **replaces** the parent class's version.

---

### **1. Basic Example of Method Overriding**

#### **Example: Overriding a Method**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak  # Outputs: "I am a dog. Woof!"
```

- The `Dog` class overrides the `speak` method from the `Animal` class. When you call `dog.speak`, the overridden method in the `Dog` class is executed, not the one in `Animal`.

---

### **2. Calling the Parent Method with `super`**

Sometimes, you may want to call the parent class’s method in addition to adding some functionality in the subclass. You can do this with the `super` keyword, which invokes the parent class’s method from the subclass.

#### **Example: Using `super` to Call the Parent Method**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    super  # Calls the parent method (Animal's speak)
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- In the `Dog` class, `super` calls the `speak` method from the parent class (`Animal`), and then the subclass method adds its own message.
- This allows the subclass to extend or modify the behavior of the parent class method.

---

### **3. Overriding Methods with Arguments**

When overriding methods in subclasses, you can choose to accept different arguments or the same ones as the parent method. In Ruby, the method signature in the subclass can match or differ from the parent’s.

#### **Example: Overriding Methods with Arguments**
```ruby
class Animal
  def speak(name)
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name)
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
dog.speak("Rex")  # Outputs: "I am a dog named Rex. Woof!"
```

- The `Dog` class overrides the `speak` method from `Animal` and provides its own implementation with the same parameter (`name`).
- Both `Animal` and `Dog` can accept and process the `name` argument, but the behavior is different.

---

### **4. Overriding Private Methods**

While you can override private methods, they still maintain their **private** visibility, meaning they can only be called within the same class or instance.

#### **Example: Overriding Private Methods**
```ruby
class Animal
  private
  def private_speak
    puts "I am an animal, and this is private."
  end
end

class Dog < Animal
  private
  def private_speak
    puts "I am a dog, and this is also private."
  end
end

dog = Dog.new
# dog.private_speak  # This would raise an error: private method `private_speak` called
```

- Both the parent (`Animal`) and the subclass (`Dog`) define a `private_speak` method, but since it's a private method, it can’t be accessed from outside the class.
- Even though `Dog` overrides the `private_speak` method, it remains private within the class.

---

### **5. Overriding and Method Arguments Compatibility**

Ruby allows flexibility in the number of arguments for overridden methods. The subclass does not necessarily need to have the same number of parameters as the parent class, but it must handle the arguments appropriately.

#### **Example: Overriding Method with Different Arguments**
```ruby
class Animal
  def speak(name)
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name, breed)
    puts "I am a dog named #{name}, and I am a #{breed}."
  end
end

dog = Dog.new
dog.speak("Rex", "Bulldog")  # Outputs: "I am a dog named Rex, and I am a Bulldog."
```

- The `Dog` class’s `speak` method accepts two arguments (`name` and `breed`), while the parent class's `speak` method accepts only one (`name`).
- The `Dog` class **does not override** the parent method directly; instead, it provides its own version, which is why the `speak` method in `Dog` can handle different arguments.

---

### **6. Overriding Methods with Default Arguments**

Ruby allows you to define **default arguments** for methods. These default values can be overridden by the subclass or parent class.

#### **Example: Overriding Methods with Default Arguments**
```ruby
class Animal
  def speak(name = "Animal")
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name = "Dog")
    super(name)  # Calls the parent method and passes `name`
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
dog.speak  # Outputs: "I am an animal named Dog."
           # Outputs: "I am a dog named Dog. Woof!"
```

- The `Dog` class overrides the `speak` method from `Animal`, using the default `name = "Dog"` argument.
- The `super(name)` in `Dog` passes the `name` argument to the parent `Animal` method.

---

### **7. Ensuring Subclass Consistency with `super`**

If you want to enforce that the parent class's method is called every time the subclass method is invoked (even if no changes are made in the subclass), you should always use `super` inside the subclass method.

#### **Example: Always Using `super`**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    super  # Ensures that the parent method is always called
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- The `super` ensures that the `speak` method of the `Animal` class is always invoked, even if `Dog` provides additional functionality.

---

### **8. Conclusion**

- **Method overriding** allows a subclass to provide a new implementation of a method defined in its parent class.
- You can use `super` to call the **parent method** while adding extra functionality in the subclass.
- When overriding methods, you can change the number of arguments or the behavior, but the method name must stay the same.
- Ruby provides flexibility in overriding methods, allowing you to adapt inherited behavior to suit the needs of the subclass.
