### **Chef - Plain Ruby with Chef DSL**

In Chef, the **Chef Domain Specific Language (DSL)** is a set of custom Ruby methods and constructs designed specifically for defining infrastructure configurations. However, while the Chef DSL is built on top of Ruby, it is often possible and sometimes necessary to use plain Ruby code in conjunction with the Chef DSL to enhance the flexibility and power of your recipes.

By using plain Ruby with Chef DSL, you can perform a wide range of actions that go beyond the built-in Chef resources and functions. This includes complex logic, external library usage, or other Ruby-based programming tasks that are specific to your needs.

### **1. What is Chef DSL?**

Chef DSL is a Ruby-based language extension that allows you to manage system resources (such as files, packages, services, etc.) in a declarative manner. It simplifies common infrastructure tasks, such as package installation, file management, and service control, by using easy-to-understand resources like `package`, `file`, and `service`.

### **2. Plain Ruby vs Chef DSL**

- **Chef DSL**: Provides easy-to-use resources to manage system configurations, such as `package`, `file`, `service`, `execute`, etc.
- **Plain Ruby**: Gives you full control to perform more complex logic or access lower-level functions that are not encapsulated by Chef's resources.

While Chef DSL is declarative and designed for infrastructure automation, plain Ruby is more procedural and flexible. In Chef recipes, you can mix Ruby code with the Chef DSL, allowing for a highly customizable approach to system configuration.

---

### **3. How to Use Plain Ruby with Chef DSL**

In Chef, you can mix Ruby code into your recipes to perform advanced tasks. Here's how Ruby interacts with the Chef DSL and how you can use both together.

#### **1. Basic Example of Plain Ruby with Chef DSL**

A simple example would be to use plain Ruby code for calculating values that are later used in Chef resources.

**Example:**
```ruby
# Plain Ruby to calculate the memory size
total_memory = node['memory']['total'].to_i
half_memory = total_memory / 2

# Using Chef DSL to configure the system based on the calculated value
file '/etc/memory_limit.conf' do
  content "Memory limit: #{half_memory} MB"
  action :create
end
```

In this example:
- The plain Ruby code (`total_memory`, `half_memory`) calculates the amount of memory.
- The Chef DSL resource (`file`) is used to create a file with dynamic content based on the Ruby calculation.

#### **2. Using Ruby Loops with Chef DSL**

Ruby loops can be used to iterate over nodes, attributes, or other structures and apply resources conditionally.

**Example:**
```ruby
# Plain Ruby loop over an array of packages to install
%w[nginx mysql vim].each do |pkg|
  package pkg do
    action :install
  end
end
```

Here:
- Ruby's `each` loop iterates over an array of package names.
- The Chef DSL `package` resource installs each package dynamically.

#### **3. Using Ruby Conditions with Chef DSL**

You can write conditional logic in Ruby and apply it to Chef resources.

**Example:**
```ruby
# Plain Ruby condition to check if a package is installed
if node['platform'] == 'ubuntu'
  package 'nginx' do
    action :install
  end
else
  package 'httpd' do
    action :install
  end
end
```

This example uses Ruby's `if` statement to decide which package to install based on the node's platform attribute, while still using Chef DSL resources.

#### **4. Using Ruby to Call External APIs**

You can use Ruby's built-in libraries to interact with external APIs and store the results in node attributes or use them in resources.

**Example:**
```ruby
require 'net/http'
require 'json'

# Fetch the current weather for the node's location using an external API
uri = URI("https://api.weather.com/current?location=#{node['location']['city']}")
response = Net::HTTP.get(uri)
weather_data = JSON.parse(response)

# Use the weather data in a Chef resource
file '/etc/weather_report.conf' do
  content "Current weather: #{weather_data['temperature']}°C"
  action :create
end
```

In this example:
- Ruby's `Net::HTTP` and `JSON` libraries are used to fetch and parse weather data.
- The Chef DSL `file` resource is used to create a file with dynamic content based on the fetched data.

---

### **4. Combining Ruby Methods with Chef Resources**

Chef allows you to define Ruby methods to encapsulate complex logic and then use those methods in the recipe.

**Example:**
```ruby
# Define a plain Ruby method
def install_package(pkg)
  package pkg do
    action :install
  end
end

# Call the method to install packages
install_package('nginx')
install_package('vim')
```

This approach abstracts the logic for installing packages into a Ruby method and then reuses it with different packages.

---

### **5. Using Ruby Classes and Modules with Chef DSL**

You can define Ruby classes and modules to organize your Chef recipes and DRY (Don’t Repeat Yourself) out your code.

**Example:**
```ruby
# Define a Ruby class for a custom resource
class MyApp
  def self.install_package(pkg)
    package pkg do
      action :install
    end
  end
end

# Use the class method to install packages
MyApp.install_package('nginx')
MyApp.install_package('mysql')
```

In this example:
- A Ruby class `MyApp` is defined with a class method `install_package` to install packages.
- The Chef DSL is still used for the actual resource (`package`), but the logic is encapsulated in the Ruby class.

---

### **6. Example: Using Ruby for Custom Logic and Chef DSL for Infrastructure Management**

A more complex use case might involve Ruby code to dynamically generate values or configurations that are passed into Chef resources.

**Example:**
```ruby
# Ruby code to determine the best memory size for a service based on available memory
available_memory = node['memory']['total'].to_i
memory_limit = if available_memory < 4_000_000
                 '1G'
               else
                 '2G'
               end

# Chef DSL resource to configure a service using Ruby-derived values
service 'my_service' do
  action :start
  environment 'MEMORY_LIMIT' => memory_limit
end
```

In this example:
- Ruby code (`if` condition) determines the appropriate memory limit based on available system memory.
- The `service` resource uses the calculated memory limit to set an environment variable.

---

### **7. Best Practices for Using Plain Ruby with Chef DSL**

- **Use Ruby for Complex Logic**: Use Ruby when you need to perform complex logic, like mathematical calculations, external API calls, or advanced string manipulation.
- **Chef DSL for Infrastructure Management**: Use Chef DSL resources like `package`, `file`, and `service` for the declarative parts of your recipes. These resources are optimized for idempotency and ensure that the configuration is consistent across runs.
- **Keep Code DRY**: Use Ruby methods, classes, and modules to encapsulate reusable logic, reducing duplication in your recipes.
- **Testing**: When using Ruby logic, be sure to test it thoroughly, as errors in Ruby code may not be immediately apparent when running Chef recipes.

---

### **8. Conclusion**

Combining plain Ruby with Chef DSL allows you to extend the capabilities of Chef recipes and manage infrastructure in a more flexible and programmatically sophisticated way. By leveraging Ruby's power for complex logic and Chef's DSL for infrastructure management, you can create recipes that are both efficient and adaptable. This approach can significantly improve your ability to handle dynamic configurations and scenarios that require more than just declarative resource management.
