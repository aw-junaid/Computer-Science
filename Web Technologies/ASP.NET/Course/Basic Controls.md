### ASP.NET - Basic Controls

ASP.NET provides a wide variety of controls that allow developers to create rich, interactive web applications. **Basic controls** are the fundamental building blocks in ASP.NET Web Forms that allow for user interaction, data display, and control flow.

Below are some of the most commonly used basic controls in ASP.NET:

---

### 1. **Label Control**

The `Label` control is used to display text on the web page. It is often used to display messages or information to the user.

#### Syntax:
```html
<asp:Label ID="lblMessage" runat="server" Text="Hello, User!"></asp:Label>
```

You can dynamically change the text of the `Label` control using server-side code.

**Code-Behind (C#)**:
```csharp
lblMessage.Text = "Welcome to ASP.NET!";
```

---

### 2. **TextBox Control**

The `TextBox` control is used for user input. It allows users to enter text, and its value can be accessed on the server side.

#### Syntax:
```html
<asp:TextBox ID="txtName" runat="server"></asp:TextBox>
```

You can get or set the value of the `TextBox` control from the server side.

**Code-Behind (C#)**:
```csharp
string name = txtName.Text;
```

---

### 3. **Button Control**

The `Button` control is used to trigger actions on the web page, such as form submission or other events when clicked.

#### Syntax:
```html
<asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" />
```

**Code-Behind (C#)**:
```csharp
protected void btnSubmit_Click(object sender, EventArgs e)
{
    lblMessage.Text = "Button clicked!";
}
```

---

### 4. **HyperLink Control**

The `HyperLink` control is used to create hyperlinks. It can navigate to another web page or a different URL.

#### Syntax:
```html
<asp:HyperLink ID="hlGoogle" runat="server" NavigateUrl="http://www.google.com" Text="Go to Google"></asp:HyperLink>
```

You can dynamically change the `NavigateUrl` and `Text` properties.

**Code-Behind (C#)**:
```csharp
hlGoogle.NavigateUrl = "http://www.microsoft.com";
hlGoogle.Text = "Go to Microsoft";
```

---

### 5. **DropDownList Control**

The `DropDownList` control is used to create a drop-down list of items for the user to select from. It allows for dynamic item generation from the server side.

#### Syntax:
```html
<asp:DropDownList ID="ddlCountries" runat="server">
    <asp:ListItem Text="Select Country" Value="" />
    <asp:ListItem Text="USA" Value="US" />
    <asp:ListItem Text="Canada" Value="CA" />
</asp:DropDownList>
```

You can access the selected value using the `SelectedValue` property.

**Code-Behind (C#)**:
```csharp
string selectedCountry = ddlCountries.SelectedValue;
```

---

### 6. **RadioButton Control**

The `RadioButton` control allows users to select one option from a group of mutually exclusive options. It is typically used in forms where only one option can be selected.

#### Syntax:
```html
<asp:RadioButton ID="rdMale" runat="server" Text="Male" GroupName="Gender" />
<asp:RadioButton ID="rdFemale" runat="server" Text="Female" GroupName="Gender" />
```

You can check if a `RadioButton` is selected by accessing the `Checked` property.

**Code-Behind (C#)**:
```csharp
if (rdMale.Checked)
{
    // Male is selected
}
else if (rdFemale.Checked)
{
    // Female is selected
}
```

---

### 7. **CheckBox Control**

The `CheckBox` control allows the user to select or deselect an option. Multiple checkboxes can be selected at once, unlike `RadioButton`.

#### Syntax:
```html
<asp:CheckBox ID="chkAccept" runat="server" Text="Accept Terms and Conditions" />
```

You can check whether a checkbox is selected using the `Checked` property.

**Code-Behind (C#)**:
```csharp
bool isAccepted = chkAccept.Checked;
```

---

### 8. **Image Control**

The `Image` control is used to display an image on the page. It can be dynamically updated from the server side.

#### Syntax:
```html
<asp:Image ID="imgLogo" runat="server" ImageUrl="~/Images/logo.png" />
```

You can change the image at runtime by modifying the `ImageUrl` property.

**Code-Behind (C#)**:
```csharp
imgLogo.ImageUrl = "~/Images/newLogo.png";
```

---

### 9. **FileUpload Control**

The `FileUpload` control allows users to upload files from their computer to the server.

#### Syntax:
```html
<asp:FileUpload ID="fileUpload" runat="server" />
```

You can access the uploaded file and save it to the server.

**Code-Behind (C#)**:
```csharp
if (fileUpload.HasFile)
{
    string filePath = Server.MapPath("~/Uploads/") + fileUpload.FileName;
    fileUpload.SaveAs(filePath);
}
```

---

### 10. **ImageButton Control**

The `ImageButton` control works like the `Button` control but displays an image instead of text. It allows users to click on an image to trigger an event.

#### Syntax:
```html
<asp:ImageButton ID="imgBtn" runat="server" ImageUrl="~/Images/submit.png" OnClick="imgBtn_Click" />
```

**Code-Behind (C#)**:
```csharp
protected void imgBtn_Click(object sender, ImageClickEventArgs e)
{
    lblMessage.Text = "ImageButton clicked!";
}
```

---

### 11. **TextBox (Multi-line) Control**

The `TextBox` control can be configured to allow multiple lines of text, essentially functioning as a text area for larger input.

#### Syntax:
```html
<asp:TextBox ID="txtDescription" runat="server" TextMode="MultiLine" Rows="5" Columns="50"></asp:TextBox>
```

You can access the multi-line content using the `Text` property.

**Code-Behind (C#)**:
```csharp
string description = txtDescription.Text;
```

---

### 12. **Table Control**

The `Table` control is used to create tables in ASP.NET. It allows you to create rows, cells, and headers dynamically.

#### Syntax:
```html
<asp:Table ID="tblData" runat="server">
    <asp:TableRow>
        <asp:TableCell>Header 1</asp:TableCell>
        <asp:TableCell>Header 2</asp:TableCell>
    </asp:TableRow>
</asp:Table>
```

**Code-Behind (C#)**:
```csharp
TableRow row = new TableRow();
TableCell cell1 = new TableCell();
TableCell cell2 = new TableCell();
cell1.Text = "Row 1, Cell 1";
cell2.Text = "Row 1, Cell 2";
row.Cells.Add(cell1);
row.Cells.Add(cell2);
tblData.Rows.Add(row);
```

---

### 13. **Literal Control**

The `Literal` control is used to display text or HTML without any additional formatting or controls. It is commonly used when you need to display dynamic content without additional markup or functionality.

#### Syntax:
```html
<asp:Literal ID="litMessage" runat="server"></asp:Literal>
```

**Code-Behind (C#)**:
```csharp
litMessage.Text = "<b>Welcome to ASP.NET!</b>";
```

---

### Conclusion

ASP.NET provides a wide range of **basic controls** that serve as essential elements for web forms, allowing developers to easily handle user input, display information, create interactivity, and manage data. Some of the most important basic controls include:

- **Label**: For displaying static text.
- **TextBox**: For user input.
- **Button**: For triggering server-side events.
- **DropDownList**: For displaying a list of options.
- **RadioButton** and **CheckBox**: For selection inputs.
- **FileUpload**: For file uploads.
- **Image**: For displaying images.
- **ImageButton**: For clickable images.

These basic controls, along with the ability to manipulate their properties and handle events through server-side code, form the foundation of web applications built with ASP.NET.
