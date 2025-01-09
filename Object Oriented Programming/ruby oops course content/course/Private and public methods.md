In Ruby, **methods** can be categorized based on their **accessibility** within the class, module, or outside code. Ruby provides three access control levels for methods:

1. **Public Methods**
2. **Private Methods**
3. **Protected Methods** (not covered here, but I can explain if needed)

---

### **1. Public Methods**

- **Definition**: By default, all methods in Ruby are **public**, meaning they can be called from anywhere—both within the class and from outside the class.
- **Usage**: Public methods are meant to be accessed and used by the objects of the class or other classes.

#### **Syntax for defining public methods**
```ruby
class ClassName
  def method_name
    # method body
  end
end
```

#### **Example of Public Methods**
```ruby
class Car
  def start_engine
    puts "Engine started."
  end

  def stop_engine
    puts "Engine stopped."
  end
end

my_car = Car.new
my_car.start_engine  # Outputs: Engine started.
my_car.stop_engine   # Outputs: Engine stopped.
```

In this example, both `start_engine` and `stop_engine` are public methods, and can be called from outside the class.

---

### **2. Private Methods**

- **Definition**: **Private methods** can only be called within the class they are defined in, **or by other methods in the same class**. They cannot be called with an explicit receiver (i.e., you cannot call a private method on `self`).
- **Usage**: Private methods are typically used for internal processing and not meant to be called outside the class.

#### **Syntax for defining private methods**
```ruby
class ClassName
  private
  def method_name
    # method body
  end
end
```

#### **Example of Private Methods**
```ruby
class Car
  def initialize
    @engine_status = "off"
  end

  def start_engine
    check_fuel_level  # Calling a private method inside the class
    @engine_status = "on"
    puts "Engine started."
  end

  private

  def check_fuel_level
    puts "Checking fuel level..."  # Private method
  end
end

my_car = Car.new
my_car.start_engine  # Outputs: Checking fuel level... and Engine started.

# my_car.check_fuel_level  # Raises an error: private method `check_fuel_level` called
```

In this example:
- `check_fuel_level` is a private method and can only be called within the class.
- Trying to call `check_fuel_level` from outside the class (like `my_car.check_fuel_level`) will raise an error.

---

### **3. Changing Method Visibility**

You can change the visibility of methods within a class using the **`public`**, **`private`**, and **`protected`** keywords.

#### **Example of Changing Visibility**
```ruby
class BankAccount
  def initialize(balance)
    @balance = balance
  end

  public
  def deposit(amount)
    @balance += amount
    puts "Deposited $#{amount}. New balance: $#{@balance}"
  end

  private
  def balance
    @balance
  end
end

account = BankAccount.new(100)
account.deposit(50)  # Outputs: Deposited $50. New balance: $150
# account.balance  # Raises an error: private method `balance` called
```

- `deposit` is public, so it can be accessed from outside.
- `balance` is private, so it can only be accessed within the class.

---

### **4. Default Visibility**

- Methods are **public** by default. If you don't specify `private` or `protected`, methods are considered public.
  
#### **Example**
```ruby
class Person
  def speak
    puts "Hello!"
  end
end

person = Person.new
person.speak  # Outputs: Hello!
```

---

### **5. Calling Private Methods**

To call private methods, you need to call them within the context of the class itself, either directly or via other methods. You **cannot** call private methods on `self`.

#### **Example of Calling Private Methods Within the Class**
```ruby
class Person
  def initialize(name)
    @name = name
  end

  def greet
    puts "Hello, #{@name}!"
    private_message
  end

  private

  def private_message
    puts "This is a private message."
  end
end

person = Person.new("Alice")
person.greet  # Outputs: Hello, Alice! and This is a private message.
```

---

### **6. Access Control Modifiers in Ruby**

- **Public**: Default for methods. Can be accessed from anywhere.
- **Private**: Can only be accessed inside the class and not with an explicit receiver.
- **Protected**: Can be accessed within the class and by its subclasses.

#### **Example of Protected Methods (for completeness)**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def compare(other)
    if self == other
      puts "The animals are the same."
    else
      puts "The animals are different."
    end
  end

  protected

  def ==(other)
    @name == other.name
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)
    @breed = breed
  end
end

dog1 = Dog.new("Rex", "Bulldog")
dog2 = Dog.new("Rex", "Poodle")

dog1.compare(dog2)  # Outputs: The animals are the same.
```

- In this example, the `==` method is protected, so it can be accessed by instances of the class and its subclasses, like `Dog`.

---

### **Key Points Summary**

| **Visibility** | **Accessible By**                          | **Use Case**                              |
|----------------|--------------------------------------------|-------------------------------------------|
| **Public**     | Anywhere (outside and inside the class)    | Methods that are meant to be used externally |
| **Private**    | Inside the class only, cannot be called with an explicit receiver | Internal helper methods, data hiding |
| **Protected**  | Inside the class and its subclasses       | Methods meant for use by subclasses only |

---
