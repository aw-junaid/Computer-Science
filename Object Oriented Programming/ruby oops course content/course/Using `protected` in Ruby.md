In Ruby, **protected** methods are a special category of method visibility that falls between **public** and **private** methods. They can be accessed:

- From within the class they are defined in.
- From within any subclasses of that class.
- **Not** from outside the class or subclass directly.

The primary purpose of **protected methods** is to allow a class and its subclasses to share certain methods, while still protecting those methods from being accessed by arbitrary objects.

### **Key Points about `protected` Methods:**

- A **protected method** can be accessed within the same class or by subclasses, but it cannot be accessed from outside the class hierarchy.
- You can call a protected method **on another object of the same class** or subclass, which is a key difference from **private** methods that cannot be called on `self` or other objects.

---

### **1. Defining Protected Methods**

To define a protected method, you use the `protected` keyword in the class definition. Any methods defined after `protected` will have protected visibility until the end of the class (or until the next access control modifier like `private` or `public`).

#### **Syntax**
```ruby
class ClassName
  protected
  def protected_method
    # method body
  end
end
```

---

### **2. Example of Using Protected Methods**

Here’s an example of how `protected` methods are typically used, demonstrating their use within the class and subclasses:

#### **Example**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def compare(other_animal)
    if self == other_animal
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

class Cat < Animal
  def initialize(name, breed)
    super(name)
    @breed = breed
  end
end

dog1 = Dog.new("Rex", "Bulldog")
dog2 = Dog.new("Rex", "Poodle")
cat = Cat.new("Whiskers", "Siamese")

dog1.compare(dog2)  # Outputs: The animals are the same.
dog1.compare(cat)   # Outputs: The animals are different.
```

- The `==` method is **protected**. It can be called inside the `compare` method of the `Animal` class because `compare` is within the same class.
- However, you **cannot** call the `==` method directly on instances like `dog1 == dog2` from outside the class hierarchy, since it is protected.

---

### **3. Protected Methods Between Subclasses**

One important aspect of **protected** methods is that they can be accessed by subclasses, which is different from **private** methods that are strictly limited to the class they belong to.

#### **Example with Subclass Access**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  protected

  def sound
    "Generic animal sound"
  end
end

class Dog < Animal
  def bark
    puts sound  # Calling protected method from the superclass
  end
end

dog = Dog.new("Rex")
dog.bark  # Outputs: Generic animal sound
```

- The `sound` method is **protected** in the `Animal` class.
- The `Dog` subclass can still access `sound` directly within the `bark` method.

---

### **4. Protected Methods and Comparisons**

A common use case for protected methods is in comparisons or equality checks between objects of the same class or subclass.

#### **Example: Comparing Objects**
```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  protected

  def ==(other)
    @name == other.name && @age == other.age
  end
end

person1 = Person.new("Alice", 30)
person2 = Person.new("Alice", 30)
person3 = Person.new("Bob", 25)

puts person1 == person2  # Outputs: true
puts person1 == person3  # Outputs: false
```

- The `==` method is **protected** and can only be used internally in the class. It compares the `name` and `age` attributes of two `Person` objects.
- The `==` method is used within the `Person` class to compare `person1` and `person2` (both are of the same class), but it is not accessible from outside the class directly.

---

### **5. Protected Methods in Real-World Scenarios**

Protected methods are useful in scenarios where you want to:

- Allow subclasses to access internal functionality that is meant to be shared, but prevent outside code from using it.
- Provide a controlled mechanism for comparisons between instances of the same class.

#### **Example: Allowing Internal Comparison**
```ruby
class BankAccount
  def initialize(balance)
    @balance = balance
  end

  def transfer(other_account, amount)
    if sufficient_funds?(amount)
      @balance -= amount
      other_account.deposit(amount)
      puts "Transferred $#{amount}."
    else
      puts "Insufficient funds."
    end
  end

  protected

  def sufficient_funds?(amount)
    @balance >= amount
  end

  def deposit(amount)
    @balance += amount
  end
end

account1 = BankAccount.new(500)
account2 = BankAccount.new(1000)
account1.transfer(account2, 200)  # Works fine since transfer is inside the class
# account1.sufficient_funds?(200)  # Raises an error: protected method `sufficient_funds?` called
```

- The `sufficient_funds?` method is protected and can be used inside the `BankAccount` class or by its subclasses.
- It’s not accessible from outside the class directly.

---

### **6. Protected Methods and the `self` Object**

In Ruby, **protected methods** **can** be called on the `self` object inside the class, but **cannot** be called on `self` from outside.

#### **Example:**
```ruby
class User
  def initialize(name)
    @name = name
  end

  def compare_name(other_user)
    if self == other_user  # Calling protected method on self
      puts "The users have the same name."
    else
      puts "The users have different names."
    end
  end

  protected

  def ==(other)
    @name == other.name
  end
end

user1 = User.new("John")
user2 = User.new("John")
user3 = User.new("Jane")

user1.compare_name(user2)  # Outputs: The users have the same name.
user1.compare_name(user3)  # Outputs: The users have different names.
```

- The `==` method is **protected** and is called using `self` within the `compare_name` method. It works because `self` refers to the current object within the class.

---

### **Key Points of Protected Methods**

| **Visibility**    | **Accessible By**                               | **Use Case**                             |
|-------------------|-------------------------------------------------|------------------------------------------|
| **Protected**     | The class itself and its subclasses             | Methods meant to be shared within the class and its subclasses. Useful for comparisons, equality checks, and shared internal logic. |

---
