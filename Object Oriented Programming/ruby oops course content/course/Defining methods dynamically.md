### **Defining Methods Dynamically in Ruby**

Ruby's metaprogramming capabilities allow you to define methods dynamically during runtime. This can be done using techniques such as `define_method`, `method_missing`, and other reflection methods. Dynamically defining methods allows you to create methods based on conditions, user input, or any other runtime data.

Here are some key ways to define methods dynamically in Ruby:

---

### **1. Using `define_method`**

`define_method` is a Ruby method that allows you to define a method dynamically within a class or module. The method name is passed as a symbol, and the block defines the body of the method.

#### **Basic Example: Dynamically Defining Methods with `define_method`**

```ruby
class DynamicMethods
  [:foo, :bar, :baz].each do |method_name|
    define_method(method_name) do
      puts "#{method_name} was called!"
    end
  end
end

obj = DynamicMethods.new
obj.foo   # Outputs: foo was called!
obj.bar   # Outputs: bar was called!
obj.baz   # Outputs: baz was called!
```

- In this example, we loop through an array of method names (`:foo`, `:bar`, `:baz`) and define each one dynamically using `define_method`. The block inside `define_method` is executed when the respective method is called.

---

### **2. Using `method_missing` for Dynamic Method Handling**

`method_missing` allows you to capture calls to undefined methods and define how they should behave. This can be used to define methods dynamically when they are called for the first time.

#### **Example: Dynamically Handling Undefined Methods with `method_missing`**

```ruby
class DynamicHandler
  def method_missing(method_name, *args)
    puts "Dynamically handling method: #{method_name} with arguments: #{args.inspect}"
    self.class.send(:define_method, method_name) do |*args|
      puts "Method #{method_name} called with arguments: #{args.inspect}"
    end
  end
end

obj = DynamicHandler.new
obj.some_method(1, 2, 3)  # Outputs: Dynamically handling method: some_method with arguments: [1, 2, 3]
obj.some_method(10)       # Outputs: Method some_method called with arguments: [10]
```

- In this example, when `some_method` is called for the first time, `method_missing` is triggered. It defines the method dynamically using `define_method`, so subsequent calls to `some_method` work normally.

---

### **3. Using `class_eval` for Dynamically Defining Class Methods**

You can use `class_eval` to evaluate Ruby code within the context of a class and define methods dynamically within a class definition.

#### **Example: Defining Class Methods Dynamically with `class_eval`**

```ruby
class Person
  class_eval do
    def greet
      "Hello, I am a Person."
    end
  end
end

person = Person.new
puts person.greet  # Outputs: Hello, I am a Person.
```

- Here, we use `class_eval` to define the `greet` method dynamically inside the `Person` class.

---

### **4. Using `instance_eval` to Define Instance Methods Dynamically**

You can also use `instance_eval` to define methods dynamically for individual instances of a class. This is useful if you need to add methods to objects at runtime rather than to the class itself.

#### **Example: Defining Instance Methods Dynamically with `instance_eval`**

```ruby
class Animal
end

dog = Animal.new

dog.instance_eval do
  def speak
    "Woof!"
  end
end

puts dog.speak  # Outputs: Woof!
```

- In this example, we use `instance_eval` to add the `speak` method to a specific instance (`dog`) of the `Animal` class at runtime.

---

### **5. Using `define_singleton_method` for Defining Methods on Single Instances**

`define_singleton_method` allows you to define methods dynamically for a specific instance of a class (not the entire class).

#### **Example: Defining Singleton Methods Dynamically**

```ruby
class Animal
end

dog = Animal.new

dog.define_singleton_method(:speak) do
  "Woof!"
end

puts dog.speak  # Outputs: Woof!
```

- Here, we use `define_singleton_method` to define the `speak` method only for the `dog` instance. This method will not be available to other instances of `Animal`.

---

### **6. Using `self.class.send` to Dynamically Define Methods**

You can also use `self.class.send` to define methods dynamically inside an instance or class.

#### **Example: Defining Methods Inside an Instance Using `self.class.send`**

```ruby
class DynamicMethodExample
  def initialize
    self.class.send(:define_method, :dynamic_method) do
      puts "This is a dynamically defined method!"
    end
  end
end

obj = DynamicMethodExample.new
obj.dynamic_method  # Outputs: This is a dynamically defined method!
```

- Here, `self.class.send` is used to define a method (`dynamic_method`) inside the `initialize` method. The method is created dynamically and can be called on the instance.

---

### **7. Using Blocks to Define Multiple Methods**

You can use blocks with `define_method` to define multiple methods at once, depending on the needs of your application.

#### **Example: Defining Multiple Methods Dynamically**

```ruby
class MultiMethodDefiner
  [:add, :subtract, :multiply].each do |method_name|
    define_method(method_name) do |x, y|
      case method_name
      when :add then x + y
      when :subtract then x - y
      when :multiply then x * y
      end
    end
  end
end

obj = MultiMethodDefiner.new
puts obj.add(2, 3)       # Outputs: 5
puts obj.subtract(5, 3)  # Outputs: 2
puts obj.multiply(4, 3)  # Outputs: 12
```

- This example demonstrates defining multiple methods (`add`, `subtract`, `multiply`) dynamically with the help of `define_method`. Each method performs its respective operation when called.

---

### **8. Using Method Names as Data**

Sometimes you might want to use method names dynamically based on external data, like a user input or database query.

#### **Example: Defining Methods from User Input**

```ruby
class DynamicMethodCreator
  def create_method(method_name)
    self.class.send(:define_method, method_name) do
      "This is dynamically created method: #{method_name}"
    end
  end
end

obj = DynamicMethodCreator.new
obj.create_method("new_method")
puts obj.new_method  # Outputs: This is dynamically created method: new_method
```

- In this case, `create_method` allows you to define methods based on dynamic input. The `new_method` is created dynamically based on the string `"new_method"` passed to `create_method`.

---

### **Conclusion**

Dynamically defining methods in Ruby allows you to write more flexible and adaptable code. Whether you use `define_method`, `method_missing`, `instance_eval`, or other metaprogramming techniques, you can generate methods at runtime based on varying conditions, user input, or external factors. This makes Ruby an incredibly powerful language for building dynamic systems, DSLs, and adaptable architectures.
