An **Employee Management System (EMS)** is a software application designed to manage and streamline various functions related to employees in an organization, such as storing employee details, payroll processing, attendance tracking, and performance management. Below is an example of how to implement a simple Employee Management System in **Java** and **Python**, focusing on object-oriented principles.

---

### **Employee Management System in Java**

In Java, we'll use **classes**, **inheritance**, **encapsulation**, and **polymorphism** to design the system.

#### **Employee Class**:
The `Employee` class will contain basic information like name, ID, and salary.

```java
class Employee {
    private int id;
    private String name;
    private double salary;

    // Constructor
    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    // Getter and Setter methods
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    // Method to display employee details
    public void displayEmployeeDetails() {
        System.out.println("ID: " + id + ", Name: " + name + ", Salary: " + salary);
    }
}
```

#### **Manager Class (Inheritance)**:
The `Manager` class extends the `Employee` class, adding extra functionality for managerial tasks, like managing a team.

```java
class Manager extends Employee {
    private String department;

    public Manager(int id, String name, double salary, String department) {
        super(id, name, salary);
        this.department = department;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    @Override
    public void displayEmployeeDetails() {
        super.displayEmployeeDetails();
        System.out.println("Department: " + department);
    }
}
```

#### **Employee Management System (Main Class)**:
This class handles the creation of employee objects and displays their details.

```java
import java.util.ArrayList;

public class EmployeeManagementSystem {
    public static void main(String[] args) {
        ArrayList<Employee> employees = new ArrayList<>();

        // Creating employee objects
        Employee emp1 = new Employee(101, "Alice", 50000);
        Manager mgr1 = new Manager(102, "Bob", 75000, "HR");

        // Adding employees to the list
        employees.add(emp1);
        employees.add(mgr1);

        // Displaying employee details
        for (Employee employee : employees) {
            employee.displayEmployeeDetails();
            System.out.println();
        }
    }
}
```

### **Employee Management System in Python**

In Python, the code can be made more compact due to Python’s dynamic typing and flexible syntax. Here’s a basic example of the system using Python’s object-oriented features.

#### **Employee Class**:
The `Employee` class will store basic details like employee ID, name, and salary.

```python
class Employee:
    def __init__(self, employee_id, name, salary):
        self.employee_id = employee_id
        self.name = name
        self.salary = salary

    def display_employee_details(self):
        print(f"ID: {self.employee_id}, Name: {self.name}, Salary: {self.salary}")
```

#### **Manager Class (Inheritance)**:
The `Manager` class will inherit from the `Employee` class, adding additional properties like the department.

```python
class Manager(Employee):
    def __init__(self, employee_id, name, salary, department):
        super().__init__(employee_id, name, salary)
        self.department = department

    def display_employee_details(self):
        super().display_employee_details()
        print(f"Department: {self.department}")
```

#### **Employee Management System (Main Function)**:
This part of the program will create employee and manager objects and display their details.

```python
def main():
    # Creating employee objects
    emp1 = Employee(101, "Alice", 50000)
    mgr1 = Manager(102, "Bob", 75000, "HR")

    # Storing employees in a list
    employees = [emp1, mgr1]

    # Displaying employee details
    for employee in employees:
        employee.display_employee_details()
        print()

if __name__ == "__main__":
    main()
```

---

### **Key Features of the System**:
1. **Employee Class**: Contains basic information like ID, name, and salary.
2. **Manager Class**: Inherits from the `Employee` class and adds additional information such as department.
3. **Polymorphism**: Both `Employee` and `Manager` objects use the `display_employee_details` method, but `Manager` overrides this method to add more details.
4. **Data Management**: Employees and managers are stored in a list/array and their details are displayed in the main function.

---

### **Expanding the System:**

This basic system can be expanded with the following features:

1. **Payroll System**: Calculate and update employee salaries.
2. **Attendance Tracking**: Track attendance or work hours for employees.
3. **Performance Management**: Record employee performance evaluations.
4. **Search Functionality**: Search employees by name, ID, or department.
5. **Database Integration**: Integrate with a database (e.g., MySQL, SQLite) to store employee records persistently.

This system can be expanded further based on your specific requirements.
