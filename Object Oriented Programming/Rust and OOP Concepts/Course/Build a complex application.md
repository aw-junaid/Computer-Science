Let’s walk through building a **Role-Based User Management System** in Rust, focusing on applying **traits**, **encapsulation**, and **ownership principles**. The system will handle user accounts with different roles (e.g., Admin, Moderator, User) and provide functionalities like creating users, assigning roles, and managing permissions.

We’ll structure the application in a way that demonstrates the following concepts:

- **Encapsulation**: Using structs to represent users, roles, and permissions while keeping data and functionality together.
- **Ownership**: Using Rust’s ownership system to manage memory safely, preventing issues like data races or memory leaks.
- **Traits**: Defining behaviors using traits, and implementing them for different user roles.

---

### **Step 1: Define the Core Structs**

We’ll define three main structs: `User`, `Role`, and `Permission`.

```rust
// Represents the user in the system.
struct User {
    username: String,
    role: Role,
    permissions: Vec<Permission>,
}

impl User {
    fn new(username: String, role: Role) -> Self {
        Self {
            username,
            role,
            permissions: Vec::new(),
        }
    }

    // Assign permission to a user
    fn add_permission(&mut self, permission: Permission) {
        self.permissions.push(permission);
    }

    // List all permissions
    fn list_permissions(&self) {
        println!("Permissions for {}:", self.username);
        for perm in &self.permissions {
            println!("{:?}", perm);
        }
    }
}

// Represents roles in the system (e.g., Admin, User, Moderator)
enum Role {
    Admin,
    Moderator,
    User,
}

impl Role {
    fn get_role_name(&self) -> &str {
        match self {
            Role::Admin => "Admin",
            Role::Moderator => "Moderator",
            Role::User => "User",
        }
    }
}

// Represents various permissions a user can have
#[derive(Debug)]
enum Permission {
    Read,
    Write,
    Execute,
}

impl Permission {
    fn get_permission_name(&self) -> &str {
        match self {
            Permission::Read => "Read",
            Permission::Write => "Write",
            Permission::Execute => "Execute",
        }
    }
}
```

### **Step 2: Define Traits for Role-Based Behaviors**

We’ll define a `RolePermissions` trait that provides role-specific behavior for permissions. Each role has specific permissions that it can grant.

```rust
// Trait to provide role-specific permissions
trait RolePermissions {
    fn assign_permissions(&self, user: &mut User);
}

impl RolePermissions for Role {
    fn assign_permissions(&self, user: &mut User) {
        match self {
            Role::Admin => {
                user.add_permission(Permission::Read);
                user.add_permission(Permission::Write);
                user.add_permission(Permission::Execute);
            }
            Role::Moderator => {
                user.add_permission(Permission::Read);
                user.add_permission(Permission::Write);
            }
            Role::User => {
                user.add_permission(Permission::Read);
            }
        }
    }
}
```

### **Step 3: Define Ownership Management**

Rust’s ownership model ensures that there is only one owner of data at a time. Here’s how we can manage ownership:

- The `User` struct owns the `username` and `permissions`.
- When assigning roles and permissions, we transfer ownership when needed (e.g., via mutable references).

### **Step 4: Main Application Logic**

Now let’s define the main part of the application where we create users, assign roles, and display permissions.

```rust
fn main() {
    // Create a new user with the "User" role
    let mut user1 = User::new("john_doe".to_string(), Role::User);
    
    // Assign permissions based on role
    user1.role.assign_permissions(&mut user1);
    
    // List user permissions
    user1.list_permissions();
    
    println!("\n");

    // Create an admin user and assign permissions
    let mut admin = User::new("admin_user".to_string(), Role::Admin);
    admin.role.assign_permissions(&mut admin);

    // List admin permissions
    admin.list_permissions();

    println!("\n");

    // Create a moderator user and assign permissions
    let mut mod_user = User::new("mod_user".to_string(), Role::Moderator);
    mod_user.role.assign_permissions(&mut mod_user);

    // List moderator permissions
    mod_user.list_permissions();
}
```

### **Step 5: Explanation of Concepts Applied**

#### **Encapsulation:**
- The `User` struct encapsulates the username, role, and permissions. The role and permissions are associated with the user, and related behaviors (e.g., `add_permission`) are implemented as methods on the `User` struct.
- We use enums like `Role` and `Permission` to encapsulate different types of roles and permissions. The `Role` enum ensures that roles are limited to specific options (Admin, Moderator, User), while the `Permission` enum ensures that permissions are predefined.

#### **Ownership:**
- The `username` field in `User` is a `String`, which is owned by the `User` instance. This means that the memory for the `username` is automatically freed when the `User` goes out of scope.
- The `permissions` field is a `Vec<Permission>`, which is also owned by the `User`. When permissions are added, they are pushed into the `Vec`, and Rust manages the memory for these items.
- The `Role` is an enum that directly belongs to the `User`, and we move it when assigning or modifying roles.

#### **Traits:**
- The `RolePermissions` trait is implemented for `Role`, which defines how each role assigns its permissions. This allows for a flexible and extensible design, where additional roles can be added later by simply implementing the trait for the new role.
- Traits provide a **polymorphic behavior** where the same `assign_permissions` method works differently based on the user's role.

---

### **Step 6: Output Example**

When you run the application, you will see an output like this:

```bash
Permissions for john_doe:
Read

Permissions for admin_user:
Read
Write
Execute

Permissions for mod_user:
Read
Write
```

- **John Doe** has only the `Read` permission because he is a **User**.
- The **Admin user** has `Read`, `Write`, and `Execute` permissions because the **Admin** role grants all permissions.
- The **Moderator** user has `Read` and `Write` permissions, as the **Moderator** role is more limited.

---

### **Conclusion**

This application demonstrates how to:
1. Use **encapsulation** by grouping data and behaviors in structs.
2. Manage **ownership** through Rust’s memory safety guarantees, ensuring that data is owned by only one entity at a time.
3. Implement **traits** to define behaviors that can be shared across types, allowing the system to remain extensible and flexible.

This structure can be expanded further by adding more roles, complex permissions, or even integrating a persistence layer (e.g., a database) while maintaining these principles. Rust's ownership and memory safety model make it an excellent choice for building reliable and safe applications.
