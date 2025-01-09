### **Using `super` to Access Parent Class Methods**

In Ruby, the `super` keyword is used to **call a method from the parent class** within the subclass. This allows the subclass to **invoke** the behavior of the parent class while potentially adding additional functionality.

The `super` keyword can be used in two primary ways:
1. **Without arguments** – It calls the parent method with the same arguments as the current method.
2. **With arguments** – It allows you to specify different arguments when calling the parent method.

---

### **1. Basic Use of `super` (No Arguments)**

When you use `super` without arguments, Ruby automatically passes the arguments received by the subclass method to the parent method. This is useful if the subclass method takes the same arguments as the parent method.

#### **Example: Using `super` Without Arguments**
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

- The `super` keyword calls the `speak` method of the parent class (`Animal`).
- After calling the parent method, the subclass (`Dog`) adds its own behavior.

---

### **2. Using `super` with Arguments**

You can also use `super` with arguments to **pass specific arguments** to the parent class's method. This is useful when you want to customize how arguments are handled or when the subclass method has different arguments than the parent method.

#### **Example: Using `super` with Arguments**
```ruby
class Animal
  def speak(name)
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name)
    super(name)  # Passes the `name` argument to the parent method
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
dog.speak("Rex")
# Outputs:
# I am an animal named Rex.
# I am a dog named Rex. Woof!
```

- In this example, the `Dog` class overrides the `speak` method and uses `super(name)` to call the parent method (`Animal`'s `speak`), passing the `name` argument.
- This way, the `name` argument is processed by both the parent and subclass methods.

---

### **3. Using `super` with a Modified Argument List**

You can modify the arguments passed to the parent method by changing the arguments within the `super` call. This allows the subclass to **customize** the behavior of the parent method based on the arguments it receives.

#### **Example: Modifying Arguments with `super`**
```ruby
class Animal
  def speak(name, age)
    puts "I am an animal named #{name} and I am #{age} years old."
  end
end

class Dog < Animal
  def speak(name, age)
    super(name, age + 1)  # Increments the age before passing it to the parent method
    puts "I am a dog named #{name} and I am #{age} years old."
  end
end

dog = Dog.new
dog.speak("Rex", 3)
# Outputs:
# I am an animal named Rex and I am 4 years old.
# I am a dog named Rex and I am 3 years old.
```

- In this example, the `Dog` class **modifies** the `age` argument by adding 1 before passing it to the parent `speak` method.
- The `super(name, age + 1)` call sends the incremented `age` to the parent method.

---

### **4. Using `super` in Constructor (`initialize`) Method**

The `super` keyword is also commonly used in the **constructor (`initialize`) method** to ensure that the parent class's initialization is properly handled before adding subclass-specific setup.

#### **Example: Using `super` in `initialize` Method**
```ruby
class Animal
  def initialize(name)
    @name = name
    puts "Animal initialized with name #{@name}."
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)  # Calls the parent's initialize method to set @name
    @breed = breed
    puts "Dog initialized with breed #{@breed}."
  end
end

dog = Dog.new("Rex", "Bulldog")
# Outputs:
# Animal initialized with name Rex.
# Dog initialized with breed Bulldog.
```

- The `Dog` class uses `super(name)` to ensure that the `@name` instance variable is initialized by the `Animal` class.
- After calling `super`, the `Dog` class continues its initialization by setting the `@breed` variable.

---

### **5. Using `super` Without Any Arguments**

You can also use `super` without any arguments. This will pass the **same arguments** that were passed to the subclass method to the parent method.

#### **Example: `super` Without Arguments**
```ruby
class Animal
  def speak(name)
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name)
    super  # Calls the parent method and passes the same `name` argument
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
dog.speak("Rex")
# Outputs:
# I am an animal named Rex.
# I am a dog named Rex. Woof!
```

- Here, the `Dog` class calls `super` without passing any arguments. This allows Ruby to automatically pass the `name` argument to the parent method.

---

### **6. `super` and No Arguments in the Parent Method**

If the parent method does not accept any arguments, and you call `super` with arguments, Ruby will raise an **ArgumentError** since the parent method does not expect any arguments.

#### **Example: Using `super` with Arguments When Parent Method Takes None**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak(name)
    super()  # Tries to call parent method with no arguments (Error)
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
# dog.speak("Rex")  # This will raise an error: wrong number of arguments
```

- The parent class `Animal`'s `speak` method does not take any arguments, but `super()` in the `Dog` class tries to pass an argument, causing an error.
- To avoid this, either **remove the arguments** in the subclass or ensure the parent class’s method signature can accept them.

---

### **7. Conclusion**

The `super` keyword in Ruby allows a subclass to:
- Call the **parent class's method** with the same arguments or customized arguments.
- **Extend or modify** the behavior of the parent method without completely replacing it.
- **Call the parent's `initialize` method** in the constructor to ensure proper initialization of inherited instance variables.

Using `super` is a key technique to achieve **method inheritance** and **behavior extension** in Ruby’s OOP paradigm.
