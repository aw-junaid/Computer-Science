### ASP.NET - Custom Controls

Custom controls in ASP.NET allow developers to create their own reusable components that can be used to encapsulate specific functionality or user interface behavior. Custom controls are essential for developers who need to extend the functionality of existing controls or create entirely new types of controls that can be used in web applications.

ASP.NET provides two types of custom controls:
1. **User Controls**
2. **Custom Server Controls**

### 1. **User Controls**
User controls are reusable components that you can create by combining existing Web Forms controls (like `Button`, `Label`, `TextBox`, etc.) into a single control. They are typically saved as `.ascx` files and are added to ASP.NET pages like any other control.

- **User controls** are created by combining multiple controls into a single file (e.g., `.ascx`).
- **User controls** are ideal for creating a reusable component, such as a custom header, footer, or navigation bar.

#### Example of User Control (`.ascx` file)
Here’s an example of a simple user control that contains a label and a button:

**MyUserControl.ascx**
```html
<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="MyUserControl.ascx.cs" Inherits="MyWebApp.MyUserControl" %>
<asp:Label ID="lblMessage" runat="server" Text="Welcome to my custom control!"></asp:Label>
<asp:Button ID="btnClick" runat="server" Text="Click Me" OnClick="btnClick_Click" />
```

**Code-behind for User Control (MyUserControl.ascx.cs)**
```csharp
using System;

namespace MyWebApp
{
    public partial class MyUserControl : System.Web.UI.UserControl
    {
        protected void btnClick_Click(object sender, EventArgs e)
        {
            lblMessage.Text = "Button clicked!";
        }
    }
}
```

To use this user control in an ASP.NET page:

**Example Page (Default.aspx)**
```html
<%@ Register Src="MyUserControl.ascx" TagPrefix="uc" TagName="MyControl" %>

<html>
<body>
    <form runat="server">
        <uc:MyControl ID="MyUserControl1" runat="server" />
    </form>
</body>
</html>
```

- **User Controls** are easier to create and use, and they allow for quick encapsulation of complex UI elements.
- However, user controls are typically **limited** in functionality compared to custom server controls and have some restrictions (e.g., they cannot be used in a control hierarchy like custom server controls).

### 2. **Custom Server Controls**
Custom server controls are more powerful and flexible than user controls. They can be used to extend the functionality of ASP.NET Web Forms by creating custom behavior or rendering logic that can be used in the same way as built-in controls.

Custom controls are defined by deriving a class from `System.Web.UI.Control` or `System.Web.UI.WebControls.WebControl`. They allow you to fully control how the control is rendered on the page and how it interacts with events.

#### Steps to Create a Custom Server Control

1. **Create a new class** that derives from `System.Web.UI.Control` or `System.Web.UI.WebControls.WebControl`.
2. **Override the `Render` method** to generate the HTML markup for the control.
3. **Optionally, define properties, events, and methods** to make the control more interactive and customizable.

#### Example of a Custom Control (Simple TextBox Control)
Here’s an example of a simple custom control that renders a text box and a button.

**CustomTextBox.cs (Custom Server Control)**
```csharp
using System;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MyWebApp
{
    public class CustomTextBox : WebControl
    {
        public string PlaceholderText { get; set; }
        
        protected override void Render(HtmlTextWriter writer)
        {
            writer.RenderBeginTag(HtmlTextWriterTag.Div); // Begin custom control container
            writer.AddAttribute(HtmlTextWriterAttribute.Type, "text");
            writer.AddAttribute(HtmlTextWriterAttribute.Name, "txtCustom");
            writer.AddAttribute(HtmlTextWriterAttribute.Placeholder, PlaceholderText);
            writer.RenderBeginTag(HtmlTextWriterTag.Input); // Render the input field
            writer.RenderEndTag(); // End input tag

            writer.RenderEndTag(); // End custom control container
        }
    }
}
```

- **PlaceholderText**: A custom property that sets the placeholder text for the input field.
- The `Render` method is responsible for generating the HTML markup for the custom control.

#### Using the Custom Control in an ASP.NET Page
After building the custom control, you need to register it in the `.aspx` page and use it just like any other ASP.NET control.

1. **Build the Custom Control** into a class library (`.dll` file).
2. **Register the custom control** in your ASP.NET page.

```html
<%@ Register Assembly="MyWebApp" Namespace="MyWebApp" TagPrefix="custom" TagName="CustomTextBox" %>

<html>
<body>
    <form runat="server">
        <custom:CustomTextBox ID="CustomTextBox1" runat="server" PlaceholderText="Enter your name here" />
    </form>
</body>
</html>
```

### Key Features of Custom Controls

1. **Custom Properties**
   Custom controls can expose properties that allow developers to customize the behavior of the control.

   **Example**: Defining a custom property in the control:
   ```csharp
   public string Text { get; set; }
   ```

2. **Event Handling**
   Custom controls can raise events like any other ASP.NET control, allowing interaction with the control's logic.

   **Example**: Raising an event in a custom control:
   ```csharp
   public event EventHandler ButtonClicked;

   protected void OnButtonClicked()
   {
       ButtonClicked?.Invoke(this, EventArgs.Empty);
   }
   ```

3. **State Management**
   Custom controls can use state management techniques like **view state** or **control state** to retain their values across postbacks.

   **Example**: Saving control state:
   ```csharp
   protected override void SaveControlState()
   {
       object[] state = new object[1];
       state[0] = this.Text;
       return state;
   }
   ```

4. **Rendering HTML**
   Custom controls can override the `Render` method to generate custom HTML for the control.

   **Example**: Rendering custom HTML in a custom control:
   ```csharp
   protected override void Render(HtmlTextWriter writer)
   {
       writer.RenderBeginTag(HtmlTextWriterTag.Div);
       writer.RenderBeginTag(HtmlTextWriterTag.H1);
       writer.Write("This is a custom control!");
       writer.RenderEndTag();
       writer.RenderEndTag();
   }
   ```

5. **Custom Styling**
   Like built-in ASP.NET controls, custom controls can be styled using CSS. You can set the control's `CssClass` property to apply a custom style.

### Differences Between User Controls and Custom Controls

| Feature                | **User Control**                                | **Custom Control**                          |
|------------------------|-------------------------------------------------|--------------------------------------------|
| **Definition**          | A reusable control defined in `.ascx` file.     | A control defined as a class derived from `Control` or `WebControl`. |
| **Complexity**          | Simple, quick to create.                       | More complex, requires more coding.       |
| **Control Type**        | Composed of existing ASP.NET controls.          | Can create entirely new control behavior.  |
| **Usage**               | Can be used in any ASP.NET page as a control.   | Registered in pages and used like a server control. |
| **Performance**         | Slightly less efficient due to multiple file parsing. | More efficient, as it's compiled into a DLL. |
| **Flexibility**         | Less flexible compared to custom controls.      | Highly flexible, allowing full control over behavior. |

### Conclusion

Custom controls in ASP.NET are essential for creating reusable and highly configurable components. While **user controls** provide a simple way to encapsulate UI elements, **custom server controls** offer greater flexibility and power, allowing developers to extend the functionality of ASP.NET and provide new, reusable components for web applications.

- **User Controls** are best suited for UI components that are made up of existing ASP.NET controls.
- **Custom Server Controls** are better for scenarios requiring full control over rendering, behavior, and state management.

Both custom controls and user controls can help simplify development and increase maintainability by providing reusable components.
