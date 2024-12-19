### ASP.NET - Server Controls

**Server controls** in ASP.NET are special controls that run on the server side and generate HTML, CSS, and JavaScript dynamically to be sent to the browser. These controls are different from HTML controls in that they are processed on the server before being sent to the client, allowing developers to add functionality without writing a lot of client-side code.

Server controls are commonly used in **Web Forms** applications in ASP.NET. They offer a higher level of abstraction for handling user input, displaying data, and interacting with the server, making it easier to create web applications without needing to manually write HTML, JavaScript, or handle client-server communication directly.

### Types of ASP.NET Server Controls

1. **HTML Server Controls**
2. **Web Server Controls**
3. **Validation Controls**
4. **User Controls**
5. **Custom Controls**

Let’s dive deeper into each of these.

---

### 1. **HTML Server Controls**

These are standard HTML controls that can be turned into server-side controls. By adding the `runat="server"` attribute to regular HTML tags, they become part of the server-side processing model.

#### Example of an HTML Server Control:
```html
<input type="text" id="txtName" runat="server" />
<button type="button" id="btnSubmit" runat="server">Submit</button>
```

**Explanation**:
- The `runat="server"` attribute indicates that the element is a server-side control, allowing it to be manipulated in C# code (e.g., setting values or handling events).
- You can access and manipulate HTML server controls in your C# code behind like this:

```csharp
protected void btnSubmit_Click(object sender, EventArgs e)
{
    string name = txtName.Value;  // Access value of the HTML input control
}
```

---

### 2. **Web Server Controls**

Web server controls are the standard controls provided by ASP.NET that generate HTML output when processed on the server. These controls include TextBoxes, Labels, Buttons, DropDownLists, etc.

#### Common Web Server Controls:

- **TextBox**: Allows users to input text.
- **Button**: Triggers server-side events.
- **Label**: Displays text or information.
- **DropDownList**: Provides a list of options for the user to select.
- **CheckBox**: Represents a checkbox input.
- **RadioButton**: Represents a radio button input.

#### Example of Web Server Controls:
```html
<asp:TextBox ID="txtName" runat="server" />
<asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" />
<asp:Label ID="lblMessage" runat="server" />
```

**Explanation**:
- `runat="server"`: Turns the HTML element into a server control.
- `OnClick="btnSubmit_Click"`: Specifies the method to be called when the button is clicked on the server-side.

In the code-behind file (`.aspx.cs` or `.aspx.vb`), you can define the `btnSubmit_Click` method to handle the button click event:

```csharp
protected void btnSubmit_Click(object sender, EventArgs e)
{
    lblMessage.Text = "Hello, " + txtName.Text;
}
```

---

### 3. **Validation Controls**

ASP.NET provides several **validation controls** that help with client-side and server-side validation of user input. These controls validate data without needing to write complex JavaScript code. They include:

- **RequiredFieldValidator**: Ensures a field is not left empty.
- **RangeValidator**: Ensures the input is within a specified range.
- **RegularExpressionValidator**: Ensures the input matches a specified regular expression.
- **CompareValidator**: Compares two values (e.g., confirm password).
- **CustomValidator**: Allows for custom validation logic.

#### Example of Validation Controls:
```html
<asp:TextBox ID="txtAge" runat="server" />
<asp:RangeValidator 
    ID="ageValidator" 
    runat="server" 
    ControlToValidate="txtAge" 
    MinimumValue="18" 
    MaximumValue="100" 
    Type="Integer" 
    ErrorMessage="Age must be between 18 and 100." 
    ForeColor="Red" />
<asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" />
```

**Explanation**:
- The `RangeValidator` ensures the value entered in the `txtAge` control is between 18 and 100.
- If the validation fails, the error message is displayed, and the form cannot be submitted until the input is corrected.

---

### 4. **User Controls (UC)**

A **User Control** in ASP.NET is a reusable control that is created using a `.ascx` file. User controls encapsulate both UI and functionality, allowing them to be used across multiple pages.

#### Example of a User Control (`.ascx` file):
```html
<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="WelcomeControl.ascx.cs" Inherits="MyApp.WelcomeControl" %>
<h2>Welcome, <asp:Label ID="lblUser" runat="server" /></h2>
```

**Code-Behind (`WelcomeControl.ascx.cs`)**:
```csharp
public partial class WelcomeControl : System.Web.UI.UserControl
{
    public string UserName
    {
        get { return lblUser.Text; }
        set { lblUser.Text = value; }
    }
}
```

**Using User Control in a Page (`.aspx` file)**:
```html
<%@ Register Src="~/Controls/WelcomeControl.ascx" TagName="Welcome" TagPrefix="uc" %>
<uc:Welcome ID="WelcomeControl1" runat="server" UserName="John Doe" />
```

**Explanation**:
- The `UserControl` is registered using the `Register` directive.
- The `UserName` property is set programmatically to personalize the greeting displayed by the user control.

---

### 5. **Custom Controls**

A **Custom Control** is a control that you build from scratch, extending the functionality of existing controls or creating entirely new controls. Custom controls can be used for complex, reusable components across your application.

#### Example of a Custom Control:

1. **Create a Custom Control**:
   Create a new class that inherits from `System.Web.UI.Control` or a base class like `WebControl`.

```csharp
public class CustomLabel : System.Web.UI.WebControls.WebControl
{
    protected override void Render(HtmlTextWriter writer)
    {
        writer.Write("<div style='color: blue;'>");
        writer.Write(this.Text);
        writer.Write("</div>");
    }

    public string Text { get; set; }
}
```

2. **Using Custom Control**:

   Register and use the custom control in your ASPX page:
   
```html
<%@ Register TagPrefix="custom" TagName="Label" Src="~/CustomControls/CustomLabel.ascx" %>
<custom:Label runat="server" Text="This is a custom label!" />
```

---

### Server Control Event Handling

Server controls often provide events that you can handle on the server side. For example, a `Button` control raises a `Click` event when it is clicked, which you can handle in the code-behind.

#### Example of Event Handling for Button:

```html
<asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" />
```

**Code-Behind:**
```csharp
protected void btnSubmit_Click(object sender, EventArgs e)
{
    // Handle button click event
    lblMessage.Text = "Button clicked!";
}
```

---

### Conclusion

ASP.NET Server Controls provide a powerful way to build dynamic, data-driven web applications. Key points about server controls include:

- **HTML Server Controls**: Standard HTML elements that are enhanced to work server-side.
- **Web Server Controls**: Built-in controls (e.g., `Button`, `TextBox`, `DropDownList`) that help you generate dynamic HTML and handle events on the server.
- **Validation Controls**: Simplify client and server-side validation.
- **User Controls**: Reusable UI components that can be embedded in different pages.
- **Custom Controls**: Custom-built controls to extend ASP.NET's functionality.

By using these controls effectively, you can streamline web development and create responsive, dynamic, and maintainable applications.
