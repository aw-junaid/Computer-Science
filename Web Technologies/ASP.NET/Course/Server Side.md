### ASP.NET - Server Side

In ASP.NET, **server-side** programming refers to the logic that is executed on the web server, rather than on the client’s browser. The server handles client requests, processes them (e.g., by interacting with databases or executing business logic), and returns a response (usually HTML, JSON, or other data formats) to the client. Server-side processing ensures that sensitive logic, data access, and security are maintained away from the client.

ASP.NET offers several ways to handle server-side logic, depending on the framework you are using (Web Forms, MVC, or Core). Below is an overview of server-side concepts in **ASP.NET Core**, including the lifecycle, page processing, and server-side techniques like handling requests, session management, and working with databases.

### 1. **ASP.NET Core Server-Side Architecture**

ASP.NET Core is a modern, cross-platform framework for building web applications. Server-side logic in ASP.NET Core typically revolves around:

- **Controllers and Actions**: Handle HTTP requests and return responses.
- **Middleware**: Intercepts requests and responses to perform tasks such as logging, authentication, authorization, and more.
- **Dependency Injection (DI)**: ASP.NET Core has built-in support for Dependency Injection, which helps to manage dependencies for services like database connections, logging, and other components.

#### **Key Components in ASP.NET Core Server-Side Processing**

- **Middleware**: The pipeline that processes HTTP requests and responses. Middleware can be used for various tasks like authentication, authorization, logging, error handling, etc.
- **Controllers**: Classes that handle HTTP requests, typically via actions (methods) that process requests and return results such as views, data, or redirects.
- **Views**: Rendered HTML that is returned to the client. Razor Views (`.cshtml`) are commonly used to dynamically generate HTML.
- **Services**: Business logic and data handling (e.g., connecting to databases or external APIs). Services can be injected into controllers or pages via Dependency Injection.

### 2. **Processing a Server-Side Request in ASP.NET Core**

In ASP.NET Core, the process of handling a request follows a clear sequence of steps. Here's a general flow of request processing:

1. **Request Reception**:
   - The client sends an HTTP request to the web server (e.g., a form submission or a page load request).
   
2. **Routing**:
   - The **Routing** middleware matches the URL to a controller action or Razor page handler.
   
3. **Middleware Execution**:
   - ASP.NET Core uses a middleware pipeline that can be customized for various purposes like authentication, authorization, logging, and more.
   
4. **Controller Action or Razor Page Execution**:
   - Once the request is routed to the appropriate controller or page, the associated action or handler is executed to process the request.
   
5. **Response**:
   - The result of the controller action or Razor Page handler (such as HTML, JSON, or a redirect) is returned as the HTTP response to the client.

#### Example of Request Flow in ASP.NET Core:

- The client accesses `http://localhost/Home/Index`.
- **Routing** maps the URL to the `Index` action in the `HomeController`.
- **Middleware** processes the request (e.g., checking for authentication).
- The `HomeController.Index` method executes and returns a view (`Index.cshtml`).
- The server sends the response back to the client.

### 3. **Server-Side Code in ASP.NET Core**

ASP.NET Core allows you to handle server-side logic through **Controllers**, **Razor Pages**, and **Services**.

#### **Controllers and Actions (MVC)**

In ASP.NET Core MVC, a **Controller** is responsible for handling HTTP requests and returning appropriate responses. Each action in a controller maps to a specific HTTP request.

**Example of a Controller**:

```csharp
using Microsoft.AspNetCore.Mvc;

namespace MyApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            // Server-side logic to process the request
            ViewData["Message"] = "Hello, ASP.NET Core!";
            return View(); // Returns the Index view with the message
        }
        
        [HttpPost]
        public IActionResult SubmitData(string name)
        {
            // Server-side logic to process submitted data
            ViewData["Message"] = $"Hello, {name}!";
            return View("Index");
        }
    }
}
```

In this example:
- The `Index` action handles a GET request to render a page.
- The `SubmitData` action handles a POST request to process form data and return a response.

#### **Razor Pages**

Razor Pages in ASP.NET Core is an alternative to MVC for server-side rendering. It simplifies the structure by using **page models** (akin to controllers in MVC) for handling HTTP requests.

**Example of Razor Page Handling Server-Side Request**:

1. **Razor Page** (`Pages/Index.cshtml`):

