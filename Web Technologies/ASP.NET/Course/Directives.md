### ASP.NET - Directives

In ASP.NET, **directives** are special instructions that provide the configuration or behavior of an ASP.NET page. They are used to specify settings or control the page, the way it behaves, or the way it interacts with other parts of the application. Directives are placed at the top of an ASPX page within the `<%@ %>` syntax.

Directives are typically used to:
- Specify the language used in the page.
- Set the page's behavior.
- Define or import namespaces and assemblies.

Here are the most commonly used directives in ASP.NET:

---

### 1. **Page Directive**

The `Page` directive is the most commonly used directive in ASP.NET. It defines the settings for a particular web page, such as language, theme, code-behind file, and more.

#### Syntax:
```html
<%@ Page Language="C#" CodeBehind="Default.aspx.cs" Inherits="WebApplication1._Default" %>
```

#### Common Attributes:
- **Language**: Specifies the programming language used for the page. Common values are `C#`, `VB`, etc.
- **CodeBehind**: Refers to the code-behind file (for example, `Default.aspx.cs`) that contains the page logic.
- **Inherits**: Specifies the class that the page inherits from (usually, the page class is in the code-behind file).
- **AutoEventWireup**: Automatically binds events defined in the page to their handlers in the code-behind.
- **EnableEventValidation**: Enables or disables event validation for the page.
- **MasterPageFile**: Specifies the location of the master page to be used by the page.
- **Theme**: Defines a theme for the page, which allows the page to inherit styles defined in a theme.
- **ValidateRequest**: Specifies whether ASP.NET should validate all requests.

#### Example:
```html
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Index.aspx.cs" Inherits="MyWebApp.Index" %>
```

---

### 2. **Control Directive**

The `Control` directive is used when creating custom user controls. This directive defines settings for user controls, including the inheritance of code-behind and the language used.

#### Syntax:
```html
<%@ Control Language="C#" CodeBehind="CustomControl.ascx.cs" Inherits="WebApplication1.CustomControl" %>
```

#### Common Attributes:
- **Language**: Specifies the language of the user control (usually `C#` or `VB`).
- **CodeBehind**: Refers to the code-behind file for the user control.
- **Inherits**: Specifies the class name for the user control.

---

### 3. **Import Directive**

The `Import` directive allows you to bring namespaces into the page or user control so that you can use types and classes without needing to fully qualify them.

#### Syntax:
```html
<%@ Import Namespace="System.Data" %>
```

#### Common Attribute:
- **Namespace**: Specifies the namespace to be imported into the page.

You can import multiple namespaces in one `Import` directive:

```html
<%@ Import Namespace="System.Data" Namespace="System.IO" %>
```

This directive allows you to use classes from the imported namespaces directly, without needing to include the full namespace path.

---

### 4. **Assembly Directive**

The `Assembly` directive is used to reference assemblies that are needed by the page or control. It allows you to use classes and types from external assemblies.

#### Syntax:
```html
<%@ Assembly Name="System.Data" %>
```

#### Common Attribute:
- **Name**: Specifies the assembly to reference (either from the GAC or a custom assembly).

You can also specify the **`GlobalAssemblyCache`** or a **`CodeBehind`** assembly in this directive.

---

### 5. **MasterPage Directive**

The `MasterPage` directive is used to define a master page that applies to all pages in the application. It is used to define settings for the master page, such as the content controls and layout.

#### Syntax:
```html
<%@ Master Language="C#" CodeBehind="MasterPage.master.cs" Inherits="WebApplication1.MasterPage" %>
```

#### Common Attributes:
- **Language**: Specifies the programming language used for the master page.
- **CodeBehind**: Refers to the code-behind file for the master page.
- **Inherits**: Specifies the class that the master page inherits from.
- **MasterPageFile**: Specifies the master page file.

---

### 6. **OutputCache Directive**

The `OutputCache` directive is used to specify caching settings for the page, which improves performance by reducing the need to generate the same page repeatedly.

#### Syntax:
```html
<%@ OutputCache Duration="60" VaryByParam="None" %>
```

#### Common Attributes:
- **Duration**: Specifies the number of seconds for which the output should be cached.
- **VaryByParam**: Defines how the output should vary based on query string or form parameters.
- **VaryByCustom**: Allows for more customized cache variations.
- **Location**: Specifies where to store the cached content (e.g., `Server`, `Client`).

---

### 7. **Trace Directive**

The `Trace` directive is used to enable tracing for a page, which helps with debugging by providing detailed information about the request lifecycle and page execution.

#### Syntax:
```html
<%@ Trace Enabled="true" %>
```

#### Common Attributes:
- **Enabled**: Turns tracing on or off for the page. Set to `true` to enable trace output.
- **RequestLimit**: Limits the number of requests for which trace output is saved.
- **TraceMode**: Specifies whether to trace requests (`SortByTime`) or responses (`SortByCategory`).

---

### 8. **Web.config Directive**

Though not a page directive, the `web.config` file also includes configuration settings that affect all ASP.NET pages and controls in an application.

The `web.config` file is an XML file that can contain settings for things like authentication, authorization, page behavior, HTTP handlers, and more.

#### Example of a section in `web.config`:
```xml
<configuration>
  <system.web>
    <pages enableEventValidation="false" />
  </system.web>
</configuration>
```

---

### Conclusion

ASP.NET directives provide a way to configure and control the behavior of web pages, user controls, master pages, and other ASP.NET components. Directives are typically placed at the top of an ASPX page (or other ASP.NET page types like `.ascx`, `.master`) and are enclosed within the `<%@ %>` tags.

Key directives include:
- **Page**: Defines settings for a web page.
- **Control**: Used for user controls.
- **Import**: Imports namespaces.
- **Assembly**: References external assemblies.
- **MasterPage**: Configures master pages.
- **OutputCache**: Caches page output for performance.
- **Trace**: Enables tracing for debugging.
