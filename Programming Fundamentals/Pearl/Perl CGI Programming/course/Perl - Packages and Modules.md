### Perl - Packages and Modules

In Perl, **packages** and **modules** are key concepts for organizing code and reusing functionality. A **package** is essentially a namespace for variables and subroutines, while a **module** is a reusable unit of code that can be included in other Perl programs.

#### 1. **Packages**

A package in Perl defines a namespace for variables and subroutines. Using packages helps avoid name collisions and organize code into logical units.

##### Creating a Package

To create a package, you use the `package` keyword. The default package is `main`, but you can create other packages for different parts of your program.

```perl
# Define a package named MyPackage
package MyPackage;

# Declare a variable
my $var = "Hello from MyPackage";

# Declare a subroutine
sub greet {
    print "Greetings from MyPackage\n";
}

# Return to the main package
package main;

# Call the subroutine from MyPackage
MyPackage::greet();  # Output: Greetings from MyPackage

# Access variable from MyPackage
print MyPackage::$var;  # Output: Hello from MyPackage
```

Here:
- **`package MyPackage;`** defines a new package.
- **`MyPackage::greet`** refers to the `greet` subroutine in the `MyPackage` namespace.

#### 2. **Modules**

A **module** is a file that contains Perl code and typically defines one or more packages. Modules are used to organize code for reuse and are often shared between programs.

##### Creating a Module

To create a Perl module, save the code in a file with a `.pm` extension (e.g., `MyModule.pm`), and place it in a directory where Perl can find it.

Here’s an example of a simple module:

```perl
# File: MyModule.pm
package MyModule;

# Declare a variable
my $message = "Hello from MyModule";

# Declare a subroutine
sub greet {
    return $message;
}

# Return true value at the end of the module
1;  # This is required to indicate the module was loaded successfully
```

- **`1;`** at the end of the module ensures it returns a true value, which is required for Perl modules to load correctly.

##### Using the Module in a Script

Once a module is created, it can be used in any Perl script with the `use` statement.

```perl
#!/usr/bin/perl
use strict;
use warnings;
use MyModule;  # Load MyModule

print MyModule::greet(), "\n";  # Output: Hello from MyModule
```

- **`use MyModule;`** loads the `MyModule.pm` file and imports its functionality.

#### 3. **Packages vs Modules**

- **Package**: A namespace for organizing variables and subroutines within a program. A package can be used anywhere in your code.
- **Module**: A collection of related code, typically in the form of one or more packages. A module is loaded into a Perl script using the `use` or `require` statement.

#### 4. **The `use` and `require` Statements**

- **`use`**: Automatically loads a module at compile time and optionally imports symbols (subroutines, variables) from the module.
- **`require`**: Loads a module at runtime, but does not import anything. It’s typically used when you need more control over when the module is loaded.

##### Example: `use` vs `require`

```perl
# Using 'use' (compile-time loading)
use MyModule;  # Automatically loads MyModule.pm and imports symbols

# Using 'require' (runtime loading)
require MyModule;  # Only loads MyModule at runtime
```

- **`use`** is typically used for modules that are required throughout the program.
- **`require`** is more flexible and allows you to load modules conditionally or at a later point in the program.

#### 5. **Exporting Symbols from a Module**

When you use a module, it is common to import functions or variables from that module. Perl provides the `Exporter` module, which allows you to export symbols (subroutines, variables) from your module to the calling script.

##### Example: Exporting Symbols

```perl
# File: MyModule.pm
package MyModule;
use Exporter 'import';  # Import Exporter's functionality

# Exported symbols
our @EXPORT = qw(greet);

# Declare a subroutine
sub greet {
    return "Hello from MyModule!";
}

1;
```

In the script that uses this module:

```perl
#!/usr/bin/perl
use strict;
use warnings;
use MyModule;  # Import greet from MyModule

print greet(), "\n";  # Output: Hello from MyModule!
```

- **`@EXPORT`** specifies which symbols (subroutines or variables) are to be exported automatically.
- **`use Exporter 'import';`** makes the `Exporter` module available for exporting symbols.

##### Exporting Specific Functions

You can also export specific functions or variables selectively:

```perl
# File: MyModule.pm
package MyModule;
use Exporter 'import';

our @EXPORT_OK = qw(greet farewell);  # Only export these upon request

sub greet {
    return "Hello!";
}

sub farewell {
    return "Goodbye!";
}

1;
```

In the script that uses this module:

```perl
#!/usr/bin/perl
use strict;
use warnings;
use MyModule qw(greet);  # Only import 'greet'

print greet(), "\n";  # Output: Hello!
```

- **`@EXPORT_OK`** is used to specify that functions can be selectively imported.
- **`use MyModule qw(greet);`** imports only the `greet` function.

#### 6. **Object-Oriented Programming with Packages**

Perl packages are also used for object-oriented programming (OOP). In OOP, a package defines a class, and you can create objects based on that class.

##### Example: Basic OOP in Perl

```perl
# File: MyClass.pm
package MyClass;

# Constructor
sub new {
    my $class = shift;
    my $self = { name => shift };
    bless $self, $class;
    return $self;
}

# Method
sub greet {
    my $self = shift;
    return "Hello, " . $self->{name};
}

1;
```

In the script using this class:

```perl
#!/usr/bin/perl
use strict;
use warnings;
use MyClass;

# Create an object of MyClass
my $object = MyClass->new("John");

# Call the method
print $object->greet(), "\n";  # Output: Hello, John
```

- **`new`**: The constructor method creates an object and blesses it into the class (`MyClass`).
- **`greet`**: An instance method that operates on the object (`$self`).

#### 7. **Module Installation**

To use external modules from CPAN (Comprehensive Perl Archive Network), you can install them using the `cpan` command.

```shell
cpan Some::Module  # Install a module from CPAN
```

Alternatively, you can use **`cpanm`** (CPAN Minus), which is a simpler and faster tool:

```shell
cpanm Some::Module
```

After installation, you can `use` the module in your scripts.

---

### Summary of Key Concepts

| **Concept**            | **Description**                                                                 |
|------------------------|---------------------------------------------------------------------------------|
| **Package**            | A namespace to group variables and subroutines.                                 |
| **Module**             | A file containing reusable code, usually consisting of one or more packages.   |
| **Exporter**           | A module to export subroutines and variables from a module to other scripts.   |
| **`use`**              | Loads a module at compile time and optionally imports functions.               |
| **`require`**          | Loads a module at runtime.                                                     |
| **Object-Oriented**    | Perl packages can also be used to implement object-oriented code.              |
| **CPAN**               | The Perl community's library for reusable modules, installable via `cpan`.      |

---

### Conclusion

Packages and modules in Perl provide an organized way to structure your code, enhance reusability, and avoid conflicts between variable and function names. By leveraging the power of packages, modules, and tools like `Exporter`, Perl helps you manage complex programs and libraries efficiently. Whether you're working with internal code or external CPAN modules, understanding packages and modules is crucial for writing modular, maintainable Perl code.
