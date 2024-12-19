### ASP.NET - HTML Server Controls

**HTML Server Controls** in ASP.NET are standard HTML elements that can be turned into server-side controls by adding the `runat="server"` attribute. This allows you to interact with these controls programmatically on the server side, as opposed to regular HTML elements that are purely static and cannot be directly manipulated from the server-side code.

When you add `runat="server"` to an HTML element, it becomes a server control, which means you can access and modify its properties, handle events, and dynamically change its content from C# code in the code-behind file.

### Key Features of HTML Server Controls

- **Server-Side Access**: You can manipulate the controls on the server side using C# or VB.NET code.
- **No Need for JavaScript**: You don't need to use JavaScript to interact with the controls on the client-side; everything can be managed via server-side code.
- **Integration with ASP.NET Controls**: They work well with other ASP.NET controls, such as validation, data binding, and event handling.

### Syntax for HTML Server Controls

To make an HTML element a server control, you need to add the `runat="server"` attribute to the element.

#### Example:

```html
<input type="text" id="txtName" runat="server" />
<input type="button" id="btnSubmit" value="Submit" runat="server" />
```

In this example, the `<input>` and `<button>` elements are regular HTML elements, but by adding `runat="server"`, they become server-side controls that you can interact with programmatically in C#.

### HTML Server Controls in ASP.NET

Here are a few common examples of HTML elements that can be made into server controls:

1. **TextBox Control (HTML Server Control)**:
   - A text input field that can be accessed and manipulated on the server side.

   ```html
   <input type="text" id="txtName" runat="server" />
   ```

   **Code-Behind** (C#):
   ```csharp
   protected void btnSubmit_Click(object sender, EventArgs e)
   {
       string name = txtName.Value; // Access the value of the TextBox control
       Response.Write("Hello, " + name);
   }
   ```

2. **Button Control (HTML Server Control)**:
   - A button that can trigger server-side events when clicked.

   ```html
   <input type="button" id="btnSubmit" value="Submit" runat="server" onclick="btnSubmit_Click" />
   ```

   **Code-Behind** (C#):
   ```csharp
   protected void btnSubmit_Click(object sender, EventArgs e)
   {
       Response.Write("Button clicked");
   }
   ```

3. **CheckBox Control (HTML Server Control)**:
   - A checkbox that can be checked or unchecked by the user and can be accessed on the server side.

   ```html
   <input type="checkbox" id="chkAgree" runat="server" />
   ```

   **Code-Behind** (C#):
   ```csharp
   protected void btnSubmit_Click(object sender, EventArgs e)
   {
       if (chkAgree.Checked)
       {
           Response.Write("You agreed");
       }
       else
       {
           Response.Write("You did not agree");
       }
   }
   ```

4. **RadioButton Control (HTML Server Control)**:
   - A radio button that can be selected and processed on the server.

   ```html
   <input type="radio" id="rdMale" name="gender" value="Male" runat="server" />
   <input type="radio" id="rdFemale" name="gender" value="Female" runat="server" />
   ```

   **Code-Behind** (C#):
   ```csharp
   protected void btnSubmit_Click(object sender, EventArgs e)
   {
       string gender = rdMale.Checked ? "Male" : rdFemale.Checked ? "Female" : "Not Selected";
       Response.Write("Gender: " + gender);
   }
   ```

5. **Hidden Field Control (HTML Server Control)**:
   - A hidden input field used to store values that are not visible to the user but can be accessed server-side.

   ```html
   <input type="hidden" id="hiddenField" value="12345" runat="server" />
   ```

   **Code-Behind** (C#):
   ```csharp
   protected void btnSubmit_Click(object sender, EventArgs e)
   {
       string value = hiddenField.Value;
       Response.Write("Hidden value: " + value);
   }
   ```

### Accessing HTML Server Controls in C# Code-Behind

Once the HTML elements are given `runat="server"`, they can be accessed and manipulated from the code-behind file (`.aspx.cs`). Each server control is treated as an object that you can modify via its properties.

#### Example of Accessing and Manipulating Server Controls:

```html
<input type="text" id="txtName" runat="server" />
<input type="button" id="btnSubmit" value="Submit" runat="server" onclick="btnSubmit_Click" />
```

**Code-Behind** (C#):
```csharp
protected void btnSubmit_Click(object sender, EventArgs e)
{
    // Access the TextBox control to get the entered value
    string userName = txtName.Value;
    
    // Modify the TextBox value
    txtName.Value = "Hello, " + userName;

    // Write output to the response
    Response.Write("Submitted Name: " + userName);
}
```

### Benefits of HTML Server Controls

1. **Dynamic Content**: Since HTML server controls can be manipulated on the server side, you can dynamically change the content of these controls based on user input or business logic.
   
2. **Event Handling**: Server controls allow you to handle events (like `click`, `change`, etc.) on the server side, simplifying the process of writing JavaScript code for event handling.
   
3. **State Management**: These controls automatically maintain their state across postbacks. This is particularly useful for forms where the user may interact with several elements, and you need to preserve the values upon page reload.
   
4. **Cross-Browser Compatibility**: Since ASP.NET handles the rendering of these controls, you don’t have to worry much about cross-browser compatibility issues.

### Limitations of HTML Server Controls

1. **Server-Side Processing**: Since HTML server controls are processed on the server, every interaction with them requires a round-trip to the server (except for controls that are associated with AJAX functionality).
   
2. **Less Control Over Markup**: When using server controls, the exact HTML that is generated is abstracted, which may limit flexibility in controlling the final HTML output compared to writing raw HTML and JavaScript.

3. **Performance Overhead**: The server has to process these controls on every postback, which could introduce performance overhead in larger applications.

---

### Conclusion

**HTML Server Controls** in ASP.NET enable developers to work with standard HTML elements programmatically on the server-side. By adding `runat="server"`, you make an HTML element accessible from C# code, where you can interact with its properties, handle events, and dynamically change its content.

Some key points:
- HTML elements like text boxes, buttons, and checkboxes can be turned into server controls using the `runat="server"` attribute.
- Server controls are useful for dynamic web applications that need to maintain state, handle events on the server, or display dynamic data.
- While they offer a higher level of abstraction, they also come with limitations such as less control over the HTML output and potential performance overhead.
