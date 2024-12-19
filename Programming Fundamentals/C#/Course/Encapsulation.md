### C# - Encapsulation

**Encapsulation** is one of the fundamental principles of object-oriented programming (OOP). It is the process of bundling the data (variables) and the methods (functions) that operate on the data into a single unit known as a **class**. Encapsulation also involves restricting direct access to some of an object's components and only exposing certain parts of it through well-defined interfaces. This helps in **data hiding** and reduces the complexity of the system.

In C#, encapsulation is typically achieved using **access modifiers**, **properties**, and **methods**. 

### Key Concepts of Encapsulation

1. **Data Hiding**: Encapsulation allows you to control how data is accessed or modified by restricting direct access to fields (variables). You can expose data in a controlled manner using **properties** and **methods**.

2. **Access Modifiers**: C# provides access modifiers to control the visibility of class members (fields, properties, and methods) to other classes and code. The common access modifiers are:
   - **`public`**: Members are accessible from any other class.
   - **`private`**: Members are only accessible within the same class.
   - **`protected`**: Members are accessible within the same class and derived classes.
   - **`internal`**: Members are accessible within the same assembly (project).
   - **`protected internal`**: Members are accessible within the same assembly and derived classes.
   - **`private protected`**: Members are accessible within the same assembly and by derived classes within the same assembly.

3. **Properties**: In C#, properties are a special kind of method that provide a way to read, write, or compute the values of private fields while controlling the access. Properties allow you to enforce certain logic (e.g., validation) when accessing or modifying data.

4. **Methods**: Methods in a class are used to define behavior and operations on the data. Methods can be public or private, controlling whether they are accessible from outside the class.

### Example of Encapsulation in C#

Let's consider an example of a class that encapsulates a `BankAccount`:

#### Without Encapsulation:
Without encapsulation, we could directly access and modify the balance of the account, which is not safe as it can lead to invalid or inconsistent data.

```csharp
public class BankAccount
{
    public decimal balance;

    public BankAccount(decimal initialBalance)
    {
        balance = initialBalance;
    }
}

BankAccount account = new BankAccount(1000);
account.balance = -500;  // Invalid operation, but allowed
Console.WriteLine(account.balance);  // Output: -500
```

In this example, we can directly modify the `balance` field, which could allow invalid values (e.g., negative balances) to be set.

#### With Encapsulation:
Now, we encapsulate the `balance` field by making it `private` and provide a **property** to control how it is accessed and modified. We can include logic in the property to ensure that the balance cannot be set to a negative value.

```csharp
public class BankAccount
{
    private decimal balance;  // Private field

    public decimal Balance    // Property to get and set the balance
    {
        get { return balance; }
        set
        {
            if (value >= 0)  // Validation: balance cannot be negative
            {
                balance = value;
            }
            else
            {
                Console.WriteLine("Balance cannot be negative.");
            }
        }
    }

    public BankAccount(decimal initialBalance)
    {
        Balance = initialBalance;  // Use property to set balance
    }

    public void Deposit(decimal amount)
    {
        if (amount > 0)
        {
            Balance += amount;
        }
    }

    public void Withdraw(decimal amount)
    {
        if (amount > 0 && amount <= Balance)
        {
            Balance -= amount;
        }
        else
        {
            Console.WriteLine("Invalid withdrawal amount.");
        }
    }
}
```

#### Using the Encapsulated Class:
```csharp
BankAccount account = new BankAccount(1000);
Console.WriteLine("Initial Balance: " + account.Balance);  // Output: 1000

account.Deposit(200);
Console.WriteLine("After Deposit: " + account.Balance);  // Output: 1200

account.Withdraw(300);
Console.WriteLine("After Withdrawal: " + account.Balance);  // Output: 900

account.Balance = -500;  // Invalid operation, balance cannot be negative
Console.WriteLine("After Invalid Set: " + account.Balance);  // Output: Balance cannot be negative.
```

### Explanation of the Encapsulated Example:

1. **Private Field**: The `balance` field is declared as `private`, so it cannot be accessed directly from outside the class.
   
2. **Property**: The `Balance` property provides controlled access to the `balance` field. The `get` accessor allows reading the value, and the `set` accessor allows modifying it. The setter includes validation to ensure that the balance is never set to a negative value.

3. **Methods**: The `Deposit` and `Withdraw` methods allow us to interact with the balance in a controlled way, ensuring that only valid amounts are deposited or withdrawn.

4. **Validation**: The setter of the `Balance` property ensures that invalid operations (like setting a negative balance) are not allowed, making the class more robust and reducing the risk of errors.

### Benefits of Encapsulation:

1. **Data Protection**: By restricting direct access to fields and exposing them through properties or methods, you can protect the integrity of the data and enforce rules (such as validation) when accessing or modifying the data.

2. **Improved Maintainability**: The internal implementation of a class can be changed without affecting the code that uses the class, as long as the public interface (properties, methods) remains the same.

3. **Controlled Access**: You can control how data is accessed and modified. For example, you can provide only a getter method for a property to make it read-only, or provide logic to ensure that a field is updated in a controlled way.

4. **Abstraction**: Encapsulation hides the internal workings of a class, allowing users of the class to focus on the interface (methods and properties) without worrying about the underlying implementation.

### Summary of Encapsulation in C#:
- **Private fields** store data and are not directly accessible from outside the class.
- **Properties** provide controlled access to private fields, often with validation logic in setters.
- **Methods** define the behavior and operations on the data.
- **Access Modifiers** (`public`, `private`, etc.) control the visibility and accessibility of class members.
  
Encapsulation is a key concept in OOP that helps in creating robust, maintainable, and secure code by controlling how data is accessed and modified.
