An extended Ruby cheat sheet that covers essential commands, syntax, and concepts. This includes data types, control structures, methods, classes, modules, and more. It serves as a quick reference for Ruby programming.

---

## **Basic Syntax**

### 1. **Structure of a Ruby Program**

```ruby
puts "Hello, World!"  # Output to console
```

**Explanation**: The `puts` method prints output to the console with a newline at the end.

---

## **Data Types**

### 2. **Primitive Data Types**

```ruby
integer = 42           # Integer
float = 3.14          # Float
string = "Hello"      # String
boolean = true        # Boolean
```

**Explanation**: Ruby supports various primitive data types, including integers, floats, strings, and booleans.

### 3. **Arrays**

```ruby
array = [1, 2, 3, 4, 5]
array << 6             # Add an element
puts array[0]         # Access element
```

**Explanation**: Arrays are ordered collections that can hold multiple values.

### 4. **Hashes**

```ruby
hash = { "name" => "Alice", "age" => 25 }
puts hash["name"]     # Access value
```

**Explanation**: Hashes are unordered collections of key-value pairs.

---

## **Control Structures**

### 5. **If-Else Statements**

```ruby
age = 18

if age < 18
  puts "Minor"
elsif age == 18
  puts "Just turned adult"
else
  puts "Adult"
end
```

**Explanation**: The `if-elsif-else` construct allows branching based on conditions.

### 6. **Case Statement**

```ruby
grade = 'A'

case grade
when 'A'
  puts "Excellent"
when 'B'
  puts "Good"
else
  puts "Needs Improvement"
end
```

**Explanation**: The `case` statement provides an easy way to match a value against multiple conditions.

### 7. **Loops**

```ruby
# For loop
for i in 1..5
  puts i
end

# While loop
j = 0
while j < 5
  puts j
  j += 1
end

# Each method
[1, 2, 3].each do |num|
  puts num
end
```

**Explanation**: Ruby supports several looping constructs, including `for`, `while`, and `each` for iterating over collections.

---

## **Methods**

### 8. **Defining and Calling Methods**

```ruby
def greet(name)
  puts "Hello, #{name}!"
end

greet("Alice")          # Calling a method
```

**Explanation**: Methods are defined with the `def` keyword and can accept parameters.

### 9. **Returning Values from Methods**

```ruby
def add(a, b)
  a + b
end

result = add(5, 3)      # result will be 8
```

**Explanation**: Methods return the value of the last expression evaluated.

---

## **Classes and Objects**

### 10. **Defining Classes**

```ruby
class Dog
  def bark
    puts "Woof!"
  end
end

dog = Dog.new
dog.bark                 # Calling a method on the object
```

**Explanation**: Classes are blueprints for creating objects. Use `new` to create an instance of a class.

### 11. **Initialize Method**

```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  def info
    puts "Name: #{@name}, Age: #{@age}"
  end
end

person = Person.new("Alice", 25)
person.info              # Name: Alice, Age: 25
```

**Explanation**: The `initialize` method is a special method called when a new object is instantiated.

### 12. **Inheritance**

```ruby
class Animal
  def speak
    puts "Animal speaks"
  end
end

class Cat < Animal
  def speak
    puts "Meow!"
  end
end

cat = Cat.new
cat.speak                # Meow!
```

**Explanation**: Classes can inherit from other classes, allowing for code reuse.

---

## **Modules**

### 13. **Defining Modules**

```ruby
module Speak
  def speak
    puts "Hello!"
  end
end

class Person
  include Speak
end

person = Person.new
person.speak             # Hello!
```

**Explanation**: Modules are used for namespacing and can be included in classes to share functionality.

---

## **Error Handling**

### 14. **Begin-Rescue-End**

```ruby
begin
  result = 10 / 0       # This will cause an exception
rescue ZeroDivisionError
  puts "Cannot divide by zero!"
end
```

**Explanation**: Ruby uses `begin`, `rescue`, and `end` to handle exceptions gracefully.

---

## **File Handling**

### 15. **Reading and Writing Files**

```ruby
# Writing to a file
File.open("example.txt", "w") do |file|
  file.puts "Hello, File!"
end

# Reading from a file
File.open("example.txt", "r") do |file|
  puts file.read
end
```

**Explanation**: Ruby provides methods for file manipulation, including reading and writing.

---

## **Enumerable Module**

### 16. **Using Enumerable Methods**

```ruby
numbers = [1, 2, 3, 4, 5]

# Using map
squared = numbers.map { |n| n ** 2 }
puts squared.inspect       # [1, 4, 9, 16, 25]

# Using select
even_numbers = numbers.select { |n| n.even? }
puts even_numbers.inspect   # [2, 4]
```

**Explanation**: The `Enumerable` module provides various methods for collections, like `map`, `select`, and `reduce`.

---

## **Regular Expressions**

### 17. **Using Regular Expressions**

```ruby
string = "Hello, World!"
if string =~ /Hello/
  puts "Match found!"
end
```

**Explanation**: Regular expressions are used for pattern matching. The `=~` operator checks if a string matches a pattern.

---

## **Lambda and Procs**

### 18. **Using Lambdas**

```ruby
my_lambda = lambda { |x| x * 2 }
puts my_lambda.call(5)     # 10
```

**Explanation**: A lambda is an anonymous function that can be assigned to a variable and called later.

### 19. **Using Procs**

```ruby
my_proc = Proc.new { |x| x * 3 }
puts my_proc.call(5)       # 15
```

**Explanation**: Procs are similar to lambdas but have different behaviors with respect to arguments and return statements.

---

## **Metaprogramming**

### 20. **Using `define_method`**

```ruby
class DynamicClass
  define_method(:dynamic_method) do
    puts "This method was defined dynamically!"
  end
end

obj = DynamicClass.new
obj.dynamic_method         # This method was defined dynamically!
```

**Explanation**: Metaprogramming allows you to define methods and classes dynamically.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of the essential commands and concepts in Ruby. Regular practice with these concepts will help you become proficient in Ruby programming.
