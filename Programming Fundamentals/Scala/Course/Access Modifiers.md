In Scala, **access modifiers** control the visibility of class members (fields, methods, etc.) and help in encapsulating the details of a class. Scala supports the following access modifiers:

1. **`private`**  
2. **`protected`**  
3. **`public`** (default)  

Let’s explore each access modifier in detail:

### 1. **`private` Modifier**
The `private` modifier restricts access to class members, making them accessible only within the class or object where they are defined. The member is not accessible from outside the class, including subclasses.

#### Example of `private`:
```scala
class Person(private var age: Int) {
  def getAge(): Int = age
  def setAge(newAge: Int): Unit = {
    if (newAge > 0) age = newAge
  }
}

val person = new Person(30)
// person.age // Error: age is private
println(person.getAge())  // Output: 30
person.setAge(35)
println(person.getAge())  // Output: 35
```
- The `age` field is private and cannot be accessed directly outside the class. However, the methods `getAge()` and `setAge()` are used to access and modify it.

### 2. **`protected` Modifier**
The `protected` modifier restricts access to class members, but they are accessible within the class and its subclasses. This allows subclasses to inherit and modify the protected members while keeping them hidden from other external classes.

#### Example of `protected`:
```scala
class Animal(protected var name: String) {
  def speak(): Unit = println(s"$name makes a sound.")
}

class Dog(name: String) extends Animal(name) {
  def greet(): Unit = println(s"Hello, I am $name and I bark!")
}

val dog = new Dog("Buddy")
dog.speak()  // Output: Buddy makes a sound.
// dog.name // Error: name is protected
dog.greet()  // Output: Hello, I am Buddy and I bark!
```
- The `name` field is `protected` in the `Animal` class. It can be accessed in the `Dog` subclass, but it cannot be accessed from outside the class hierarchy.

### 3. **`public` Modifier** (Default)
The `public` modifier makes members accessible from anywhere in the code, both within the class and from external code. In Scala, class members are **public** by default unless specified otherwise using `private` or `protected`.

#### Example of `public` (default):
```scala
class Person(val name: String, var age: Int) {
  def greet(): Unit = {
    println(s"Hello, my name is $name and I am $age years old.")
  }
}

val person = new Person("Alice", 30)
person.greet()  // Output: Hello, my name is Alice and I am 30 years old.
println(person.name)  // Output: Alice
person.age = 31
println(person.age)   // Output: 31
```
- The `name` and `age` fields are public by default, meaning they can be accessed directly from outside the class. You can modify `age` directly as well.

### 4. **Private Members in Companion Objects**
You can use the `private` modifier in the **companion object** to restrict access to private methods or variables. The companion object has access to the private members of its associated class.

#### Example with Companion Object:
```scala
class Person(val name: String) {
  private var age: Int = 0

  def greet(): Unit = {
    println(s"Hello, my name is $name and I am $age years old.")
  }
}

object Person {
  def createPerson(name: String, age: Int): Person = {
    val person = new Person(name)
    person.age = age  // Accessing private member from the companion object
    person
  }
}

val person = Person.createPerson("John", 25)
person.greet()  // Output: Hello, my name is John and I am 25 years old.
```
- The `age` field is private in the `Person` class, but the `Person` companion object can access it directly.

### 5. **Private Members in Nested Classes and Inner Objects**
You can also restrict the access to members within **nested classes** or **inner objects** using the `private` modifier.

#### Example of `private` in Nested Classes:
```scala
class Outer {
  private class Inner {
    def hello(): Unit = println("Hello from Inner class!")
  }

  def createInner(): Unit = {
    val inner = new Inner
    inner.hello()  // Output: Hello from Inner class!
  }
}

val outer = new Outer
outer.createInner()  // Valid because the method is inside the Outer class
// val inner = new outer.Inner  // Error: cannot access private Inner class
```
- The `Inner` class is private and cannot be accessed from outside the `Outer` class.

### 6. **Private Constructor**
You can make the constructor of a class **private** to prevent direct instantiation of the class from outside. This is useful when you want to control the creation of objects using methods in the companion object or other class members.

#### Example of Private Constructor:
```scala
class Person private (val name: String, val age: Int)

object Person {
  def apply(name: String, age: Int): Person = {
    new Person(name, age)
  }
}

val person = Person("Alice", 30)  // Valid, using the apply method
// val p = new Person("Bob", 25)  // Error: constructor is private
```
- The constructor of the `Person` class is private, so objects can only be created through the `apply` method in the companion object.

### Summary of Access Modifiers in Scala:

| **Modifier**   | **Description**                                                                                     |
|----------------|-----------------------------------------------------------------------------------------------------|
| **`private`**  | Limits access to the defining class or object. Members cannot be accessed from outside the class.   |
| **`protected`**| Members are accessible within the class and its subclasses, but not from outside the class hierarchy.|
| **`public`**   | Default access level in Scala. Members are accessible from anywhere in the program.                 |

### Conclusion:
Access modifiers in Scala provide a way to control the visibility and encapsulation of members in a class or object. Using **`private`** for internal details and **`protected`** for subclass access ensures that your code remains modular and secure. The **`public`** modifier (the default in Scala) allows unrestricted access to class members. Proper use of access modifiers helps in maintaining a clean and understandable object-oriented design.
