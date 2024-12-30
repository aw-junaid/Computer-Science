Here are practical examples in **C++** that demonstrate the use of the **Singleton**, **Factory**, and **Observer** design patterns in real-world applications.

---

### **1. Singleton Pattern in C++**

#### **Example: Logging System**

A logging system typically requires a single instance throughout the application to manage all logging operations. Using the Singleton pattern ensures that only one instance of the logger exists.

```cpp
#include <iostream>
#include <fstream>
#include <string>

class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;

    // Private constructor to prevent direct instantiation
    Logger() {
        logFile.open("log.txt", std::ios::out | std::ios::app);
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        logFile << message << std::endl;
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

// Initialize static member to nullptr
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger = Logger::getInstance();
    logger->log("This is a log message.");
    
    // Accessing the same instance later in the program
    Logger* anotherLogger = Logger::getInstance();
    anotherLogger->log("Another log message.");
    
    return 0;
}
```

#### **Explanation**:
- The **Logger** class follows the Singleton pattern, ensuring that only one logger instance exists throughout the application.
- The **getInstance()** method ensures that only one instance of the `Logger` class is created, no matter how many times it is called.

---

### **2. Factory Pattern in C++**

#### **Example: GUI Button Creation**

In a GUI application, different types of buttons may be required for different platforms (e.g., Windows, Linux). The Factory pattern allows creating different button types without specifying the exact class in the client code.

```cpp
#include <iostream>

class Button {
public:
    virtual void render() = 0;
};

class WindowsButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Windows Button" << std::endl;
    }
};

class LinuxButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Linux Button" << std::endl;
    }
};

class ButtonFactory {
public:
    virtual Button* createButton() = 0;
};

class WindowsButtonFactory : public ButtonFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
};

class LinuxButtonFactory : public ButtonFactory {
public:
    Button* createButton() override {
        return new LinuxButton();
    }
};

int main() {
    ButtonFactory* factory;
    std::string osType = "Windows";  // Assume platform is dynamically set

    if (osType == "Windows") {
        factory = new WindowsButtonFactory();
    } else {
        factory = new LinuxButtonFactory();
    }

    Button* button = factory->createButton();
    button->render();  // Outputs: Rendering Windows Button or Rendering Linux Button
    
    delete button;
    delete factory;

    return 0;
}
```

#### **Explanation**:
- **Button** is the abstract product.
- **WindowsButton** and **LinuxButton** are concrete products.
- **ButtonFactory** is the abstract factory, and **WindowsButtonFactory** and **LinuxButtonFactory** are concrete factories.
- The **client** code selects the appropriate factory based on the operating system type, and the factory creates the correct button.

---

### **3. Observer Pattern in C++**

#### **Example: Weather Station**

In a weather station, the temperature data changes frequently. The Observer pattern allows different components (like displays) to automatically update whenever the temperature changes.

```cpp
#include <iostream>
#include <vector>
#include <string>

// Abstract Observer
class Observer {
public:
    virtual void update(float temperature) = 0;
};

// Subject (Weather Station)
class WeatherStation {
private:
    std::vector<Observer*> observers;
    float temperature;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void setTemperature(float temp) {
        temperature = temp;
        notify();
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(temperature);
        }
    }
};

// Concrete Observer: Display system
class TemperatureDisplay : public Observer {
private:
    std::string displayName;

public:
    TemperatureDisplay(const std::string& name) : displayName(name) {}

    void update(float temperature) override {
        std::cout << displayName << " updated with temperature: " << temperature << "°C" << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;

    TemperatureDisplay display1("Display 1");
    TemperatureDisplay display2("Display 2");

    weatherStation.addObserver(&display1);
    weatherStation.addObserver(&display2);

    weatherStation.setTemperature(25.0f);  // Updates all displays with new temperature
    weatherStation.setTemperature(30.0f);  // Updates all displays again

    return 0;
}
```

#### **Explanation**:
- **Observer** is the base class for all observers (e.g., displays).
- **WeatherStation** is the subject that maintains the state (temperature) and notifies observers when the state changes.
- **TemperatureDisplay** is a concrete observer that updates its state when the weather station sends a notification.

---

### **Summary of Practical Examples:**

1. **Singleton Pattern**:
   - Ensures a class has only one instance (e.g., a logger or configuration manager).
   - Useful for scenarios where a global shared resource is needed (e.g., logging, database connections).

2. **Factory Pattern**:
   - Simplifies the object creation process by abstracting the instantiation details.
   - Ideal for cases where the exact type of object to be created may vary based on certain conditions (e.g., GUI elements, database connections).

3. **Observer Pattern**:
   - Allows automatic updates to dependent objects when the subject’s state changes.
   - Useful in event-driven systems where multiple components need to be updated (e.g., user interface elements, weather stations).

By applying these patterns, developers can design more flexible, maintainable, and scalable systems.
