### ASP.NET - File Uploading

File uploading is a common feature in web applications where users need to upload files, such as images, documents, or videos. ASP.NET provides several ways to handle file uploads in both **ASP.NET Web Forms** and **ASP.NET MVC** applications. Below is an overview of how file uploading works in ASP.NET.

### Key Concepts for File Uploading

1. **HTML Form for File Upload**: To upload a file from a client to the server, you'll need an HTML form with an `<input>` field of type `file`.

2. **Server-Side Handling**: On the server, the file data can be accessed using the `HttpPostedFile` class. ASP.NET provides built-in methods to handle uploaded files securely.

3. **File Storage**: Uploaded files are typically saved to a specific folder on the server or a database, depending on the application requirements.

4. **Validation**: It's important to validate the file's size, type, and extension before saving it to ensure it meets the application's requirements.

---

### Steps to Upload a File in ASP.NET

1. **Create the HTML Form for File Upload**: This form allows the user to select a file and submit it to the server.

#### Example: HTML Form for File Upload (ASP.NET Web Forms)
```html
<asp:Form runat="server">
    <form id="uploadForm" runat="server" enctype="multipart/form-data">
        <label for="fileUpload">Choose a file:</label>
        <input type="file" id="fileUpload" name="fileUpload" />
        <input type="submit" value="Upload" />
    </form>
</asp:Form>
```

The form uses the `enctype="multipart/form-data"` attribute, which is necessary for file uploads.

---

### 2. **Server-Side File Handling in ASP.NET Web Forms**

When the form is submitted, the file is sent to the server. On the server-side, you can handle the uploaded file using the `Request.Files` collection.

#### Example: File Uploading in ASP.NET Web Forms (C#)
```csharp
using System;
using System.Web;

public partial class FileUploadExample : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
    }

    protected void UploadFile(object sender, EventArgs e)
    {
        // Check if the file is posted
        if (Request.Files.Count > 0)
        {
            // Get the uploaded file
            HttpPostedFile uploadedFile = Request.Files["fileUpload"];

            // Check if the file is not null and has content
            if (uploadedFile != null && uploadedFile.ContentLength > 0)
            {
                // Get the file name
                string fileName = System.IO.Path.GetFileName(uploadedFile.FileName);

                // Define the path to save the uploaded file
                string savePath = Server.MapPath("~/UploadedFiles/") + fileName;

                // Save the file
                uploadedFile.SaveAs(savePath);

                Response.Write("File uploaded successfully.");
            }
            else
            {
                Response.Write("No file selected.");
            }
        }
    }
}
```

- `Request.Files["fileUpload"]`: Retrieves the uploaded file.
- `HttpPostedFile`: Represents the uploaded file and provides properties like `FileName`, `ContentType`, `ContentLength`, and `InputStream`.
- `SaveAs()`: Saves the uploaded file to a specified location on the server.

### 3. **Validating the Uploaded File**

Before saving the file, it's crucial to validate the file to ensure it's of the correct type and size. For example, you might only want to allow image files and limit the file size.

#### Example: Validating File Type and Size
```csharp
if (uploadedFile != null && uploadedFile.ContentLength > 0)
{
    string fileExtension = System.IO.Path.GetExtension(uploadedFile.FileName).ToLower();
    string[] allowedExtensions = { ".jpg", ".jpeg", ".png", ".gif" };
    int maxFileSize = 5 * 1024 * 1024; // 5 MB

    // Check file type
    if (Array.Exists(allowedExtensions, ext => ext == fileExtension))
    {
        // Check file size
        if (uploadedFile.ContentLength <= maxFileSize)
        {
            // Save the file
            uploadedFile.SaveAs(savePath);
            Response.Write("File uploaded successfully.");
        }
        else
        {
            Response.Write("File size exceeds the maximum limit of 5 MB.");
        }
    }
    else
    {
        Response.Write("Invalid file type. Only image files are allowed.");
    }
}
else
{
    Response.Write("No file selected.");
}
```

### 4. **Handling File Uploads in ASP.NET MVC**

In ASP.NET MVC, file uploads are handled through a controller action. The file is sent from the client-side form, and you can retrieve it using the `HttpPostedFileBase` class.

#### Example: HTML Form for File Upload in ASP.NET MVC
```html
@using (Html.BeginForm("Upload", "File", FormMethod.Post, new { enctype = "multipart/form-data" }))
{
    <input type="file" name="file" />
    <input type="submit" value="Upload" />
}
```

#### Example: File Upload Action in ASP.NET MVC Controller
```csharp
using System.Web;
using System.IO;
using System.Web.Mvc;

public class FileController : Controller
{
    // GET: File/Upload
    public ActionResult Upload()
    {
        return View();
    }

    // POST: File/Upload
    [HttpPost]
    public ActionResult Upload(HttpPostedFileBase file)
    {
        if (file != null && file.ContentLength > 0)
        {
            // Get the file name and extension
            string fileName = Path.GetFileName(file.FileName);
            string fileExtension = Path.GetExtension(file.FileName).ToLower();
            string[] allowedExtensions = { ".jpg", ".jpeg", ".png", ".gif" };

            // Validate the file type and size
            if (Array.Exists(allowedExtensions, ext => ext == fileExtension))
            {
                // Define the path to save the file
                string path = Path.Combine(Server.MapPath("~/UploadedFiles/"), fileName);

                // Save the file
                file.SaveAs(path);

                TempData["Message"] = "File uploaded successfully!";
            }
            else
            {
                TempData["Message"] = "Invalid file type. Only image files are allowed.";
            }
        }
        else
        {
            TempData["Message"] = "No file selected.";
        }

        return RedirectToAction("Upload");
    }
}
```

### 5. **Handling Multiple File Uploads**

You can handle multiple file uploads by using a `File[]` array or `IEnumerable<HttpPostedFileBase>` to capture all the uploaded files.

#### Example: Handling Multiple Files in MVC
```html
@using (Html.BeginForm("UploadMultiple", "File", FormMethod.Post, new { enctype = "multipart/form-data" }))
{
    <input type="file" name="files" multiple />
    <input type="submit" value="Upload" />
}
```

#### Controller Action to Handle Multiple Files
```csharp
[HttpPost]
public ActionResult UploadMultiple(IEnumerable<HttpPostedFileBase> files)
{
    if (files != null && files.Any())
    {
        foreach (var file in files)
        {
            if (file.ContentLength > 0)
            {
                string fileName = Path.GetFileName(file.FileName);
                string path = Path.Combine(Server.MapPath("~/UploadedFiles/"), fileName);
                file.SaveAs(path);
            }
        }

        TempData["Message"] = "Files uploaded successfully!";
    }
    else
    {
        TempData["Message"] = "No files selected.";
    }

    return RedirectToAction("UploadMultiple");
}
```

---

### 6. **Conclusion**

File uploading in ASP.NET is straightforward but requires handling several aspects like validation, saving files securely, and managing multiple file uploads. Whether you're using Web Forms or MVC, the process generally follows the same steps:

1. **Create an HTML form** with the `enctype="multipart/form-data"` attribute.
2. **Handle the file on the server side**, using `HttpPostedFile` for Web Forms or `HttpPostedFileBase` for MVC.
3. **Validate file types and sizes** to ensure secure and efficient file uploads.
4. **Save the file to a directory** on the server or other storage solutions.

This approach can be extended for more complex scenarios, such as handling large file uploads, saving files to cloud storage, or working with advanced validation rules.
