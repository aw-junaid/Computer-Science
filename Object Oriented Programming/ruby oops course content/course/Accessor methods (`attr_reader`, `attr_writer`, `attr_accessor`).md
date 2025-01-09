In Ruby, **accessor methods** are a convenient way to define getter and setter methods for an object's instance variables. They provide a cleaner and more concise way to access and modify instance variables without manually defining methods. Ruby offers three built-in methods for this purpose:

- **`attr_reader`**: Defines getter methods.
- **`attr_writer`**: Defines setter methods.
- **`attr_accessor`**: Defines both getter and setter methods.

---

### **1. `attr_reader`: Getter Method**

- Creates a method to read the value of an instance variable.
- Does **not** allow modification of the variable.

#### **Syntax**
```ruby
attr_reader :variable_name
```

#### **Example**
```ruby
class Person
  attr_reader :name  # Getter for @name

  def initialize(name)
    @name = name
  end
end

person = Person.new("Alice")
puts person.name  # Outputs: Alice
# person.name = "Bob"  # Raises an error: undefined method `name='
```

---

### **2. `attr_writer`: Setter Method**

- Creates a method to set (modify) the value of an instance variable.
- Does **not** allow reading the value directly.

#### **Syntax**
```ruby
attr_writer :variable_name
```

#### **Example**
```ruby
class Person
  attr_writer :name  # Setter for @name

  def initialize(name)
    @name = name
  end
end

person = Person.new("Alice")
person.name = "Bob"  # Modifies @name
# puts person.name  # Raises an error: undefined method `name'
```

---

### **3. `attr_accessor`: Getter and Setter**

- Combines `attr_reader` and `attr_writer`.
- Creates both getter and setter methods for an instance variable.

#### **Syntax**
```ruby
attr_accessor :variable_name
```

#### **Example**
```ruby
class Person
  attr_accessor :name  # Getter and setter for @name

  def initialize(name)
    @name = name
  end
end

person = Person.new("Alice")
puts person.name  # Outputs: Alice
person.name = "Bob"  # Modifies @name
puts person.name  # Outputs: Bob
```

---

### **Using Multiple Variables**

You can define accessors for multiple instance variables in a single line by separating them with commas.

#### **Example**
```ruby
class Book
  attr_accessor :title, :author  # Both getter and setter for @title and @author

  def initialize(title, author)
    @title = title
    @author = author
  end
end

book = Book.new("1984", "George Orwell")
puts book.title  # Outputs: 1984
puts book.author  # Outputs: George Orwell

book.title = "Animal Farm"
book.author = "George Orwell"
puts book.title  # Outputs: Animal Farm
puts book.author  # Outputs: George Orwell
```

---

### **4. Why Use Accessor Methods?**

1. **Encapsulation**: Provides controlled access to instance variables.
2. **Readability**: Simplifies code by removing the need to manually define getter and setter methods.
3. **Maintainability**: Allows modifications to accessor methods later without changing external code.

---

### **5. Customizing Accessor Methods**

You can override the default behavior of accessors by manually defining getter or setter methods.

#### **Example**
```ruby
class Product
  attr_accessor :price

  def initialize(price)
    @price = price
  end

  # Customize setter to ensure price is non-negative
  def price=(new_price)
    if new_price >= 0
      @price = new_price
    else
      puts "Price can't be negative!"
    end
  end
end

product = Product.new(100)
puts product.price  # Outputs: 100

product.price = -50  # Outputs: Price can't be negative!
puts product.price  # Outputs: 100
```

---

### **6. Access Modifiers with Accessors**

You can use Ruby's access control keywords (`public`, `protected`, `private`) to restrict access to accessor methods.

#### **Example**
```ruby
class Account
  attr_reader :balance  # Only getter

  def initialize(balance)
    @balance = balance
  end

  private

  attr_writer :balance  # Setter is private

  def update_balance(new_balance)
    self.balance = new_balance  # Can only be called internally
  end
end

account = Account.new(1000)
puts account.balance  # Outputs: 1000
# account.balance = 2000  # Raises an error: private method `balance='
```

---

### **Comparison of Accessor Methods**

| **Method**       | **Purpose**                                      | **Access**         |
|-------------------|--------------------------------------------------|--------------------|
| `attr_reader`     | Provides read-only access to an instance variable | Getter only        |
| `attr_writer`     | Provides write-only access to an instance variable | Setter only        |
| `attr_accessor`   | Provides both read and write access               | Getter and Setter  |

---
