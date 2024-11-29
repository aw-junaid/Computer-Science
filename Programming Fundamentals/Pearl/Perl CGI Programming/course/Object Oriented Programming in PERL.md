### Object-Oriented Programming in Perl

Perl supports Object-Oriented Programming (OOP), allowing you to create and manipulate objects, which are instances of classes (packages). In Perl, OOP is flexible and straightforward, making it possible to integrate OO principles with Perl's procedural and functional style. 

### Basic Concepts of OOP in Perl

1. **Class**: A class in Perl is a package that defines the behavior and attributes of objects.
2. **Object**: An object is an instance of a class, usually implemented as a reference (usually a hash reference) that is blessed into a class.
3. **Methods**: Subroutines within a class that operate on objects.

---

### 1. **Creating a Class in Perl**

A Perl class is defined using the `package` keyword. Let’s create a simple `Animal` class.

#### Example: Defining an `Animal` Class

```perl
package Animal;

# Constructor
sub new {
    my ($class, %args) = @_;
    my $self = {
        name => $args{name} || "Unnamed",
        sound => $args{sound} || "No sound",
    };
    # Bless the hash reference into the class
    bless $self, $class;
    return $self;
}

# Method to get animal sound
sub make_sound {
    my ($self) = @_;
    print $self->{name} . " says: " . $self->{sound} . "\n";
}

1;  # Return true to indicate successful package loading
```

Here:
- `new` is a constructor that initializes the object’s attributes (`name` and `sound`).
- `bless` associates the hash reference `$self` with the `Animal` class, making it an object of `Animal`.
- `make_sound` is a method that prints the `name` and `sound`.

---

### 2. **Creating an Object and Calling Methods**

To use the `Animal` class, save it as `Animal.pm` and then create a script to instantiate and interact with objects.

#### Example: Using the `Animal` Class

```perl
use strict;
use warnings;
use Animal;

# Create an Animal object
my $dog = Animal->new(name => "Dog", sound => "Woof");

# Call the make_sound method
$dog->make_sound();  # Output: Dog says: Woof
```

---

### 3. **Inheritance**

Perl supports single inheritance, where a class can inherit methods and properties from a parent class using the `@ISA` array. Let’s create a `Dog` class that inherits from `Animal`.

#### Example: Inheriting from the `Animal` Class

```perl
package Dog;
use parent 'Animal';

# Override constructor
sub new {
    my ($class, %args) = @_;
    $args{sound} ||= "Woof";  # Default sound for Dog
    return $class->SUPER::new(%args);
}

1;
```

#### Usage of `Dog` Class

```perl
use strict;
use warnings;
use Dog;

# Create a Dog object
my $dog = Dog->new(name => "Buddy");

# Call inherited method
$dog->make_sound();  # Output: Buddy says: Woof
```

Here, `Dog` inherits `make_sound` from `Animal` and overrides the `new` constructor to set a default sound.

---

### 4. **Encapsulation (Accessors and Mutators)**

Encapsulation allows controlled access to object attributes. Perl does not have built-in access control, so you implement encapsulation by defining getter and setter methods.

#### Example: Adding Accessors and Mutators

```perl
package Animal;

sub new {
    my ($class, %args) = @_;
    my $self = {
        name  => $args{name} || "Unnamed",
        sound => $args{sound} || "No sound",
    };
    bless $self, $class;
    return $self;
}

# Getter for name
sub get_name {
    my ($self) = @_;
    return $self->{name};
}

# Setter for name
sub set_name {
    my ($self, $name) = @_;
    $self->{name} = $name;
}

# Getter for sound
sub get_sound {
    my ($self) = @_;
    return $self->{sound};
}

# Setter for sound
sub set_sound {
    my ($self, $sound) = @_;
    $self->{sound} = $sound;
}

sub make_sound {
    my ($self) = @_;
    print $self->get_name() . " says: " . $self->get_sound() . "\n";
}

1;
```

#### Usage of Encapsulation Methods

```perl
use strict;
use warnings;
use Animal;

# Create an Animal object
my $cat = Animal->new(name => "Cat", sound => "Meow");

# Access and modify attributes using methods
print $cat->get_name() . " says: " . $cat->get_sound() . "\n";  # Cat says: Meow
$cat->set_name("Kitty");
$cat->make_sound();  # Output: Kitty says: Meow
```

---

### 5. **Polymorphism**

Perl supports polymorphism through method overriding in derived classes. Polymorphic behavior is achieved by calling methods on objects that have been overridden in subclass implementations.

#### Example: Overriding `make_sound` in the `Dog` Class

```perl
package Dog;
use parent 'Animal';

sub new {
    my ($class, %args) = @_;
    $args{sound} ||= "Woof";
    return $class->SUPER::new(%args);
}

# Override make_sound method
sub make_sound {
    my ($self) = @_;
    print $self->get_name() . " barks: " . $self->get_sound() . "\n";
}

1;
```

---

### 6. **Destructor in Perl**

A destructor in Perl is a method named `DESTROY`. It is automatically called when an object goes out of scope or is explicitly undefined.

#### Example: Adding a Destructor

```perl
package Animal;

sub new {
    my ($class, %args) = @_;
    my $self = {
        name  => $args{name} || "Unnamed",
        sound => $args{sound} || "No sound",
    };
    bless $self, $class;
    return $self;
}

sub DESTROY {
    my ($self) = @_;
    print $self->{name} . " is being destroyed\n";
}

1;
```

When an `Animal` object is no longer needed, the `DESTROY` method is called, allowing for resource cleanup.

---

### Summary of Key OOP Features in Perl

| **Feature**        | **Description**                                                           |
|--------------------|---------------------------------------------------------------------------|
| **Class**          | Defined using a `package` that holds attributes and methods               |
| **Object**         | An instance of a class, created with a constructor like `new`             |
| **Inheritance**    | Supported through `@ISA` or `use parent`                                  |
| **Encapsulation**  | Achieved through accessor and mutator methods                             |
| **Polymorphism**   | Enabled through method overriding in derived classes                      |
| **Destructor**     | `DESTROY` method for cleanup when an object is destroyed                  |

Perl's object-oriented features allow you to encapsulate and organize code effectively, combining procedural and OO paradigms to fit a wide range of application needs.