```html
@page
@model MyApp.Pages.IndexModel

<h2>@Model.Message</h2>

<form method="post">
    <input type="text" name="name" />
    <button type="submit">Submit</button>
</form>
```

2. **Page Model** (`Pages/Index.cshtml.cs`):

```csharp
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace MyApp.Pages
{
    public class IndexModel : PageModel
    {
        [BindProperty]
        public string Name { get; set; }
        
        public string Message { get; set; }

        public void OnGet()
        {
            Message = "Enter your name to greet.";
        }

        public void OnPost()
        {
            if (string.IsNullOrEmpty(Name))
            {
                Message = "Hello, Guest!";
            }
            else
            {
                Message = $"Hello, {Name}!";
            }
        }
    }
}
```

Here:
- The `OnGet` method handles GET requests (renders the page).
- The `OnPost` method handles POST requests (processes form data and updates the page).

### 4. **Session Management in ASP.NET Core**

ASP.NET Core provides the ability to store data on the server between requests using **sessions**. Session management is useful for storing user-specific data, such as authentication tokens, shopping cart contents, etc.

#### Enabling Session:

1. Add session services in the `Startup.cs` file:

```csharp
public void ConfigureServices(IServiceCollection services)
{
    services.AddDistributedMemoryCache();  // Adds a memory cache for session storage
    services.AddSession(options => {
        options.IdleTimeout = TimeSpan.FromMinutes(30); // Set session timeout
    });
}
```

2. Add session middleware in the `Configure` method:

```csharp
public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
{
    app.UseSession(); // Enable session management
}
```

3. Use session in a controller or Razor page:

```csharp
public IActionResult SetSession()
{
    HttpContext.Session.SetString("Username", "JohnDoe");  // Store data in session
    return View();
}

public IActionResult GetSession()
{
    var username = HttpContext.Session.GetString("Username");  // Retrieve session data
    return Content($"Hello, {username}");
}
```

### 5. **Server-Side Validation and Data Handling**

ASP.NET Core provides built-in mechanisms to handle server-side validation of user inputs, both on Razor Pages and in MVC controllers.

#### Example of Server-Side Validation in a Razor Page:

```csharp
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace MyApp.Pages
{
    public class FormModel : PageModel
    {
        [BindProperty]
        [Required(ErrorMessage = "Name is required")]
        public string Name { get; set; }

        public void OnPost()
        {
            if (ModelState.IsValid)
            {
                // Process data if valid
            }
            else
            {
                // Handle validation errors
            }
        }
    }
}
```

In this example, the `Name` property is validated to ensure it's not empty. If the validation fails, the page will display an error message.

### 6. **Working with Databases Server-Side**

In ASP.NET Core, you can interact with databases server-side using **Entity Framework Core (EF Core)**, which provides an ORM (Object-Relational Mapping) solution.

#### Example: Connecting to a Database with EF Core

1. **Define a Model** (`Models/User.cs`):

```csharp
public class User
{
    public int Id { get; set; }
    public string Name { get; set; }
}
```

2. **Create a DbContext** (`Data/ApplicationDbContext.cs`):

```csharp
using Microsoft.EntityFrameworkCore;

namespace MyApp.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options) { }

        public DbSet<User> Users { get; set; }
    }
}
```

3. **Configure EF Core in Startup** (`Startup.cs`):

```csharp
public void ConfigureServices(IServiceCollection services)
{
    services.AddDbContext<ApplicationDbContext>(options =>
        options.UseSqlServer(Configuration.GetConnectionString("DefaultConnection")));
}
```

4. **Query the Database in a Controller or Razor Page**:

```csharp
public class HomeController : Controller
{
    private readonly ApplicationDbContext _context;

    public HomeController(ApplicationDbContext context)
    {
        _context = context;
    }

    public IActionResult Index()
    {
        var users = _context.Users.ToList(); // Retrieve all users from the database
        return View(users);
    }
}
```

### Conclusion

Server-side programming in ASP.NET involves handling HTTP requests, processing data on the server, managing user sessions, and interacting with databases. ASP.NET Core provides various techniques for managing server-side logic:
- **Controllers and Actions** in MVC for structured request handling.
- **Razor Pages** for a simplified model with server-side event handling.
- **Middleware** to intercept and modify HTTP requests.
- **Session Management** for maintaining state between requests.
- **Entity Framework Core** for database operations.

These tools enable developers to build dynamic, scalable, and secure web applications.
