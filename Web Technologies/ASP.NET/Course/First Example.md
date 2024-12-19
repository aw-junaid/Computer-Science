### First Example of an ASP.NET Core Web Application

Let’s walk through the steps to create a basic **ASP.NET Core Web Application**.

### Prerequisites
Before starting, make sure you have the following installed:
- **.NET SDK** (download from [here](https://dotnet.microsoft.com/download/dotnet))
- **Visual Studio** or **Visual Studio Code**

### Step-by-Step Guide to Creating a Simple ASP.NET Core Web Application

#### 1. **Create a New Project**
   Open your terminal or command prompt, navigate to the folder where you want to create your project, and run the following command:

   ```bash
   dotnet new webapp -n FirstAspNetApp
   ```

   This will create a new ASP.NET Core Web Application project named `FirstAspNetApp` in a folder of the same name.

#### 2. **Navigate to the Project Folder**
   After the project is created, navigate to the project folder:

   ```bash
   cd FirstAspNetApp
   ```

#### 3. **Explore the Project Structure**
   The basic structure of an ASP.NET Core Web Application created with the `webapp` template will look like this:

   ```
   FirstAspNetApp/
   ├── Pages/
   │   ├── _ViewStart.cshtml
   │   ├── Index.cshtml
   │   ├── _Layout.cshtml
   ├── appsettings.json
   ├── Program.cs
   ├── Startup.cs
   ├── FirstAspNetApp.csproj
   ```

   **Key files**:
   - `Program.cs`: Contains the entry point for the application, where the web server is configured and run.
   - `Pages/`: Contains Razor Pages like `Index.cshtml` for rendering the UI.
   - `appsettings.json`: Configuration file where app settings such as connection strings and environment settings are stored.

#### 4. **Run the Application**
   Run the application with the following command:

   ```bash
   dotnet run
   ```

   This starts the web server and listens on `http://localhost:5000` by default.

   Open your web browser and go to `http://localhost:5000`, and you should see the default "Hello World" page rendered by ASP.NET Core.

#### 5. **Modify the Index Page**
   Let’s modify the default page (`Index.cshtml`) to display custom content.

   Open the `Pages/Index.cshtml` file, and change its content to:

   ```html
   @page
   @model FirstAspNetApp.Pages.IndexModel

   <h1>Welcome to My First ASP.NET Core Web Application!</h1>
   <p>This is a simple page created with Razor syntax in ASP.NET Core.</p>
   ```

   Save the file, then refresh your browser at `http://localhost:5000`. You should now see your updated message: "Welcome to My First ASP.NET Core Web Application!".

#### 6. **Understanding the Program.cs File**
   Open the `Program.cs` file, which contains the code to configure and start the ASP.NET Core application:

   ```csharp
   using Microsoft.AspNetCore.Hosting;
   using Microsoft.Extensions.Hosting;

   public class Program
   {
       public static void Main(string[] args)
       {
           CreateHostBuilder(args).Build().Run();
       }

       public static IHostBuilder CreateHostBuilder(string[] args) =>
           Host.CreateDefaultBuilder(args)
               .ConfigureWebHostDefaults(webBuilder =>
               {
                   webBuilder.UseStartup<Startup>();
               });
   }
   ```

   - `CreateHostBuilder`: Configures and starts the web host, using `Startup` for configuring services and middleware.
   - `Startup`: The `Startup` class (if present) is where services and the request pipeline are configured. 

#### 7. **Understanding the Startup.cs File**
   The `Startup.cs` class is where you configure services (e.g., MVC, authentication) and middleware (e.g., routing, static files).

   ```csharp
   public class Startup
   {
       public void ConfigureServices(IServiceCollection services)
       {
           services.AddRazorPages();
       }

       public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
       {
           if (env.IsDevelopment())
           {
               app.UseDeveloperExceptionPage();
           }
           else
           {
               app.UseExceptionHandler("/Home/Error");
               app.UseHsts();
           }

           app.UseHttpsRedirection();
           app.UseStaticFiles();

           app.UseRouting();

           app.UseEndpoints(endpoints =>
           {
               endpoints.MapRazorPages();
           });
       }
   }
   ```

   - `ConfigureServices`: Configures the services your application will use, such as Razor Pages here (`services.AddRazorPages()`).
   - `Configure`: Configures the middleware pipeline, such as error handling, HTTPS redirection, and routing (`app.UseRouting()`).

#### 8. **Explore Razor Pages**
   Razor Pages are used to render dynamic HTML content on the client side. In your `Pages/Index.cshtml` file, you can see that Razor syntax (`@`) is used to dynamically generate HTML content.

   For instance, you can add dynamic data to the page by modifying the `Index.cshtml.cs` page model class (found in the `Pages` folder), where you can add logic to pass data to the page.

   **Example**:
   In `Index.cshtml.cs`:

   ```csharp
   using Microsoft.AspNetCore.Mvc.RazorPages;

   namespace FirstAspNetApp.Pages
   {
       public class IndexModel : PageModel
       {
           public string Message { get; set; }

           public void OnGet()
           {
               Message = "Welcome to the ASP.NET Core web application!";
           }
       }
   }
   ```

   Now, modify the `Index.cshtml` to use this data:

   ```html
   @page
   @model FirstAspNetApp.Pages.IndexModel

   <h1>@Model.Message</h1>
   ```

   After running the app again, you should see the dynamic message displayed in your browser.

### Conclusion
You’ve just created your first ASP.NET Core web application, including a basic Razor Page. ASP.NET Core provides a highly modular and flexible environment for web development, and with Razor Pages, you can easily build dynamic websites.

The steps you followed covered:
- Creating a new ASP.NET Core project.
- Running the application on a local development server.
- Modifying a Razor Page to display dynamic data.
